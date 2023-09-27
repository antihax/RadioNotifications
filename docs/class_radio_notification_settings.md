---
title: RadioNotificationSettings

---

# RadioNotificationSettings



 [More...](#detailed-description)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| void | **[DefaultSettings](class_radio_notification_settings.md#function-defaultsettings)**() |
| bool | **[DeserializeRPC](class_radio_notification_settings.md#function-deserializerpc)**(BitStreamReader ctx)<br>Deserialize the settings from the client. Called internally.  |
| void | **[DetectSoundSets](class_radio_notification_settings.md#function-detectsoundsets)**()<br>DetectSoundSets is called internally to detect the number of sound sets available.  |
| RadioNotificationAlarmEvent | **[GetAlarm](class_radio_notification_settings.md#function-getalarm)**(string typeName) |
| [RadioNotificationEvent](class_radio_notification_event.md) | **[GetEvent](class_radio_notification_settings.md#function-getevent)**(string typeName) |
| [RadioNotificationOneTimePad](class_radio_notification_one_time_pad.md) | **[GetOneTimePad](class_radio_notification_settings.md#function-getonetimepad)**()<br>GetOneTimePad returns the OneTimePad for decoding encrypted messages.  |
| [RadioNotificationSettings](class_radio_notification_settings.md) | **[GetSettings](class_radio_notification_settings.md#function-getsettings)**()<br>GetSettings returns the loaded settings. Should be called after mission start by mod developers.  |
| void | **[Init](class_radio_notification_settings.md#function-init)**()<br>Called internally to initialize the singleton.  |
| void | **[InitOneTimePad](class_radio_notification_settings.md#function-initonetimepad)**() |
| void | **[Load](class_radio_notification_settings.md#function-load)**() |
| void | **[RadioNotificationSettings](class_radio_notification_settings.md#function-radionotificationsettings)**() |
| void | **[Save](class_radio_notification_settings.md#function-save)**() |
| bool | **[SerializeRPC](class_radio_notification_settings.md#function-serializerpc)**(BitStreamWriter ctx)<br>Serialize the settings to the client. Called internally.  |
| void | **[~RadioNotificationSettings](class_radio_notification_settings.md#function-~radionotificationsettings)**() |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| protected const string | **[FOLDER](class_radio_notification_settings.md#variable-folder)**  |
| protected const string | **[SETTINGS](class_radio_notification_settings.md#variable-settings)**  |
| autoptr map< string, RadioNotificationAlarmEvent > | **[alarmMap](class_radio_notification_settings.md#variable-alarmmap)** <br>Map of alarms to their typeNames. See RadioNotificationAlarmEvent for more information.  |
| float | **[baseRadioMultiplier](class_radio_notification_settings.md#variable-baseradiomultiplier)** <br>Multiplier for base radios.  |
| bool | **[disablePlayerBroadcast](class_radio_notification_settings.md#variable-disableplayerbroadcast)** <br>Disable players broadcasting on the radio.  |
| autoptr map< string, [RadioNotificationEvent](class_radio_notification_event.md) > | **[eventMap](class_radio_notification_settings.md#variable-eventmap)** <br>Map of events to their typeNames. See [RadioNotificationEvent](class_radio_notification_event.md) for more information.  |
| const int | **[expectedVersion](class_radio_notification_settings.md#variable-expectedversion)** <br>Expected version, used to detect if settings need to be reset. Not user configurable.  |
| int | **[ignoreDistance](class_radio_notification_settings.md#variable-ignoredistance)** <br>Falloff to ignore transmissions.  |
| ref [RadioNotificationSettings](class_radio_notification_settings.md) | **[m_Settings](class_radio_notification_settings.md#variable-m-settings)**  |
| int | **[maxDistance](class_radio_notification_settings.md#variable-maxdistance)** <br>Furthest distance a transmission can be heard.  |
| float | **[maxVolume](class_radio_notification_settings.md#variable-maxvolume)** <br>Volume range for transmissions.  |
| float | **[minVolume](class_radio_notification_settings.md#variable-minvolume)** <br>Volume range for transmissions.  |
| int | **[numAlarms](class_radio_notification_settings.md#variable-numalarms)** <br>Automatically detected.  |
| int | **[numNoises](class_radio_notification_settings.md#variable-numnoises)** <br>Automatically detected.  |
| int | **[numPhonetics](class_radio_notification_settings.md#variable-numphonetics)** <br>Automatically detected.  |
| int | **[numPreambles](class_radio_notification_settings.md#variable-numpreambles)** <br>Automatically detected.  |
| int | **[numVoices](class_radio_notification_settings.md#variable-numvoices)** <br>Automatically detected.  |
| autoptr [RadioNotificationOneTimePad](class_radio_notification_one_time_pad.md) | **[pad](class_radio_notification_settings.md#variable-pad)** <br>Automatically created.  |
| int | **[padSeed](class_radio_notification_settings.md#variable-padseed)** <br>Automatically created.  |
| int | **[radioChannel](class_radio_notification_settings.md#variable-radiochannel)** <br>Radio Channel Broadcast.  |
| bool | **[randomNoise](class_radio_notification_settings.md#variable-randomnoise)** <br>Enable randomize noise to minimize predicting the message type.  |
| autoptr array< [RadioNotificationStaticAlarmPair](class_radio_notification_static_alarm_pair.md) > | **[staticAlarms](class_radio_notification_settings.md#variable-staticalarms)** <br>Static alarms to always repeat. See RadioNotificationStaticPair for more information.  |
| autoptr array< RadioNotificationStaticPair > | **[staticEvents](class_radio_notification_settings.md#variable-staticevents)** <br>Static events to always repeat. See RadioNotificationStaticPair for more information.  |
| int | **[version](class_radio_notification_settings.md#variable-version)** <br>Current version, used to detect if settings need to be reset. Not user configurable.  |

## Detailed Description

```cpp
class RadioNotificationSettings;
```


[RadioNotificationSettings](class_radio_notification_settings.md) is a singleton class that stores all the settings for the mod configured from the JSON file at $profile:RadioNotifications/Settings.json 

## Public Functions Documentation

### function DefaultSettings

```cpp
void DefaultSettings()
```


### function DeserializeRPC

```cpp
bool DeserializeRPC(
    BitStreamReader ctx
)
```

Deserialize the settings from the client. Called internally. 

### function DetectSoundSets

```cpp
void DetectSoundSets()
```

DetectSoundSets is called internally to detect the number of sound sets available. 

### function GetAlarm

```cpp
RadioNotificationAlarmEvent GetAlarm(
    string typeName
)
```


### function GetEvent

```cpp
RadioNotificationEvent GetEvent(
    string typeName
)
```


### function GetOneTimePad

```cpp
RadioNotificationOneTimePad GetOneTimePad()
```

GetOneTimePad returns the OneTimePad for decoding encrypted messages. 

### function GetSettings

```cpp
static RadioNotificationSettings GetSettings()
```

GetSettings returns the loaded settings. Should be called after mission start by mod developers. 

### function Init

```cpp
static void Init()
```

Called internally to initialize the singleton. 

### function InitOneTimePad

```cpp
void InitOneTimePad()
```


### function Load

```cpp
void Load()
```


### function RadioNotificationSettings

```cpp
void RadioNotificationSettings()
```


### function Save

```cpp
void Save()
```


### function SerializeRPC

```cpp
bool SerializeRPC(
    BitStreamWriter ctx
)
```

Serialize the settings to the client. Called internally. 

### function ~RadioNotificationSettings

```cpp
void ~RadioNotificationSettings()
```


## Public Attributes Documentation

### variable FOLDER

```cpp
static protected const string FOLDER = "$profile:RadioNotifications";
```


### variable SETTINGS

```cpp
static protected const string SETTINGS = FOLDER + "\\Settings.json";
```


### variable alarmMap

```cpp
autoptr map< string, RadioNotificationAlarmEvent > alarmMap;
```

Map of alarms to their typeNames. See RadioNotificationAlarmEvent for more information. 

### variable baseRadioMultiplier

```cpp
float baseRadioMultiplier;
```

Multiplier for base radios. 

### variable disablePlayerBroadcast

```cpp
bool disablePlayerBroadcast;
```

Disable players broadcasting on the radio. 

### variable eventMap

```cpp
autoptr map< string, RadioNotificationEvent > eventMap;
```

Map of events to their typeNames. See [RadioNotificationEvent](class_radio_notification_event.md) for more information. 

### variable expectedVersion

```cpp
const int expectedVersion = 1;
```

Expected version, used to detect if settings need to be reset. Not user configurable. 

### variable ignoreDistance

```cpp
int ignoreDistance;
```

Falloff to ignore transmissions. 

### variable m_Settings

```cpp
static ref RadioNotificationSettings m_Settings;
```


### variable maxDistance

```cpp
int maxDistance;
```

Furthest distance a transmission can be heard. 

### variable maxVolume

```cpp
float maxVolume;
```

Volume range for transmissions. 

### variable minVolume

```cpp
float minVolume;
```

Volume range for transmissions. 

### variable numAlarms

```cpp
int numAlarms;
```

Automatically detected. 

### variable numNoises

```cpp
int numNoises;
```

Automatically detected. 

### variable numPhonetics

```cpp
int numPhonetics;
```

Automatically detected. 

### variable numPreambles

```cpp
int numPreambles;
```

Automatically detected. 

### variable numVoices

```cpp
int numVoices;
```

Automatically detected. 

### variable pad

```cpp
autoptr RadioNotificationOneTimePad pad;
```

Automatically created. 

### variable padSeed

```cpp
int padSeed;
```

Automatically created. 

### variable radioChannel

```cpp
int radioChannel;
```

Radio Channel Broadcast. 

### variable randomNoise

```cpp
bool randomNoise;
```

Enable randomize noise to minimize predicting the message type. 

### variable staticAlarms

```cpp
autoptr array< RadioNotificationStaticAlarmPair > staticAlarms;
```

Static alarms to always repeat. See RadioNotificationStaticPair for more information. 

### variable staticEvents

```cpp
autoptr array< RadioNotificationStaticPair > staticEvents;
```

Static events to always repeat. See RadioNotificationStaticPair for more information. 

### variable version

```cpp
int version;
```

Current version, used to detect if settings need to be reset. Not user configurable. 

-------------------------------

Updated on 2023-09-27 at 14:30:58 -0500