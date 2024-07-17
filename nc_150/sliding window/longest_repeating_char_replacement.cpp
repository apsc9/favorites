// Idea: you dont have to find the actual window, you just have to find the max size of the
// window where you can replace the k elem and get the max len of the window
// the idea is to move the start index till wherever possible while the below condn is satisfied
// we will keep track of max freq possible for a character
// we simply have to check : window size - mxcount <= k , until this is satisfied, 
// we dont need to move the start index, when this condition fails, this indicates that 
// there are more different characters to be replaced in that particular window than k
// so we need to move the start index to a new index and also reduce the freq of char at start 
// in the end when this is done, start will simply be at an index where this condition holds true
// so you can get the ans by simply n -start


// Some more explanation:
// When end-start+1-maxCount == 0, then then the window is filled with only one character
// When end-start+1-maxCount > 0, then we have characters in the window that are NOT the character 
// that occurs the most. end-start+1-maxCount is equal to exactly the # of characters 
// that are NOT the character that occurs the most in that window. 
// Example: For a window "xxxyz", end-start+1-maxCount would equal 2. 
// (maxCount is 3 and there are 2 characters here, "y" and "z" that are not "x" in the window.)
// We are allowed to have at most k replacements in the window, so when end-start+1-maxCount > k, 
// then there are more characters in the window than we can replace, and we need to shrink the window.
// If we have window with "xxxy" and k = 1, that's fine because end-start+1-maxCount = 1, 
// which is not > k. maxLength gets updated to 4.
// But if we then find a "z" after, like "xxxyz", then we need to shrink the window because 
// now end-start+1-maxCount = 2, and 2 > 1. The window becomes "xxyz".
// maxCount may be invalid at some points, but this doesn't matter, because 
// it was valid earlier in the string, and all that matters is finding the max window that occurred anywhere in the string. 
// Additionally, it will expand if and only if enough repeating characters appear in the window to make it expand. 
// So whenever it expands, it's a valid expansion.


// TC = O(n)
// SC = O(1), at max 26 char 


int characterReplacement(string s, int k) {
    unordered_map<int,int>m;
    int start = 0 , mx = 0 ;
    for (int end = 0 ; end < s.size(); end++){
        
        mx = max(mx, ++m[s[end]]);
        if (end - start + 1 - mx > k){
            m[s[start]]--;
            start++;
        }
    }
    return s.size() - start ;
}