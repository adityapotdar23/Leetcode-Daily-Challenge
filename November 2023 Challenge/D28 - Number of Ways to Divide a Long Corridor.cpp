// Approach 1 
class Solution {
public:
    int numberOfWays(string corridor) {
        int mod = 1e9+7;
        int n = corridor.size();
        vector<vector<int>> cache;
        for(int i=0;i<n;i++)
        {
            cache.push_back({-1, -1, -1});
        }

        function<int(int, int)> dfs = [&](int i, int seats)
        {
            if(i==n)
            {
                if(seats==2)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            if(cache[i][seats]!=-1)
            {
                return cache[i][seats];
            }

            int res = 0;
            if(seats==2)
            {
                if(corridor[i]=='S')
                {
                    res = dfs(i+1, 1);
                }
                else
                {
                    res = (dfs(i+1, 0) + dfs(i+1, 2))%mod;
                }
            }
            else
            {
                if(corridor[i]=='S')
                {
                    res = dfs(i+1, seats+1);
                }
                else
                {
                    res = dfs(i+1, seats);
                }
            }

            cache[i][seats] = res;
            return res;
        };

        return dfs(0, 0);
    }
};


// Approach 2
class Solution {
public:
    int numberOfWays(string corridor) {
        int mod = 1e9+7;

        vector<int> seats;
        int n = corridor.size();

        for(int i=0;i<n;i++)
        {
            if(corridor[i]=='S')
            {
                seats.push_back(i);
            }
        }

        int l =seats.size();
        if(l<2 or l%2==1)
        {
            return 0;
        }

        long long res = 1;
        int i = 1;
        while(i<l-1)
        {
            res = (res * (seats[i+1]-seats[i]))%mod;
            i += 2;
        }
        return static_cast<int>(res%mod);
    }
};
