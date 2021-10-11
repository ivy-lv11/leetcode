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
    int jump(vector<int>& nums) {
        int INF = 1e9;
        int N = nums.size();
        vector<int> dp(N,INF);
        dp[0] = 0;
        for(int i=1;i<N;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(j+nums[j]>=i)//within reach
                {
                    dp[i] = min(dp[i],dp[j]+1);
                }
            }
        }
        return dp[N-1];
    }
};

int main()
{
    vector<int> grid = {2,3,1,1,4};
    Solution sol;
    int x = sol.jump(grid);

    return 0;
}