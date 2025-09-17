#ifndef WORD_DICTIONARY_H
#define WORD_DICTIONARY_H
#include "trie_node.h"
#include <string>



class WordDictionary
{

public:
    WordDictionary();

    ~WordDictionary();

    void addWord(std::string word);

    bool search(std::string word);

private:
    TrieNode* root;
};



#endif //WORD_DICTIONARY_H
