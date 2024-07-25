// the idea is to store all the elem of one string in a map and try to find a window 
// in the string which contains all those char, once we find such window , 
// we try to shrink the window, while shrinking we try to see if the char we are excluding
// was already part of other string or not, so we update the count accordingly
// as long as the count is zero we can shrink the window, because count = 0 indicates 
// that we now have all the char from the string , as soon as the window loses some char
// it can no longer shrink that particular window, so the window moves towards right now
// when window reaches towards the end we will have min len and the starting char
// from where the window has to start 

// TC = O(n)
// SC = O(1)

string minWindow(string s, string t) {
    vector<int>m(128,0);
    int start = 0 , end = 0, count = 0, sindex = 0, minlen = INT_MAX;
    for (auto x: t){
        m[x]++;
    }
    count = t.size();

    while (end < s.size()){
        if (m[s[end]] > 0) // if char is already part of t 
            count--;    // decrease the count

        m[s[end]]--; // this will be negative if char is not in t
        end++;
        
        while (count == 0){ //indicates window now all char of t,          
        // so now you can try to shrink the window while you have all chars

            if (end - start < minlen){
                minlen = end-start;
                sindex = start ;
            }

            m[s[start]]++; // try to exclude that and see if that was from t
            if (m[s[start]] > 0) // if char is in t, increase count
                count++; // increasing counter makes sure that this if this char is 
                // excluded we cant shrink window anymore from the start , thus we 
                // need to move towards the right 

            start++;
        }
    }
    return minlen == INT_MAX ? "" : s.substr(sindex, minlen);
}