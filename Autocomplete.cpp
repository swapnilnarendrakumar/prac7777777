// Dai(a1837470), Dil(a1825200), Swapnil(a1848855), Duong(a1876928)
#include "Autocomplete.h"

TrieNode::TrieNode() {
    isEndOfWord = false;

    children = vector<TrieNode*>(26, nullptr);
}

Autocomplete::Autocomplete() {
    root = new TrieNode();
}

void Autocomplete::insert(string word) {
    insert(word, root, 0);
}

void Autocomplete::insert(const string& word, TrieNode* node, int index) {
    // If it is the end of the string then make the leaf true
    if (index == word.length()) {
        node->isEndOfWord = true;
        return;
    }

    // Find out what the first letter is
    // This gives the index, for example, if word[0] is 'b'then doing
    // word[0] - 'a' = 1, which is the second position in the alphabet
    int childIndex = word[index] - 'a';

    // Check if the pointer at that is nullptr then make a new TrieNode
    // Otherwise it means that there is a word there already 
    if (node->children[childIndex] == nullptr) {
        node->children[childIndex] = new TrieNode();
    }

    // Using recursion until inserting the entire word
    insert(word, node->children[childIndex], index + 1);
}

vector<string> Autocomplete::getSuggestions(string partialWord) {
    TrieNode* currNode = root;

    for (int i = 0; i < partialWord.length(); i++) {
        if (currNode->children[partialWord[i] - 'a'] == nullptr) {
            // Check is there is no suggestion to be found at the index
            return {}; //then return empty
        }

        // Move to the next letter in the string and check
        currNode = currNode->children[partialWord[i] - 'a'];
    }

    // When finish the partialWord and there are still suggestion
    vector<string> suggested_string;
    collectSuggestions(currNode, partialWord, suggested_string);
    return suggested_string;
}

void Autocomplete::collectSuggestions(TrieNode* node, string current, vector<string>& suggested_string) {
    // If the node is endOfWord then this is the suggestion and add the string to suggested_string
    if (node->isEndOfWord == true) {
        suggested_string.push_back(current);
    }

    for (int i = 0; i < 26; i++) {
        if (node->children[i] != nullptr) {
            // If there are still word
            collectSuggestions(node->children[i], current + char('a' + i), suggested_string);
        }
    }
}
