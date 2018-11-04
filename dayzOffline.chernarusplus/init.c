/*
	DayZ SA CCCP Mod
	
	FileName: Init.c
	
	Usage:
	FNR:Description

	Authors: DayZ SA CCCP Mod Team and Community Contributors(see credits.md)
	FNR:ModTeamInfo
	
	FNR:LicenseInfo
*/
	
void main()
{
	//Load map structures-before Hive Init
	#include "$CurrentDir:\mpmissions\dayzOffline.chernarusplus\CCCP\configs\MapStructuresCfg.c"
	
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();
	
	//Use this for gathering your loot positions from your building additions
    #include "$CurrentDir:\mpmissions\dayzOffline.chernarusplus\CCCP\tools\ExportProxyData.c"
	
	//Weather Configuration
	#include "$CurrentDir:\mpmissions\dayzOffline.chernarusplus\CCCP\configs\WeatherCfg.c"
}

class CustomMission: MissionServer
{
	//PreInit mission and systems within this file
	#include "$CurrentDir:\mpmissions\dayzOffline.chernarusplus\CCCP\PreInit.c"
	
	//This loads after everything is ready above
	#include "$CurrentDir:\mpmissions\dayzOffline.chernarusplus\CCCP\overrides\MS_OnInit.c"
	
};
  
Mission CreateCustomMission(string path)
{
	return new CustomMission();
}
