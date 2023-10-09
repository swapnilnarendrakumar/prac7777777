// Dai(a1837470), Dil(a1825200), Swapnil(a1848855), Duong(a1876928)
#include <vector>
#include <string>

using namespace std;

struct TrieNode {
    // TrieNode* children[26];
    bool isEndOfWord;
    vector<TrieNode *> children;
    TrieNode();
};

class Autocomplete {
private:
    TrieNode* root;
    void insert(const string& word, TrieNode* node, int index);
    void collectSuggestions(TrieNode* node, string current, vector<string>& results);

public:
    Autocomplete();
    vector<string> getSuggestions(string partialWord);  // return the known words that start with partialWord
    void insert(string word); // add a word to the known words

};
