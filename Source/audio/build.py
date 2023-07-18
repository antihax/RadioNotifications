#!/usr/bin/python3

 # RadioNotifications Mod
 # https://github.com/antihax/RadioNotifications
 # © 2022 antihax
 #
 # This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 # To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.

from pydub import AudioSegment
from pydub.silence import split_on_silence
import os

num_voices = 9
num_samples = 54
normalization_target = -30.0

# Normalize a chunk to a target amplitude.
def match_target_amplitude(aChunk, target_dBFS):
    change_in_dBFS = target_dBFS - aChunk.dBFS
    return aChunk.apply_gain(change_in_dBFS)

def convertFile(file: str, type: str, voice: int):
    audio = AudioSegment.from_wav(file)
    normalized_chunk = match_target_amplitude(audio, normalization_target)
    normalized_chunk.set_channels(1)
    normalized_chunk.export(
        "../../sounds/"+type+"/{0}.ogg".format(voice),
        format = "ogg",
        codec="libvorbis",
        parameters=["-ac", "1"]
    )

def split_file_on_silence(voice: int):
    audio = AudioSegment.from_wav("phonetic/"+str(voice)+".wav")
    chunks = split_on_silence (
        audio, 

        # Specify that a silent chunk must be at least min_silence_len ms long.
        min_silence_len = 300,
        
        # Consider a chunk silent if it's quieter than silence_thresh dBFS.
        # Keep this low to prevent clicky sounds and cutting off early
        silence_thresh = -70
    )

    print("Found {0} slices.".format(len(chunks)))
    if (len(chunks) != num_samples):
        print("Expected {0] slices, got {1}".format(num_samples, len(chunks)))
        quit()


    for i, chunk in enumerate(chunks):
        # Add some silence to the beginning and end of the chunk.
        silence_chunk = AudioSegment.silent(duration=225)

        # Add the padding chunk to beginning and end of the entire chunk.
        audio_chunk = silence_chunk + chunk + silence_chunk

        # Normalize the entire chunk.
        normalized_chunk = match_target_amplitude(audio_chunk, normalization_target)

        # Export the audio chunk with new bitrate.
        print("Exporting {0} {1}.".format(voice, i))
        normalized_chunk.set_channels(1)
        normalized_chunk.export(
            "../../sounds/phonetics/{0}_{1}.ogg".format(voice, i),
            format = "ogg",
            codec="libvorbis",
            parameters=["-ac", "1"]
        )

sound_shaders = []
sound_sets = []

print("Converting preambles...")
c = 0
for file in os.listdir("./preambles"):
  if file.endswith(".wav"):
    convertFile("./preambles/"+file, "preambles", c)
    print(c)
    sound_shaders.append("""
        class RadioNotification_Preamble%d_SoundShader: RadioNotification_SoundShader
        {
            samples[] = {{"RadioNotifications\\sounds\\preambles\\%d",1}};
        };""" % (c, c))
    
    sound_sets.append("""
        class RadioNotification_Preamble%d: RadioNotification_SoundSet
        {
            soundShaders[] = {"RadioNotification_Preamble%d_SoundShader"};
        };""" % (c, c))    
    c+=1

print("Converting noise...")
c = 0
for file in os.listdir("./noise"):
  if file.endswith(".wav"):
    convertFile("./noise/"+file, "noise", c)
    print(c)
    
    sound_shaders.append("""
        class RadioNotification_Noise%d_SoundShader: RadioNotification_SoundShader
        {
            samples[] = {{"RadioNotifications\\sounds\\noise\%d",1}};
        };""" % (c, c))
    
    sound_sets.append("""
        class RadioNotification_Noise%d: RadioNotification_SoundSet
        {
            soundShaders[] = {"RadioNotification_Noise%d_SoundShader"};
            loop = 1;
        };""" % (c, c))        
    c+=1

print("Converting phonetics...")
for i in range(num_voices):
    split_file_on_silence(i)
    for v in range(num_samples):
        sound_shaders.append("""
            class RadioNotification_Voice%d_Phonetic%d_SoundShader: RadioNotification_SoundShader
            {
                samples[] = {{"RadioNotifications\\sounds\\phonetics\\%d_%d",1}};
            };""" % (i, v, i, v))
        
        sound_sets.append("""
            class RadioNotification_Voice%d_Phonetic%d: RadioNotification_SoundSet
            {
                soundShaders[] = {"RadioNotification_Voice%d_Phonetic%d_SoundShader"};
            };""" % (i, v, i, v))        


with open('./export/sound_shaders.cpp', 'w') as f:
    for l in sound_shaders:
        f.write(f"{l}\n")

with open('./export/sound_sets.cpp', 'w') as f:
    for l in sound_sets:
        f.write(f"{l}\n")
