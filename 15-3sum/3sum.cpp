class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort the nums, iterate up the list in a for loop,
        // use 2 pointer method to generate results.
        // for loop i stops at i > 0
        // eg. [-3,-2,-1,-1,0,0,1,2,3]
        //       i  j->            <-k
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > 0 ){
                break;
            }// if i > 0 then we have no remaining combos that sum to 0
            
            if (i > 0 && nums[i] == nums[i-1]){
                continue;
            }// if i == i - 1  we skip since we dont want duplicates

            int j = i+1;
            int k = nums.size() - 1;
            
            
            while (j<k){// while the 2 pointers havent met.
                int sum = nums[i] + nums[j] + nums[k];
                
                if (sum < 0){
                    j++;
                } // if sum is small increment the lower pointer
                else if (sum > 0){
                    k--;
                } // if its too large decrement the higher pointer
                else {
                    result.push_back({nums[i],nums[j],nums[k]}); // if we found a match append to results
                    while(j<k && nums[j] == nums[j+1]){
                        j++;
                    }
                    j++;
                        // then increment the lower pointer
                }
            }
            
        }

        return result;
    }
};