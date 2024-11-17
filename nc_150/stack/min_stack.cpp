// Approach 1 : Use 2 stacks
// One should be the normal one and the other one to keep track of min elem so far 
// if you find a new min val , then push onto the minstack as well, else just normal stack
// while popping take care if the top value matches the minstack top as well, pop from there too
// TC = O(1)
// SC = O(n+n)

class MinStack {
public:
    stack<int>st , minst;
    MinStack() {
        
    }
    
    void push(int val) {
        if (minst.empty()) minst.push(val);
        else if (val <= minst.top())
            minst.push(val);
        st.push(val);
    }
    
    void pop() {
        if (st.top() == minst.top())
            minst.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};

// Approach 2 : use pair in vectors 
// first value behaves like normal stack, second val keeps track of min till that point 

class MinStack {
public:
    vector<pair<int,int>>st ;
    MinStack() {
        
    }
    
    void push(int val) {
        if (st.empty())
            st.push_back({val, val});
        else 
            st.push_back({val, min(st.back().second, val)});
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
        
    }
};

// Approach 3 : A little bit trick to store only the index of min elem 
// push the index to which the min val is going to the pushed in a separate arr
// while popping out an elem, if the min elem is popped out, pop one out from minInd as well
// use index from minInd and the pop out from array s

// TC = O(1)
// SC = O(n+n)

class MinStack {
public:
    vector<int>s, minInd;
    MinStack() {
        
    }
    
    void push(int val) {
        if (s.empty() || val < s[minInd.back()])
            minInd.push_back(s.size());

        s.push_back(val);
    }
    
    void pop() {
        s.pop_back();
        if(minInd.back() == s.size()) 
            minInd.pop_back();
        
    }
    
    int top() {
        return s.back();
    }
    
    int getMin() {
        return s[minInd.back()];
    }
};