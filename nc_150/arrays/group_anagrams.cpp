// the idea is sort the strings and store it in a map 
// which contains a particular vector of strings for a particular sorted string
// TC = O(n * (strlen))

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>>ans ;
    unordered_map<string,vector<string>>m;
    for (auto x : strs){
        string s = x ;
        //sort(s.begin(), s.end());
        m[countsort(s)].push_back(x);
    }

    for (auto x : m){
        ans.push_back(x.second);
    }
    return ans ;
}

string countsort(string s){
    vector<int>count(26,0);
    // lets have count of each letter
    for(auto x: s){
        count[x-'a']++;
    }
    string t ;
    for (int i = 0 ; i < 26 ; i++){
        t += string(count[i], i+'a'); // appends the letter count[i] num of times
    }
    return t ;
}

