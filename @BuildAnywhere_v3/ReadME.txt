BuildAnywhere version 3.3.

Allows ghosts to be set anywhere for placing objects and building of components where the vanilla game normally would not.
There are some limitations, for example if you cannot see the trigger points (ie putting a fence completely inside a wall,
you will not be able to actually build it as the wall will obstruct your view of the fence).

=============================================================================
WARNING!
Mod not allows placing GardenPlot on roads, stones, in houses and builds stairs from it.
Mod not allows placing tents on water, trees and much higher or lower than player.
Mod not overrides default restrictions for placing Barrels and Fireplaces.
=============================================================================

Server Owners:
Install the mod on your client to download.
Right click on the mod in Launcher and Browse Files
Copy the @BuildAnywhere_v3 directory to your DayZServer directory root
add -mod=@BuildAnywhere_v3 to your launch parameter -mod= or ;@BuildAnywhere_v3 after all other mods.

Copy BorizzK.bikey from inside @BuildAnywhere_v3/Key to the Keys difrectory in the root of your DayZServer.

=============================================================================

For change default Tent place restriction level on server side (affects to clients) add parameter
TentCanBePlaceAnywhereLevel to config file of your server (for example: serverDZ.cfg) and set parameter to:

0 or no parameter - Soft restrictions for placing tents, default restrictions for Garden Plot and no restrictions for others. BuildAnywhere V3 Default. Recommended.

1 - No restrictions for all (Like in original BuildAnywhere), but little resrictions for placing tents.

2 - Default game restrictions.

For example: TentCanBePlaceAnywhereLevel = 1;

=============================================================================

NOTE: This is required on both client and server to function. Requires verifySignatures=3; to be set in server config file.
Be sure to copy the provided .bikey from key to your keys folder.

Mod co-Author: Cleetus.
https://steamcommunity.com/sharedfiles/filedetails/?id=1574054508

ThanX to: MusTanG, Wardog and Equadro.

License:
ADPL-SA [url=http://bistudio.com]Bohemia Interactive[/url]
