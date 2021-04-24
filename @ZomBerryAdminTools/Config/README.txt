Please note that admins.cfg needs to be in ZomBerry subfolder of profiles folder
Editing it right here, in "@ZomBerry Admin Tools\Config" WILL NOT WORK

If you're confused about what in hell is this "profiles folder" - please consider reading #how-to-install on our community server:
https://discord.gg/gVSS5Tu

TL;DR: Profiles folder is whatever was specified in -profiles= parameter in launch options (command line parameters):
"-profiles=VeryCoolFolder" would lead to creation of "VeryCoolFolder" in root of your server, in this case you're expected
to put admins.cfg in "VeryCoolFolder\ZomBerry"
If you're using a GSP, it's likely that you already have some default profiles folder, check latest .RPT logs and see if you
can find -profiles parameter across first lines of the file