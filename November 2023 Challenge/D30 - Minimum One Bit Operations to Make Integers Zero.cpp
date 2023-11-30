class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n==0)
        {
            return 0;
        }
        int k = 0;
        while(static_cast<int>(pow(2, k))<=n)
        {
            k+=1;
        }

        k -= 1;
        return static_cast<int>(pow(2, k+1)) - 1 - minimumOneBitOperations(static_cast<int>(pow(2, k))^n);
    }
};
