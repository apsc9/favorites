// Problem Link: https://leetcode.com/problems/valid-palindrome/description/

// Idea : ignore all non-alphanumic char, convert the rem to lower case and compare 

bool isPalindrome(string s) {
    int st = 0 , e = s.size() - 1;
    while (st <= e){
        if (!isalnum(s[st])){
            st++;
            continue ;
        }
        if (!isalnum(s[e])){
            e--;
            continue ;
        }
        if (tolower(s[st]) != tolower(s[e])) 
            return false ;
        else {
            st++;
            e--;
        }
    }
    return true ;
}
