// Just because we have both the opening and closing brackets here, we can make use of stack
// for the opening parenthesis , just keep pushing them onto the stack
// for any closing one, just check that stack should not be empty(shouldnt be a lone elem)
// and also its top should have the same set of opening parenthesis
// if both conditions are met, pop the top element from the stack

// TC = O(n)
// SC = O(n)

bool isValid(string s) {
    stack<char>st ;

    for(auto ch : s){
        if (ch == ')' && !st.empty() && st.top() == '(')
            st.pop();
        else if (ch == '}' && !st.empty() && st.top() == '{')
            st.pop();
        else if (ch == ']' && !st.empty() && st.top() == '[')
            st.pop();
        else    
            st.push(ch);
    }
    return st.empty();
}