// tc : first you need to insert all the 32 bits for all the elem, then 
// you need to go and find the max number across array2
// so tc = O(n*32) + O(m*32) 

struct Node{
    Node* links[2];
    bool containsKey(int bit){
        return links[bit];
    }

    void put(int bit, Node* node){
        links[bit] = node;
    }

    Node* get(int bit){
        return links[bit];
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(int num){
        Node* node = root;
        for(int i = 31 ; i >= 0; i--){
            int bit = (num >> i) & 1 ;
            if (!node -> containsKey(bit)){
                node-> put(bit, new Node());
            }
            node = node -> get(bit);
        }
    }

    int getMax(int num){
        int mxnum = 0;
        Node* node = root;
        for (int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1 ;
            if (node -> containsKey(1-bit)){
                mxnum = mxnum | (1 << i);
                node = node -> get(1-bit);
            }
            else {
                node = node -> get(bit);
            }
        }
        return mxnum;
    }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    Trie trie;
    for (auto& x: arr1){
        trie.insert(x);
    }

    int mxmm = 0 ;
    for (auto& x: arr2){
        mxmm = max(mxmm,trie.getMax(x));
    }
    return mxmm;

}