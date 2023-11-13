
class Solution {
public:
    string sortVowels(string s) {
        int n = s.length();
        vector<char> v;
        // vector<int> ind;
        for(char c: s)
        {
            if(string("aeiouAEIOU").find(c)!=string::npos)
            {
                v.push_back(c);
            }
        }
        sort(v.begin(), v.end(), greater<char>());
        string result;
        for(char c: s)
        {
            if(string("aeiouAEIOU").find(c)!=string::npos)
            {
                result += v.back();
                v.pop_back();
            }
            else
            {
                result+=c;
            }
        }
        return result;
    }
};
