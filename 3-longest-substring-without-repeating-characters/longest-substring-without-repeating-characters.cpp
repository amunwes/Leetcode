class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        queue<char> window;

        int i=0, j=0;
        int result = 0;
        int count = 0;

        for (int i = 0; i<s.size(); i++){
            map[s[i]]++;
            
            if (map[s[i]] > 1){// only goes if current element is a dupe.
                result = max<size_t>(result, window.size());
                // pop elements off queue till we reach the dupe. resetting counts.
                while(window.front()!= s[i]){
                    map[window.front()] = 0;
                    window.pop();
                }
                //front should be the dupe now.
                window.pop();// lose the dupe.
                //set the counter to 1 since were about to push the new occurance onto the queue.
                map[s[i]] = 1;
                
            }
            window.push(s[i]);//push the new occurance.
        }
        result = max<size_t>(result,window.size());
        return result;
    }
};