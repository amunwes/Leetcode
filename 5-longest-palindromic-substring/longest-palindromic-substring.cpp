class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        return window(s, 0, n-1, n);
    }

private: 
    bool isPal(string& s, int i, int j){
        while(i<=j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    string window(string& s, int start, int end, int n){
        int i = start;
        int j = end;
        while (j<n){
            if(isPal(s,i,j)){
                return s.substr(i,j-i+1);
            }
            i++;
            j++;
        }
        return(window(s,start, end-1, n));
    }
};