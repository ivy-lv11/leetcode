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
    map<char,int> dic;
public:
    int check(vector<string>& words,int n,vector<char>& letters,vector<int>& score)
    {
        map<char,int> temp = dic;
        int total = 0;
        for(int i=0;i<words.size();i++)
        {
            int mode = 1<<i;
            if(((mode & n)>>i)==1)
            {
                //exist
                int N = words.size();
                for(auto ch:words[N-1-i])
                {
                    temp[ch] --;
                    total += score[ch-'a'];
                    if(temp[ch]<0)
                        return -1;
                }
            }
        }
        return total;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int N = words.size();
        int re = -1;
        for(auto v:letters)
            dic[v]+= 1;
        for(int i=1;i<(1<<N);i++)
        {
                re = max(re,check(words,i,letters,score));
        }
        return re;
    }
};

int main()
{
    Solution sol;
    vector<string> words = {"dog","cat","dad","good"};
    vector<char> letters = {'a','a','c','d','d','d','g','o','o'};
    vector<int> score = {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
    int re = sol.maxScoreWords(words,letters,score);
    return 0;
}