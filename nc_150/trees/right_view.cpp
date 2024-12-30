// Recursion : Idea is to simply push only one elem at a level and that is when the curr ans size matches
// the level you are currently traversing at :

vector<int> rightSideView(TreeNode* root) {
    vector<int>ans ;
    traverse(root, ans, 0);
    return ans ;
}

void traverse(TreeNode* node, vector<int>&ans, int currDep){
    if (node == NULL) return ;
    if (currDep == ans.size()) ans.push_back(node -> val);

    traverse(node -> right, ans, currDep + 1);
    traverse(node -> left, ans, currDep + 1);
}

// BFS : Idea is to make use of queue only to push elements level wise and just pop out the 
// first elem in the queue for that level , push from the right first as we need the right view

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans ;
    if (!root) return ans ;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        for (int i = 1 ; i <= n ; i++){
            TreeNode* node = q.front();
            q.pop();

            if (i == 1) ans.push_back(node -> val);

            if (node -> right) q.push(node -> right);
            if (node -> left) q.push(node -> left);
        }
    }
    return ans;
}

// The above approach can also be used if we make use of 2 vectors but the above one is simpler and intuitive

vector<int> rightSideView(TreeNode* root) {
    vector<int>ans ;
    if (!root) return ans ;
    vector<TreeNode*> outer ;

    outer.push_back(root);
    while (!outer.empty()){
        int len = outer.size();
        vector<TreeNode*>vec ;
        
        for (int i = 0 ; i < len ; i++){
            if (i == len - 1){
                ans.push_back(outer[len-1] -> val);
            }
            TreeNode* node = outer[i];

            if (node -> left) vec.push_back(node -> left);
            if (node -> right) vec.push_back(node -> right);
        }
        outer = vec ;
    }
    return ans ;
}