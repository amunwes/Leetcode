class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int temp;
        int first = cost[n-2];
        int second = cost[n-1];
        for (int i = n-3; 0<=i; i--){
            temp = first;
            first = cost[i] + min(first,second);
            second = temp;
        } 
        return min(first,second);
    }
};