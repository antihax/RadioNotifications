---
title: Container_Base

---

# Container_Base





## Public Functions

|                | Name           |
| -------------- | -------------- |
| override void | **[DeferredInit](class_container___base.md#function-deferredinit)**() |
| override void | **[EEDelete](class_container___base.md#function-eedelete)**(EntityAI parent) |
| override void | **[EEKilled](class_container___base.md#function-eekilled)**(Object killer) |
| void | **[EOnRadioNotificationUpdate](class_container___base.md#function-eonradionotificationupdate)**() |
| void | **[~Container_Base](class_container___base.md#function-~container-base)**() |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| protected int | **[m_RadioNotificationID](class_container___base.md#variable-m-radionotificationid)**  |
| protected autoptr Timer | **[m_RadioNotificationUpdateTimer](class_container___base.md#variable-m-radionotificationupdatetimer)**  |

## Public Functions Documentation

### function DeferredInit

```cpp
override void DeferredInit()
```


### function EEDelete

```cpp
override void EEDelete(
    EntityAI parent
)
```


### function EEKilled

```cpp
override void EEKilled(
    Object killer
)
```


### function EOnRadioNotificationUpdate

```cpp
void EOnRadioNotificationUpdate()
```


### function ~Container_Base

```cpp
void ~Container_Base()
```


## Public Attributes Documentation

### variable m_RadioNotificationID

```cpp
protected int m_RadioNotificationID;
```


### variable m_RadioNotificationUpdateTimer

```cpp
protected autoptr Timer m_RadioNotificationUpdateTimer;
```


-------------------------------

Updated on 2023-12-27 at 17:47:50 -0600