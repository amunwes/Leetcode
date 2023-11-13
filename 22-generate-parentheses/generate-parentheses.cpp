class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // recursion is necessary and it took me a bit to understand the solution. credit to neetcode. 
        // done with a seperate private recursive function
            vector<string> result;
            generate(n, 0, 0, "", result);
            return result;
    }
private:
// function keeps track of the opens/closes and appends 
// them to the end of the result vector we give it a reference to. 
    void generate(int n, int open, int close, string str, vector<string>& result){
        if (open == n && close == n){// if we have the right number of open and closes then we append and return.
            result.push_back(str);
            return;
        }
        if (open < n){// if we dont have enough opens then recursive call until we do
            generate(n, open + 1, close, str + '(', result); // add ( to the string.
        }
        if (open > close){// if we have more closed brackets than open then we want to recursively call to add a close
            generate(n, open, close + 1, str + ')', result); // add ) to the string.
        }
    }
// the reason this works is because when we finish our first recursive call ((())) we return to 
//the previous recursive call at str = (( which adds a ) and continues on with (()() until it terminates at (()())
// the next call starts at (()) and so on.    
};
