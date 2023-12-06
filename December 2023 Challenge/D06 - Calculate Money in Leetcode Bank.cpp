class Solution {
public:
    int totalMoney(int n) {
        int week_count = n/7;
        int money = week_count*28;
        money += (7*week_count*(week_count-1))/2;

        if(n%7)
        {
            int extra_days = n%7;
            int money_to_add = week_count + 1;
            for(int i=0;i<extra_days;i++)
            {
                money += money_to_add;
                money_to_add += 1;
            }
        }

        return money;
    }
};
