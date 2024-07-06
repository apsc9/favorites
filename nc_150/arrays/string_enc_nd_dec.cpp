// The idea is to simply append the size of the size along with some symbol
// so that it can be decoded easily when required 
// TC = O(n)
// SC = O(n)

string encode(vector<string>& strs) {
    string s="";
    for (int i = 0 ; i < strs.size(); i++){
        s += to_string(strs[i].size()) + "*" + strs[i];
    }
    return s ;
}

vector<string> decode(string s) {
    int i = 0 ;
    vector<string>ans;
    while(i < s.length()){
        int pos = s.find("*", i);
        int len = stoi(s.substr(i, pos-i));
        string temp = s.substr(pos+1, len);
        ans.push_back(temp);
        i = pos + len + 1;
    }
    return ans ;
}