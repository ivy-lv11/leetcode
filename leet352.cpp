#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;

class SummaryRanges {
    map<int,int> dic;
public:
    SummaryRanges() {
        ;
    }
    
    void addNum(int val) {
        bool flag_inside = false;
        bool flag_outside = false;
        bool flag_continue  = false;
        for(auto v:dic)
        {
            int l = v.first;
            int r = v.second;
            if((l<=val) && (r>=val))
            {
                flag_inside = true;
                return;
            }
            else if((val==l-1)||(val==r+1))
            {
                flag_continue = true;
                if(val==l-1)
                {
                    dic.erase(l);
                    int flag_concat = -1;
                    for(auto u:dic)
                    {
                        if(u.second==val-1)
                        {
                            flag_concat = u.first;
                            dic.erase(u.first);
                            break;
                        }
                    }
                    if(flag_concat!=-1)
                    {
                        dic[flag_concat] = r;
                    }
                    else
                        dic[val] = r;
                    return;
                }
                else if(val==r+1)
                {
                    dic.erase(l);
                    int flag_concat = -1;
                    for(auto u:dic)
                    {
                        if(u.first==val+1)
                        {
                            flag_concat = u.second;
                            dic.erase(u.first);
                            break;
                        }
                    }
                    if(flag_concat!=-1)
                    {
                        dic[l] = flag_concat;
                        
                    }
                    else
                        dic[l] = val;
                    return;
                }
            }
            
        }
        dic[val] = val;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> re;
        for(auto v:dic)
        {
            vector<int> t = {v.first,v.second};
            re.emplace_back(t);
        }
        return re;
    }
};

int main()
{
    SummaryRanges sr;
    sr.addNum(1);
    sr.getIntervals();
    sr.addNum(3);
    sr.getIntervals();
    sr.addNum(7);
    sr.getIntervals();
    sr.addNum(2);
    sr.addNum(6);
    return 0;
    
}