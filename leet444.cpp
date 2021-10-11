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
    vector<int> findDuplicates(vector<int>& nums) {
        int N = nums.size();
        vector<int> re;
        set<int> temp;
        for(int i=0;i<N;i++)
        {
            while(nums[i]!=nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
            if(nums[i]!=i+1 && temp.find(nums[i])==temp.end())
            {
                temp.insert(nums[i]);
                re.push_back(nums[i]);
            }
        }
        return re;
    }
};

int main()
{
    vector<int>t = {4,3,2,7,8,2,3,1};
    Solution sol;
    sol.findDuplicates(t);
    return 0;
}