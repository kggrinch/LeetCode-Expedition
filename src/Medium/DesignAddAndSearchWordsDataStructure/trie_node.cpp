#include "trie_node.h"

TrieNode::TrieNode() : isLeaf(false)
{

}

// Recursively call deconstruct on each child
TrieNode::~TrieNode()
{
    for(auto& [ch, child] : children)
    {
        delete child;
    }
    children.clear();
}

TrieNode* TrieNode::getChild(const char& ch)
{
    auto it = children.find(ch);
    if (it != children.end()) return it->second;
    return nullptr;
}

void TrieNode::setChild(const char& ch, TrieNode* node)
{
    children[ch] = node;
}

bool TrieNode::getIsLeaf() const
{
    return isLeaf;
}

void TrieNode::setIsLeaf(bool val)
{
    isLeaf = val;
}

std::unordered_map<char, TrieNode*> TrieNode::getChildren()
{
    return children;
}