class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int leftmax = height[i]; //holds the highest values weve seen on either side.
        int rightmax = height[j];
        int result = 0;
        while (i <j){
            if (leftmax <= rightmax){// if leftside is lower increment and calc water stored.
                i++;
                leftmax = max(leftmax,height[i]);//overwrite the max if the new 1 is bigger.
                result += leftmax - height[i];// add the water - the filler of the current index. 
                // since leftside is guranteed to be lower or equal to the right side 
                // the water calc'd is guranteed to be stored.
            }else{
                j--;
                rightmax = max(rightmax,height[j]);
                result += rightmax - height[j];
            }
            
        }
        return result;
    }
};