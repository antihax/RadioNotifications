---
title: BuildingBase

---

# BuildingBase





## Public Functions

|                | Name           |
| -------------- | -------------- |
| override void | **[DeferredInit](class_building_base.md#function-deferredinit)**() |
| override void | **[EEDelete](class_building_base.md#function-eedelete)**(EntityAI parent) |
| override void | **[EEKilled](class_building_base.md#function-eekilled)**(Object killer) |
| void | **[EOnRadioNotificationUpdate](class_building_base.md#function-eonradionotificationupdate)**() |
| void | **[~BuildingBase](class_building_base.md#function-~buildingbase)**() |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| protected int | **[m_RadioNotificationID](class_building_base.md#variable-m-radionotificationid)**  |
| protected autoptr Timer | **[m_RadioNotificationUpdateTimer](class_building_base.md#variable-m-radionotificationupdatetimer)**  |

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


### function ~BuildingBase

```cpp
void ~BuildingBase()
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

Updated on 2023-11-04 at 11:33:00 -0500