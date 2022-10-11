// Problem Link: https://leetcode.com/problems/divide-two-integers/

// Explanation: As the input of divident and divisor may be greater than int range (i.e out of int range), so we have to change the input datatype of the divide function from int to long long. This is the keypoint of this question, nothing else special is there in this question.

class Solution {
public:
    int divide(long long dividend, long long divisor) {
        long long result;
        int ans;
        result = dividend / divisor;
        if(result < INT_MIN)
        {
            return INT_MIN;
        }
        else if(result > INT_MAX)
        {
            return INT_MAX;
        }
        else
        {
            ans = result;
            return ans;
        }
    }
};