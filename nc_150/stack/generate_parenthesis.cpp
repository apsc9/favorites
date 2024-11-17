// the main concept is that in a parenthesis balanced string, count of ')' must be 
// less than equal to count of '(' for every prefix of the string. A parenthesis balanced string 
// (of size 2*N) must have N number of '(' and N number of ')'. We go on adding '(' before ')' 
// for every recursive state string until count of '(' becomes equal to N. 
// Then we start adding ')' only on a condition that count of ')' is less than count of '('. 
// These two conditions will always produce balanced string.

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string s= "" ;

    solve(n, s, 0, 0, ans);
    return ans ;
}

void solve(int n, string s, int l, int r, vector<string>&ans){
    if(l == n && r == n ){
        ans.push_back(s);
        return ;
    }

    if (l < n){
        solve(n, s+"(", l+1, r, ans);
    }
    if (r < l){
        solve(n, s+")", l, r+1, ans);
    }
}