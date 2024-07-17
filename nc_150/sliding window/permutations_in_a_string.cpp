// the idea is to make use of the concept of sliding window while keeping the count
// of characters in the window, also we have a vector containing counts for char in first
// string as well, so now these things need to be checked:
// 1. If curr window size == s1.size() then check if the count arrays for char are same
// 2. if window size < s1.size() , increase the window 
// 3. if window size is greater , then move forward to a diff window, make sure you 
// adjust the freq of the count in the array

bool checkInclusion(string s1, string s2) {
    vector<int>vs1(26,0), vs2(26,0);
    for (auto x: s1){
        vs1[x-'a']++;
    }
    int start = 0, end = 0 ;
    while(end < s2.size()){
        vs2[s2[end] - 'a']++;
        if (end - start + 1 == s1.size()){
            if (vs1 == vs2) return true ;
        }
        
        if (end - start + 1 < s1.size()){
                end++;
        }
        else {
            vs2[s2[start]-'a']--;
            start++;
            end++;
        }
    }
    return false ;
}