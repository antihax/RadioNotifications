[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/O5O33VK5S)
[Or GitHub Sponsors](https://github.com/sponsors/antihax)

# RadioNotifications

Configurable radio notifications provide immersive coordinates or clues to in-game events such as helicopter crashes, loot drops, or hidden traders.

Features:

- Multiple voices, signal noise, and preamble sounds.
- API for third-party mod integration.
- No-code configuration for BuildingBase spawned event.
- Loud notification of incoming artillery strikes.

# Table of Contents

1. [License](#license)
2. [Configuration](#configuration)
   1. [Global Configuration](#global)
   2. [eventMap](#eventmap)
   3. [staticEvents](#staticevents)
   4. [alarmMap](#alarmmap)
   5. [RadioNotificationEvent](#RadioNotificationEvent)
3. [API](#api)
4. [Credits](#credits)

# License

License: This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.

https://creativecommons.org/licenses/by-nc-nd/4.0/

Content locked behind this mod must be available to public DayZ players on participating servers.

# Configuration

A default JSON file is created at `$profile/RadioNotifications/Settings.json` on the first run of the server.

## Global Configuration <a name="global"></a>

### maxDistance `int`

Furthest distance a transmission can be heard.

### baseRadioMultiplier `float`

Multiplier to maxDistance for base radios.

### ignoreDistance `int`

Falloff to ignore transmissions.

### minVolume `float`

Lowest volume to reduce voice or noise. 0.0 through 1.0.

### maxVolume `float`

Highest volume to allow voice or noise. 0.0 through 1.0.

### radioChannel `int`

The radio channel to broadcast events. 0 through 7.

### randomNoise `bool`

Randomize noise for each broadcast instead of using predefined values. 0 or 1.

### disablePlayerBroadcast `bool`

Disable players broadcasting on the radio channel used for events. 0 or 1.

## eventMap

The eventMap allows events to be broadcast when a new BuildingBase is created.

```json
    "eventMap": {
        "Wreck_UH1Y": {
            "preamble": 1,
            "voice": 1,
            "noise": 2,
            "signature": 1,
            "phonetics": [
                36,
                37,
                45,
                30,
                17,
                1,
                34,
                41,
                128,
                41,
                128,
                42
            ],
            "pause": 1,
            "delay": 60,
            "repeat": 5
        }
    }
```

## staticEvents

The array staticEvents provides constantly looping notifications for a fixed world position.

```json
    "staticEvents": [
        {
            "position": [
                5232.0,
                0.0,
                2435.0
            ],
            "anEvent": {
                "preamble": 0,
                "voice": 0,
                "noise": 0,
                "signature": 0,
                "phonetics": [1,2,3,4,5,6],
                "pause": 0,
                "delay": 0,
                "repeat": 0
            }
        }
    ]
```

## alarmMap

The alarmMap links BaseBuilding classes to alarms. At this time there is only a single airraid alarm used mostly for `ContaminatedArea_Dynamic` aka the Toxic Artillery Strike.

```json
    "alarmMap": {
        "ContaminatedArea_Dynamic": {
            "alarm": 0,
            "radius": 100
        }
    }
```

## RadioNotificationEvent

RadioNotificationEvent are the core data structure and have the following components.

### preamble `int`

The initial burst during the transmission. 255 disables. Range is 0 through 8.

### voice `int`

The voice for the broadcast. Current range is 0 through 9.

### noise `int`

The background static noise for the broadcast. Current range is 0 through 7.

### signature `int`

Same samples as preamble, the final burst during transmission. 255 disables.

### phonetics

Array of samples to play in the voice. A [list of phonetic values](PHONETICS.md) is available.

### pause `int`

Short delay in seconds between preamble and the voice speaking phonetics. 0 through 7.

### delay `int`

Delay in seconds between repeating the notification. Shall be significant enough to prevent overfilling the queue. Overfilling the queue will cause desync between players observations if two radios are in proximity.

### repeat `int`

Number of times to repeat the notification before no longer sending furtern notifications. A value of 0 repeats forever or the entity is destroyed. It is not guaranteed that all BuildingBase objects are removed.

# API

[API Documentation](API.md) is provided separately due to size.

# Credits

- Helkhiana - Consulting, testing, sanity.
- Pixabay: the base source for the air-raid siren sample.
- Narakeet: the licensed base source for voice audio.
- [Enfusion Modders Discord](https://discord.com/invite/enfusionmodders) A community built around modding Enfusion powered games such as DayZ and Arma Reforger.
