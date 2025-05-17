#include <bits/stdc++.h> 

struct Node {
    Node* links[26];

    int cntEndsWith = 0 ;
    int cntPrefix = 0 ;

    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
    }

    void put(char ch, Node* node){
        links[ch -'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void increasePrefix() {
        cntPrefix++;
    }

    void increaseEnd() {
        cntEndsWith++;
    }

    void reducePrefix() {
        cntPrefix--;
    }

    void reduceEnd() {
        cntEndsWith--;
    }

    int getEnd() {
        return cntEndsWith;
    }

    int getPrefix() {
        return cntPrefix;
    }

};

class Trie{
    private:
        Node* root;
    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for(int i = 0 ; i < word.size(); i++){
            if (!node -> containsKey(word[i])){
                node -> put(word[i], new Node());
            }
            node = node -> get(word[i]);
            node -> increasePrefix();
        }
        node -> increaseEnd();
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for (int i = 0;i < word.size(); i++){
            if (node -> containsKey(word[i]))
                node = node -> get(word[i]);
            else 
                return 0;
        }
        return node -> getEnd();
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if (node -> containsKey(word[i]))
                node = node -> get(word[i]);
            else 
                return 0;
        }

        return node -> getPrefix();
    }

    void erase(string &word){
        // we assume that the word already exists
        // since we need to decrease it

        Node* node = root;
        for(int i = 0 ;i < word.size(); i++){
            if (node -> containsKey(word[i])){
                node = node -> get(word[i]);
                node -> reducePrefix();
            }
            else {
                return;
            }
        }
        node -> reduceEnd();
    }
};
