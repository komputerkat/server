KillFeed README.txt
-------------------

Welcome to KillFeed (v3.1). KillFeed has had another major overhaul.

----------------------
Notes:
----------------------
The configuration file is now in json format and should be pretty easy to understand, it will be found on the server side at ServerProfile/ModConfigs/KillFeedServer.json.
Client now has KillFeeedClient.json configuration file in their profile folder (%localappdata%/dayz/KillFeedClient.json).



*********************************************************************************************************************************************************************************
For Players:
*********************************************************************************************************************************************************************************
In-Game you have a menu available, by pressing the Backslash key on the keyboard (configurable in keybinds menu). Also now there is an option to toggle the feed visibility (check keybinds menu).

Alternatively you can manually edit the configuration as follows:
*********************************************************************************************************************************************************************************
KillFeedClient.json:
----------------------
{
    "ShowKillFeed": 1,
    "PositionX": 25,
    "PositionY": 150,
    "MaxCustomMessages": 5,
    "DisplayTime": 5
}
----------------------

ShowKillFeed:
1 = show UI feed
0 = hide UI feed
NOTE: This setting is only for if server has UI feed enabled (will not disable feed messages when server is using chat mode).

----------------------
PositionX:
(+)Number = horizontal position on screen in relation to top left

----------------------
PositionY:
(+)Number = vertical position on screen in relation to top left

----------------------
MaxCustomMessages:
(+)Number = maximum number of messages to show on custom KillFeed output (1-5)

----------------------
DisplayTime:
(+)Number = how long each message stays for (new messages override this if maximum is reached) in seconds (0-5)

----------------------



*********************************************************************************************************************************************************************************
For Servers:
*********************************************************************************************************************************************************************************
Installation (option 1 - killfeed custom notifications or dayz notifications):
-------------
1. Copy @KillFeed to Server folder.
2. Copy the CleetusV3.bikey file from @KillFeed folder into your server's keys folder.
3. Add -mod=@KillFeed to your server launch parameters (or add @KillFeed; to your list of existing mod parameters).
4. Run your server.

Installation (option 2 - killfeed chat):
-------------
1. Copy @KillFeed to Server folder.
2. Copy the CleetusV3.bikey file from @KillFeed folder into your server's keys folder.
3. Add -servermod=@KillFeed to your server launch parameters (or add @KillFeed; to your list of existing servermod parameters).
4. Run your server.
*********************************************************************************************************************************************************************************
If you are updating from the previous version, a new configuration file generated on load of server.
*********************************************************************************************************************************************************************************
KillFeedServer.json:
----------------------------------
{
    "MessageType": "custom",
    "UseCustomLogs": 1,
    "AnnouncePvEHitsOnlyToTheHitPlayer": 1,
    "ChatColorClass": "WHITE",
    "FEEDTYPE": {
        "ShowFeed": 1,
        "LogFeed": 1,
        "Color": "WHITE",
        "Message": "KillerInfo killed VictimInfo in Melee combat."
    },
	*** trimmed so this README isn't too ridiculously large ***
}
----------------------------------

MessageType:
chat = use chat for feed output
dayz = use dayz notification system for feed output
custom = use killfeed notification system for feed output.

----------------------------------
UseCustomLogs:
1 = enable custom KillFeed.log; 0 = disable custom logging

----------------------------------
AnnouncePvEHitsOnlyToTheHitPlayer:
1 = PvEHits only sent to player; 0 = PvEHits sent to all players

NOTE: If PvE Hit Feeds are enabled

----------------------------------
ChatColorClass:
WHITE = white text chat; RED = red text chat;

NOTE: Due to DayZ Limitations in Chat, these are the only two options for chat-based messages.
WARNING: These MUST BE CAPITAL LETTERS. If using WHITE and AnnouncePvEHitsOnlyToTheHitPlayer: 1, then players will not be able to currently receive the message due to DayZ Devs having disabled the functions.

----------------------------------
INDIVIDUAL FEED SETTINGS
----------------------------------
ShowFeed:
0 = disable announcement for feed type; 1 = enable announcement for feed type;

----------------------------------
LogFeed:
0 = disable log for feed type; 1 = enable log for feed type;

----------------------------------
Color:

options:
---------
WHITE, YELLOW, GOLD, ORANGE, CORAL, RED, TURQUOISE, GREEN, LIME, FOREST, CADET, BLUE, ROYAL, BROWN, MAROON, PURPLE, INDIGO, BLACK, GRAY, SILVER

NOTE: This is only valid for use with Custom Feed UI
WARNING: These MUST BE CAPITAL LETTERS.
----------------------------------
Message:

Each feed type has it's own customizable message. There are some existing placeholders:

placeholders:
--------------
VictimInfo	= Victim's name will be changed out for this placeholder.
KillerInfo	= Killer's name will be changed out for this placeholder.
WeaponName	= Weapon's name will be changed out for this placeholder.
KillRange	= Range of kill will be changed out for this placeholder.
VehicleName	= Vehicle's name will be changed out for this placeholder.

----------------------------------