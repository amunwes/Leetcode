class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool flag = false;
        unordered_map<int, int> hashmap;
        for (auto i : nums) hashmap[i]++;
        
        for (auto i : hashmap){
            if(i.second >= 2) flag = true;
        }


        return flag;
    }
};