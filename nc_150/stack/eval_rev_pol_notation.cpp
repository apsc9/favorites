// Idea : when you see operators pop two elem, and push the result of the nos onto stack
// when you see a num, keep pushing on to the stack
// return what is left on the top of stack in the end
// TC = O(n)
// SC = O(n)

int evalRPN(vector<string>& tokens) {
    int n = tokens.size();
    stack<int>st ;

    for (auto x : tokens){
        if (x == "+" || x == "-" || x == "*" || x == "/"){
            int second = st.top() ; st.pop();
            int first = st.top() ; st.pop();
            int val ; 
            if ( x == "+"){
                val = first + second ;
            }
            else if (x == "-"){
                val = first - second;
            }
            else if (x == "*"){
                val = first * second ;
            }
            else {
                val = first/second ;
            }
            st.push(val);
        }
        else {
            int num = stoi(x);
            st.push(num);   
        }
    }
    return st.top();
}