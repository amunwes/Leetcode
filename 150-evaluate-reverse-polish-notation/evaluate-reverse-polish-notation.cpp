class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // need to iterate through the vector, convert the strings to integers or operators,
        // evaluate the expression in steps...

        // possible algorithm, push first 2 ints on stack, get operator, use operator popping off stack.
        // push answer and next integer on stack, get operator, repeat. 
        stack<int> nums;
        for (auto i : tokens){
            string token = i;            
            if (token.size() > 1 || isdigit(token[0])) {// if the string is a decimal digit.
                nums.push(stoi(token));
                continue; // continue causes the loop to progress without passing this point.
            }
            // after 2 digits should be an operator.
            // we pop the top 2 things off the stack.
            int num2 = nums.top();
            nums.pop();
            int num1 = nums.top();
            nums.pop();

            int result = 0;
            // switch handles the different operator logic.
            switch (i[0]){                
                case '*':
                    result = num1 * num2;
                    nums.push(result); // we push the result back on the stack so we always have 2 numbers.
                    break;
                case '/':
                    result = num1 / num2;
                    nums.push(result);
                    break;
                case '+':
                    result = num1 + num2;
                    nums.push(result);
                    break;
                case '-':
                    result = num1 - num2;
                    nums.push(result);
                    break;                
            }
        }
        // after weve looped fully the only thing on the stack should be the final answer
        return nums.top();
    }
};