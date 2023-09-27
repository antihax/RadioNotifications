---
title: RadioNotifications_TrieNode

---

# RadioNotifications_TrieNode



 [More...](#detailed-description)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| void | **[Insert](class_radio_notifications___trie_node.md#function-insert)**(string key, string code) |
| void | **[RadioNotifications_TrieNode](class_radio_notifications___trie_node.md#function-radionotifications-trienode)**() |
| string | **[Search](class_radio_notifications___trie_node.md#function-search)**(string key) |
| void | **[~RadioNotifications_TrieNode](class_radio_notifications___trie_node.md#function-~radionotifications-trienode)**() |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| ref map< string, [RadioNotifications_TrieNode](class_radio_notifications___trie_node.md) > | **[m_Children](class_radio_notifications___trie_node.md#variable-m-children)**  |
| string | **[m_Code](class_radio_notifications___trie_node.md#variable-m-code)**  |
| string | **[m_Value](class_radio_notifications___trie_node.md#variable-m-value)**  |

## Detailed Description

```cpp
class RadioNotifications_TrieNode;
```


Represents a node in a trie data structure used by the RadioNotifications engine to store and search for keywords. 

## Public Functions Documentation

### function Insert

```cpp
void Insert(
    string key,
    string code
)
```


**Parameters**: 

  * **key** The key to insert. 
  * **code** The value to associate with the key. 


Inserts a new key-value pair into the trie.


### function RadioNotifications_TrieNode

```cpp
void RadioNotifications_TrieNode()
```


### function Search

```cpp
string Search(
    string key
)
```


**Parameters**: 

  * **key** The key to search for in the trie. 


**Return**: The string associated with the given key, or an empty string if the key is not found.

**Note**: 

  * This function assumes that the trie has been initialized and populated with data. 
  * The returned string is owned by the trie and should not be modified or freed by the caller. 


Searches for a given key in the trie data structure.


### function ~RadioNotifications_TrieNode

```cpp
void ~RadioNotifications_TrieNode()
```


## Public Attributes Documentation

### variable m_Children

```cpp
ref map< string, RadioNotifications_TrieNode > m_Children;
```


### variable m_Code

```cpp
string m_Code;
```


### variable m_Value

```cpp
string m_Value;
```


-------------------------------

Updated on 2023-09-27 at 14:30:58 -0500