//
//  Dictionary.h
//  Problems
//
//  Created by Riabinin, Andrei on 8/17/15.
//  Copyright (c) 2015 Riabinin, Andrei. All rights reserved.
//

#ifndef __Problems__Dictionary__
#define __Problems__Dictionary__

#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iterator>
#include <cassert>
#include <unordered_map>
#include "utils.h"


using namespace std;
class PermutationDictionary
{
    unordered_set<string> permutations;
    friend ostream &operator << (ostream &os, const PermutationDictionary &dict);
public:
    //adds all permutations of a given word to the dictionary
    void addWord (const string &str)
    {
        vector<char> strvec(str.begin(), str.end());
        sort(strvec.begin(), strvec.end());
        do
        {
            permutations.emplace(string(strvec.begin(), strvec.end()));
        }while (next_permutation(strvec.begin(), strvec.end()));
    }
    
    void addWords(initializer_list<string> list)
    {
        for(auto s: list)
            addWord(s);
    }
    bool containsWord (string str)
    {
        return permutations.count(str);
    }
    
};

ostream &operator << (ostream &os, const PermutationDictionary &dict)
{
    for(auto &s : dict.permutations)
        cout << s << ";";
    
    cout << endl;
    return os;
}

void TestPermutationDictionary()
{
    PermutationDictionary dict;
    dict.addWords({"Will", "the", "real", "Slim", "Shady", "please", "stand", "up"});
    cout << dict;
    
    assert(dict.containsWord("real") == true);
    assert(dict.containsWord("earl") == true);
    assert(dict.containsWord("rale") == true);
    assert(dict.containsWord("peasle") == true);
    assert(dict.containsWord("sdkjhf") == false);
    
    
}

class SortedDictionary
{
    unordered_multimap<string, string> dictionaries;
    friend ostream &operator << (ostream &os, const SortedDictionary &dict);
public:
    
    SortedDictionary(initializer_list<string> ilist)
    {
        for (auto s : ilist)
            addWord(s);
    }
    
    void addWord(const string &str)
    {
        string copy(str);
        sort(copy.begin(), copy.end());
        dictionaries.emplace(copy, str);
    }
    
    vector<string> getAnagrams(const string &str)
    {
        string copy = str;
        sort(copy.begin(), copy.end());
        auto range = dictionaries.equal_range(copy);
        vector<string> ret;
        for (; range.first != range.second;++range.first)
            ret.push_back(range.first->second);
        return ret;
    }
    

    
};

ostream &operator << (ostream &os, const SortedDictionary &dict)
{
    for(auto &s : dict.dictionaries)
        cout << "(" << s.first << "," << s.second << "); ";
    
    cout << endl;
    return os;
}



void TestSortedDictionary()
{
    SortedDictionary dict ({"hi", "hello", "elloh", "lleho"});

    cout << dict;
    
    cout << dict.getAnagrams("ih");
    
    cout << dict.getAnagrams("hello");
    
    
    
}

#endif /* defined(__Problems__Dictionary__) */
