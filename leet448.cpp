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
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int N = nums.size();
        vector<int> re;
        for(int i=0;i<N;i++)
        {
            while(nums[i]!=nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
        }
        for(int i=0;i<N;i++)
            if(nums[i]!=i+1)
                re.push_back(i+1);
        return re;
    }
};