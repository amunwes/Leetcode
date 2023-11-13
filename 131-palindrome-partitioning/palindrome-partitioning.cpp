class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        dfs(s, 0, result, curr);
        return result;
    }
private:
    void dfs(string s, int index, vector<vector<string>>& result, vector<string>& curr){
        if(index == s.size()){
            result.push_back(curr);
            return;
        }
        
        for (int j = index; j<s.size(); j++){
            if(isPal(s, index, j)){
                string sub = s.substr(index, j-index+1);
                curr.push_back(sub);
                dfs(s, j+1, result, curr);
                curr.pop_back();
            }
        }
    }

    bool isPal(string s, int i, int j){
        while(i<=j){
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};