#include <iostream>
#include "word_dictionary.h"

std::string condition(bool value)
{
    if(value) return "true";
    return "false";
}

int main()
{
    WordDictionary w;

    w.addWord("day");
    w.addWord("bay");
    w.addWord("may");

    w.search("say");
    w.search("day");
    w.search(".ay");
    std::cout << w.search("b..") << "\n";




    // w.addWord("xgvk");
    // w.addWord("wykzbvwdsoyfowqicymzd");
    // w.addWord("xajbtjyjuwgoynjgu");
    //
    // std::cout << condition(w.search("wykzbvwdso..owqicymzd")) << "\n";
    // std::cout << condition(w.search("..ha")) << "\n";
    //
    // w.addWord("qsibzxaorktypkfg");
    //
    // std::cout << condition(w.search("xgvk")) << "\n";
    //
    // w.addWord("vbycuvrkbcq");
    //
    // std::cout << condition(w.search("qsibz.aorkty.kfg")) << "\n";
    //
    // w.addWord("sm");
    // w.addWord("fkqclfmvzpzpnbvz");
    //
    // std::cout << condition(w.search("vb..uvrkbcq")) << "\n";
    //
    // w.addWord("jpnneostllnnma");
    // w.addWord("zvmtfg");
    //
    // std::cout << condition(w.search("g..")) << "\n";
    // std::cout << condition(w.search("..kqclfmvzpzpnbvz")) << "\n";


    return 0;
}
