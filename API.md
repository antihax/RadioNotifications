# API for mod communications.

Custom events can be created using API allowing other mods to create notifications
To determine the mod is available, API calls and logic can be wrapped with ifdef.

```c
#ifdef RADIONOTIFICATIONS
    ...
#endif
```

## RadioNotificationManager

The main controller

### GetRadioNotificationManager

`RadioNotificationManager GetRadioNotificationManager()`
Returns the Radio Notification Manager.

### RadioNotificationManager::AddEvent

`int AddEvent(RadioNotificationEvent e)`
For injecting custom events to the queue. Returns the eventID on the queue.

### RadioNotificationManager::UpdateEventPosition

`int UpdateEventPosition(int id, vector position, vector direction)`
Update the position of a moving RadioNotificationEvent based on the id. Such as an airplane or helicopter if you wish to have the player time trajectory from a notification.

### RadioNotificationManager::RemoveEvent

`int RemoveEvent(int id)`
Remove the eventID from the queue.

## RadioNotificationEvent

The RadioNotificationEvent structure passed to `AddEvent`. See the [JSON configuration](README.md#radionotificationevent) for explanation of the values.

````c
    void RadioNotificationEvent(
    int _preamble = 255,
    int _voice = 0,
    int _noise = 0,
    int _signature = 255,
    array<int> _phonetics = null,
    int _pause = 0,
    int _delay = 60,
    int _repeat = 3,
    vector _position = "0 0 0",
    int _heading = 0)```
````
