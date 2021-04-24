@echo off
:START
DayZServer_x64.exe -cpuCount=4 -mod=@42MonthsAfter;@DeerIsle;@CF;@ZomBerryAdminTools;@CodeLock;@BuilderItems;@BuildAnywhere_v3;@Ear-Plugs;@BaseBuildingPlus;@DayZEditorLoader;@IRPLandRoverDefender110;@TeddysWeaponPack;@CannabisPlus;@ModularVestSystem;@VanillaPlusPlusMap;@VendingMachine;@TraderPlus; -config=serverDZ.cfg -port=2302 -noFilePatching -profiles=myprofile -scrAllowFileWrite -adminlog
timeout 15
goto START