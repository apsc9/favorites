// the idea is make use of unordered_map in order to store char, index pair
// the idea to use the sliding window technique here : so just keep adding char as 
// per their respective indices and as soon as you find that the char is already present
// in the map, just update the start to the right of the same char last found , use curr pointer
// to scan through the string , a corner case to take care of is "abba"
// TC = O(n) 
// SC = O(1) 

int lengthOfLongestSubstring(string s) {
    unordered_map<char,int>m;
    int beg = 0, cur = 0 , mx = 0 ;
    int n = s.size();
    while (cur < n){
        if (m.find(s[cur]) != m.end()){
            beg = max(beg,m[s[cur]]+1) ; // consider "abba"
        }
        m[s[cur]] = cur ;
        mx = max(mx, cur - beg + 1);
        cur++;
    }
    return mx ;
}