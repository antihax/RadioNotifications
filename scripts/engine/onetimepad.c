/*
 * RadioNotifications Mod
 * https://github.com/antihax/RadioNotifications
 * © 2023 antihax
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
 */

/**
 * @brief Class definition for RadioNotificationOneTimePad.
 * 
 * This class provides functionality for generating and using one-time pads
 * for secure communication between radio devices.
 */
class RadioNotificationOneTimePad {
	protected const int TABLE_SIZE = 46;
	protected const string TABLE_ALPHABET[TABLE_SIZE] = {
		"[CODE]", "A", "E", "I", "N", "T",
		"AN", "AT", "B", "C", "D", "ED", "EN", "ER", "F", "G",
		"H", "HA", "HE", "IN", "IT", "J", "K", "L", "M", "ND",
		"O", "ON", "OR", "OU", "P", "Q", "R", "RE", "S", "TH",
		"TO", "U", "V", "W", "X", "Y", "Z", " ", ".", "[FIG]"
	};
	protected const int TABLE_VALUES[TABLE_SIZE] = {
		0, 1, 2, 3, 4, 5,
		60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
		70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
		80, 81, 82, 83, 84, 85, 86, 87, 88, 89,
		90, 91, 92, 93, 94, 95, 96, 97, 98, 99
	};

	protected autoptr array<string> TABLE_WORDS = {
		"ABORT",
		"ABOUT",
		"ABOVE",
		"ACCEPT",
		"ACCESS",
		"ADDRESS",
		"AFTER",
		"AGAIN",
		"AGENT",
		"AIRPLANE",
		"AIRPORT",
		"ALMOST",
		"ALONG",
		"ALWAYS",
		"ANOTHER",
		"ANSWER",
		"AROUND",
		"AUTH",
		"BECAUSE",
		"BEFORE",
		"BEGAN",
		"BEGIN",
		"BEING",
		"BELOW",
		"BETWEEN",
		"BORDER",
		"BUILDING",
		"CANCEL",
		"CARRY",
		"CHANGE",
		"CIVILIAN",
		"CLOSE",
		"COMPUTER",
		"CONFIRM",
		"CONTACT",
		"COORDS",
		"COULD",
		"COVERT",
		"CURRENT",
		"DANGER",
		"DECODE",
		"DELAY",
		"DOCUMENT",
		"ENCODE",
		"ENOUGH",
		"EVERY",
		"EXAMPLE",
		"EXECUTE",
		"FACTORY",
		"FAILED",
		"FIRST",
		"FOLLOW",
		"FOUND",
		"FREQUENCY",
		"GREAT",
		"GROUP",
		"HARBOUR",
		"HELI",
		"HIGHWAY",
		"HOUSE",
		"IDENTITY",
		"IMMEDIATE",
		"LARGE",
		"LATER",
		"LEARN",
		"LEAVE",
		"LETTER",
		"LIGHT",
		"LITTLE",
		"LOCATE",
		"LOCATION",
		"MEET",
		"MESSAGE",
		"MIGHT",
		"MILITARY",
		"MONEY",
		"MONTH",
		"MOUNTAIN",
		"NEGATIVE",
		"NEVER",
		"NIGHT",
		"NUMBER",
		"OFTEN",
		"OTHER",
		"PAPER",
		"PASSPORT",
		"PEOPLE",
		"PERSON",
		"PICTURE",
		"PLACE",
		"PLANT",
		"POINT",
		"POSITIVE",
		"POSSIBLE",
		"POWER",
		"PRIORITY",
		"PROBLEM",
		"QUESTION",
		"RADIO",
		"REALLY",
		"RECEIVE",
		"REPEAT",
		"RIGHT",
		"RIVER",
		"ROUTINE",
		"SCHOOL",
		"SECOND",
		"SENTENCE",
		"SHOULD",
		"SMALL",
		"SOMETHING",
		"SOMETIMES",
		"SOUND",
		"SPELL",
		"START",
		"STATE",
		"STILL",
		"STORY",
		"STREET",
		"STUDY",
		"SUCCESS",
		"SUPPLY",
		"SUPPORT",
		"THEIR",
		"THERE",
		"THESE",
		"THING",
		"THINK",
		"THOSE",
		"THOUGHT",
		"THROUGH",
		"TODAY",
		"TOGETHER",
		"TOMORROW",
		"TRAIN",
		"TRANSFER",
		"TRANSMIT",
		"TRAVEL",
		"TRUCK",
		"UNABLE",
		"UNDER",
		"UNTIL",
		"URGENT",
		"VERIFY",
		"WATCH",
		"WATER",
		"WHERE",
		"WHICH",
		"WHILE",
		"WHITE",
		"WITHIN",
		"WITHOUT",
		"WOULD",
		"WRITE",
	};

	protected autoptr map<string, int> alphabetTable = new map<string, int>;
	protected autoptr map<int, string> valueTable = new map<int, string>;
	protected RadioNotifications_Trie coderTrie = new RadioNotifications_Trie();
	static const int KEY_SIZE = 95;
	static const int PAD_SIZE = 34;
	static const int TOTAL_PAD_SIZE = 3230;
	protected int keyPads[TOTAL_PAD_SIZE];
	protected int state = 0;

	/**
	 * Pads an integer with leading zeros to ensure it has a minimum length of 4 digits.
	 * 
	 * @param num The integer to pad with zeros.
	 * @return The padded integer as a string.
	 */
	private string PadIntWithZeros(int num) {
		string str = num.ToString();
		while (str.Length() < 4) {
			str = "0" + str;
		}
		return str;
	}

	/**
	 * Pad a string with spaces to a specified length.
	 * If the string is already longer than the specified length, it will be returned unchanged.
	 * @param str The string to pad with spaces.
	 * @param length The desired length of the padded string.
	 * @return The padded string.
	 */
	private string PadStringWithSpaces(string str, int length) {
		int padding = length - str.Length();
		if (padding <= 0) {
			return str;
		}
		for (int i = 0; i < padding; ++i) {
			str += " ";
		}
		return str;
	}

	/**
	 * RadioNotificationOneTimePad - Generates encryption keys and performs encoding and decoding using a one-time pad algorithm.
	 * @param seed: An integer value used to seed the random number generator.
	 * @return: void
	 */
	void RadioNotificationOneTimePad(int seed = 123) {
		state = seed;

		// Setup the lookup tables
		for (int i = 0; i < TABLE_SIZE; ++i) {
			alphabetTable.Insert(TABLE_ALPHABET[i], TABLE_VALUES[i]);
			valueTable.Insert(TABLE_VALUES[i], TABLE_ALPHABET[i]);
		}

		// Build the trie
		for (i = 0; i < TABLE_SIZE; ++i) {
			coderTrie.Insert(TABLE_ALPHABET[i], TABLE_VALUES[i].ToString());
		}

		for (i = 0; i < TABLE_WORDS.Count(); ++i) {
			// Add a space here since we will pack a space when decoding
			coderTrie.Insert(TABLE_WORDS[i] + " ", PadIntWithZeros(i));
		}

		string list;
		// Create encryption keys
		for (int x = 0; x < PAD_SIZE; ++x) {
			for (int j = 0; j < KEY_SIZE; ++j) {
				int index = (x * KEY_SIZE) + j;
				keyPads[index] = Next();
				list += keyPads[index].ToString();
			}
		}

		/*string src = "THIS IS A TEST LETTER PICTURE 123 SOMETHING 444 SHOULD RUN FROM PEOPLE";
		string test1 = Encode(src);
		string test2 = Decode(test1);
		string test3 = (0, src);
		Print(src);
		Print("Test1: " + test1);
		Print("Test2: " + test2);
		Print("Test3: " + test3);*/
	}

	/**
	 * GetPad - Retrieves a one-time pad from the keyPads array.
	 * 
	 * @param pad: The index of the pad to retrieve.
	 * @param result: An array to store the retrieved pad.
	 */
	void GetPad(int pad, out int[] result) {
		for (int i = 0; i < KEY_SIZE; ++i) {
			int index = (pad * KEY_SIZE) + i;
			result[i] = keyPads[index];
		}
	}

	/**
	 * GetPads - Retrieves the key pads used for one-time pad encryption.
	 * 
	 * @param[out] result - An integer array to store the key pads.
	 * 
	 * @remarks
	 * This function retrieves the key pads used for one-time pad encryption and stores them in the provided integer array.
	 * The size of the array must be equal to TOTAL_PAD_SIZE.
	 */
	void GetPads(out int[] result) {
		for (int i = 0; i < TOTAL_PAD_SIZE; ++i) {
			result[i] = keyPads[i];
		}
	}

	/**
	 * Searches the key pads for a matching code block and returns the index of the matching pad.
	 * @param codeBlock The code block to search for.
	 * @return The index of the matching pad, or -1 if no match was found.
	 */
	int GetKeyFromPad(string codeBlock) {
		for (int x = 0; x < PAD_SIZE; ++x) {
			bool match = true;
			for (int j = 0; j < 5; ++j) {
				if (keyPads[x * KEY_SIZE + j].ToString() != codeBlock[j]) {
					match = false;
					break;
				}
			}
			if (match) {
				return x;
			}
		}
		return -1;
	}

	/**
	 * Returns a string representation of the one-time pad.
	 * The one-time pad is a matrix of characters used for encryption.
	 * Each row of the matrix represents a different key pad.
	 * Each key pad is a sequence of random characters used to encrypt messages.
	 * The string representation of the one-time pad is formatted as follows:
	 * Each row of the matrix is separated by a newline character.
	 * Each key pad is separated by a space character.
	 * @return A string representation of the one-time pad.
	 */
	string GetPadText() {
		string result;
		for (int x = 0; x < PAD_SIZE; ++x) {
			for (int j = 0; j < KEY_SIZE; ++j) {
				result += keyPads[(x * KEY_SIZE) + j].ToString();
				if (j % 5 == 4) {
					result += " ";
				}
			}
			result += "\n";
		}
		return result;
	}

	/**
	 * Returns the text of the word table.
	 * 
	 * @return The text of the word table.
	 */
	string GetWordTableText() {
		string result;
		const int breakAt = 22; // fits 22
		int rows = TABLE_WORDS.Count() / breakAt + 1;

		// Find longest word
		int wordLen = 10;
		for (int i = 0; i < TABLE_WORDS.Count(); ++i)
			if (TABLE_WORDS[i].Length() > wordLen)
				wordLen = TABLE_WORDS[i].Length();

		// Build rows
		for (i = 0; i < breakAt; ++i) {
			// Build columns
			for (int j = 0; j < rows; ++j) {
				int index = j * breakAt + i;

				// Early out if we run out of words
				if (index >= TABLE_WORDS.Count())
					break;

				string word = PadStringWithSpaces(TABLE_WORDS[index], wordLen);
				string num = PadIntWithZeros(index);

				result += num + " " + word + " ";
			}
			result += "\n";
		}

		return result;
	}

	void ~RadioNotificationOneTimePad() {
	}

	/**
	 * Returns an array of strings representing a word table.
	 * 
	 * @return An array of strings representing a word table.
	 */
	array<string> GetWordTable() {
		return TABLE_WORDS;
	}

	/**
	 * Returns a map that represents the alphabet table.
	 * The keys of the map are the characters of the alphabet and the values are their corresponding integer values.
	 * @return A map that represents the alphabet table.
	 */
	map<string, int> GetAlphabetTable() {
		return alphabetTable;
	}

	/**
	 * Returns a map of integer values to string values.
	 * The integer values represent the index of the string in the one-time pad.
	 * The string values represent the one-time pad values.
	 *
	 * @return A map of integer values to string values representing the one-time pad.
	 */
	map<int, string> GetValueTable() {
		return valueTable;
	}

	/**
	 * Generates a predictable pseudo-random number between 0 and 9 using a linear congruential generator algorithm.
	 * @return The next pseudo-random number in the sequence.
	 */
	protected int Next() {
		state = (state * 1103515245 + 12345) & 0x7FFFFFFF;
		return ((state >> 16) % 10);
	}

	/**
	 * Returns a key of the specified length from the given one-time pad.
	 * 
	 * @param pad The index of the one-time pad to use.
	 * @param length The length of the key to generate.
	 * @return A string containing the generated key.
	 */
	string GetKey(int pad, int length) {
		string result;
		for (int i = 0; i < length; ++i) {
			int index = ((pad * KEY_SIZE) + i + 5) % TOTAL_PAD_SIZE;
			result += keyPads[index].ToString();
		}
		return result;
	}

	// Using strings because an array of ints just seems worse for a 0-9 value.
	// String get was optimized in
	/**
	 * Decrypts a given cipher text using a one-time pad encryption scheme.
	 *
	 * @param key The one-time pad key used for decryption.
	 * @param cipherText The cipher text to be decrypted.
	 * @return The plain text obtained after decryption.
	 */
	protected string Decrypt(string key, string cipherText) {
		string plainText = cipherText;
		for (int i = 0; i < cipherText.Length(); ++i) {
			int keyVal = key[i].ToInt();
			int plainIndex = (cipherText[i].ToInt() - keyVal + 10) % 10;
			plainText[i] = plainIndex.ToString();
		}
		return plainText;
	}

	/**
	 * Returns a random pad for encoding.
	 * 
	 * @return A random integer between 0 and PAD_SIZE - 1 (inclusive).
	 */
	int GetRandomPadNumber() {
		return Math.RandomIntInclusive(0, PAD_SIZE - 1);
	}

	/**
	 * Encrypts the given plain text using the one-time pad encryption algorithm.
	 *
	 * @param padIndex The index of the key pad to use for encryption.
	 * @param plainText The plain text to encrypt.
	 * @return The encrypted text, including the key used for encryption.
	 */
	protected string Encrypt(int padIndex, string plainText) {
		Print(plainText);
		string cipherText = plainText;
		for (int i = 0; i < plainText.Length(); ++i) {
			int keyIndex = (padIndex * KEY_SIZE + i + 5) % TOTAL_PAD_SIZE;
			cipherText[i] = ((plainText[i].ToInt() + keyPads[keyIndex]) % 10).ToString();
		}
		string insertKey;
		for (i = 0; i < 5; ++i) {
			insertKey += keyPads[padIndex * KEY_SIZE + i].ToString();
		}
		return insertKey + cipherText;
	}

	/**
	 * Decodes a message using a one-time pad cipher.
	 *
	 * @param key The key used to encrypt the message.
	 * @param cipherText The encrypted message to decode.
	 * @return The decoded message.
	 */
	string DecodeMessage(string key, string cipherText) {
		return Decode(Decrypt(key, cipherText));
	}

	/**
	 * Decodes a given string using a one-time pad cipher.
	 *
	 * @param plainText The string to be decoded.
	 * @return The decoded string.
	 */
	protected string Decode(string plainText) {
		string decodedText;

		int figuresLen = 0;
		for (int i = 0; i < plainText.Length(); ++i) {
			// Get the current code value
			int code = plainText[i].ToInt();

			// Early out on figures
			if ((figuresLen--) > 0) {
				decodedText += plainText[i];
				if (figuresLen == 0)
					decodedText += " ";
				continue;
			} else if (code > 5) {
				// Codes > 5 are 2 digit codes
				code = plainText.Substring(i++, 2).ToInt();
			}

			if (code == 0) {
				// Code 0 are word table codes
				int tableIndex = plainText.Substring(i, 4).ToInt();
				decodedText += TABLE_WORDS[tableIndex] + " ";
				i += 3;
				continue;
			} else if (code == 99) {
				// Code 99 are figure codes, read the next n(len) verbatim
				figuresLen = plainText[++i].ToInt();
				continue;
			}

			decodedText += valueTable[code];
		}
		return decodedText;
	}

	// why is this language like this?
	protected bool isDigit(string c) {
		if (c == "0" || c == "1" || c == "2" || c == "3" || c == "4" || c == "5" || c == "6" || c == "7" || c == "8" || c == "9") {
			return true;
		}
		return false;
	}

	/**
	 * Encodes the given plain text using a one-time pad cipher.
	 * 
	 * @param plainText The plain text to encode.
	 * @return The encoded cipher text.
	 */
	protected string Encode(string plainText) {
		plainText.ToUpper();
		string cipherText;
		string figures;

		for (int i = 0; i < plainText.Length();) {
			if (isDigit(plainText[i])) {
				figures += plainText[i];
				i++;
				if (i < plainText.Length())
					continue;
			}

			if (figures.Length() > 0) {
				cipherText += "99" + figures.Length().ToString() + figures;
				figures = "";
			}

			string lastCode = "";
			int lastLen;
			for (int len = 1; i + len <= plainText.Length(); ++len) {
				string code = coderTrie.Search(plainText.Substring(i, len));
				if (code == "")
					break;
				if (code != "-") {
					lastCode = code;
					lastLen = len;
				}
			}
			i += lastLen;
			cipherText += lastCode;
		}
		return cipherText;
	}

	/**
	 * Encodes the given plain text message using a one-time pad encryption scheme.
	 *
	 * @param padIndex The index of the one-time pad to use for encryption.
	 * @param plainText The plain text message to encode.
	 * @return The encoded message.
	 */
	string EncodeMessage(int padIndex, string plainText) {
		return Encrypt(padIndex, Encode(plainText));
	}
}