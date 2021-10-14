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

struct Node{
    int id;
    int dist;
    Node(int x,int d):id(x),dist(d){}
    bool operator<(const Node& node) const
    {
        return dist>node.dist;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> link(n+1,vector<int>(n+1,-1));
        for(auto v:times)
        {
            int x = v[0];
            int y =v[1];
            int  w = v[2];
            link[x][y] = w;
        }

        vector<int> label(n+1,1e9);
        vector<bool> certain(n+1,false);

        int INF = 1e9;
        priority_queue<Node> pq;
        for(int i=1;i<=n;i++)
        {
            Node node(i,INF);
            if(i==k)
                node.dist = 0;
            pq.push(node);
        }

        while(pq.empty()==false)
        {
            while(!pq.empty()&&certain[pq.top().id])
                pq.pop();
            if(pq.empty())
                break;
            Node src = pq.top();
            pq.pop();
            int id = src.id;
            int dist = src.dist;
            label[id] = dist;
            certain[id] = true;

            for(int i=1;i<=n;i++)
            {
                if(link[id][i]!=-1 && label[i]>label[id]+link[id][i])
                {
                    Node node(i,label[id]+link[id][i]);
                    pq.push(node);
                }
            }
        }
        return *max_element(label.begin()+1,label.end())==INF?-1:*max_element(label.begin()+1,label.end());

        
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> t = {{3,4,1},{2,1,1},{2,3,1}};
    sol.networkDelayTime(t,4,2);
    return 0;
}

