// Approach 1 - O(n+m)
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string r1 = "";
        for(int i=0;i<word1.size();i++)
        {
            r1 = r1 + word1[i];
        }

        string r2 = "";
        for(int i=0;i<word2.size();i++)
        {
            r2 = r2 + word2[i];
        }

        if(r1==r2)
        {
            return true;
        }
        return false;
    }
};



// Approach 2 - O(max(n, m))
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string r1 = "";
        string r2 = "";
        int i=0;
        while(i<word1.size() or i<word2.size())
        {
            if(i<word1.size())
            {
                r1 = r1 + word1[i];
            }
            if(i<word2.size())
            {
                r2 = r2 + word2[i];
            }
            i++;
        }

        if(r1==r2)
        {
            return true;
        }
        return false;
    }
};
