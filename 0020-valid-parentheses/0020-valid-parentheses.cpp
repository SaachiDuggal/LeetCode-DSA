class Solution {
public:
    bool isValid(string s) {
        
        //edge case
        if(s.empty() && s.size() == 1){
            return false;
        }

        //make a stack to store all the open brackets in sequence
        stack<char> open;

        /* for(int i = 0; i < s.size(); i++){
                char bracket = s[i]}*/
        for(char bracket : s){

            //if open bracket we add them into the stack
            if(bracket == '(' || bracket == '[' || bracket == '{'){
                open.push(bracket);
            }

            //if closed brackets
            else{
                //if stack empty, means that we only have closing brackets
                if(open.empty()){
                    return false;
                }

                //if brackets are unmatched
                else if((bracket == ')' && open.top() != '(') ||
                        (bracket == ']' && open.top() != '[') ||
                        (bracket == '}' && open.top() != '{')){
                        return false;
                }

                //if it passes all checks that means we found a match
                else{
                    open.pop();
                }   
            }
        }
        return (open.empty());
    }
};