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

class Solution_linear {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        if(arr.size()<3)
            -1;
        for(int i=1;i<arr.size()-1;i++)
        {
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
                return i;
        }
        return -1;
    }
};


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        //二分查找
        int l = 0;
        int r = arr.size()-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(mid >0 && mid<arr.size()-1 && arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
                return mid;
            else if(mid >0 && mid<arr.size()-1 && arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1])
                l = mid+1;
            else if(mid >0 && mid<arr.size()-1 && arr[mid]<arr[mid-1] && arr[mid]>arr[mid+1])
                r = mid-1;
            else if(mid==0)
                l = mid+1;
            else if(mid==arr.size()-1)
                r = mid-1;
        }
        return -1;
        
    }
};


int main()
{
    vector<int> t = {3,5,3,2,0};
    Solution sol;
    int x = sol.peakIndexInMountainArray(t);
    return 0;
}