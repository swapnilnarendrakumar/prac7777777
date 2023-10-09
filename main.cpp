// Dai(a1837470), Dil(a1825200), Swapnil(a1848855), Duong(a1876928)
#include <iostream>
#include "Autocomplete.h"
#include "PrefixMatcher.h"

int main() {
    // Testing the Autocomplete class
    cout << "Testing Autocomplete:\n";
    Autocomplete autocomplete;
    autocomplete.insert("bin");
    autocomplete.insert("ball");
    autocomplete.insert("ballet");

    vector<string> suggestions;

    suggestions = autocomplete.getSuggestions("b");
    for (const string& word : suggestions) cout << word << " ";
    cout << endl; // Expected: bin ball ballet

    suggestions = autocomplete.getSuggestions("ba");
    for (const string& word : suggestions) cout << word << " ";
    cout << endl; // Expected: ball ballet

    suggestions = autocomplete.getSuggestions("bal");
    for (const string& word : suggestions) cout << word << " ";
    cout << endl; // Expected: ball ballet

    suggestions = autocomplete.getSuggestions("balle");
    for (const string& word : suggestions) cout << word << " ";
    cout << endl; // Expected: ballet

    // Testing the PrefixMatcher class
    cout << "\nTesting PrefixMatcher:\n";
    PrefixMatcher matcher;
    matcher.insert("1100110111", 1);
    matcher.insert("110011011", 2);
    matcher.insert("11001101", 3);

    cout << "Router for 110011011001: " << matcher.selectRouter("110011011001") << endl; // Expected: 2
    cout << "Router for 110011010010: " << matcher.selectRouter("110011010010") << endl; // Expected: 3
    cout << "Router for 110011111111: " << matcher.selectRouter("110011111111") << endl; // Expected: 1

    return 0;
}
