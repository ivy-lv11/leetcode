#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;

class Solution {
    vector<vector<int>> dic = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<bool>> visit;
    int N,M;
public:
    bool dfs(vector<vector<char>>& grid,int i,int j)
    {
        visit[i][j] = true;
        for(auto v:dic)
        {
            int x = i+v[0];
            int y = j+v[1];
            if(x>=0 && y>=0 && x<N && y<M && !visit[x][y] && grid[x][y]=='1')
                dfs(grid,x,y);
        }
        return true;
    }
    int numIslands(vector<vector<char>>& grid) {
        N = grid.size();
        M= grid[0].size();
        int total = 0;
        visit.resize(N);
        for(int i=0;i<N;i++)
            visit[i].resize(M);
        
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(grid[i][j]=='1' && !visit[i][j])
                {
                    total += 1;
                    dfs(grid,i,j);
                }
            }
        }
        return total;
    }
};

int main()
{
    vector<vector<char>> grid = {{'1','1','1','0'},{'0','0','0','0'},{'1','0','0','0'}};
    Solution sol;
    int x = sol.numIslands(grid);
    return 0;
}