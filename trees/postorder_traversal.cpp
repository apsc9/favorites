// I. The idea is to simply keep pushing the elements on one stack initially and one by
//  one on another stack thereafter, and traverse in the order root, left , right and keep popping it up from the second stack in the end once all the elements are pushed and taken out from the first stack 

// TC = O(N)
// sc = O(N) + O(N)

vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if (!root) return ans ;
        stack<TreeNode* >s , t ;

        s.push(root);
        while(!s.empty()){
            TreeNode* curr = s.top();
            s.pop();
            t.push(curr);
            
            if(curr -> left)
                s.push(curr -> left);
            if (curr -> right)
                s.push(curr -> right);
        }

        while(!t.empty()){
            ans.push_back(t.top() -> val);
            t.pop();
        }
        return ans;
    }

// II. Use only a single stack :
// For postorder traversal, the order is left, right, root 
// So the idea is to go towards the left side first and keep traversing the left subtree
// But when you reach a leaf, put it in reorder, While you traverse the right  node make sure you keep a ptr called prev so that it can be used to identify whether it has already been taken as a right leaf and you can take the root in the post order traversal.

// TC = O(N)
// SC = O(N)
// this is just a check --ignore


vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>s;
        TreeNode* curr = root , *prev = NULL;

        // idea is to traverse in the order root, left, right 
        // idea is to go and cover left part first, then move to right subtree and then root 
        // so if curr is not pointing to null , then try to explore the left subtree first
        while(curr || !s.empty()){
            if (curr){
                s.push(curr);
                curr = curr -> left ; 
            }
            else {
                curr = s.top() ; // make a full tree , then dry run this step
                if(curr -> right == NULL || curr -> right == prev){
                    ans.push_back(curr -> val); // if this is the leaf node or the right node 
                    s.pop(); // previously traversed then just push the leaf/root to the ans
                    prev = curr ; // so as to check that the right node has already been seen
                    curr = NULL ; // to take another node(root/right node)  from stack
                }
                else 
                    curr = curr -> right ;
            }
        }
        return ans ;
    }