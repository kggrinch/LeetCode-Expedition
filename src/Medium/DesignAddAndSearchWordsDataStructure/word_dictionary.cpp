#include "word_dictionary.h"
#include "word_dictionary.h"

WordDictionary::WordDictionary()
{
    root = new TrieNode;
}

WordDictionary:: ~WordDictionary()
{
    delete root;
}

// Time Complexity: O(n) where n is the number of characters in word
// Space Complexity: O(1)
void WordDictionary::addWord(std::string word)
{
    TrieNode* cur = root;
    for(char c : word)
    {
        if(!cur->getChild(c)) cur->setChild(c, new TrieNode());
        cur = cur->getChild(c);
    }
    cur->setIsLeaf(true);
}

// Time Complexity: O(26^m) - m = the number of . inside the word
// Space Complexity: O(n) - n - depth of the recursive tree | O(n + t) if count t as number of Trie nodes
bool WordDictionary::search(std::string word)
{
    if(!root) return false;

    TrieNode* cur = root;

    auto backtracking = [&](int i, TrieNode* cur, auto& backtracking) -> bool
    {
        if(i == word.size() && cur->getIsLeaf()) return true;
        if(word[i] == '.')
        {
            for(auto child : cur->getChildren())
            {
                if(backtracking(i + 1, child.second, backtracking)) return true;
            }
            return false;
        }
        cur = cur->getChild(word[i]);
        if(!cur) return false;
        return backtracking(i + 1, cur, backtracking);
    };

    return backtracking(0, cur, backtracking);
}

