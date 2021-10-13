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
    vector<vector<int>> link;
    vector<int> order;
    vector<int> visit;
public:
    int dfs(int start)
    {
        visit[start]= 1;
        for(auto v:link[start])
        {
            if(visit[v]==false)
            {
                int x = dfs(v);
                if(x==-1)
                    return -1;
            }
            else if(visit[v]==1)
                return -1;
            else if(visit[v]==2)
                continue;
        }
        visit[start] = 2;
        order.push_back(start);
        return 0;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        link.resize(numCourses);
        visit.resize(numCourses,false);
        if(prerequisites.empty())
        {
            for(int i=numCourses-1;i>=0;i--)
                order.push_back(i);
            return order;
        }
        for(auto v:prerequisites)
        {
            int u = v[1];
            int d = v[0];
            link[u].push_back(d);
        }
        
        for(int i=0;i<numCourses;i++)
        {
            if(visit[i]==0)
            {
                if(dfs(i)==-1)
                {
                    vector<int> re;
                    return re;
                } 
            }
                
        }
        reverse(order.begin(),order.end());
        return order;
    }
};


int main()
{

}