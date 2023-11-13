// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //only wanna apply binary search on the smaller list 
        // so this step organizes it so nums1 is always the shorter list
        if (nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        
        int total = nums1.size()+nums2.size();
        // int half = total /2;

        int low = 0;
        int high = nums1.size();

        double result = 0.0;

        while (low<=high){
            int i = (low + high)/2;
            // 2nd lists partition is dependant on how much space is left we want the total left side to equal half.
            int j = (total + 1) /2 - i;

            //ternary's to handle the edge cases. if 1 of the lists is entirely greater or less than
            // then our partition would go our of bounds of the list as it adjusts. 
            // if that happens we set it to min or max to continue running.
            int left1 = (i > 0) ? nums1[i-1] : INT_MIN;
            int right1 = (i < nums1.size()) ? nums1[i] : INT_MAX;            
            int left2 = (j > 0) ? nums2[j-1] : INT_MIN;
            int right2 = (j < nums2.size()) ? nums2[j] : INT_MAX;

            // we check if our partition is correct 
            if (left1<=right2 && left2<=right1){
                //if it is then we calc the median based on whether the total length is even or odd
                if(total%2 ==0){
                    result = (max(left1,left2) + min(right1,right2)) /2.0;
                }else{
                    result = max(left1,left2);
                }
                break;
            }else if(left1>right2){// if the partition isnt right yet then we need to adjust the pointers.
                high = i-1;
            }else{
                low = i+1;
            }
            
        }
        return result;


    }
};