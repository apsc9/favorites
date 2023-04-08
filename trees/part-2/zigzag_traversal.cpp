// The idea is to do a level order traversal with a catch , Its like alternatively it will be left to right and then right to left
// just have a flag to keep track of whether it is left to right or right to left

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if (!root) return ans;
        queue<TreeNode*>q;
        q.push(root);

        bool flag = false; // true only of nodes have to be traversed from right to left
        while(!q.empty()){
            int n = q.size();
            vector<int>temp ;
            while(n--){
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node-> val);
                if(node -> left) q.push(node-> left);
                if (node -> right) q.push(node -> right);
            }
            if (flag)
                reverse(temp.begin(),temp.end());
            
            flag = flag ^ 1;
            ans.push_back(temp);
        }
        return ans;
}

// TC = O(N);
// SC = O(N);

// Same approach, slightly better way of storing the answer

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if (!root) return ans;
        queue<TreeNode*>q;
        q.push(root);

        bool flag = false; // true only for right to left traversal in a level
        while(!q.empty()){
            int n = q.size();
            vector<int>temp(n) ;
            for(int i = 0 ; i < n ; i++){
                TreeNode* node = q.front();
                q.pop();
                int index = (flag) ? (n - 1 - i) : i ;
                temp[index] = node -> val;
            
                if(node -> left) q.push(node-> left);
                if (node -> right) q.push(node -> right);
            }
            
            flag = flag ^ 1;
            ans.push_back(temp);
        }
        return ans;
    }