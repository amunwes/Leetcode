class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.size() == 0){
            return result;
        }
        string curr;
        dfs(0, digits, curr, result);
        return result;
    }

private:
    unordered_map<char, string> lut = {
        {'2',"abc"}, {'3',"def"}, 
        {'4',"ghi"}, {'5',"jkl"}, 
        {'6',"mno"}, {'7',"pqrs"}, 
        {'8',"tuv"}, {'9',"wxyz"}};

    void dfs(int index, string digits, string& curr, vector<string>& result){
        if (index== digits.size()){
            result.push_back(curr);
            return;
        }
        for (int i = 0; i<lut[digits[index]].size(); i++){
            curr.push_back(lut[digits[index]][i]);
            dfs(index+1, digits, curr, result);
            curr.pop_back();
        }

    }
};