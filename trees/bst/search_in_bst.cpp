// Idea : The idea is to make use of the standard property of 
// binary search tree in order to achieve this , we make use of 
// kind of binary search here to find the key 
// TC will be O(logN) as the height of bst is logN only

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != NULL && root -> val != val)
            root = val < root -> val ? root -> left : root -> right ;

        return root ? root : NULL ;
    }
};