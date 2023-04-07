// The idea is to make use of queue to push the element one by one and then compare them 
// if one of them is not same , return same 
// if you couldnt find any mismatch then it is identical and hence return true at the end 

bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true ;
        if (!p || !q) return false ;

        if (p ->val != q -> val) return false ;
        queue<TreeNode*>Q ;

        Q.push(p);
        Q.push(q);

        while(!Q.empty()){
            TreeNode* first = Q.front();
            Q.pop();
            TreeNode* second = Q.front();
            Q.pop();

            if (!first && !second) continue ;
            if (!first || !second) return false;
            if (first -> val != second -> val) return false;

            Q.push(first -> left);
            Q.push(second -> left);
            Q.push(first -> right);
            Q.push(second -> right);
        }
        return true ;
    }

// TC = O(N) as all the nodes have to be traversed
// SC = O(N)  