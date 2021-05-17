
void main()
{
	//INIT WEATHER BEFORE ECONOMY INIT------------------------
	Weather weather = g_Game.GetWeather();

	weather.MissionWeather(false);    // false = use weather controller from Weather.c

	weather.GetOvercast().Set( Math.RandomFloatInclusive(0.4, 0.6), 1, 0);
	weather.GetRain().Set( 0, 0, 1);
	weather.GetFog().Set( Math.RandomFloatInclusive(0.05, 0.1), 1, 0);

	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

	//DATE RESET AFTER ECONOMY INIT-------------------------
	int year, month, day, hour, minute;
	int reset_month = 9, reset_day = 20;
	GetGame().GetWorld().GetDate(year, month, day, hour, minute);

    if ((month == reset_month) && (day < reset_day))
    {
        GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
    }
    else
    {
        if ((month == reset_month + 1) && (day > reset_day))
        {
            GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
        }
        else
        {
            if ((month < reset_month) || (month > reset_month + 1))
            {
                GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
            }
        }
    }
}

class CustomMission: MissionServer
{	
	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			int rndHlt = Math.RandomInt(55,100);
			itemEnt.SetHealth("","",rndHlt);
		}
	}

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");//Creates random player
		Class.CastTo(m_player, playerEnt);
		
		GetGame().SelectPlayer(identity, m_player);
		
		return m_player;
	}
	
//More Wolves BEGIN
	void addMags(PlayerBase player, string mag_type, int count)
	{
		if (count < 1)
			return;

		EntityAI mag;

		for (int i = 0; i < count; i++) {
			mag = player.GetInventory().CreateInInventory(mag_type);
		}

		player.SetQuickBarEntityShortcut(mag, 2, true);
	}

	EntityAI assaultClass(PlayerBase player)
	{
		ItemBase light = player.GetInventory().CreateInInventory("Flashlight");
		light.GetInventory().CreateAttachment("Battery9V");
		EntityAI gun = player.GetInventory().CreateInInventory("M4A1");
		gun.GetInventory().CreateAttachment("M4_RISHndgrd");
		ItemBase gunlight = gun.GetInventory().CreateAttachment("UniversalLight");
		gunlight.GetInventory().CreateAttachment("Battery9V");
		addMags(player, "Mag_STANAG_30Rnd", 3);
		
		return gun;
	}
	
	EntityAI sniperClass(PlayerBase player)
	{
		ItemBase light = player.GetInventory().CreateInInventory("Headtorch_Grey");
		light.GetInventory().CreateAttachment("Battery9V");
		EntityAI gun = player.GetInventory().CreateInInventory("Mosin9130");
		gun.GetInventory().CreateAttachment("PUScopeOptic");
		addMags(player, "Ammo_762x54", 8);
		
		return gun;
	}

	EntityAI shotgunClass(PlayerBase player)
	{
		ItemBase light = player.GetInventory().CreateInInventory("Headtorch_Grey");
		light.GetInventory().CreateAttachment("Battery9V");
		EntityAI gun = player.GetInventory().CreateInInventory("Mp133Shotgun");
		addMags(player, "Ammo_12gaSlug", 12);

		return gun;
	}

	EntityAI smgClass(PlayerBase player)
	{
		ItemBase light = player.GetInventory().CreateInInventory("Flashlight");
		light.GetInventory().CreateAttachment("Battery9V");
		EntityAI gun = player.GetInventory().CreateInInventory("MP5K");
		gun.GetInventory().CreateAttachment("MP5_RailHndgrd");
		ItemBase gunlight = gun.GetInventory().CreateAttachment("UniversalLight");
		gunlight.GetInventory().CreateAttachment("Battery9V");
		addMags(player, "Mag_MP5_30Rnd", 3);
		
		return gun;
	}

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen) // remember to remove the original void.
	{
		player.RemoveAllItems();

		player.GetInventory().CreateInInventory("TrackSuitPants_LightBlue");
		player.GetInventory().CreateInInventory("TShirt_White");
		player.GetInventory().CreateInInventory("AviatorGlasses");
		player.GetInventory().CreateInInventory("AthleticShoes_Blue");

		player.GetInventory().CreateInInventory("BandageDressing");
		player.GetInventory().CreateInInventory("StoneKnife");
		player.GetInventory().CreateInInventory("SodaCan_Pipsi");
		player.GetInventory().CreateInInventory("Apple");

		EntityAI primary;
		EntityAI axe = player.GetInventory().CreateInInventory("NailedBaseballBat");

		switch (Math.RandomInt(0, 4)) {
			case 0: primary = assaultClass(player); break;
			case 1: primary = sniperClass(player); break;
			case 2: primary = shotgunClass(player); break;
			case 3: primary = smgClass(player); break;
		}

		player.LocalTakeEntityToHands(primary);
		player.SetQuickBarEntityShortcut(primary, 0, true);
		player.SetQuickBarEntityShortcut(axe, 1, true);
	}
//More Wolves END
};
  
Mission CreateCustomMission(string path)
{
	return new CustomMission();
}