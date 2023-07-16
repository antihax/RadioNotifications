@echo off
taskkill /im DayZDiag_x64.exe /F

set modpath=%DAYZ%%\!Workshop
set path=P:\RadioNotifications
REM set path2=%DAYZ%\!ModsTesting
set path2=P:\RadioNotifications\Source\dist
set exportPath=p:\RadioNotifications\Source\dist\RadioNotifications\addons
set allclientmods=%modpath%\@CF;%modpath%\@VanillaPlusPlusMap;%modpath%\@VPPAdminTools;
set currentMod=%path2%\RadioNotifications;

%DAYZTOOLS%\Bin\AddonBuilder\AddonBuilder.exe %path% %exportPath% -clear -packonly

set profileFolder=%DAYZ%\dayzOffline.chernarusplus\profiles
set profileFolderClient=%DAYZ%\mpmissions\dayzOffline.chernarusplus\profilesClient
set configPath=%DAYZ%\mpmissions\dayzOffline.chernarusplus\serverDZ.cfg

start %DAYZ%\DayZDiag_x64.exe "-server" "-mod=%allclientmods%%currentMod%" "-config=%configPath%" "-profiles=%profileFolder%" "-limitFPS=1000" -doLogs -newErrorsAreWarnings=1 -nosplash -noPause  -filePatching 
start %DAYZ%\DayZDiag_x64.exe  "-mod=%allclientmods%%currentMod%" "-connect=127.0.0.1" "-port=2302" "-profiles=%profileFolderClient%" -dologs -newErrorsAreWarnings=1  -nosplash -noPause  -filePatching 