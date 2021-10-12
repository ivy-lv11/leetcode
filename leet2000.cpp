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
    string reversePrefix(string word, char ch) {
        int index = word.find(ch);
        if(index!=string::npos)
        {
            string temp = word.substr(0,index+1);
            reverse(temp.begin(),temp.end());
            return temp+word.substr(index+1,word.size()-index-1);
        }else
            return word;

    }
};


int main()
{
    string s("1234567");
    Solution sol;
    string t = sol.reversePrefix(s,'4');
    return 0;
}