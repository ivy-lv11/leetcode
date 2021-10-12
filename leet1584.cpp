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

struct Edge{
    int u,v;
    int w;
    Edge(int x,int y,int z):u(x),v(y),w(z){}
    bool operator< (const Edge& e) const
    {
        return w<e.w;
    }
};


class Solution {
    vector<int> parent;
public:
    int find_parent(int id)
    {
        return parent[id]==id?id:find_parent(parent[id]);
    }
    void unify(int x,int y)
    {
        parent[find_parent(x)] = y;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int N = points.size();
        vector<Edge> vec;
        parent.resize(N);
        for(int i=0;i<N;i++)
            parent[i] = i;
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                int dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                //link[i][j] = dist;
                //link[j][i] = dist;
                Edge edge(i,j,dist);
                vec.emplace_back(edge);
            }  
        }
        sort(vec.begin(),vec.end());

        int re = 0;
        for(auto e:vec)
        {
            int u = e.u;
            int v = e.v;
            if(find_parent(u)!=find_parent(v))
            {unify(u,v);
                re += e.w;
            }
                
        }
        return re;

        
        
    }
};

int main()
{
    vector<vector<int>> t = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    Solution sol;
    sol.minCostConnectPoints(t);
    return 0;
}