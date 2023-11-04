---
title: RadioNotificationOneTimePad
summary: Class definition for RadioNotificationOneTimePad. 

---

# RadioNotificationOneTimePad



Class definition for [RadioNotificationOneTimePad]().  [More...](#detailed-description)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| protected string | **[Decode](class_radio_notification_one_time_pad.md#function-decode)**(string plainText) |
| string | **[DecodeMessage](class_radio_notification_one_time_pad.md#function-decodemessage)**(string key, string cipherText) |
| protected string | **[Decrypt](class_radio_notification_one_time_pad.md#function-decrypt)**(string key, string cipherText) |
| protected string | **[Encode](class_radio_notification_one_time_pad.md#function-encode)**(string plainText) |
| string | **[EncodeMessage](class_radio_notification_one_time_pad.md#function-encodemessage)**(int padIndex, string plainText) |
| protected string | **[Encrypt](class_radio_notification_one_time_pad.md#function-encrypt)**(int padIndex, string plainText) |
| map< string, int > | **[GetAlphabetTable](class_radio_notification_one_time_pad.md#function-getalphabettable)**() |
| string | **[GetKey](class_radio_notification_one_time_pad.md#function-getkey)**(int pad, int length) |
| int | **[GetKeyFromPad](class_radio_notification_one_time_pad.md#function-getkeyfrompad)**(string codeBlock) |
| void | **[GetPad](class_radio_notification_one_time_pad.md#function-getpad)**(int pad, out int[] result) |
| string | **[GetPadText](class_radio_notification_one_time_pad.md#function-getpadtext)**() |
| void | **[GetPads](class_radio_notification_one_time_pad.md#function-getpads)**(out int[] result) |
| int | **[GetRandomPadNumber](class_radio_notification_one_time_pad.md#function-getrandompadnumber)**() |
| map< int, string > | **[GetValueTable](class_radio_notification_one_time_pad.md#function-getvaluetable)**() |
| array< string > | **[GetWordTable](class_radio_notification_one_time_pad.md#function-getwordtable)**() |
| string | **[GetWordTableText](class_radio_notification_one_time_pad.md#function-getwordtabletext)**() |
| protected int | **[Next](class_radio_notification_one_time_pad.md#function-next)**() |
| public string | **[PadIntWithZeros](class_radio_notification_one_time_pad.md#function-padintwithzeros)**(int num) |
| public string | **[PadStringWithSpaces](class_radio_notification_one_time_pad.md#function-padstringwithspaces)**(string str, int length) |
| void | **[RadioNotificationOneTimePad](class_radio_notification_one_time_pad.md#function-radionotificationonetimepad)**(int seed =123) |
| protected bool | **[isDigit](class_radio_notification_one_time_pad.md#function-isdigit)**(string c) |
| void | **[~RadioNotificationOneTimePad](class_radio_notification_one_time_pad.md#function-~radionotificationonetimepad)**() |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| const int | **[KEY_SIZE](class_radio_notification_one_time_pad.md#variable-key-size)**  |
| const int | **[PAD_SIZE](class_radio_notification_one_time_pad.md#variable-pad-size)**  |
| protected const string[TABLE_SIZE] | **[TABLE_ALPHABET](class_radio_notification_one_time_pad.md#variable-table-alphabet)**  |
| protected const int | **[TABLE_SIZE](class_radio_notification_one_time_pad.md#variable-table-size)**  |
| protected const int[TABLE_SIZE] | **[TABLE_VALUES](class_radio_notification_one_time_pad.md#variable-table-values)**  |
| protected autoptr array< string > | **[TABLE_WORDS](class_radio_notification_one_time_pad.md#variable-table-words)**  |
| const int | **[TOTAL_PAD_SIZE](class_radio_notification_one_time_pad.md#variable-total-pad-size)**  |
| protected autoptr map< string, int > | **[alphabetTable](class_radio_notification_one_time_pad.md#variable-alphabettable)**  |
| protected RadioNotifications_Trie | **[coderTrie](class_radio_notification_one_time_pad.md#variable-codertrie)**  |
| protected int[TOTAL_PAD_SIZE] | **[keyPads](class_radio_notification_one_time_pad.md#variable-keypads)**  |
| protected int | **[state](class_radio_notification_one_time_pad.md#variable-state)**  |
| protected autoptr map< int, string > | **[valueTable](class_radio_notification_one_time_pad.md#variable-valuetable)**  |

## Detailed Description

```cpp
class RadioNotificationOneTimePad;
```

Class definition for [RadioNotificationOneTimePad](). 

This class provides functionality for generating and using one-time pads for secure communication between radio devices. 

## Public Functions Documentation

### function Decode

```cpp
protected string Decode(
    string plainText
)
```


**Parameters**: 

  * **plainText** The string to be decoded. 


**Return**: The decoded string. 

Decodes a given string using a one-time pad cipher.


### function DecodeMessage

```cpp
string DecodeMessage(
    string key,
    string cipherText
)
```


**Parameters**: 

  * **key** The key used to encrypt the message. 
  * **cipherText** The encrypted message to decode. 


**Return**: The decoded message. 

Decodes a message using a one-time pad cipher.


### function Decrypt

```cpp
protected string Decrypt(
    string key,
    string cipherText
)
```


**Parameters**: 

  * **key** The one-time pad key used for decryption. 
  * **cipherText** The cipher text to be decrypted. 


**Return**: The plain text obtained after decryption. 

Decrypts a given cipher text using a one-time pad encryption scheme.


### function Encode

```cpp
protected string Encode(
    string plainText
)
```


**Parameters**: 

  * **plainText** The plain text to encode. 


**Return**: The encoded cipher text. 

Encodes the given plain text using a one-time pad cipher.


### function EncodeMessage

```cpp
string EncodeMessage(
    int padIndex,
    string plainText
)
```


**Parameters**: 

  * **padIndex** The index of the one-time pad to use for encryption. 
  * **plainText** The plain text message to encode. 


**Return**: The encoded message. 

Encodes the given plain text message using a one-time pad encryption scheme.


### function Encrypt

```cpp
protected string Encrypt(
    int padIndex,
    string plainText
)
```


**Parameters**: 

  * **padIndex** The index of the key pad to use for encryption. 
  * **plainText** The plain text to encrypt. 


**Return**: The encrypted text, including the key used for encryption. 

Encrypts the given plain text using the one-time pad encryption algorithm.


### function GetAlphabetTable

```cpp
map< string, int > GetAlphabetTable()
```


**Return**: A map that represents the alphabet table. 

Returns a map that represents the alphabet table. The keys of the map are the characters of the alphabet and the values are their corresponding integer values. 


### function GetKey

```cpp
string GetKey(
    int pad,
    int length
)
```


**Parameters**: 

  * **pad** The index of the one-time pad to use. 
  * **length** The length of the key to generate. 


**Return**: A string containing the generated key. 

Returns a key of the specified length from the given one-time pad.


### function GetKeyFromPad

```cpp
int GetKeyFromPad(
    string codeBlock
)
```


**Parameters**: 

  * **codeBlock** The code block to search for. 


**Return**: The index of the matching pad, or -1 if no match was found. 

Searches the key pads for a matching code block and returns the index of the matching pad. 


### function GetPad

```cpp
void GetPad(
    int pad,
    out int[] result
)
```


**Parameters**: 

  * **pad** The index of the pad to retrieve. 
  * **result** An array to store the retrieved pad. 


GetPad - Retrieves a one-time pad from the keyPads array.


### function GetPadText

```cpp
string GetPadText()
```


**Return**: A string representation of the one-time pad. 

Returns a string representation of the one-time pad. The one-time pad is a matrix of characters used for encryption. Each row of the matrix represents a different key pad. Each key pad is a sequence of random characters used to encrypt messages. The string representation of the one-time pad is formatted as follows: Each row of the matrix is separated by a newline character. Each key pad is separated by a space character. 


### function GetPads

```cpp
void GetPads(
    out int[] result
)
```


**Parameters**: 

  * **result** - An integer array to store the key pads.


**Remark**: This function retrieves the key pads used for one-time pad encryption and stores them in the provided integer array. The size of the array must be equal to TOTAL_PAD_SIZE. 

GetPads - Retrieves the key pads used for one-time pad encryption.


### function GetRandomPadNumber

```cpp
int GetRandomPadNumber()
```


**Return**: A random integer between 0 and PAD_SIZE - 1 (inclusive). 

Returns a random pad for encoding.


### function GetValueTable

```cpp
map< int, string > GetValueTable()
```


**Return**: A map of integer values to string values representing the one-time pad. 

Returns a map of integer values to string values. The integer values represent the index of the string in the one-time pad. The string values represent the one-time pad values.


### function GetWordTable

```cpp
array< string > GetWordTable()
```


**Return**: An array of strings representing a word table. 

Returns an array of strings representing a word table.


### function GetWordTableText

```cpp
string GetWordTableText()
```


**Return**: The text of the word table. 

Returns the text of the word table.


### function Next

```cpp
protected int Next()
```


**Return**: The next pseudo-random number in the sequence. 

Generates a predictable pseudo-random number between 0 and 9 using a linear congruential generator algorithm. 


### function PadIntWithZeros

```cpp
public string PadIntWithZeros(
    int num
)
```


**Parameters**: 

  * **num** The integer to pad with zeros. 


**Return**: The padded integer as a string. 

Pads an integer with leading zeros to ensure it has a minimum length of 4 digits.


### function PadStringWithSpaces

```cpp
public string PadStringWithSpaces(
    string str,
    int length
)
```


**Parameters**: 

  * **str** The string to pad with spaces. 
  * **length** The desired length of the padded string. 


**Return**: The padded string. 

Pad a string with spaces to a specified length. If the string is already longer than the specified length, it will be returned unchanged. 


### function RadioNotificationOneTimePad

```cpp
void RadioNotificationOneTimePad(
    int seed =123
)
```


**Parameters**: 

  * **seed** An integer value used to seed the random number generator. 


**Return**: : void 

[RadioNotificationOneTimePad](class_radio_notification_one_time_pad.md) - Generates encryption keys and performs encoding and decoding using a one-time pad algorithm. 


### function isDigit

```cpp
protected bool isDigit(
    string c
)
```


### function ~RadioNotificationOneTimePad

```cpp
void ~RadioNotificationOneTimePad()
```


## Public Attributes Documentation

### variable KEY_SIZE

```cpp
static const int KEY_SIZE = 95;
```


### variable PAD_SIZE

```cpp
static const int PAD_SIZE = 34;
```


### variable TABLE_ALPHABET

```cpp
protected const string[TABLE_SIZE] TABLE_ALPHABET = {
		"[CODE]", "A", "E", "I", "N", "T",
		"AN", "AT", "B", "C", "D", "ED", "EN", "ER", "F", "G",
		"H", "HA", "HE", "IN", "IT", "J", "K", "L", "M", "ND",
		"O", "ON", "OR", "OU", "P", "Q", "R", "RE", "S", "TH",
		"TO", "U", "V", "W", "X", "Y", "Z", " ", ".", "[FIG]"
	};
```


### variable TABLE_SIZE

```cpp
protected const int TABLE_SIZE = 46;
```


### variable TABLE_VALUES

```cpp
protected const int[TABLE_SIZE] TABLE_VALUES = {
		0, 1, 2, 3, 4, 5,
		60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
		70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
		80, 81, 82, 83, 84, 85, 86, 87, 88, 89,
		90, 91, 92, 93, 94, 95, 96, 97, 98, 99
	};
```


### variable TABLE_WORDS

```cpp
protected autoptr array< string > TABLE_WORDS;
```


### variable TOTAL_PAD_SIZE

```cpp
static const int TOTAL_PAD_SIZE = 3230;
```


### variable alphabetTable

```cpp
protected autoptr map< string, int > alphabetTable = new map<string, int>;
```


### variable coderTrie

```cpp
protected RadioNotifications_Trie coderTrie = new RadioNotifications_Trie();
```


### variable keyPads

```cpp
protected int[TOTAL_PAD_SIZE] keyPads;
```


### variable state

```cpp
protected int state = 0;
```


### variable valueTable

```cpp
protected autoptr map< int, string > valueTable = new map<int, string>;
```


-------------------------------

Updated on 2023-11-04 at 11:33:00 -0500