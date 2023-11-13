class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int i = 0;
        int j = 0;
        
        vector<int> result;
        deque<int> window;
        
        while (j < nums.size()){
            // mono decr double ended queue, front is always highest value
            while(!window.empty() && nums[window.back()] < nums[j] ){
                window.pop_back();
            }
            window.push_back(j);
            
            if(window.front() < i){// if front is out of window remove it.
                window.pop_front();
            }

            // if j increments to k then our window is the right size and from this point on we wanna
            // inc i so the window slides instead of growing more.
            // we also want to start building the result here since the window is now the right size.
            if(j + 1 >= k){
                result.push_back(nums[window.front()]);
                i++;
            }
        j++;
        }
        return result;
    }
};