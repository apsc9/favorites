#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data ;
    struct Node *left, *right;
} 

struct Node* newNode(int data){
    struct Node* node = (struct Node*) malloc(sizeof(struct Node)); 
    node -> data = data;
    node -> left = NULL ;
    node -> right = NULL ;

    return (node);
}

// Idea is to make use of the fact that for preorder , we traverse an element only for a single time,so we take elem and move to its left child 
// for inorder traversal when we are visiting an element for the second time we take it and move to its right child
// for postorder, an element is taken only when it has been traversed thrice, so we just take it in the end

void solve(Node* root, vector<int>&pre, vector<int>&in, vector<int>&post){
    stack<pair<Node*,int>>s ;
    s.push({root, 1});

    if (root == NULL) return ;
    while(!s.empty()){
        auto curr = s.top();
        s.pop();

        // for inorder , traversal is like, root then left then right , so we just move on to the left child thereafter
        // Keep track of whether the node has been visited the first time , second time or third time
        // for the first time visit , put it in preorder and also push it back  incrementing it to 2 as it will be visited second time for inorder traversal
        if (curr.second == 1){
            pre.push_back(curr.first -> data);
            curr.second++ ; // incrementing it as it will be traversed for the second time for 
            s.push(curr);

            if (curr.first -> left){
                s.push({curr.first->left,1}); // this will also be pushed for the first time only 
            }
        }
        // for inorder the traversal is like, we have already come back to the root and we are now ready to move to the right 
        // but what has been considered in inorder will be there in postorder as well once the right child is covered, so 
        // we again push onto the stack after incrementing it from 2 to 3 
        else if (curr.second == 2){
            in.push_back(curr.first -> data);
            curr.second++;
            s.push(curr);

            if (curr.first -> right){
                s.push({curr.first -> right, 1});
            }
        }
        // if it is being traversed for the third time, then it is simply the postorder traversal
        else 
            post.push_back(curr.first -> data);
    }
}

int main() {
    struct Node* root = newNode(1);
    root -> left =newNode(2);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(5);

    root -> right = newNode(3);
    root -> right -> left = newNode(6);
    root -> right -> right = newNode(7);

    vector<int> pre, in , post;
    solve(root, pre, in, post);

    cout << "Preorder traversal is:" << endl ;
    for(auto x : pre){
        cout << x << " " ;
    }
    cout << endl ;

    cout << "Inorder traversal is:" << endl ;
    for(auto x : in){
        cout << x << " " ;
    }
    cout << endl ;

    cout << "PostOrder traversal is:" << endl ;
    for(auto x : post){
        cout << x << " " ;
    }
    cout << endl ;
}

// Time Complexity: O(N)
// We are visiting every node thrice therefore time complexity will be O(3*N), which can be assumed as linear time complexity.

// Space Complexity: O(N)
// Reason: We are using three lists and a stack to store the nodes. The space complexity will be about O(4*N), which can be assumed as linear time complexity.