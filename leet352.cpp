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
        auto intervall1 = dic.upper_bound(val);
        auto intervall0 = intervall1==dic.begin()?dic.end():prev(intervall1);
        if(intervall0!=dic.end() && intervall0->first<=val && val<=intervall0->second)
            return;
        else {
            bool left_side = intervall0!=dic.end() && intervall0->second==val-1;
            bool right_side = intervall1!=dic.end() && intervall1->first==val+1;
            if(left_side && right_side)
            {
                int new_start = intervall0->first;
                int new_end = intervall1->second;
                dic.erase(intervall1);
                dic.erase(intervall0);
                dic[new_start]= new_end;
            }
            else if(left_side)
            {
                intervall0->second ++;
            }
            else if(right_side)
            {
                int new_end = intervall1->second;
                dic.erase(intervall1);
                dic[val] = new_end;
            }
            else
                dic[val] = val;
        }
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