#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <set>
#include <queue>
#include <map>
#include <numeric>
#include <stack>
#include <cmath>
#include <assert.h>
#include <cstdio>
using namespace std;
// namespace std;

struct TreeNode{
    char ch;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char id, TreeNode* l=NULL, TreeNode* r = NULL):ch(id),left(l),right(r) {}
};

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> dict;
        vector<string> re;
        if(s.size()<=10)
            return re;
        for(int i=0;i<s.size()-9;i++){
            dict[s.substr(i,10)] += 1;
        }
        for(auto v:dict)
        {
            if(v.second>1)
                re.emplace_back(v.first);
        }
        return re;
        
    }
};

int main()
{
    Solution sol;
    sol.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCC");
    return 0;
}