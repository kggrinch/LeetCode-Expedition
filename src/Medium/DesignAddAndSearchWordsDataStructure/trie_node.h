#ifndef TRIE_NODE_H
#define TRIE_NODE_H
#include <unordered_map>



class TrieNode
{

public:
    TrieNode();
    ~TrieNode();

    TrieNode* getChild(const char& ch);
    void setChild(const char& ch, TrieNode* node);
    bool getIsLeaf() const;
    void setIsLeaf(bool val);

    std::unordered_map<char, TrieNode*> getChildren();

private:
    // hashmap holds TrieNodes of existing characters
    std::unordered_map<char, TrieNode*> children;

    // Used for indicating ending of string
    bool isLeaf;
};



#endif //TRIE_NODE_H
