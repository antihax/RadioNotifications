---
title: RadioNotificationEvent

---

# RadioNotificationEvent





## Public Functions

|                | Name           |
| -------------- | -------------- |
| [RadioNotificationEvent](class_radio_notification_event.md) | **[Clone](class_radio_notification_event.md#function-clone)**() |
| bool | **[DeserializeRPC](class_radio_notification_event.md#function-deserializerpc)**(BitStreamReader ctx) |
| void | **[RadioNotificationEvent](class_radio_notification_event.md#function-radionotificationevent)**(int _preamble =-1, int _voice =0, int _noise =0, int _signature =-1, array< int > _phonetics =null, int _pause =0, int _delay =300, int _repeat =3, vector _position ="0 0 0", int _heading =0, string _message ="") |
| bool | **[SerializeRPC](class_radio_notification_event.md#function-serializerpc)**(BitStreamWriter ctx) |
| void | **[~RadioNotificationEvent](class_radio_notification_event.md#function-~radionotificationevent)**() |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| int | **[delay](class_radio_notification_event.md#variable-delay)**  |
| int | **[heading](class_radio_notification_event.md#variable-heading)**  |
| int | **[lastTime](class_radio_notification_event.md#variable-lasttime)**  |
| string | **[message](class_radio_notification_event.md#variable-message)**  |
| int | **[noise](class_radio_notification_event.md#variable-noise)**  |
| int | **[pause](class_radio_notification_event.md#variable-pause)**  |
| ref array< int > | **[phonetics](class_radio_notification_event.md#variable-phonetics)**  |
| vector | **[position](class_radio_notification_event.md#variable-position)**  |
| int | **[preamble](class_radio_notification_event.md#variable-preamble)**  |
| int | **[repeat](class_radio_notification_event.md#variable-repeat)**  |
| int | **[signature](class_radio_notification_event.md#variable-signature)**  |
| int | **[state](class_radio_notification_event.md#variable-state)**  |
| int | **[ticks](class_radio_notification_event.md#variable-ticks)**  |
| int | **[voice](class_radio_notification_event.md#variable-voice)**  |

## Public Functions Documentation

### function Clone

```cpp
RadioNotificationEvent Clone()
```


### function DeserializeRPC

```cpp
bool DeserializeRPC(
    BitStreamReader ctx
)
```


### function RadioNotificationEvent

```cpp
void RadioNotificationEvent(
    int _preamble =-1,
    int _voice =0,
    int _noise =0,
    int _signature =-1,
    array< int > _phonetics =null,
    int _pause =0,
    int _delay =300,
    int _repeat =3,
    vector _position ="0 0 0",
    int _heading =0,
    string _message =""
)
```


### function SerializeRPC

```cpp
bool SerializeRPC(
    BitStreamWriter ctx
)
```


### function ~RadioNotificationEvent

```cpp
void ~RadioNotificationEvent()
```


## Public Attributes Documentation

### variable delay

```cpp
int delay;
```


### variable heading

```cpp
int heading = 0;
```


### variable lastTime

```cpp
int lastTime = 0;
```


### variable message

```cpp
string message;
```


### variable noise

```cpp
int noise;
```


### variable pause

```cpp
int pause;
```


### variable phonetics

```cpp
ref array< int > phonetics = {};
```


### variable position

```cpp
vector position = "0 0 0";
```


### variable preamble

```cpp
int preamble;
```


### variable repeat

```cpp
int repeat;
```


### variable signature

```cpp
int signature;
```


### variable state

```cpp
int state = 0;
```


### variable ticks

```cpp
int ticks = 0;
```


### variable voice

```cpp
int voice;
```


-------------------------------

Updated on 2023-09-27 at 14:30:58 -0500