class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int smallest = INT_MAX, secondSmallest = INT_MAX;

        for(int n: prices)
        {
            if(n<smallest)
            {
                secondSmallest = smallest;
                smallest = n;
            }
            else
            {
                secondSmallest = min(secondSmallest, n);
            }
        }

        int leftover = money - (smallest + secondSmallest);

        if(leftover>=0)
        {
            return leftover;
        }
        return money;
    }
};
