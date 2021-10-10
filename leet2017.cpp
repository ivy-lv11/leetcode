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
using namespace std;
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int N = grid[0].size();
        vector<long long> up(N);
        vector<long long> down(N);
        up[0] = grid[0][0];
        down[0] = grid[1][0];
        for(int i=1;i<N;i++)
        {
            up[i] = up[i-1]+grid[0][i];
            down[i] = down[i-1]+grid[1][i];
        }

        long long re = min(up[N-1]-up[0],down[N-2]);
        for(int i=1;i<N-1;i++)
        {
            long long temp = max(down[i-1],up[N-1]-up[i]);
            re = min(re,temp);
        }
        return re;
        
    }
};

int main()
{
    vector<vector<int>> grid = {{3,3,1},{8,5,2}};
    Solution sol;
    int x = sol.gridGame(grid);
    return 0;
}