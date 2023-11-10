class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //edge case of empty array being passed
        if (nums.size()==0) 
            return 0;
        // sort the vector into ascending order. O(nlog(n))X
        // better idea, since the elements arent unique use a set instead.
        // sets are automatically ordered and force ever element to be unique.
        // sort(nums.begin(),nums.end());
        set<int> s(nums.begin(), nums.end());
        
        // pass through the vector checking if the previous value is 1 lower
        int longest_chain = 1;
        int current_chain = 1;
        // sets dont have indexing so we gotta use iterators...
        set<int>::iterator itr;
        set<int>::iterator prev;

        for (itr = next(s.begin(),1), prev=s.begin(); itr != s.end();prev=itr, itr++){
            if (*itr - *prev == 1){
                current_chain++;
            }
            else{
                current_chain = 1;
            }
            if (current_chain > longest_chain){
                longest_chain = current_chain;
            }
        }

        // for (int i = 1; i<s.size(); i++){
        //     if (s[i]-s[i-1]==1){
        //         current_chain++;
        //     }
        //     else{
        //         current_chain = 1;
        //     }
        //     if (current_chain > longest_chain){
        //         longest_chain = current_chain;
        //     }

        // }
        return longest_chain;

    }
};