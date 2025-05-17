// tc = O(n * len) , where n is the total number of words and len is the avg len of the string 
// this is both to insert as well as check if that particular string is a complete string or not
// sc = O(26*26*26*... )
// first root might have 26 tries and those might have another reference tries 

#include <bits/stdc++.h> 

struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){
        return links[ch-'a'];
    }

    Node* get(char ch){
        return links[ch -'a'];
    }

    void put(char ch, Node* node){
        links[ch -'a'] = node ;
    }

    void setEnd() {
        flag = true ;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
private: 
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string word){
        Node* node = root;
        for (int i = 0 ; i < word.size() ; i++){
            if (!node -> containsKey(word[i])){
                node-> put (word[i],new Node());
            }
            node = node -> get(word[i]);
        }
        node -> setEnd();
    }

    bool prefExists(string word){
        bool flag = true ;
        Node* node = root;
        for (int i = 0; i < word.size(); i++){
            if (node -> containsKey(word[i])){
                node = node -> get(word[i]);
                if(!node-> isEnd())
                    return false;
            }
            else return false;
        }
        return flag;
    }


};

string completeString(int n, vector<string> &a){
    
    Trie trie;
    for(auto& x: a){
        trie.insert(x);
    }

    string longest = "";
    for (auto word : a){
        if (trie.prefExists(word)){
            if (longest.length() < word.length())
                longest = word;
            else if (longest.length() == word.length() && word < longest)
                longest = word ;
        }
    }

    if (longest == "")
        return "None";

    return longest;

}