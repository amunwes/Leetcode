class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // idea, iterate through the list, use a stack to track what days we havent found a higher temp for yet.
        int n = temperatures.size();
        
        // actual solution
        stack<pair<int,int>> high_temp;
        vector<int> result(n);// initialize our result the size of our input with all 0's
        // pair: [index, temp]
        
        for (int i = 0; i < n; i++){// iterate through the list.
            // int currDay = i;
            // int currTemp = temperatures[i];
            int current_temp = temperatures[i];
            int current_day =  i;
            
            // since we push if the stack is empty or if the current temp is lower than the top of the stack
            // we can invert the condition and have our while loop run.
            while (!high_temp.empty() && high_temp.top().second < current_temp){
                // while the stack isnt empty and the current temp is higher than our stack temp.
                int prev_day = high_temp.top().first;
                int prev_temp = high_temp.top().second;
                
                // calc and record number of days it took.
                result[prev_day] = current_day - prev_day; 
                // then pop off the stack.
                high_temp.pop();
                
                // loop till current isnt higher or stack empties.
            }
            
            // once the stack is empty or the current temp is lower again we push.
            high_temp.push({current_day, current_temp});
        }
        
        return result;
    }
};

        
        
        // after writing out the parts its better to simplify the code because we always need to push the current temp after we finish the while loop and naming conventions makes things easier.

        // for (int i = 0; i , temperatures.size(); i++){// iterate through the list.
        //     if (hightemp.empty()){// if the stack is empty then we have nothing to compare to. and theres no temps higher
        //         high_temp.push({i,temperatures[i]}); // push the day index and temp value to the stack.
        //     }
        //     if (high_temp.top().second > temperatures[i])
        //         high_temp.push({i,temperatures[i]});

        //     while (high_temp.top().second < temperatures[i]){ // if the stacks top is smaller than the current temp
        //         /* subtract the day indexes to find how many days it took and record that in the result vector 
        //         for the high temps day index. ie if the 2nd day wasnt surpassed till the 5th day 
        //         index 4-1 = 3 it took 3 days and we record that in result[1]. */ 
        //         result[high_temp.top().first] = i - high_temp.top().first; 
        //         // then pop off the stack.
        //         high_temp.pop();
        //         //loop this so while loop
        //     }
                        

        // }