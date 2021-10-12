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
    vector<int> label;
    vector<int> certain;
    vector<int> dist;
public:
    int prim(int start)
    {
        dist[start] = 0;
        label[start] = 0;
        certain[start] =true;
        int total = 0;
        for(int time=0;time<link.size();time++)
        {
            int x = min_element(dist.begin(),dist.end())-dist.begin();
            certain[x] = true;
            label[x] = dist[x];
            total += label[x];
            dist[x] = 1e9;

            for(int i=0;i<link.size();i++)
            {
                if(link[x][i]!=-1 && certain[i]==false && link[x][i]<dist[i])
                    dist[i] = link[x][i];
            }
        }
        return total;

    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int N = points.size();
        link.resize(N);
        dist.resize(N,1e9);
        label.resize(N,1e9);
        certain.resize(N,false);
        for(int i=0;i<N;i++)
            link[i].resize(N,-1);
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                int dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                link[i][j] = dist;
                link[j][i] = dist;
            }  
        }

        return prim(0);
    }
};

int main()
{
    vector<vector<int>> t = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    Solution sol;
    sol.minCostConnectPoints(t);
    return 0;
}

