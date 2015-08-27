//
//  utils.h
//  Problems
//
//  Created by Riabinin, Andrei on 8/20/15.
//  Copyright (c) 2015 Riabinin, Andrei. All rights reserved.
//

#ifndef Problems_utils_h
#define Problems_utils_h
#include <utility>
#include <vector>
#include <iostream>

using namespace std;

template <class T>
ostream &operator << (ostream &os, const vector<T> v)
{
    cout << "(";
    for(auto &s : v)
        cout << s << ", " ;
    
    cout << ")";
    return os;
}

template <class T, class U>
ostream & operator << (ostream &os, pair<T, U> p)
{
    os << "(" << p.first << "," << p.second << ")";
    return os;
}


#endif
