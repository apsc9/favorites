// Prob Link : https://leetcode.com/problems/valid-anagram/description/

// Approach 1 : sorting 
// TC = O(nlogn)

bool isAnagram(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

// Approach 2 : use hashmap
// the idea is that if it is an anagram, then you will have the contents of hashmap >= 2
// we make use of the same thing, for every char in one string, we inc the count 
// for every char in other string, we decrease the count, at the end if we find any
// char with count > 0  then not an anagram
// TC = O(n) , as there will only be a single iteration

bool isAnagram(string s, string t) {
    int s1 = s.length() , s2 = t.length();
    if (s1 != s2) return false ;

    unordered_map<char,int>m;
    for (int i = 0 ; i < s1; i++){
        m[s[i]]++;
        m[t[i]]--;
    }

    for (auto x : m){
        if (x.second != 0) return false ;
    }
    return true ;
}

// approach 3 : use hashing along with array
// this is an optimized approach to the above method where we make use of the fact
// that there are only 26 letters in an alphabet , so we can use an arr of 26 size
// TC = O(1)

bool isAnagram(string s, string t) {
    vector<int>arr(26,0);
    for (auto x : s)
        arr[x-'a']++;

    for (auto x : t)
        arr[x-'a']--;

    for (auto x : arr){
        if (x != 0)
            return false;
    }
    return true ;  
}