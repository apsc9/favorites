// I. Approach 1 :

// The idea is to break the problem into 3 parts : i) traverse the left boundary first(excl leaf nodes) ii) traverse the leaves(left to right)
// iii) traverse the right boundary(excl leaf nodes) from down to top
// root comes from both the left and right boundary, so to avoid confusion push the root initially onto the the ans vector
// For left boundary start from the left  of the root, if it is not a leaf node then push it and move to left , if left not available
// then move on to the right part
// for leaves, push if they are leaves, then recurse onto left and right and do the same
// for rboundary there is a twist , as the results have to be stored from bottom to top, so we make use of a vector to reverse the results
// for r boundary also , rest is the same as left : check if it is a leaf , if not push to ans, move to right if possible, else move to left


vector <int> boundary(Node *root){
    vector<int>ans;
    if (!root) return ans;
    if (!leaf(root)) ans.push_back(root -> data);

    lbound(root,ans);
    leaves(root,ans);
    rbound(root,ans);
    return ans ;
}

bool leaf(Node* root){
    return !(root -> left) && !(root -> right);
}

void lbound(Node* root,vector<int>&ans){
    Node* curr = root -> left;
    while(curr){
        if (!leaf(curr)) ans.push_back(curr -> data);
        if (curr -> left) curr = curr -> left;
        else curr = curr -> right ;
    }
}

void leaves(Node* root, vector<int>&ans){
    if (leaf(root)){
        ans.push_back(root ->data);
        return;
    }
    if (root -> left) leaves(root -> left,ans);
    if (root -> right) leaves(root -> right,ans);
}

void rbound(Node* root, vector<int>&ans){
    Node* curr = root -> right ;
    vector<int>temp;
    while(curr){
        if (!leaf(curr)) temp.push_back(curr -> data);
        if (curr -> right) curr = curr -> right;
        else curr = curr -> left ;
    }

    for(int i = temp.size()-1 ; i >= 0; i--)
        ans.push_back(temp[i]);
}

// Time Complexity: O(N).
// Reason: The time complexity will be O(H) + O(H) + O(N) which is ≈ O(N)

// Space Complexity: O(N)
// Reason: Space is needed for the recursion stack while adding leaves. In the worst case (skewed tree), space complexity can be O(N).