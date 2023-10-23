// Approach 1 - Recursion
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1) 
        {
            return true;
        }
        if(n<=0 || n%4!=0)
        {
            return false;
        }
        return isPowerOfFour(n/4);
    }
}; 


// Approach 2 - Log
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n>0 && fmod(log(n)/log(4), 1.0)==0;
    }
};
