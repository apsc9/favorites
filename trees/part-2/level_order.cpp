// The idea is to make traverse the nodes level by level from left to right
// Output has to be given in the same order i.e. FIFO , so we make use of queue data structure
// We keep pusing all the nodes at a level into the queue and keep putting them into vectors ,
// and when that level is complete, we push the vector onto the ans vector and move onto the next level nodes 

vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans ;
        if (!root) return ans;

        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            vector<int>temp ;
            
            while(n--){
                TreeNode* node = q.front(); 
                q.pop();
                temp.push_back(node-> val);
                if (node -> left)
                    q.push(node -> left);
                if (node -> right)
                    q.push(node -> right);
            }
            ans.push_back(temp);
        }
        return ans ;
    }

// TC = O(N)  as all nodes are traversed exactly once 
// SC = O(N) for storing nodes in queue data structure 