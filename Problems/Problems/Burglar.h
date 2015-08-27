//
//  Burglar.h
//  Problems
//
//  Created by Riabinin, Andrei on 8/19/15.
//  Copyright (c) 2015 Riabinin, Andrei. All rights reserved.
//

#ifndef Problems_Burglar_h
#define Problems_Burglar_h

/** There is a set of houses on the street, the 'loot' gained from each valued at a different rate. The burglar cannot steal from two houses next to each other. Determine the optimal set of houses to steal from. */
#include "utils.h"


class Burglar
{
    typedef pair<vector<int>, int> Solution;
public:
    typedef vector<int> Street;
    static Solution optimalHeist(const Street &street)
    {
        Solution curminus1, curminus2;
       
        
        for ( auto it = street.begin(); it != street.end(); ++it)
        {
            if(curminus2.second + *it > curminus1.second )
            {
                addHouse(street, static_cast<int>(it-street.begin()), curminus2);
                swap(curminus1, curminus2);
            }
            else
            {
                curminus2 = curminus1;
            }
            
        }
        return curminus1.second > curminus2.second? curminus1:curminus2;
    }
    
private:
    static void addHouse (const Street &street, int index, Solution &sol)
    {
        sol.first.push_back(index);
        sol.second += street[index];
    }
};


void TestBurglar()
{
    
    cout << Burglar::optimalHeist({}) << endl;
    cout << Burglar::optimalHeist({100}) << endl;
    cout << Burglar::optimalHeist({100, 1000}) << endl;
    cout << Burglar::optimalHeist({100, 1000, 100}) << endl;
    cout << Burglar::optimalHeist({1000, 100, 100, 1000}) << endl;
    cout << Burglar::optimalHeist({100, 1000, 100, 1000}) << endl;
    cout << Burglar::optimalHeist({100, 1000, 100, 100,  1000, 100, 100,  1000, 100, 100,  1000, 100, 100,  1000, 100, 100,  1000}) << endl;
    
    
}


#endif
