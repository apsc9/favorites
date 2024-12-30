// the idea is to make use of queue and put the nodes level by level
// keep count of the nodes at a particular level
// TC = O(n)


vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>>ans ;
    queue<TreeNode*>q ;

    if (root) q.push(root);
    while(!q.empty()){
        int n = q.size();
        vector<int>temp ;
        while(n--){
            TreeNode* node = q.front();
            q.pop();
            temp.push_back(node -> val);
            if (node -> left) q.push(node -> left);
            if (node -> right) q.push(node -> right);
        }
        ans.push_back(temp);
    }
    return ans ;
}