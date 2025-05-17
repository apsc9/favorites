// tc = O(n*n) , n: len of input string
// bcoz for each starting position of the substring, we traverse the entire substring once
// however due to the trie structure, the actual num of comparisons is reduced as we progress
// sc = O(n*n) : in worst case, where there are no common prefixes among substrings, the num nodes
// could be as high as total num of substrings which is O(n*n)

struct Node{
    Node* links[26];
    bool containsKey(char ch){
        return links[ch-'a'];
    }

    void put(char ch, Node* node){
        links[ch -'a'] = node ;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

};

int countDistinctSubstrings(string &s)
{
    int ans = 0 ;
    Node* root = new Node();

    for(int i = 0 ; i < s.size(); i++){
        Node* node = root;
        for (int j =i; j < s.size(); j++){
            if(!node -> containsKey(s[j])){
                ans++;
                node -> put(s[j], new Node());
            }
            node = node -> get(s[j]);
        }
    }
    return ans+1 ;
}