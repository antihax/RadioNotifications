@echo off
taskkill /im DayZDiag_x64.exe /F
timeout /t 1

set modpath=%DAYZ%%\!Workshop
set srcpath=P:\RadioNotifications
set path2=P:\RadioNotifications\Source\dist
set exportPath=p:\RadioNotifications\Source\dist\RadioNotifications
set allclientmods=P:\BitWiseFramework\Source\dist\BitWiseFramework;%modpath%\@CF;%modpath%\@VanillaPlusPlusMap;%modpath%\@VPPAdminTools;%modpath%\@RedFalcon Flight System Heliz;%modpath%\@Airdrop-Upgraded;%modpath%\@DNA_Keycards;%modpath%\@RUSForma_vehicles;%modpath%\@eAI;
set currentMod=%path2%\RadioNotifications;

%DAYZTOOLS%\Bin\CfgConvert\CfgConvert.exe -bin -dst %srcpath%\config.bin  %srcpath%\config.cpp
pboProject.exe -P +e="dayzSA" +Z +C -B +K +J +T +M="%exportPath%" +K="%DAYZPRIVATEKEY%" "%srcpath%" 

set profileFolder=%DAYZ%\dayzOffline.chernarusplus\profiles
set profileFolderClient=%DAYZ%\mpmissions\dayzOffline.chernarusplus\profilesClient
set configPath=%DAYZ%\mpmissions\dayzOffline.chernarusplus\serverDZ.cfg

start %DAYZ%\DayZDiag_x64.exe "-server" "-mod=%allclientmods%%currentMod%" "-config=%configPath%" "-profiles=%profileFolder%"  -doLogs -newErrorsAreWarnings=1 -nosplash -noPause -filePatching -scrDef=RADIONOTIFICATIONS_DEBUG
rem start %DAYZ%\DayZDiag_x64.exe "-mod=%allclientmods%%currentMod%" "-connect=127.0.0.1" "-port=2302" "-profiles=%profileFolderClient%" -dologs -newErrorsAreWarnings=1  -nosplash -noPause -filePatching -scrDef=RADIONOTIFICATIONS_DEBUG