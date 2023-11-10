class Solution {
public:
    bool isValid(string s) {
        // 1st idea, iterate through the string, add every bracket to its own stack.
        // pop the brackets off their stack and count how many open for how many closed using a running talley )+1 (-1
        // could also implement the same idea but with one hot encoded numbers )+1 }+10 ]+100
        // but thats prone to errors if there are too many brackets )x10 = }
        // iffy approach

        // better approach: make a stack that holds open brackets, if we encounter a 
        // corresponding closed bracket then pop it off the stack, the open bracket has been completed.
        // stack holds the current parenthesis we care about at any given time.
        // could use a switch statement for the logic but its much easier to use a map.
        stack<char> open;
        unordered_map<char,char> map = {
            {')','('},
            {'}','{'},
            {']','['}
        };

        for (const auto& i: s){ // const auto& so we look at a constant reference to the data instead of the actual data.
            if (map.find(i) != map.end()){ // if the character is a closed bracket. map.find looks for the key (i)
                if (open.empty()){ // if its a closed bracket and the stack is empty we fail
                    return false;
                }
                // if its a closed bracket and theres something on the stack, 
                // check if the top thing is the corresponding open bracket.
                if (open.top() != map[i]) 
                    return false;
                // if it is then pop it off the stack if it isnt then we fail.
                open.pop();

            }
            else{ // if the character is not a closed bracket, we assume its an open bracket and push it on the stack.
                open.push(i);
            }
            
        }
        return open.empty(); // at the end if the stack is empty we return true and if its not it returns false.
        
    }
};