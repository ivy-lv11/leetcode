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

/*
原地哈希：哈希函数可以看作是把nums[i]交换到nums[i]-1位置上
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();
        for(int i=0;i<N;i++)
        {
            while(nums[i]>0 && nums[i]<=N && nums[i]!=nums[nums[i]-1])
            {
                swap(nums[i],nums[nums[i]-1]);
            }
        }

        for(int i=0;i<N;i++)
        {
            if(nums[i]!=i+1)
                return i+1;
        }
        return N+1;
    }
};


int main()
{
    vector<int> t = {3,4,-1,1,9,-5};
    Solution sol;
    int x = sol.firstMissingPositive(t);
    return 0;
}