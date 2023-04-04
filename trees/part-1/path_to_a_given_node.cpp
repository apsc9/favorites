
// Idea is to make use of recursive function so as to have different paths to find the required nodes in the tree
// if node is present then it returns true and stores the path to that node
// else it returns false

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>ans ;
    soln(A,ans,B); // try the traversal via this bool function
    return ans;
}

bool soln(TreeNode* root,vector<int>&ans, int B){
    if (!root)        // if you reach the end without finding the node , return false
        return false ;
    ans.push_back(root-> val); // else it is just a  node in the path

    if (root -> val == B) //if the val of the node matches the required val, then return as you already have the path by  now 
        return true ;

    if (soln(root ->left,ans,B) || soln(root -> right, ans, B)) // try to traverse both left and right side  and see if you can get a path to that node
        return true ;

    ans.pop_back(); // if you cant find a path using that node, its better to just pop it off the ans, so do just that 
    return false ; // return false as you are unable to find the node and the related path
}