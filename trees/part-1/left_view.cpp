// I. The idea is to use recursion to do a level order traversal 
// for left view : go like root -> left -> right 
// for right view : go like root -> right -> left 
// make use of levels variable to see if you have first element ,
// the first element for every level is what we need , so we check for result.size == level && if it holds true , we push the curr val onto it

void solve(Node* root, int level, vector<int>&ans){
    if (root == NULL) return ;
    if (ans.size() == level)
        ans.push_back(root -> data);
    solve(root -> left, level+1, ans);
    solve(root -> right,level+1, ans);
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int>ans ;
    if (root == NULL) // to handle one of the edge cases
     return ans ;

    solve(root,0,ans);
    return ans;
}

// Time Complexity: O(N), The function does a simple traversal of the tree, so the complexity is O(n). 
// Auxiliary Space: O(h), due to the stack space during recursive call. ‘h’ here is the height of the binary tree


// II. Iterative method: Here we make use of queue and the first element for the corresponding level
// to begin with we do level order traversal and insert it in answer array as soon as we get the first element of that level
// We explore all the children of the elements in a level so as to check for the next level


//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int>ans ;
    if (root == NULL) // to handle one of the edge cases
        return ans ;
    queue<Node*>q ;
    q.push(root);
    
    while(!q.empty()){
        int i = 0 ;
        int s = q.size() ; // to check elements at a particular level
        
        while(i++ < s){
            Node* curr = q.front();
            q.pop();
            
            if (i == 1) // if its the first element , put it in the results arr
                ans.push_back(curr -> data);
            if (curr -> left)
                q.push(curr ->left);
            if (curr -> right)
                q.push(curr -> right);
        }
    }
    return ans ;

}

// Time Complexity: O(N) where N is the total number of nodes.
// Auxiliary Space: O(N) due to the space occupied by queue.


// NOte : for right view , simply traverse the right node first before the left one, rest of the things remain same

