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
#include <sstream>
using namespace std;

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<k;i++)
        {
            istringstream is(nums[i]);
            int k;
            is>>k;
            pq.push(k);
        }
        
        for(int i=k;i<nums.size();i++)
        {
            int number = atoi(nums[i].c_str());
            if(number<pq.top())
                continue;
            else
            {
                pq.pop();
                pq.push(number);
            }
        }
        int x = pq.top();
        char buf[10];
        sprintf(buf,"%d",x);
        return string(buf);
    }
};

int main()
{
    vector<string> t  = {"577725","387","908","2","1","3312038","60997700","960084840","721182339","554615679","4410","76","9700217","6918033","8401489025"};
    Solution sol;
    string re = sol.kthLargestNumber(t,1);
    return 0;
}