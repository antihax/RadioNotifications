---
title: RadioNotificationManager

---

# RadioNotificationManager





## Public Functions

|                | Name           |
| -------------- | -------------- |
| int | **[AddAlarm](class_radio_notification_manager.md#function-addalarm)**([RadioNotificationStaticAlarmPair](class_radio_notification_static_alarm_pair.md) e) |
| int | **[AddEvent](class_radio_notification_manager.md#function-addevent)**([RadioNotificationEvent](class_radio_notification_event.md) e) |
| int | **[GetNewTransmissionID](class_radio_notification_manager.md#function-getnewtransmissionid)**(string type, vector position) |
| void | **[RadioNotificationManager](class_radio_notification_manager.md#function-radionotificationmanager)**() |
| void | **[RemoveEvent](class_radio_notification_manager.md#function-removeevent)**(int id) |
| protected void | **[RunAlarmPump](class_radio_notification_manager.md#function-runalarmpump)**() |
| protected void | **[RunNotificationPump](class_radio_notification_manager.md#function-runnotificationpump)**() |
| void | **[SendConfiguration](class_radio_notification_manager.md#function-sendconfiguration)**(notnull Man player) |
| void | **[SendRadioNotificationAlarmEvent](class_radio_notification_manager.md#function-sendradionotificationalarmevent)**(RadioNotificationAlarmEvent e) |
| void | **[SendRadioNotificationEvent](class_radio_notification_manager.md#function-sendradionotificationevent)**([RadioNotificationEvent](class_radio_notification_event.md) e) |
| void | **[StartNotificationPump](class_radio_notification_manager.md#function-startnotificationpump)**() |
| void | **[UpdateEventPosition](class_radio_notification_manager.md#function-updateeventposition)**(int id, vector position, vector direction) |
| void | **[~RadioNotificationManager](class_radio_notification_manager.md#function-~radionotificationmanager)**() |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| protected autoptr map< int, ref [RadioNotificationStaticAlarmPair](class_radio_notification_static_alarm_pair.md) > | **[m_ActiveAlarms](class_radio_notification_manager.md#variable-m-activealarms)**  |
| protected autoptr map< int, ref [RadioNotificationEvent](class_radio_notification_event.md) > | **[m_ActiveEvents](class_radio_notification_manager.md#variable-m-activeevents)**  |
| protected autoptr array< int > | **[m_AlarmIDs](class_radio_notification_manager.md#variable-m-alarmids)**  |
| protected int | **[m_AlarmPointer](class_radio_notification_manager.md#variable-m-alarmpointer)**  |
| protected autoptr Timer | **[m_AlarmPump](class_radio_notification_manager.md#variable-m-alarmpump)**  |
| protected autoptr array< int > | **[m_EventIDs](class_radio_notification_manager.md#variable-m-eventids)**  |
| protected int | **[m_EventPointer](class_radio_notification_manager.md#variable-m-eventpointer)**  |
| protected autoptr Timer | **[m_NotificationPump](class_radio_notification_manager.md#variable-m-notificationpump)**  |
| protected int | **[m_RPC_CONFIGURATION](class_radio_notification_manager.md#variable-m-rpc-configuration)**  |
| protected int | **[m_RPC_RADIONOTIFICATION](class_radio_notification_manager.md#variable-m-rpc-radionotification)**  |
| protected int | **[m_RPC_RADIONOTIFICATIONALARM](class_radio_notification_manager.md#variable-m-rpc-radionotificationalarm)**  |
| protected int | **[m_TransmissionID](class_radio_notification_manager.md#variable-m-transmissionid)**  |

## Public Functions Documentation

### function AddAlarm

```cpp
int AddAlarm(
    RadioNotificationStaticAlarmPair e
)
```


### function AddEvent

```cpp
int AddEvent(
    RadioNotificationEvent e
)
```


### function GetNewTransmissionID

```cpp
int GetNewTransmissionID(
    string type,
    vector position
)
```


### function RadioNotificationManager

```cpp
void RadioNotificationManager()
```


### function RemoveEvent

```cpp
void RemoveEvent(
    int id
)
```


### function RunAlarmPump

```cpp
protected void RunAlarmPump()
```


### function RunNotificationPump

```cpp
protected void RunNotificationPump()
```


### function SendConfiguration

```cpp
void SendConfiguration(
    notnull Man player
)
```


### function SendRadioNotificationAlarmEvent

```cpp
void SendRadioNotificationAlarmEvent(
    RadioNotificationAlarmEvent e
)
```


### function SendRadioNotificationEvent

```cpp
void SendRadioNotificationEvent(
    RadioNotificationEvent e
)
```


### function StartNotificationPump

```cpp
void StartNotificationPump()
```


### function UpdateEventPosition

```cpp
void UpdateEventPosition(
    int id,
    vector position,
    vector direction
)
```


### function ~RadioNotificationManager

```cpp
void ~RadioNotificationManager()
```


## Public Attributes Documentation

### variable m_ActiveAlarms

```cpp
protected autoptr map< int, ref RadioNotificationStaticAlarmPair > m_ActiveAlarms = new map<int, ref RadioNotificationStaticAlarmPair>();
```


### variable m_ActiveEvents

```cpp
protected autoptr map< int, ref RadioNotificationEvent > m_ActiveEvents = new map<int, ref RadioNotificationEvent>();
```


### variable m_AlarmIDs

```cpp
protected autoptr array< int > m_AlarmIDs = {};
```


### variable m_AlarmPointer

```cpp
protected int m_AlarmPointer;
```


### variable m_AlarmPump

```cpp
protected autoptr Timer m_AlarmPump;
```


### variable m_EventIDs

```cpp
protected autoptr array< int > m_EventIDs = {};
```


### variable m_EventPointer

```cpp
protected int m_EventPointer;
```


### variable m_NotificationPump

```cpp
protected autoptr Timer m_NotificationPump;
```


### variable m_RPC_CONFIGURATION

```cpp
protected int m_RPC_CONFIGURATION;
```


### variable m_RPC_RADIONOTIFICATION

```cpp
protected int m_RPC_RADIONOTIFICATION;
```


### variable m_RPC_RADIONOTIFICATIONALARM

```cpp
protected int m_RPC_RADIONOTIFICATIONALARM;
```


### variable m_TransmissionID

```cpp
protected int m_TransmissionID = 1;
```


-------------------------------

Updated on 2023-09-27 at 14:30:58 -0500