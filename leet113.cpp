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
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
      vector<vector<int> > re;
      vector<vector<int> > t = get(root);
      for(int i=0;i<t.size();i++)
      {
        vector<int> v = t[i];
        if(accumulate(v.begin(),v.end(),0)==sum)
          re.push_back(v);
      }
      return re;
        
    }
    vector<vector<int> > get(TreeNode* root)
    {
      vector<vector<int> > re;
      if(root==NULL)
        return re;
      int val = root->val;
      if(root->left==NULL && root->right==NULL)
      {
        vector<int> t;
        t.push_back(val);
        re.push_back(t);
        return re;
      }
      
      vector<vector<int> > left = get(root->left);
      vector<vector<int> > right = get(root->right);
      for(int i=0;i<left.size();i++)
      {
        vector<int> v = left[i];
        vector<int> temp;
        temp.push_back(val);
        for(int j=0;j<v.size();j++)
        {
          temp.push_back(v[j]);
        }
          
        re.push_back(temp);
      }
      for(int i=0;i<right.size();i++)
      {
        vector<int> v = right[i];
        vector<int> temp;
        temp.push_back(val);
        for(int j=0;j<v.size();j++)
        {
          temp.push_back(v[j]);
        }
        re.push_back(temp);
      }
      return re;
    }
};
