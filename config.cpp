class CfgPatches {
	class RadioNotificationsMod {
		requiredAddons[] = {"DZ_Data", "DZ_Sounds_Effects"};
	};
};

class CfgMods {
	class RadioNotificationsMod {
		type = "mod";

		class defs {
			// Keep these in order of execution for reference.
			class engineScriptModule {
				files[] = {"RadioNotifications\scripts\engine"};
			};
			class gameLibScriptModule {
				files[] = {"RadioNotifications\scripts\gamelib"};
			};
			class gameScriptModule {
				files[] = {"RadioNotifications\scripts\game"};
			};
			class worldScriptModule {
				files[] = {"RadioNotifications\scripts\world"};
			};
			class missionScriptModule {
				files[] = {"RadioNotifications\scripts\mission"};
			};
		};
	};
};

class CfgSoundCurves {
	class alarmAttenuationCurve {
		points[] = {
			{0, 0.8},
			{25, 0.3},
			{150, 0.2},
			{500, 0.1},
			{750, 0.05},
			{1000, 0}};
	};
};

class CfgSoundShaders {
	class RadioNotification_SoundShader {
		volume = 1;
		frequency = 1;
		range = 25;
		limitation = 0;
	};

	class RadioNotification_Alarm_SoundShader : RadioNotification_SoundShader {
		volume = 0.8;
		range = 2000;
	};

	class RadioNotification_Alarm0_SoundShader : RadioNotification_Alarm_SoundShader {
		samples[] = {{"RadioNotifications\sounds\alarms\0", 1}};
	};

	class RadioNotification_Preamble0_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\preambles\0", 1}};
	};

	class RadioNotification_Preamble1_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\preambles\1", 1}};
	};

	class RadioNotification_Preamble2_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\preambles\2", 1}};
	};

	class RadioNotification_Noise0_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\noise\0", 1}};
	};

	class RadioNotification_Noise1_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\noise\1", 1}};
	};

	class RadioNotification_Noise2_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\noise\2", 1}};
	};

	class RadioNotification_Noise3_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\noise\3", 1}};
	};

	class RadioNotification_Voice0_Phonetic0_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_0", 1}};
	};

	class RadioNotification_Voice0_Phonetic1_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_1", 1}};
	};

	class RadioNotification_Voice0_Phonetic2_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_2", 1}};
	};

	class RadioNotification_Voice0_Phonetic3_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_3", 1}};
	};

	class RadioNotification_Voice0_Phonetic4_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_4", 1}};
	};

	class RadioNotification_Voice0_Phonetic5_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_5", 1}};
	};

	class RadioNotification_Voice0_Phonetic6_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_6", 1}};
	};

	class RadioNotification_Voice0_Phonetic7_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_7", 1}};
	};

	class RadioNotification_Voice0_Phonetic8_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_8", 1}};
	};

	class RadioNotification_Voice0_Phonetic9_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_9", 1}};
	};

	class RadioNotification_Voice0_Phonetic10_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_10", 1}};
	};

	class RadioNotification_Voice0_Phonetic11_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_11", 1}};
	};

	class RadioNotification_Voice0_Phonetic12_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_12", 1}};
	};

	class RadioNotification_Voice0_Phonetic13_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_13", 1}};
	};

	class RadioNotification_Voice0_Phonetic14_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_14", 1}};
	};

	class RadioNotification_Voice0_Phonetic15_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_15", 1}};
	};

	class RadioNotification_Voice0_Phonetic16_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_16", 1}};
	};

	class RadioNotification_Voice0_Phonetic17_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_17", 1}};
	};

	class RadioNotification_Voice0_Phonetic18_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_18", 1}};
	};

	class RadioNotification_Voice0_Phonetic19_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_19", 1}};
	};

	class RadioNotification_Voice0_Phonetic20_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_20", 1}};
	};

	class RadioNotification_Voice0_Phonetic21_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_21", 1}};
	};

	class RadioNotification_Voice0_Phonetic22_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_22", 1}};
	};

	class RadioNotification_Voice0_Phonetic23_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_23", 1}};
	};

	class RadioNotification_Voice0_Phonetic24_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_24", 1}};
	};

	class RadioNotification_Voice0_Phonetic25_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_25", 1}};
	};

	class RadioNotification_Voice0_Phonetic26_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_26", 1}};
	};

	class RadioNotification_Voice0_Phonetic27_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_27", 1}};
	};

	class RadioNotification_Voice0_Phonetic28_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_28", 1}};
	};

	class RadioNotification_Voice0_Phonetic29_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_29", 1}};
	};

	class RadioNotification_Voice0_Phonetic30_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_30", 1}};
	};

	class RadioNotification_Voice0_Phonetic31_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_31", 1}};
	};

	class RadioNotification_Voice0_Phonetic32_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_32", 1}};
	};

	class RadioNotification_Voice0_Phonetic33_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_33", 1}};
	};

	class RadioNotification_Voice0_Phonetic34_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_34", 1}};
	};

	class RadioNotification_Voice0_Phonetic35_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_35", 1}};
	};

	class RadioNotification_Voice0_Phonetic36_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_36", 1}};
	};

	class RadioNotification_Voice0_Phonetic37_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_37", 1}};
	};

	class RadioNotification_Voice0_Phonetic38_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_38", 1}};
	};

	class RadioNotification_Voice0_Phonetic39_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_39", 1}};
	};

	class RadioNotification_Voice0_Phonetic40_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_40", 1}};
	};

	class RadioNotification_Voice0_Phonetic41_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_41", 1}};
	};

	class RadioNotification_Voice0_Phonetic42_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_42", 1}};
	};

	class RadioNotification_Voice0_Phonetic43_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_43", 1}};
	};

	class RadioNotification_Voice0_Phonetic44_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_44", 1}};
	};

	class RadioNotification_Voice0_Phonetic45_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_45", 1}};
	};

	class RadioNotification_Voice0_Phonetic46_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_46", 1}};
	};

	class RadioNotification_Voice0_Phonetic47_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_47", 1}};
	};

	class RadioNotification_Voice0_Phonetic48_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_48", 1}};
	};

	class RadioNotification_Voice0_Phonetic49_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_49", 1}};
	};

	class RadioNotification_Voice0_Phonetic50_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_50", 1}};
	};

	class RadioNotification_Voice0_Phonetic51_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_51", 1}};
	};

	class RadioNotification_Voice0_Phonetic52_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_52", 1}};
	};

	class RadioNotification_Voice0_Phonetic53_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\0_53", 1}};
	};

	class RadioNotification_Voice1_Phonetic0_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_0", 1}};
	};

	class RadioNotification_Voice1_Phonetic1_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_1", 1}};
	};

	class RadioNotification_Voice1_Phonetic2_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_2", 1}};
	};

	class RadioNotification_Voice1_Phonetic3_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_3", 1}};
	};

	class RadioNotification_Voice1_Phonetic4_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_4", 1}};
	};

	class RadioNotification_Voice1_Phonetic5_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_5", 1}};
	};

	class RadioNotification_Voice1_Phonetic6_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_6", 1}};
	};

	class RadioNotification_Voice1_Phonetic7_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_7", 1}};
	};

	class RadioNotification_Voice1_Phonetic8_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_8", 1}};
	};

	class RadioNotification_Voice1_Phonetic9_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_9", 1}};
	};

	class RadioNotification_Voice1_Phonetic10_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_10", 1}};
	};

	class RadioNotification_Voice1_Phonetic11_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_11", 1}};
	};

	class RadioNotification_Voice1_Phonetic12_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_12", 1}};
	};

	class RadioNotification_Voice1_Phonetic13_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_13", 1}};
	};

	class RadioNotification_Voice1_Phonetic14_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_14", 1}};
	};

	class RadioNotification_Voice1_Phonetic15_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_15", 1}};
	};

	class RadioNotification_Voice1_Phonetic16_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_16", 1}};
	};

	class RadioNotification_Voice1_Phonetic17_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_17", 1}};
	};

	class RadioNotification_Voice1_Phonetic18_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_18", 1}};
	};

	class RadioNotification_Voice1_Phonetic19_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_19", 1}};
	};

	class RadioNotification_Voice1_Phonetic20_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_20", 1}};
	};

	class RadioNotification_Voice1_Phonetic21_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_21", 1}};
	};

	class RadioNotification_Voice1_Phonetic22_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_22", 1}};
	};

	class RadioNotification_Voice1_Phonetic23_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_23", 1}};
	};

	class RadioNotification_Voice1_Phonetic24_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_24", 1}};
	};

	class RadioNotification_Voice1_Phonetic25_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_25", 1}};
	};

	class RadioNotification_Voice1_Phonetic26_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_26", 1}};
	};

	class RadioNotification_Voice1_Phonetic27_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_27", 1}};
	};

	class RadioNotification_Voice1_Phonetic28_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_28", 1}};
	};

	class RadioNotification_Voice1_Phonetic29_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_29", 1}};
	};

	class RadioNotification_Voice1_Phonetic30_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_30", 1}};
	};

	class RadioNotification_Voice1_Phonetic31_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_31", 1}};
	};

	class RadioNotification_Voice1_Phonetic32_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_32", 1}};
	};

	class RadioNotification_Voice1_Phonetic33_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_33", 1}};
	};

	class RadioNotification_Voice1_Phonetic34_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_34", 1}};
	};

	class RadioNotification_Voice1_Phonetic35_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_35", 1}};
	};

	class RadioNotification_Voice1_Phonetic36_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_36", 1}};
	};

	class RadioNotification_Voice1_Phonetic37_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_37", 1}};
	};

	class RadioNotification_Voice1_Phonetic38_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_38", 1}};
	};

	class RadioNotification_Voice1_Phonetic39_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_39", 1}};
	};

	class RadioNotification_Voice1_Phonetic40_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_40", 1}};
	};

	class RadioNotification_Voice1_Phonetic41_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_41", 1}};
	};

	class RadioNotification_Voice1_Phonetic42_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_42", 1}};
	};

	class RadioNotification_Voice1_Phonetic43_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_43", 1}};
	};

	class RadioNotification_Voice1_Phonetic44_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_44", 1}};
	};

	class RadioNotification_Voice1_Phonetic45_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_45", 1}};
	};

	class RadioNotification_Voice1_Phonetic46_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_46", 1}};
	};

	class RadioNotification_Voice1_Phonetic47_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_47", 1}};
	};

	class RadioNotification_Voice1_Phonetic48_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_48", 1}};
	};

	class RadioNotification_Voice1_Phonetic49_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_49", 1}};
	};

	class RadioNotification_Voice1_Phonetic50_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_50", 1}};
	};

	class RadioNotification_Voice1_Phonetic51_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_51", 1}};
	};

	class RadioNotification_Voice1_Phonetic52_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_52", 1}};
	};

	class RadioNotification_Voice1_Phonetic53_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\1_53", 1}};
	};

	class RadioNotification_Voice2_Phonetic0_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_0", 1}};
	};

	class RadioNotification_Voice2_Phonetic1_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_1", 1}};
	};

	class RadioNotification_Voice2_Phonetic2_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_2", 1}};
	};

	class RadioNotification_Voice2_Phonetic3_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_3", 1}};
	};

	class RadioNotification_Voice2_Phonetic4_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_4", 1}};
	};

	class RadioNotification_Voice2_Phonetic5_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_5", 1}};
	};

	class RadioNotification_Voice2_Phonetic6_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_6", 1}};
	};

	class RadioNotification_Voice2_Phonetic7_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_7", 1}};
	};

	class RadioNotification_Voice2_Phonetic8_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_8", 1}};
	};

	class RadioNotification_Voice2_Phonetic9_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_9", 1}};
	};

	class RadioNotification_Voice2_Phonetic10_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_10", 1}};
	};

	class RadioNotification_Voice2_Phonetic11_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_11", 1}};
	};

	class RadioNotification_Voice2_Phonetic12_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_12", 1}};
	};

	class RadioNotification_Voice2_Phonetic13_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_13", 1}};
	};

	class RadioNotification_Voice2_Phonetic14_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_14", 1}};
	};

	class RadioNotification_Voice2_Phonetic15_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_15", 1}};
	};

	class RadioNotification_Voice2_Phonetic16_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_16", 1}};
	};

	class RadioNotification_Voice2_Phonetic17_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_17", 1}};
	};

	class RadioNotification_Voice2_Phonetic18_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_18", 1}};
	};

	class RadioNotification_Voice2_Phonetic19_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_19", 1}};
	};

	class RadioNotification_Voice2_Phonetic20_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_20", 1}};
	};

	class RadioNotification_Voice2_Phonetic21_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_21", 1}};
	};

	class RadioNotification_Voice2_Phonetic22_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_22", 1}};
	};

	class RadioNotification_Voice2_Phonetic23_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_23", 1}};
	};

	class RadioNotification_Voice2_Phonetic24_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_24", 1}};
	};

	class RadioNotification_Voice2_Phonetic25_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_25", 1}};
	};

	class RadioNotification_Voice2_Phonetic26_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_26", 1}};
	};

	class RadioNotification_Voice2_Phonetic27_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_27", 1}};
	};

	class RadioNotification_Voice2_Phonetic28_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_28", 1}};
	};

	class RadioNotification_Voice2_Phonetic29_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_29", 1}};
	};

	class RadioNotification_Voice2_Phonetic30_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_30", 1}};
	};

	class RadioNotification_Voice2_Phonetic31_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_31", 1}};
	};

	class RadioNotification_Voice2_Phonetic32_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_32", 1}};
	};

	class RadioNotification_Voice2_Phonetic33_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_33", 1}};
	};

	class RadioNotification_Voice2_Phonetic34_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_34", 1}};
	};

	class RadioNotification_Voice2_Phonetic35_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_35", 1}};
	};

	class RadioNotification_Voice2_Phonetic36_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_36", 1}};
	};

	class RadioNotification_Voice2_Phonetic37_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_37", 1}};
	};

	class RadioNotification_Voice2_Phonetic38_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_38", 1}};
	};

	class RadioNotification_Voice2_Phonetic39_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_39", 1}};
	};

	class RadioNotification_Voice2_Phonetic40_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_40", 1}};
	};

	class RadioNotification_Voice2_Phonetic41_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_41", 1}};
	};

	class RadioNotification_Voice2_Phonetic42_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_42", 1}};
	};

	class RadioNotification_Voice2_Phonetic43_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_43", 1}};
	};

	class RadioNotification_Voice2_Phonetic44_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_44", 1}};
	};

	class RadioNotification_Voice2_Phonetic45_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_45", 1}};
	};

	class RadioNotification_Voice2_Phonetic46_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_46", 1}};
	};

	class RadioNotification_Voice2_Phonetic47_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_47", 1}};
	};

	class RadioNotification_Voice2_Phonetic48_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_48", 1}};
	};

	class RadioNotification_Voice2_Phonetic49_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_49", 1}};
	};

	class RadioNotification_Voice2_Phonetic50_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_50", 1}};
	};

	class RadioNotification_Voice2_Phonetic51_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_51", 1}};
	};

	class RadioNotification_Voice2_Phonetic52_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_52", 1}};
	};

	class RadioNotification_Voice2_Phonetic53_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\2_53", 1}};
	};

	class RadioNotification_Voice3_Phonetic0_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_0", 1}};
	};

	class RadioNotification_Voice3_Phonetic1_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_1", 1}};
	};

	class RadioNotification_Voice3_Phonetic2_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_2", 1}};
	};

	class RadioNotification_Voice3_Phonetic3_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_3", 1}};
	};

	class RadioNotification_Voice3_Phonetic4_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_4", 1}};
	};

	class RadioNotification_Voice3_Phonetic5_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_5", 1}};
	};

	class RadioNotification_Voice3_Phonetic6_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_6", 1}};
	};

	class RadioNotification_Voice3_Phonetic7_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_7", 1}};
	};

	class RadioNotification_Voice3_Phonetic8_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_8", 1}};
	};

	class RadioNotification_Voice3_Phonetic9_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_9", 1}};
	};

	class RadioNotification_Voice3_Phonetic10_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_10", 1}};
	};

	class RadioNotification_Voice3_Phonetic11_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_11", 1}};
	};

	class RadioNotification_Voice3_Phonetic12_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_12", 1}};
	};

	class RadioNotification_Voice3_Phonetic13_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_13", 1}};
	};

	class RadioNotification_Voice3_Phonetic14_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_14", 1}};
	};

	class RadioNotification_Voice3_Phonetic15_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_15", 1}};
	};

	class RadioNotification_Voice3_Phonetic16_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_16", 1}};
	};

	class RadioNotification_Voice3_Phonetic17_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_17", 1}};
	};

	class RadioNotification_Voice3_Phonetic18_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_18", 1}};
	};

	class RadioNotification_Voice3_Phonetic19_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_19", 1}};
	};

	class RadioNotification_Voice3_Phonetic20_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_20", 1}};
	};

	class RadioNotification_Voice3_Phonetic21_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_21", 1}};
	};

	class RadioNotification_Voice3_Phonetic22_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_22", 1}};
	};

	class RadioNotification_Voice3_Phonetic23_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_23", 1}};
	};

	class RadioNotification_Voice3_Phonetic24_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_24", 1}};
	};

	class RadioNotification_Voice3_Phonetic25_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_25", 1}};
	};

	class RadioNotification_Voice3_Phonetic26_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_26", 1}};
	};

	class RadioNotification_Voice3_Phonetic27_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_27", 1}};
	};

	class RadioNotification_Voice3_Phonetic28_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_28", 1}};
	};

	class RadioNotification_Voice3_Phonetic29_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_29", 1}};
	};

	class RadioNotification_Voice3_Phonetic30_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_30", 1}};
	};

	class RadioNotification_Voice3_Phonetic31_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_31", 1}};
	};

	class RadioNotification_Voice3_Phonetic32_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_32", 1}};
	};

	class RadioNotification_Voice3_Phonetic33_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_33", 1}};
	};

	class RadioNotification_Voice3_Phonetic34_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_34", 1}};
	};

	class RadioNotification_Voice3_Phonetic35_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_35", 1}};
	};

	class RadioNotification_Voice3_Phonetic36_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_36", 1}};
	};

	class RadioNotification_Voice3_Phonetic37_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_37", 1}};
	};

	class RadioNotification_Voice3_Phonetic38_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_38", 1}};
	};

	class RadioNotification_Voice3_Phonetic39_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_39", 1}};
	};

	class RadioNotification_Voice3_Phonetic40_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_40", 1}};
	};

	class RadioNotification_Voice3_Phonetic41_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_41", 1}};
	};

	class RadioNotification_Voice3_Phonetic42_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_42", 1}};
	};

	class RadioNotification_Voice3_Phonetic43_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_43", 1}};
	};

	class RadioNotification_Voice3_Phonetic44_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_44", 1}};
	};

	class RadioNotification_Voice3_Phonetic45_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_45", 1}};
	};

	class RadioNotification_Voice3_Phonetic46_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_46", 1}};
	};

	class RadioNotification_Voice3_Phonetic47_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_47", 1}};
	};

	class RadioNotification_Voice3_Phonetic48_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_48", 1}};
	};

	class RadioNotification_Voice3_Phonetic49_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_49", 1}};
	};

	class RadioNotification_Voice3_Phonetic50_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_50", 1}};
	};

	class RadioNotification_Voice3_Phonetic51_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_51", 1}};
	};

	class RadioNotification_Voice3_Phonetic52_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_52", 1}};
	};

	class RadioNotification_Voice3_Phonetic53_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\3_53", 1}};
	};

	class RadioNotification_Voice4_Phonetic0_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_0", 1}};
	};

	class RadioNotification_Voice4_Phonetic1_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_1", 1}};
	};

	class RadioNotification_Voice4_Phonetic2_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_2", 1}};
	};

	class RadioNotification_Voice4_Phonetic3_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_3", 1}};
	};

	class RadioNotification_Voice4_Phonetic4_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_4", 1}};
	};

	class RadioNotification_Voice4_Phonetic5_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_5", 1}};
	};

	class RadioNotification_Voice4_Phonetic6_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_6", 1}};
	};

	class RadioNotification_Voice4_Phonetic7_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_7", 1}};
	};

	class RadioNotification_Voice4_Phonetic8_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_8", 1}};
	};

	class RadioNotification_Voice4_Phonetic9_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_9", 1}};
	};

	class RadioNotification_Voice4_Phonetic10_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_10", 1}};
	};

	class RadioNotification_Voice4_Phonetic11_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_11", 1}};
	};

	class RadioNotification_Voice4_Phonetic12_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_12", 1}};
	};

	class RadioNotification_Voice4_Phonetic13_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_13", 1}};
	};

	class RadioNotification_Voice4_Phonetic14_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_14", 1}};
	};

	class RadioNotification_Voice4_Phonetic15_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_15", 1}};
	};

	class RadioNotification_Voice4_Phonetic16_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_16", 1}};
	};

	class RadioNotification_Voice4_Phonetic17_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_17", 1}};
	};

	class RadioNotification_Voice4_Phonetic18_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_18", 1}};
	};

	class RadioNotification_Voice4_Phonetic19_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_19", 1}};
	};

	class RadioNotification_Voice4_Phonetic20_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_20", 1}};
	};

	class RadioNotification_Voice4_Phonetic21_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_21", 1}};
	};

	class RadioNotification_Voice4_Phonetic22_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_22", 1}};
	};

	class RadioNotification_Voice4_Phonetic23_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_23", 1}};
	};

	class RadioNotification_Voice4_Phonetic24_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_24", 1}};
	};

	class RadioNotification_Voice4_Phonetic25_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_25", 1}};
	};

	class RadioNotification_Voice4_Phonetic26_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_26", 1}};
	};

	class RadioNotification_Voice4_Phonetic27_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_27", 1}};
	};

	class RadioNotification_Voice4_Phonetic28_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_28", 1}};
	};

	class RadioNotification_Voice4_Phonetic29_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_29", 1}};
	};

	class RadioNotification_Voice4_Phonetic30_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_30", 1}};
	};

	class RadioNotification_Voice4_Phonetic31_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_31", 1}};
	};

	class RadioNotification_Voice4_Phonetic32_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_32", 1}};
	};

	class RadioNotification_Voice4_Phonetic33_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_33", 1}};
	};

	class RadioNotification_Voice4_Phonetic34_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_34", 1}};
	};

	class RadioNotification_Voice4_Phonetic35_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_35", 1}};
	};

	class RadioNotification_Voice4_Phonetic36_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_36", 1}};
	};

	class RadioNotification_Voice4_Phonetic37_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_37", 1}};
	};

	class RadioNotification_Voice4_Phonetic38_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_38", 1}};
	};

	class RadioNotification_Voice4_Phonetic39_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_39", 1}};
	};

	class RadioNotification_Voice4_Phonetic40_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_40", 1}};
	};

	class RadioNotification_Voice4_Phonetic41_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_41", 1}};
	};

	class RadioNotification_Voice4_Phonetic42_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_42", 1}};
	};

	class RadioNotification_Voice4_Phonetic43_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_43", 1}};
	};

	class RadioNotification_Voice4_Phonetic44_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_44", 1}};
	};

	class RadioNotification_Voice4_Phonetic45_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_45", 1}};
	};

	class RadioNotification_Voice4_Phonetic46_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_46", 1}};
	};

	class RadioNotification_Voice4_Phonetic47_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_47", 1}};
	};

	class RadioNotification_Voice4_Phonetic48_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_48", 1}};
	};

	class RadioNotification_Voice4_Phonetic49_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_49", 1}};
	};

	class RadioNotification_Voice4_Phonetic50_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_50", 1}};
	};

	class RadioNotification_Voice4_Phonetic51_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_51", 1}};
	};

	class RadioNotification_Voice4_Phonetic52_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_52", 1}};
	};

	class RadioNotification_Voice4_Phonetic53_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\4_53", 1}};
	};

	class RadioNotification_Voice5_Phonetic0_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_0", 1}};
	};

	class RadioNotification_Voice5_Phonetic1_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_1", 1}};
	};

	class RadioNotification_Voice5_Phonetic2_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_2", 1}};
	};

	class RadioNotification_Voice5_Phonetic3_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_3", 1}};
	};

	class RadioNotification_Voice5_Phonetic4_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_4", 1}};
	};

	class RadioNotification_Voice5_Phonetic5_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_5", 1}};
	};

	class RadioNotification_Voice5_Phonetic6_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_6", 1}};
	};

	class RadioNotification_Voice5_Phonetic7_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_7", 1}};
	};

	class RadioNotification_Voice5_Phonetic8_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_8", 1}};
	};

	class RadioNotification_Voice5_Phonetic9_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_9", 1}};
	};

	class RadioNotification_Voice5_Phonetic10_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_10", 1}};
	};

	class RadioNotification_Voice5_Phonetic11_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_11", 1}};
	};

	class RadioNotification_Voice5_Phonetic12_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_12", 1}};
	};

	class RadioNotification_Voice5_Phonetic13_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_13", 1}};
	};

	class RadioNotification_Voice5_Phonetic14_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_14", 1}};
	};

	class RadioNotification_Voice5_Phonetic15_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_15", 1}};
	};

	class RadioNotification_Voice5_Phonetic16_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_16", 1}};
	};

	class RadioNotification_Voice5_Phonetic17_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_17", 1}};
	};

	class RadioNotification_Voice5_Phonetic18_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_18", 1}};
	};

	class RadioNotification_Voice5_Phonetic19_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_19", 1}};
	};

	class RadioNotification_Voice5_Phonetic20_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_20", 1}};
	};

	class RadioNotification_Voice5_Phonetic21_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_21", 1}};
	};

	class RadioNotification_Voice5_Phonetic22_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_22", 1}};
	};

	class RadioNotification_Voice5_Phonetic23_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_23", 1}};
	};

	class RadioNotification_Voice5_Phonetic24_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_24", 1}};
	};

	class RadioNotification_Voice5_Phonetic25_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_25", 1}};
	};

	class RadioNotification_Voice5_Phonetic26_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_26", 1}};
	};

	class RadioNotification_Voice5_Phonetic27_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_27", 1}};
	};

	class RadioNotification_Voice5_Phonetic28_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_28", 1}};
	};

	class RadioNotification_Voice5_Phonetic29_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_29", 1}};
	};

	class RadioNotification_Voice5_Phonetic30_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_30", 1}};
	};

	class RadioNotification_Voice5_Phonetic31_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_31", 1}};
	};

	class RadioNotification_Voice5_Phonetic32_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_32", 1}};
	};

	class RadioNotification_Voice5_Phonetic33_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_33", 1}};
	};

	class RadioNotification_Voice5_Phonetic34_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_34", 1}};
	};

	class RadioNotification_Voice5_Phonetic35_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_35", 1}};
	};

	class RadioNotification_Voice5_Phonetic36_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_36", 1}};
	};

	class RadioNotification_Voice5_Phonetic37_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_37", 1}};
	};

	class RadioNotification_Voice5_Phonetic38_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_38", 1}};
	};

	class RadioNotification_Voice5_Phonetic39_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_39", 1}};
	};

	class RadioNotification_Voice5_Phonetic40_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_40", 1}};
	};

	class RadioNotification_Voice5_Phonetic41_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_41", 1}};
	};

	class RadioNotification_Voice5_Phonetic42_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_42", 1}};
	};

	class RadioNotification_Voice5_Phonetic43_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_43", 1}};
	};

	class RadioNotification_Voice5_Phonetic44_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_44", 1}};
	};

	class RadioNotification_Voice5_Phonetic45_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_45", 1}};
	};

	class RadioNotification_Voice5_Phonetic46_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_46", 1}};
	};

	class RadioNotification_Voice5_Phonetic47_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_47", 1}};
	};

	class RadioNotification_Voice5_Phonetic48_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_48", 1}};
	};

	class RadioNotification_Voice5_Phonetic49_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_49", 1}};
	};

	class RadioNotification_Voice5_Phonetic50_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_50", 1}};
	};

	class RadioNotification_Voice5_Phonetic51_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_51", 1}};
	};

	class RadioNotification_Voice5_Phonetic52_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_52", 1}};
	};

	class RadioNotification_Voice5_Phonetic53_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\5_53", 1}};
	};

	class RadioNotification_Voice6_Phonetic0_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_0", 1}};
	};

	class RadioNotification_Voice6_Phonetic1_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_1", 1}};
	};

	class RadioNotification_Voice6_Phonetic2_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_2", 1}};
	};

	class RadioNotification_Voice6_Phonetic3_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_3", 1}};
	};

	class RadioNotification_Voice6_Phonetic4_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_4", 1}};
	};

	class RadioNotification_Voice6_Phonetic5_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_5", 1}};
	};

	class RadioNotification_Voice6_Phonetic6_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_6", 1}};
	};

	class RadioNotification_Voice6_Phonetic7_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_7", 1}};
	};

	class RadioNotification_Voice6_Phonetic8_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_8", 1}};
	};

	class RadioNotification_Voice6_Phonetic9_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_9", 1}};
	};

	class RadioNotification_Voice6_Phonetic10_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_10", 1}};
	};

	class RadioNotification_Voice6_Phonetic11_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_11", 1}};
	};

	class RadioNotification_Voice6_Phonetic12_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_12", 1}};
	};

	class RadioNotification_Voice6_Phonetic13_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_13", 1}};
	};

	class RadioNotification_Voice6_Phonetic14_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_14", 1}};
	};

	class RadioNotification_Voice6_Phonetic15_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_15", 1}};
	};

	class RadioNotification_Voice6_Phonetic16_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_16", 1}};
	};

	class RadioNotification_Voice6_Phonetic17_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_17", 1}};
	};

	class RadioNotification_Voice6_Phonetic18_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_18", 1}};
	};

	class RadioNotification_Voice6_Phonetic19_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_19", 1}};
	};

	class RadioNotification_Voice6_Phonetic20_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_20", 1}};
	};

	class RadioNotification_Voice6_Phonetic21_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_21", 1}};
	};

	class RadioNotification_Voice6_Phonetic22_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_22", 1}};
	};

	class RadioNotification_Voice6_Phonetic23_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_23", 1}};
	};

	class RadioNotification_Voice6_Phonetic24_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_24", 1}};
	};

	class RadioNotification_Voice6_Phonetic25_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_25", 1}};
	};

	class RadioNotification_Voice6_Phonetic26_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_26", 1}};
	};

	class RadioNotification_Voice6_Phonetic27_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_27", 1}};
	};

	class RadioNotification_Voice6_Phonetic28_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_28", 1}};
	};

	class RadioNotification_Voice6_Phonetic29_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_29", 1}};
	};

	class RadioNotification_Voice6_Phonetic30_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_30", 1}};
	};

	class RadioNotification_Voice6_Phonetic31_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_31", 1}};
	};

	class RadioNotification_Voice6_Phonetic32_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_32", 1}};
	};

	class RadioNotification_Voice6_Phonetic33_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_33", 1}};
	};

	class RadioNotification_Voice6_Phonetic34_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_34", 1}};
	};

	class RadioNotification_Voice6_Phonetic35_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_35", 1}};
	};

	class RadioNotification_Voice6_Phonetic36_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_36", 1}};
	};

	class RadioNotification_Voice6_Phonetic37_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_37", 1}};
	};

	class RadioNotification_Voice6_Phonetic38_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_38", 1}};
	};

	class RadioNotification_Voice6_Phonetic39_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_39", 1}};
	};

	class RadioNotification_Voice6_Phonetic40_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_40", 1}};
	};

	class RadioNotification_Voice6_Phonetic41_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_41", 1}};
	};

	class RadioNotification_Voice6_Phonetic42_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_42", 1}};
	};

	class RadioNotification_Voice6_Phonetic43_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_43", 1}};
	};

	class RadioNotification_Voice6_Phonetic44_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_44", 1}};
	};

	class RadioNotification_Voice6_Phonetic45_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_45", 1}};
	};

	class RadioNotification_Voice6_Phonetic46_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_46", 1}};
	};

	class RadioNotification_Voice6_Phonetic47_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_47", 1}};
	};

	class RadioNotification_Voice6_Phonetic48_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_48", 1}};
	};

	class RadioNotification_Voice6_Phonetic49_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_49", 1}};
	};

	class RadioNotification_Voice6_Phonetic50_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_50", 1}};
	};

	class RadioNotification_Voice6_Phonetic51_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_51", 1}};
	};

	class RadioNotification_Voice6_Phonetic52_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_52", 1}};
	};

	class RadioNotification_Voice6_Phonetic53_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\6_53", 1}};
	};

	class RadioNotification_Voice7_Phonetic0_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_0", 1}};
	};

	class RadioNotification_Voice7_Phonetic1_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_1", 1}};
	};

	class RadioNotification_Voice7_Phonetic2_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_2", 1}};
	};

	class RadioNotification_Voice7_Phonetic3_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_3", 1}};
	};

	class RadioNotification_Voice7_Phonetic4_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_4", 1}};
	};

	class RadioNotification_Voice7_Phonetic5_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_5", 1}};
	};

	class RadioNotification_Voice7_Phonetic6_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_6", 1}};
	};

	class RadioNotification_Voice7_Phonetic7_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_7", 1}};
	};

	class RadioNotification_Voice7_Phonetic8_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_8", 1}};
	};

	class RadioNotification_Voice7_Phonetic9_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_9", 1}};
	};

	class RadioNotification_Voice7_Phonetic10_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_10", 1}};
	};

	class RadioNotification_Voice7_Phonetic11_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_11", 1}};
	};

	class RadioNotification_Voice7_Phonetic12_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_12", 1}};
	};

	class RadioNotification_Voice7_Phonetic13_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_13", 1}};
	};

	class RadioNotification_Voice7_Phonetic14_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_14", 1}};
	};

	class RadioNotification_Voice7_Phonetic15_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_15", 1}};
	};

	class RadioNotification_Voice7_Phonetic16_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_16", 1}};
	};

	class RadioNotification_Voice7_Phonetic17_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_17", 1}};
	};

	class RadioNotification_Voice7_Phonetic18_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_18", 1}};
	};

	class RadioNotification_Voice7_Phonetic19_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_19", 1}};
	};

	class RadioNotification_Voice7_Phonetic20_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_20", 1}};
	};

	class RadioNotification_Voice7_Phonetic21_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_21", 1}};
	};

	class RadioNotification_Voice7_Phonetic22_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_22", 1}};
	};

	class RadioNotification_Voice7_Phonetic23_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_23", 1}};
	};

	class RadioNotification_Voice7_Phonetic24_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_24", 1}};
	};

	class RadioNotification_Voice7_Phonetic25_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_25", 1}};
	};

	class RadioNotification_Voice7_Phonetic26_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_26", 1}};
	};

	class RadioNotification_Voice7_Phonetic27_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_27", 1}};
	};

	class RadioNotification_Voice7_Phonetic28_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_28", 1}};
	};

	class RadioNotification_Voice7_Phonetic29_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_29", 1}};
	};

	class RadioNotification_Voice7_Phonetic30_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_30", 1}};
	};

	class RadioNotification_Voice7_Phonetic31_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_31", 1}};
	};

	class RadioNotification_Voice7_Phonetic32_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_32", 1}};
	};

	class RadioNotification_Voice7_Phonetic33_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_33", 1}};
	};

	class RadioNotification_Voice7_Phonetic34_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_34", 1}};
	};

	class RadioNotification_Voice7_Phonetic35_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_35", 1}};
	};

	class RadioNotification_Voice7_Phonetic36_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_36", 1}};
	};

	class RadioNotification_Voice7_Phonetic37_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_37", 1}};
	};

	class RadioNotification_Voice7_Phonetic38_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_38", 1}};
	};

	class RadioNotification_Voice7_Phonetic39_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_39", 1}};
	};

	class RadioNotification_Voice7_Phonetic40_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_40", 1}};
	};

	class RadioNotification_Voice7_Phonetic41_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_41", 1}};
	};

	class RadioNotification_Voice7_Phonetic42_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_42", 1}};
	};

	class RadioNotification_Voice7_Phonetic43_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_43", 1}};
	};

	class RadioNotification_Voice7_Phonetic44_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_44", 1}};
	};

	class RadioNotification_Voice7_Phonetic45_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_45", 1}};
	};

	class RadioNotification_Voice7_Phonetic46_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_46", 1}};
	};

	class RadioNotification_Voice7_Phonetic47_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_47", 1}};
	};

	class RadioNotification_Voice7_Phonetic48_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_48", 1}};
	};

	class RadioNotification_Voice7_Phonetic49_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_49", 1}};
	};

	class RadioNotification_Voice7_Phonetic50_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_50", 1}};
	};

	class RadioNotification_Voice7_Phonetic51_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_51", 1}};
	};

	class RadioNotification_Voice7_Phonetic52_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_52", 1}};
	};

	class RadioNotification_Voice7_Phonetic53_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\7_53", 1}};
	};

	class RadioNotification_Voice8_Phonetic0_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_0", 1}};
	};

	class RadioNotification_Voice8_Phonetic1_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_1", 1}};
	};

	class RadioNotification_Voice8_Phonetic2_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_2", 1}};
	};

	class RadioNotification_Voice8_Phonetic3_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_3", 1}};
	};

	class RadioNotification_Voice8_Phonetic4_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_4", 1}};
	};

	class RadioNotification_Voice8_Phonetic5_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_5", 1}};
	};

	class RadioNotification_Voice8_Phonetic6_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_6", 1}};
	};

	class RadioNotification_Voice8_Phonetic7_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_7", 1}};
	};

	class RadioNotification_Voice8_Phonetic8_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_8", 1}};
	};

	class RadioNotification_Voice8_Phonetic9_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_9", 1}};
	};

	class RadioNotification_Voice8_Phonetic10_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_10", 1}};
	};

	class RadioNotification_Voice8_Phonetic11_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_11", 1}};
	};

	class RadioNotification_Voice8_Phonetic12_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_12", 1}};
	};

	class RadioNotification_Voice8_Phonetic13_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_13", 1}};
	};

	class RadioNotification_Voice8_Phonetic14_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_14", 1}};
	};

	class RadioNotification_Voice8_Phonetic15_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_15", 1}};
	};

	class RadioNotification_Voice8_Phonetic16_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_16", 1}};
	};

	class RadioNotification_Voice8_Phonetic17_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_17", 1}};
	};

	class RadioNotification_Voice8_Phonetic18_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_18", 1}};
	};

	class RadioNotification_Voice8_Phonetic19_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_19", 1}};
	};

	class RadioNotification_Voice8_Phonetic20_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_20", 1}};
	};

	class RadioNotification_Voice8_Phonetic21_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_21", 1}};
	};

	class RadioNotification_Voice8_Phonetic22_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_22", 1}};
	};

	class RadioNotification_Voice8_Phonetic23_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_23", 1}};
	};

	class RadioNotification_Voice8_Phonetic24_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_24", 1}};
	};

	class RadioNotification_Voice8_Phonetic25_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_25", 1}};
	};

	class RadioNotification_Voice8_Phonetic26_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_26", 1}};
	};

	class RadioNotification_Voice8_Phonetic27_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_27", 1}};
	};

	class RadioNotification_Voice8_Phonetic28_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_28", 1}};
	};

	class RadioNotification_Voice8_Phonetic29_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_29", 1}};
	};

	class RadioNotification_Voice8_Phonetic30_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_30", 1}};
	};

	class RadioNotification_Voice8_Phonetic31_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_31", 1}};
	};

	class RadioNotification_Voice8_Phonetic32_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_32", 1}};
	};

	class RadioNotification_Voice8_Phonetic33_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_33", 1}};
	};

	class RadioNotification_Voice8_Phonetic34_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_34", 1}};
	};

	class RadioNotification_Voice8_Phonetic35_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_35", 1}};
	};

	class RadioNotification_Voice8_Phonetic36_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_36", 1}};
	};

	class RadioNotification_Voice8_Phonetic37_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_37", 1}};
	};

	class RadioNotification_Voice8_Phonetic38_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_38", 1}};
	};

	class RadioNotification_Voice8_Phonetic39_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_39", 1}};
	};

	class RadioNotification_Voice8_Phonetic40_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_40", 1}};
	};

	class RadioNotification_Voice8_Phonetic41_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_41", 1}};
	};

	class RadioNotification_Voice8_Phonetic42_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_42", 1}};
	};

	class RadioNotification_Voice8_Phonetic43_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_43", 1}};
	};

	class RadioNotification_Voice8_Phonetic44_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_44", 1}};
	};

	class RadioNotification_Voice8_Phonetic45_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_45", 1}};
	};

	class RadioNotification_Voice8_Phonetic46_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_46", 1}};
	};

	class RadioNotification_Voice8_Phonetic47_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_47", 1}};
	};

	class RadioNotification_Voice8_Phonetic48_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_48", 1}};
	};

	class RadioNotification_Voice8_Phonetic49_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_49", 1}};
	};

	class RadioNotification_Voice8_Phonetic50_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_50", 1}};
	};

	class RadioNotification_Voice8_Phonetic51_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_51", 1}};
	};

	class RadioNotification_Voice8_Phonetic52_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_52", 1}};
	};

	class RadioNotification_Voice8_Phonetic53_SoundShader : RadioNotification_SoundShader {
		samples[] = {{"RadioNotifications\sounds\phonetics\8_53", 1}};
	};
};

class CfgSoundSets {
	class RadioNotification_SoundSet {
		sound3DProcessingType = "character3DProcessingType";
		volumeCurve = "characterAttenuationCurve";

		spatial = 1;
		doppler = 0;
		loop = 0;
		distanceFilter = "defaultDistanceFilter";
	};

	class RadioNotification_Alarm_SoundSet : RadioNotification_SoundSet {

		speedOfSound = 1;
		volumeCurve = "alarmAttenuationCurve";
		distanceFilter = "defaultDistanceFreqAttenuationFilter";
		sound3DProcessingType = "ThunderNear3DProcessingType";
	};

	class RadioNotification_Alarm0 : RadioNotification_Alarm_SoundSet {
		soundShaders[] = {"RadioNotification_Alarm0_SoundShader"};
	};

	class RadioNotification_Preamble0 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Preamble0_SoundShader"};
	};

	class RadioNotification_Preamble1 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Preamble1_SoundShader"};
	};

	class RadioNotification_Preamble2 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Preamble2_SoundShader"};
	};

	class RadioNotification_Noise0 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Noise0_SoundShader"};
		loop = 1;
	};

	class RadioNotification_Noise1 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Noise1_SoundShader"};
		loop = 1;
	};

	class RadioNotification_Noise2 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Noise2_SoundShader"};
		loop = 1;
	};

	class RadioNotification_Noise3 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Noise3_SoundShader"};
		loop = 1;
	};

	class RadioNotification_Voice0_Phonetic0 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic0_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic1 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic1_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic2 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic2_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic3 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic3_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic4 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic4_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic5 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic5_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic6 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic6_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic7 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic7_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic8 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic8_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic9 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic9_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic10 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic10_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic11 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic11_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic12 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic12_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic13 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic13_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic14 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic14_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic15 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic15_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic16 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic16_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic17 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic17_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic18 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic18_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic19 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic19_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic20 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic20_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic21 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic21_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic22 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic22_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic23 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic23_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic24 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic24_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic25 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic25_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic26 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic26_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic27 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic27_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic28 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic28_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic29 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic29_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic30 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic30_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic31 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic31_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic32 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic32_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic33 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic33_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic34 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic34_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic35 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic35_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic36 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic36_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic37 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic37_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic38 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic38_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic39 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic39_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic40 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic40_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic41 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic41_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic42 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic42_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic43 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic43_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic44 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic44_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic45 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic45_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic46 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic46_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic47 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic47_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic48 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic48_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic49 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic49_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic50 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic50_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic51 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic51_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic52 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic52_SoundShader"};
	};

	class RadioNotification_Voice0_Phonetic53 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice0_Phonetic53_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic0 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic0_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic1 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic1_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic2 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic2_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic3 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic3_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic4 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic4_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic5 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic5_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic6 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic6_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic7 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic7_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic8 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic8_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic9 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic9_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic10 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic10_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic11 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic11_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic12 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic12_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic13 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic13_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic14 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic14_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic15 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic15_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic16 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic16_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic17 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic17_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic18 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic18_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic19 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic19_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic20 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic20_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic21 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic21_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic22 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic22_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic23 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic23_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic24 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic24_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic25 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic25_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic26 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic26_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic27 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic27_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic28 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic28_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic29 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic29_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic30 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic30_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic31 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic31_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic32 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic32_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic33 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic33_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic34 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic34_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic35 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic35_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic36 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic36_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic37 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic37_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic38 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic38_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic39 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic39_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic40 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic40_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic41 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic41_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic42 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic42_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic43 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic43_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic44 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic44_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic45 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic45_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic46 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic46_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic47 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic47_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic48 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic48_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic49 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic49_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic50 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic50_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic51 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic51_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic52 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic52_SoundShader"};
	};

	class RadioNotification_Voice1_Phonetic53 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice1_Phonetic53_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic0 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic0_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic1 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic1_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic2 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic2_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic3 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic3_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic4 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic4_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic5 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic5_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic6 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic6_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic7 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic7_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic8 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic8_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic9 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic9_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic10 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic10_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic11 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic11_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic12 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic12_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic13 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic13_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic14 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic14_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic15 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic15_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic16 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic16_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic17 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic17_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic18 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic18_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic19 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic19_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic20 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic20_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic21 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic21_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic22 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic22_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic23 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic23_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic24 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic24_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic25 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic25_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic26 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic26_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic27 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic27_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic28 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic28_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic29 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic29_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic30 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic30_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic31 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic31_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic32 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic32_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic33 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic33_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic34 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic34_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic35 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic35_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic36 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic36_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic37 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic37_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic38 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic38_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic39 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic39_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic40 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic40_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic41 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic41_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic42 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic42_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic43 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic43_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic44 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic44_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic45 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic45_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic46 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic46_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic47 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic47_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic48 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic48_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic49 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic49_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic50 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic50_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic51 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic51_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic52 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic52_SoundShader"};
	};

	class RadioNotification_Voice2_Phonetic53 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice2_Phonetic53_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic0 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic0_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic1 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic1_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic2 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic2_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic3 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic3_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic4 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic4_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic5 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic5_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic6 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic6_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic7 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic7_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic8 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic8_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic9 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic9_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic10 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic10_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic11 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic11_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic12 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic12_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic13 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic13_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic14 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic14_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic15 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic15_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic16 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic16_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic17 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic17_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic18 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic18_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic19 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic19_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic20 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic20_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic21 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic21_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic22 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic22_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic23 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic23_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic24 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic24_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic25 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic25_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic26 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic26_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic27 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic27_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic28 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic28_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic29 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic29_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic30 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic30_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic31 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic31_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic32 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic32_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic33 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic33_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic34 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic34_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic35 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic35_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic36 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic36_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic37 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic37_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic38 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic38_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic39 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic39_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic40 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic40_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic41 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic41_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic42 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic42_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic43 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic43_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic44 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic44_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic45 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic45_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic46 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic46_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic47 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic47_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic48 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic48_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic49 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic49_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic50 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic50_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic51 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic51_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic52 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic52_SoundShader"};
	};

	class RadioNotification_Voice3_Phonetic53 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice3_Phonetic53_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic0 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic0_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic1 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic1_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic2 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic2_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic3 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic3_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic4 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic4_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic5 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic5_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic6 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic6_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic7 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic7_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic8 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic8_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic9 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic9_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic10 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic10_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic11 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic11_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic12 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic12_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic13 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic13_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic14 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic14_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic15 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic15_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic16 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic16_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic17 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic17_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic18 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic18_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic19 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic19_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic20 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic20_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic21 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic21_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic22 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic22_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic23 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic23_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic24 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic24_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic25 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic25_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic26 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic26_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic27 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic27_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic28 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic28_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic29 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic29_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic30 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic30_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic31 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic31_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic32 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic32_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic33 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic33_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic34 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic34_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic35 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic35_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic36 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic36_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic37 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic37_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic38 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic38_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic39 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic39_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic40 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic40_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic41 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic41_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic42 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic42_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic43 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic43_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic44 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic44_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic45 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic45_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic46 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic46_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic47 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic47_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic48 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic48_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic49 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic49_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic50 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic50_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic51 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic51_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic52 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic52_SoundShader"};
	};

	class RadioNotification_Voice4_Phonetic53 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice4_Phonetic53_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic0 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic0_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic1 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic1_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic2 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic2_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic3 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic3_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic4 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic4_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic5 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic5_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic6 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic6_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic7 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic7_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic8 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic8_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic9 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic9_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic10 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic10_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic11 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic11_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic12 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic12_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic13 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic13_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic14 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic14_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic15 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic15_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic16 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic16_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic17 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic17_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic18 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic18_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic19 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic19_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic20 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic20_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic21 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic21_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic22 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic22_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic23 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic23_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic24 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic24_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic25 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic25_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic26 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic26_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic27 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic27_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic28 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic28_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic29 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic29_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic30 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic30_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic31 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic31_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic32 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic32_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic33 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic33_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic34 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic34_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic35 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic35_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic36 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic36_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic37 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic37_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic38 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic38_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic39 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic39_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic40 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic40_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic41 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic41_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic42 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic42_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic43 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic43_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic44 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic44_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic45 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic45_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic46 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic46_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic47 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic47_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic48 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic48_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic49 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic49_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic50 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic50_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic51 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic51_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic52 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic52_SoundShader"};
	};

	class RadioNotification_Voice5_Phonetic53 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice5_Phonetic53_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic0 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic0_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic1 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic1_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic2 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic2_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic3 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic3_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic4 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic4_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic5 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic5_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic6 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic6_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic7 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic7_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic8 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic8_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic9 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic9_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic10 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic10_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic11 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic11_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic12 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic12_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic13 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic13_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic14 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic14_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic15 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic15_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic16 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic16_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic17 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic17_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic18 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic18_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic19 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic19_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic20 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic20_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic21 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic21_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic22 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic22_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic23 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic23_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic24 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic24_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic25 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic25_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic26 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic26_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic27 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic27_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic28 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic28_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic29 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic29_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic30 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic30_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic31 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic31_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic32 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic32_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic33 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic33_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic34 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic34_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic35 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic35_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic36 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic36_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic37 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic37_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic38 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic38_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic39 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic39_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic40 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic40_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic41 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic41_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic42 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic42_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic43 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic43_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic44 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic44_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic45 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic45_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic46 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic46_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic47 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic47_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic48 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic48_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic49 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic49_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic50 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic50_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic51 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic51_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic52 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic52_SoundShader"};
	};

	class RadioNotification_Voice6_Phonetic53 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice6_Phonetic53_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic0 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic0_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic1 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic1_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic2 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic2_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic3 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic3_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic4 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic4_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic5 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic5_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic6 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic6_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic7 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic7_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic8 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic8_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic9 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic9_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic10 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic10_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic11 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic11_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic12 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic12_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic13 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic13_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic14 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic14_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic15 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic15_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic16 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic16_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic17 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic17_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic18 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic18_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic19 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic19_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic20 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic20_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic21 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic21_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic22 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic22_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic23 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic23_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic24 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic24_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic25 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic25_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic26 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic26_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic27 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic27_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic28 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic28_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic29 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic29_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic30 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic30_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic31 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic31_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic32 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic32_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic33 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic33_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic34 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic34_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic35 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic35_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic36 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic36_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic37 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic37_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic38 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic38_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic39 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic39_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic40 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic40_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic41 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic41_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic42 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic42_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic43 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic43_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic44 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic44_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic45 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic45_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic46 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic46_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic47 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic47_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic48 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic48_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic49 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic49_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic50 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic50_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic51 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic51_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic52 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic52_SoundShader"};
	};

	class RadioNotification_Voice7_Phonetic53 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice7_Phonetic53_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic0 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic0_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic1 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic1_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic2 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic2_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic3 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic3_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic4 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic4_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic5 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic5_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic6 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic6_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic7 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic7_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic8 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic8_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic9 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic9_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic10 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic10_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic11 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic11_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic12 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic12_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic13 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic13_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic14 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic14_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic15 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic15_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic16 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic16_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic17 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic17_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic18 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic18_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic19 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic19_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic20 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic20_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic21 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic21_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic22 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic22_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic23 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic23_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic24 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic24_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic25 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic25_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic26 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic26_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic27 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic27_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic28 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic28_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic29 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic29_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic30 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic30_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic31 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic31_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic32 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic32_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic33 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic33_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic34 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic34_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic35 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic35_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic36 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic36_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic37 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic37_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic38 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic38_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic39 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic39_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic40 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic40_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic41 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic41_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic42 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic42_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic43 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic43_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic44 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic44_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic45 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic45_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic46 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic46_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic47 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic47_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic48 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic48_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic49 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic49_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic50 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic50_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic51 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic51_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic52 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic52_SoundShader"};
	};

	class RadioNotification_Voice8_Phonetic53 : RadioNotification_SoundSet {
		soundShaders[] = {"RadioNotification_Voice8_Phonetic53_SoundShader"};
	};
};