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
 * Represents a node in a trie data structure used by the RadioNotifications engine to store and search for keywords.
 */
class RadioNotifications_TrieNode {
	string m_Value;
	string m_Code;
	ref map<string, RadioNotifications_TrieNode> m_Children;

	void RadioNotifications_TrieNode() {
		m_Value = "";
		m_Code = "";
		m_Children = new map<string, RadioNotifications_TrieNode>;
	}

	void ~RadioNotifications_TrieNode() {
		delete m_Children;
	}

	/**
	 * Inserts a new key-value pair into the trie.
	 *
	 * @param key The key to insert.
	 * @param code The value to associate with the key.
	 */
	void Insert(string key, string code) {
		RadioNotifications_TrieNode current = this;
		for (int len = 1; len <= key.Length(); len++) {
			string subKey = key.Substring(0, len);
			for (int j = 0; j < subKey.Length(); j++) {
				string character = subKey.Get(j);
				if (!current.m_Children.Contains(character)) {
					current.m_Children.Insert(character, new RadioNotifications_TrieNode);
				}
				current = current.m_Children.Get(character);
			}
			current.m_Value = subKey;

			if (len == key.Length())
				current.m_Code = code;
			else if (current.m_Code == "")
				current.m_Code = "-";

			current = this;
		}
	}

	/**
	 * Searches for a given key in the trie data structure.
	 * 
	 * @param key The key to search for in the trie.
	 * @return The string associated with the given key, or an empty string if the key is not found.
	 * 
	 * @note This function assumes that the trie has been initialized and populated with data.
	 * @note The returned string is owned by the trie and should not be modified or freed by the caller.
	 */
	string Search(string key) {
		RadioNotifications_TrieNode current = this;
		for (int i = 0; i < key.Length(); i++) {
			string character = key.Get(i);
			if (!current.m_Children.Contains(character)) {
				return "";
			}
			current = current.m_Children.Get(character);
		}
		return current.m_Code;
	}
}

class RadioNotifications_Trie {
	private RadioNotifications_TrieNode m_root;

	void RadioNotifications_Trie() {
		m_root = new RadioNotifications_TrieNode;
	}

	/**
	 * Inserts a key-value pair into the trie.
	 * 
	 * @param key The key to be inserted.
	 * @param code The value to be associated with the key.
	 */
	void Insert(string key, string code) {
		m_root.Insert(key, code);
	}

	/**
	 * Searches for a given key in the trie.
	 * 
	 * @param key The key to search for in the trie.
	 * @return The string associated with the given key, or an empty string if the key is not found.
	 */
	string Search(string key) {
		return m_root.Search(key);
	}
}
