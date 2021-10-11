class Solution {
    
public:
    int arrangeCoins(int n) {
        int total = 0;
        int k = 0;
        while(total<n)
        {
            k++;
            total += k;
        }
        return k;
    }
};