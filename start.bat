@echo off
:START
DayZServer_x64.exe -cpuCount=4 -mod=@42MonthsAfter;@DeerIsle;@CF;@ZomBerryAdminTools;@GameLabs;@DayZEditorLoader;@ForeverLightsandCampfires;@ModularVestSystem;@TeddysWeaponPack;@CodeLock;@BaseBuildingPlus;@MoreWolves;@MuchStuffPack;@CannabisPlus;@Notifications;@GAZ;@VanillaPlusPlusMap;@zSpawnSelection;@ToxicZone;@BuildAnywherev3;@BuilderItems;@MoreDoors;@MuchCarKey;@IRPLandRoverDefender110;@TrolleyKart;@EarPlugs;@AirdropUpgraded;@VendingMachine;@BattlEyePrefixRemoval;@TraderPlus; -config=serverDZ.cfg -port=2302 -noFilePatching -profiles=myprofile -scrAllowFileWrite -adminlog
timeout 10
goto START