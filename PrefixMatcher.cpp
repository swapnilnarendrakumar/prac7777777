// Dai(a1837470), Dil(a1825200), Swapnil(a1848855), Duong(a1876928)
#include "PrefixMatcher.h"

RouterNode::RouterNode() {
    routerNumber = -1;
    children[0] = nullptr;
    children[1] = nullptr;
}

PrefixMatcher::PrefixMatcher() {
    root = new RouterNode();
}

void PrefixMatcher::insert(string address, int routerNum) {
    insert(address, root, routerNum, 0);
}

void PrefixMatcher::insert(const string& address, RouterNode* node, int routerNum, int index) {
    // If it is the end of the string then make the leaf true
    if (index == address.length()) {
        node->routerNumber = routerNum;
        return;
    }

    // Find out what the first letter is
    // This gives the index, for example, if word[0] is 'b'then doing
    // word[0] - 'a' = 1, which is the second position in the alphabet
    int bit = address[index] - '0';

    // Check if the pointer at that is nullptr then make a new TrieNode
    // Otherwise it means that there is a word there already 
    if (node->children[bit] == nullptr) {
        node->children[bit] = new RouterNode();
    }

    // Using recursion until inserting the entire word
    insert(address, node->children[bit], routerNum, index + 1);
}

int PrefixMatcher::selectRouter(string networkAddress) {
    RouterNode* currNode = root;
    int longestMatchingRouter = -1;

    for (int i = 0; i < networkAddress.length(); i++) {
        int index = networkAddress[i] - '0';

        if (currNode->children[index] == nullptr) {
            // If there is no more matching prefixes, exit the loop
            break;
        }

        currNode = currNode->children[index];

        if (currNode->routerNumber != -1) {
            longestMatchingRouter = currNode->routerNumber;
        }
    }
    return longestMatchingRouter;
}
