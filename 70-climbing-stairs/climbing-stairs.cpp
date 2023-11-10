class Solution {
public:
    int climbStairs(int n) {
        int one = 1;
        int two = 1;
        int result = 1;
        if (n<2){
            return result;
        }
        for (int i = 1; i<n; i++){
            result = one+two;
            two = one;
            one = result;
        }
        return result;
    }
};