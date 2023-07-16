class CfgPatches
{
	class RadioNotificationsMod
	{
		requiredAddons[] = {"DZ_Data", "DZ_Sounds_Effects"};
	};
};

class CfgMods
{
	class RadioNotificationsMod
	{
		type = "mod";

		class defs
		{
			// Keep these in order of execution for reference.
			class engineScriptModule
			{
				files[] = {"RadioNotifications\scripts\engine"};
			};
			class gameLibScriptModule
			{
				files[] = {"RadioNotifications\scripts\gamelib"};
			};
			class gameScriptModule
			{
				files[] = {"RadioNotifications\scripts\game"};
			};
			class worldScriptModule
			{
				files[] = {"RadioNotifications\scripts\world"};
			};
			class missionScriptModule
			{
				files[] = {"RadioNotifications\scripts\mission"};
			};
		};
	};
};

class CfgSoundShaders
{
	class RadioNotification_SoundShader
	{
		volume = 1;
		frequency = 1;
		range = 25;
		limitation = 0;
	};

	class RadioNotification_Preamble0_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\preambles\0", 1}};
	};

	class RadioNotification_Preamble1_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\preambles\1", 1}};
	};

	class RadioNotification_Preamble2_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\preambles\2", 1}};
	};

	class RadioNotification_Noise0_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\noise\0", 1}};
	};

	class RadioNotification_Noise1_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\noise\1", 1}};
	};

	class RadioNotification_Noise2_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\noise\2", 1}};
	};

	class RadioNotification_Noise3_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\noise\3", 1}};
	};
	
	class RadioNotification_Voice0_Phonetic0_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_0", 1}};
	};

	class RadioNotification_Voice0_Phonetic1_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_1", 1}};
	};

	class RadioNotification_Voice0_Phonetic2_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_2", 1}};
	};

	class RadioNotification_Voice0_Phonetic3_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_3", 1}};
	};

	class RadioNotification_Voice0_Phonetic4_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_4", 1}};
	};

	class RadioNotification_Voice0_Phonetic5_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_5", 1}};
	};

	class RadioNotification_Voice0_Phonetic6_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_6", 1}};
	};

	class RadioNotification_Voice0_Phonetic7_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_7", 1}};
	};

	class RadioNotification_Voice0_Phonetic8_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_8", 1}};
	};

	class RadioNotification_Voice0_Phonetic9_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_9", 1}};
	};

	class RadioNotification_Voice0_Phonetic10_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_10", 1}};
	};

	class RadioNotification_Voice0_Phonetic11_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_11", 1}};
	};

	class RadioNotification_Voice0_Phonetic12_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_12", 1}};
	};

	class RadioNotification_Voice0_Phonetic13_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_13", 1}};
	};

	class RadioNotification_Voice0_Phonetic14_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_14", 1}};
	};

	class RadioNotification_Voice0_Phonetic15_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_15", 1}};
	};

	class RadioNotification_Voice0_Phonetic16_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_16", 1}};
	};

	class RadioNotification_Voice0_Phonetic17_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_17", 1}};
	};

	class RadioNotification_Voice0_Phonetic18_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_18", 1}};
	};

	class RadioNotification_Voice0_Phonetic19_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_19", 1}};
	};

	class RadioNotification_Voice0_Phonetic20_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_20", 1}};
	};

	class RadioNotification_Voice0_Phonetic21_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_21", 1}};
	};

	class RadioNotification_Voice0_Phonetic22_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_22", 1}};
	};

	class RadioNotification_Voice0_Phonetic23_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_23", 1}};
	};

	class RadioNotification_Voice0_Phonetic24_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_24", 1}};
	};

	class RadioNotification_Voice0_Phonetic25_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_25", 1}};
	};

	class RadioNotification_Voice0_Phonetic26_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_26", 1}};
	};

	class RadioNotification_Voice0_Phonetic27_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_27", 1}};
	};

	class RadioNotification_Voice0_Phonetic28_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_28", 1}};
	};

	class RadioNotification_Voice0_Phonetic29_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_29", 1}};
	};

	class RadioNotification_Voice0_Phonetic30_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_30", 1}};
	};

	class RadioNotification_Voice0_Phonetic31_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_31", 1}};
	};

	class RadioNotification_Voice0_Phonetic32_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_32", 1}};
	};

	class RadioNotification_Voice0_Phonetic33_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_33", 1}};
	};

	class RadioNotification_Voice0_Phonetic34_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_34", 1}};
	};

	class RadioNotification_Voice0_Phonetic35_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_35", 1}};
	};

	class RadioNotification_Voice0_Phonetic36_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_36", 1}};
	};

	class RadioNotification_Voice0_Phonetic37_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_37", 1}};
	};

	class RadioNotification_Voice0_Phonetic38_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_38", 1}};
	};

	class RadioNotification_Voice0_Phonetic39_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_39", 1}};
	};

	class RadioNotification_Voice0_Phonetic40_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_40", 1}};
	};

	class RadioNotification_Voice0_Phonetic41_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_41", 1}};
	};

	class RadioNotification_Voice0_Phonetic42_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_42", 1}};
	};

	class RadioNotification_Voice0_Phonetic43_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_43", 1}};
	};

	class RadioNotification_Voice0_Phonetic44_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\0_44", 1}};
	};

	class RadioNotification_Voice1_Phonetic0_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_0", 1}};
	};

	class RadioNotification_Voice1_Phonetic1_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_1", 1}};
	};

	class RadioNotification_Voice1_Phonetic2_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_2", 1}};
	};

	class RadioNotification_Voice1_Phonetic3_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_3", 1}};
	};

	class RadioNotification_Voice1_Phonetic4_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_4", 1}};
	};

	class RadioNotification_Voice1_Phonetic5_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_5", 1}};
	};

	class RadioNotification_Voice1_Phonetic6_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_6", 1}};
	};

	class RadioNotification_Voice1_Phonetic7_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_7", 1}};
	};

	class RadioNotification_Voice1_Phonetic8_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_8", 1}};
	};

	class RadioNotification_Voice1_Phonetic9_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_9", 1}};
	};

	class RadioNotification_Voice1_Phonetic10_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_10", 1}};
	};

	class RadioNotification_Voice1_Phonetic11_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_11", 1}};
	};

	class RadioNotification_Voice1_Phonetic12_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_12", 1}};
	};

	class RadioNotification_Voice1_Phonetic13_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_13", 1}};
	};

	class RadioNotification_Voice1_Phonetic14_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_14", 1}};
	};

	class RadioNotification_Voice1_Phonetic15_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_15", 1}};
	};

	class RadioNotification_Voice1_Phonetic16_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_16", 1}};
	};

	class RadioNotification_Voice1_Phonetic17_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_17", 1}};
	};

	class RadioNotification_Voice1_Phonetic18_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_18", 1}};
	};

	class RadioNotification_Voice1_Phonetic19_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_19", 1}};
	};

	class RadioNotification_Voice1_Phonetic20_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_20", 1}};
	};

	class RadioNotification_Voice1_Phonetic21_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_21", 1}};
	};

	class RadioNotification_Voice1_Phonetic22_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_22", 1}};
	};

	class RadioNotification_Voice1_Phonetic23_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_23", 1}};
	};

	class RadioNotification_Voice1_Phonetic24_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_24", 1}};
	};

	class RadioNotification_Voice1_Phonetic25_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_25", 1}};
	};

	class RadioNotification_Voice1_Phonetic26_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_26", 1}};
	};

	class RadioNotification_Voice1_Phonetic27_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_27", 1}};
	};

	class RadioNotification_Voice1_Phonetic28_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_28", 1}};
	};

	class RadioNotification_Voice1_Phonetic29_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_29", 1}};
	};

	class RadioNotification_Voice1_Phonetic30_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_30", 1}};
	};

	class RadioNotification_Voice1_Phonetic31_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_31", 1}};
	};

	class RadioNotification_Voice1_Phonetic32_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_32", 1}};
	};

	class RadioNotification_Voice1_Phonetic33_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_33", 1}};
	};

	class RadioNotification_Voice1_Phonetic34_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_34", 1}};
	};

	class RadioNotification_Voice1_Phonetic35_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_35", 1}};
	};

	class RadioNotification_Voice1_Phonetic36_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_36", 1}};
	};

	class RadioNotification_Voice1_Phonetic37_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_37", 1}};
	};

	class RadioNotification_Voice1_Phonetic38_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_38", 1}};
	};

	class RadioNotification_Voice1_Phonetic39_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_39", 1}};
	};

	class RadioNotification_Voice1_Phonetic40_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_40", 1}};
	};

	class RadioNotification_Voice1_Phonetic41_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_41", 1}};
	};

	class RadioNotification_Voice1_Phonetic42_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_42", 1}};
	};

	class RadioNotification_Voice1_Phonetic43_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_43", 1}};
	};

	class RadioNotification_Voice1_Phonetic44_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\1_44", 1}};
	};

	class RadioNotification_Voice2_Phonetic0_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_0", 1}};
	};

	class RadioNotification_Voice2_Phonetic1_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_1", 1}};
	};

	class RadioNotification_Voice2_Phonetic2_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_2", 1}};
	};

	class RadioNotification_Voice2_Phonetic3_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_3", 1}};
	};

	class RadioNotification_Voice2_Phonetic4_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_4", 1}};
	};

	class RadioNotification_Voice2_Phonetic5_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_5", 1}};
	};

	class RadioNotification_Voice2_Phonetic6_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_6", 1}};
	};

	class RadioNotification_Voice2_Phonetic7_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_7", 1}};
	};

	class RadioNotification_Voice2_Phonetic8_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_8", 1}};
	};

	class RadioNotification_Voice2_Phonetic9_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_9", 1}};
	};

	class RadioNotification_Voice2_Phonetic10_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_10", 1}};
	};

	class RadioNotification_Voice2_Phonetic11_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_11", 1}};
	};

	class RadioNotification_Voice2_Phonetic12_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_12", 1}};
	};

	class RadioNotification_Voice2_Phonetic13_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_13", 1}};
	};

	class RadioNotification_Voice2_Phonetic14_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_14", 1}};
	};

	class RadioNotification_Voice2_Phonetic15_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_15", 1}};
	};

	class RadioNotification_Voice2_Phonetic16_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_16", 1}};
	};

	class RadioNotification_Voice2_Phonetic17_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_17", 1}};
	};

	class RadioNotification_Voice2_Phonetic18_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_18", 1}};
	};

	class RadioNotification_Voice2_Phonetic19_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_19", 1}};
	};

	class RadioNotification_Voice2_Phonetic20_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_20", 1}};
	};

	class RadioNotification_Voice2_Phonetic21_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_21", 1}};
	};

	class RadioNotification_Voice2_Phonetic22_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_22", 1}};
	};

	class RadioNotification_Voice2_Phonetic23_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_23", 1}};
	};

	class RadioNotification_Voice2_Phonetic24_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_24", 1}};
	};

	class RadioNotification_Voice2_Phonetic25_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_25", 1}};
	};

	class RadioNotification_Voice2_Phonetic26_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_26", 1}};
	};

	class RadioNotification_Voice2_Phonetic27_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_27", 1}};
	};

	class RadioNotification_Voice2_Phonetic28_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_28", 1}};
	};

	class RadioNotification_Voice2_Phonetic29_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_29", 1}};
	};

	class RadioNotification_Voice2_Phonetic30_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_30", 1}};
	};

	class RadioNotification_Voice2_Phonetic31_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_31", 1}};
	};

	class RadioNotification_Voice2_Phonetic32_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_32", 1}};
	};

	class RadioNotification_Voice2_Phonetic33_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_33", 1}};
	};

	class RadioNotification_Voice2_Phonetic34_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_34", 1}};
	};

	class RadioNotification_Voice2_Phonetic35_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_35", 1}};
	};

	class RadioNotification_Voice2_Phonetic36_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_36", 1}};
	};

	class RadioNotification_Voice2_Phonetic37_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_37", 1}};
	};

	class RadioNotification_Voice2_Phonetic38_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_38", 1}};
	};

	class RadioNotification_Voice2_Phonetic39_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_39", 1}};
	};

	class RadioNotification_Voice2_Phonetic40_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_40", 1}};
	};

	class RadioNotification_Voice2_Phonetic41_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_41", 1}};
	};

	class RadioNotification_Voice2_Phonetic42_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_42", 1}};
	};

	class RadioNotification_Voice2_Phonetic43_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_43", 1}};
	};

	class RadioNotification_Voice2_Phonetic44_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\2_44", 1}};
	};

	class RadioNotification_Voice3_Phonetic0_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_0", 1}};
	};

	class RadioNotification_Voice3_Phonetic1_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_1", 1}};
	};

	class RadioNotification_Voice3_Phonetic2_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_2", 1}};
	};

	class RadioNotification_Voice3_Phonetic3_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_3", 1}};
	};

	class RadioNotification_Voice3_Phonetic4_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_4", 1}};
	};

	class RadioNotification_Voice3_Phonetic5_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_5", 1}};
	};

	class RadioNotification_Voice3_Phonetic6_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_6", 1}};
	};

	class RadioNotification_Voice3_Phonetic7_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_7", 1}};
	};

	class RadioNotification_Voice3_Phonetic8_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_8", 1}};
	};

	class RadioNotification_Voice3_Phonetic9_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_9", 1}};
	};

	class RadioNotification_Voice3_Phonetic10_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_10", 1}};
	};

	class RadioNotification_Voice3_Phonetic11_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_11", 1}};
	};

	class RadioNotification_Voice3_Phonetic12_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_12", 1}};
	};

	class RadioNotification_Voice3_Phonetic13_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_13", 1}};
	};

	class RadioNotification_Voice3_Phonetic14_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_14", 1}};
	};

	class RadioNotification_Voice3_Phonetic15_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_15", 1}};
	};

	class RadioNotification_Voice3_Phonetic16_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_16", 1}};
	};

	class RadioNotification_Voice3_Phonetic17_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_17", 1}};
	};

	class RadioNotification_Voice3_Phonetic18_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_18", 1}};
	};

	class RadioNotification_Voice3_Phonetic19_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_19", 1}};
	};

	class RadioNotification_Voice3_Phonetic20_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_20", 1}};
	};

	class RadioNotification_Voice3_Phonetic21_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_21", 1}};
	};

	class RadioNotification_Voice3_Phonetic22_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_22", 1}};
	};

	class RadioNotification_Voice3_Phonetic23_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_23", 1}};
	};

	class RadioNotification_Voice3_Phonetic24_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_24", 1}};
	};

	class RadioNotification_Voice3_Phonetic25_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_25", 1}};
	};

	class RadioNotification_Voice3_Phonetic26_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_26", 1}};
	};

	class RadioNotification_Voice3_Phonetic27_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_27", 1}};
	};

	class RadioNotification_Voice3_Phonetic28_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_28", 1}};
	};

	class RadioNotification_Voice3_Phonetic29_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_29", 1}};
	};

	class RadioNotification_Voice3_Phonetic30_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_30", 1}};
	};

	class RadioNotification_Voice3_Phonetic31_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_31", 1}};
	};

	class RadioNotification_Voice3_Phonetic32_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_32", 1}};
	};

	class RadioNotification_Voice3_Phonetic33_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_33", 1}};
	};

	class RadioNotification_Voice3_Phonetic34_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_34", 1}};
	};

	class RadioNotification_Voice3_Phonetic35_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_35", 1}};
	};

	class RadioNotification_Voice3_Phonetic36_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_36", 1}};
	};

	class RadioNotification_Voice3_Phonetic37_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_37", 1}};
	};

	class RadioNotification_Voice3_Phonetic38_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_38", 1}};
	};

	class RadioNotification_Voice3_Phonetic39_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_39", 1}};
	};

	class RadioNotification_Voice3_Phonetic40_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_40", 1}};
	};

	class RadioNotification_Voice3_Phonetic41_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_41", 1}};
	};

	class RadioNotification_Voice3_Phonetic42_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_42", 1}};
	};

	class RadioNotification_Voice3_Phonetic43_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_43", 1}};
	};

	class RadioNotification_Voice3_Phonetic44_SoundShader : RadioNotification_SoundShader
	{
		samples[] = {{"RadioNotifications\sounds\phonetics\3_44", 1}};
	};
};

class CfgSoundSets
{
	class RadioNotification_SoundSet
	{
		sound3DProcessingType = "character3DProcessingType";
		volumeCurve = "characterAttenuationCurve";
		spatial = 1;
		doppler = 0;
		loop = 0;
		distanceFilter = "defaultDistanceFilter";
	};

	class RadioNotification_Preamble0 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Preamble0_SoundShader"};
	};

	class RadioNotification_Preamble1 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Preamble1_SoundShader"};
	};

	class RadioNotification_Preamble2 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Preamble2_SoundShader"};
	};

	class RadioNotification_Noise0 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Noise0_SoundShader"};
		loop = 1;
	};

	class RadioNotification_Noise1 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Noise1_SoundShader"};
		loop = 1;
	};

	class RadioNotification_Noise2 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Noise2_SoundShader"};
		loop = 1;
	};

	class RadioNotification_Noise3 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Noise3_SoundShader"};
		loop = 1;
	};

	class RadioNotification_Voice0_Phonetic0 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic0_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic1 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic1_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic2 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic2_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic3 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic3_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic4 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic4_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic5 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic5_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic6 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic6_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic7 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic7_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic8 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic8_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic9 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic9_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic10 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic10_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic11 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic11_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic12 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic12_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic13 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic13_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic14 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic14_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic15 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic15_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic16 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic16_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic17 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic17_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic18 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic18_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic19 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic19_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic20 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic20_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic21 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic21_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic22 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic22_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic23 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic23_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic24 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic24_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic25 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic25_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic26 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic26_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic27 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic27_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic28 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic28_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic29 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic29_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic30 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic30_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic31 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic31_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic32 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic32_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic33 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic33_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic34 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic34_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic35 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic35_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic36 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic36_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic37 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic37_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic38 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic38_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic39 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic39_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic40 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic40_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic41 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic41_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic42 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic42_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic43 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic43_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic44 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice0_Phonetic44_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic0 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic0_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic1 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic1_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic2 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic2_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic3 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic3_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic4 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic4_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic5 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic5_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic6 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic6_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic7 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic7_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic8 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic8_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic9 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic9_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic10 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic10_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic11 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic11_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic12 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic12_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic13 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic13_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic14 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic14_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic15 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic15_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic16 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic16_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic17 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic17_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic18 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic18_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic19 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic19_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic20 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic20_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic21 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic21_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic22 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic22_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic23 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic23_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic24 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic24_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic25 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic25_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic26 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic26_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic27 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic27_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic28 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic28_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic29 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic29_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic30 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic30_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic31 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic31_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic32 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic32_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic33 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic33_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic34 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic34_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic35 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic35_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic36 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic36_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic37 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic37_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic38 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic38_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic39 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic39_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic40 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic40_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic41 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic41_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic42 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic42_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic43 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic43_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic44 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice1_Phonetic44_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic0 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic0_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic1 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic1_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic2 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic2_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic3 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic3_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic4 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic4_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic5 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic5_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic6 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic6_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic7 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic7_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic8 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic8_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic9 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic9_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic10 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic10_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic11 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic11_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic12 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic12_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic13 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic13_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic14 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic14_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic15 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic15_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic16 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic16_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic17 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic17_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic18 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic18_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic19 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic19_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic20 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic20_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic21 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic21_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic22 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic22_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic23 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic23_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic24 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic24_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic25 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic25_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic26 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic26_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic27 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic27_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic28 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic28_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic29 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic29_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic30 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic30_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic31 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic31_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic32 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic32_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic33 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic33_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic34 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic34_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic35 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic35_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic36 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic36_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic37 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic37_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic38 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic38_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic39 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic39_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic40 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic40_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic41 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic41_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic42 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic42_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic43 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic43_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic44 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice2_Phonetic44_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic0 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic0_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic1 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic1_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic2 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic2_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic3 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic3_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic4 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic4_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic5 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic5_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic6 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic6_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic7 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic7_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic8 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic8_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic9 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic9_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic10 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic10_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic11 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic11_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic12 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic12_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic13 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic13_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic14 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic14_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic15 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic15_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic16 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic16_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic17 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic17_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic18 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic18_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic19 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic19_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic20 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic20_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic21 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic21_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic22 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic22_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic23 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic23_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic24 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic24_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic25 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic25_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic26 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic26_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic27 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic27_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic28 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic28_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic29 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic29_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic30 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic30_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic31 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic31_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic32 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic32_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic33 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic33_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic34 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic34_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic35 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic35_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic36 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic36_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic37 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic37_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic38 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic38_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic39 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic39_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic40 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic40_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic41 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic41_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic42 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic42_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic43 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic43_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic44 : RadioNotification_SoundSet
	{
		soundShaders[] = {"RadioNotification_Voice3_Phonetic44_SoundShader"};
	};
};