// Recursive solution: if both the trees are empty, they are identical . If only one tree is empty or the 
// values of the current nodes are diff, the trees are not identical. We can then traverse recursively
// TC = O(n)
// SC = O(Height)

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL && q == NULL) return true ;
    if(p == NULL || q == NULL || p -> val != q -> val) return false ;
    
    return isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right); 
}

// Iterative solution : 
// the idea is to make use of Q, and keep pushing elements in sequence on it , 
// keep popping and keep comparing like we did in recursive solution above 

bool isSameTree(TreeNode* p, TreeNode* q) {

    queue<TreeNode*>Q ;
    Q.push(p);
    Q.push(q);

    while(!Q.empty()){
        TreeNode* q1 = Q.front();
        Q.pop();
        TreeNode* q2 = Q.front();
        Q.pop();

        if (!q1 && !q2) continue ;
        if (!q1 || !q2 || q1 -> val != q2 -> val) return false;

        Q.push(q1 -> left);
        Q.push(q2 -> left);
        Q.push(q1 -> right);
        Q.push(q2 -> right);
    } 
    return true ;
}