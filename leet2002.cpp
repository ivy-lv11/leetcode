#include <stdio.h>
#include <string.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <functional>
#include <cmath>
#include <set>
#include <map>
#include <assert.h>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool check(int num,string s)
    {
        string re;
        for(int i=0;i<s.size();i++)
        {
            int mode = 1<<i;
            if(((num & mode)>>i) == 1)
            {
                re += s[i];
            }
        }
        string temp = re;
        reverse(temp.begin(),temp.end());
        return temp==re;
    }
    int maxProduct(string s) {
        int n = s.size();
        int upper_bound = 1<<n;
        vector<pair<int,int> > list;
        for(int i=1;i<upper_bound;i++)
        {
            if(check(i,s))
                list.emplace_back(pair<int,int>(i,__builtin_popcount(i)));
        }

        int re = -1;
        int a,b;
        for(int i=0;i<list.size();i++)
        {
            for(int j=i+1;j<list.size();j++)
            {
                if((list[i].first & list[j].first)==0)
                {
                    re = max(re,list[i].second*list[j].second);
                    a = list[i].first;
                    b = list[j].first;
                }
            }
        }
        cout<<a<<" "<<b<<" "<<re << endl;
        return re;
    }

};


int main()
{
    string x = "leetcodecom";
    Solution sol;
    int t = sol.maxProduct(x);
    return 0;
}