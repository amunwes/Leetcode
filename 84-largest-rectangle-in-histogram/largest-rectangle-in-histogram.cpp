// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         //initial idea. iterate through the list, find the areas for all options and pick the biggest.
//         //find min value of list and count consecutive index's greater than it then move on to the next.
//         // could also create a 2nd vector which counts the consecutive connections for each index.
//         // so for the case [2,1,5,6,2,3] we'd make a vector of [2,6,2,1,4,1]
//         // yeah we'd need to iterate through the vector n times but i think it'd work and then we
//         // calculate the area by multiplying the values of the same index together.
//         const int n = heights.size();
//         vector <int> counts(n,0);
//         // counts init to 0

//         int result = 0;
//             // its O(n^2) but i dont see a more efficient way off the bat.
//         for (int i = 0; i<n; i++){// iterate through heights
//             for(int j = i; j<n; j++){// starting from the current height loop through all the heights that come after.
//                 if(heights[j] >= heights[i]){// if each subsequent height is larger or equal increment the count 
//                     counts[i]++;
//                 }else{// if a height is ever smaller then break the loop because thats the end of the cts index ->
//                     break;
//                 }
//             }
//             if(i > 0){// if were not at the start of the vector then we need to check behind us.
//                 for (int j = i-1; j>= 0; j--){// same as previous but going backwards in the vector. 
//                     if(heights[j] >= heights[i]){
//                         counts[i]++;
//                     }else{// break the loop because we reach the end of the cts index <-
//                         break;
//                     }
//                 }
//             }
//             int rectangle = heights[i] * counts[i];
//             if (rectangle > result){
//                 result = rectangle;
//             }
//         // now counts[i] * heights[i] = rectangle of area.
//         // and we just need to return the max of rectangle.
//         }
//         return result;
//     }
// };// this solution was brute force and didnt meet the time constraint.

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //initial idea wasnt wrong it just didn't utilize stacks to efficiently find bounds.
        const int n = heights.size();
        vector <pair<int,int>> bounds(n,{-1, n});
        // set defaults to begining and end indexes so min values in the list have the full index to calc length.

        stack <int> stack; //mono inc stack to calc next/prev smallest in 1 pass.

        for (int i = 0; i< n; i++){ // single pass to get both sides.

            // while stack isnt empty and the current value is smaller than the top we pop 
            while(!stack.empty() && heights[stack.top()] > heights[i]){
                //since i is smaller it is the next smallest for the items on stack.
                bounds[stack.top()].second = i;
                stack.pop();

            } 
            // this ensures the top of the stack is the index of the previous element that was smaller than i
            // or the stack is empty.
            if (!stack.empty()){
                bounds[i].first = stack.top() ;
            }
            stack.push(i);// adds current element to stack
                
        }// since we dont pop elements that are equal in height off the stack any subsequent lowest values will see 
        // the first occurance of itself as its left bound instead of the leftmost index. This is fine as we only need
        // 1 instance to be correct to calc the box.

        int result = 0;            
        for (int i = 0; i<n; i++){// make the forward pass with enough info to calc each rectangle size.
            
            int length = bounds[i].second - bounds[i].first - 1;
            int rectangle = heights[i] * length;
            if ( rectangle > result)
                result = rectangle;    
        }

        return result;
    }
};







