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
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<double,int> cnt;
        for(auto v:rectangles)
        {
            double x = (double)v[0]/v[1];
            cnt[x]+=1;
        }
        int total = 0;
        for(auto v:cnt)
            total += v.second*(v.second-1)/2;
        return total;
    }
};


int main()
{

}