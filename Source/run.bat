@echo off
taskkill /im DayZDiag_x64.exe /F

rmdir /s /q p:\RadioNotifications\docs\
mkdir p:\RadioNotifications\docs\
doxygen
DayZInput.ps1
doxybook2 --input=p:\RadioNotifications\Source\tempdocs\xml --output=p:\RadioNotifications\docs --config config.json

set modpath=%DAYZ%%\!Workshop
set srcpath=P:\RadioNotifications
set defpath=P:\0_RadioNotifications
set path2=P:\RadioNotifications\Source\dist
set exportPath=p:\RadioNotifications\Source\dist\RadioNotifications
set allclientmods=P:\BitWiseFramework\Source\dist\BitWiseFramework;%modpath%\@CF;%modpath%\@PvZmoD_CustomisableZombies;%modpath%\@BuilderItems;%modpath%\@VPPAdminTools;%modpath%\@Code Lock;%modpath%\@Ear-Plugs;%modpath%\@SchanaModParty;%modpath%\@SchanaModGlobalChat;%modpath%\@Notes;%modpath%\@Basic Map;%modpath%\@Basic Territories;%modpath%\@BaseBuildingPlus;%modpath%\@TraderPlus;%modpath%\@Survivor Animations;%modpath%\@Mortys Weapons;%modpath%\@WindstridesClothingPack;%modpath%\@Uncuepas Civilian Clothing;%modpath%\@Jills Collection;%modpath%\@Tommys Books;%modpath%\@Zeroy-FishingZ;%modpath%\@CJ187-PokemonCards;%modpath%\@CarsForAll;%modpath%\@RedFalcon Flight System Heliz;%modpath%\@Trolley kart;%modpath%\@MuchDecos;%modpath%\@MuchCarKey;%modpath%\@MuchStuffPack;
set currentMod=%path2%\RadioNotifications;

%DAYZTOOLS%\Bin\CfgConvert\CfgConvert.exe -bin -dst %srcpath%\config.bin %srcpath%\config.cpp
pboProject.exe -P +e="dayzSA" +Z +C -B +K +J +T  +M="%exportPath%" +K="%DAYZPRIVATEKEY%" "%defpath%" 
pboProject.exe -P +e="dayzSA" +Z +C -B +K +J +T +M="%exportPath%" +K="%DAYZPRIVATEKEY%" "%srcpath%" 

set profileFolder=%DAYZ%\dayzOffline.chernarusplus\profiles
set profileFolderClient=%DAYZ%\mpmissions\dayzOffline.chernarusplus\profilesClient
set configPath=%DAYZ%\mpmissions\dayzOffline.chernarusplus\serverDZ.cfg

IF EXIST "P:\temp\" (
    rmdir "P:\temp\" /s /q
)

start %DAYZ%\DayZDiag_x64.exe "-server" "-mod=%allclientmods%%currentMod%" "-config=%configPath%" "-profiles=%profileFolder%"  -doLogs -newErrorsAreWarnings=1 -nosplash -noPause -filePatching -scrDef=BITWISEDEBUG
start %DAYZ%\DayZDiag_x64.exe "-mod=%allclientmods%%currentMod%" "-connect=127.0.0.1" "-port=2302" "-profiles=%profileFolderClient%" -dologs -newErrorsAreWarnings=1  -nosplash -noPause -filePatching -scrDef=BITWISEDEBUG


