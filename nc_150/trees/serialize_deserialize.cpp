// idea is to make use of level order traversal in order to traverse the tree (u can use any traversal) 
// add a symbol for the null nodes, make sure everything is separated by commas
// TC = O(N)
// SC = O(N)

string serialize(TreeNode* root){
    if (!root) return "";

    string s = "";
    queue<TreeNode*>q ;
    q.push(root);

    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        if (node == NULL) s +="#,";
        else s += (to_string(node -> val) + ',')
        if (node != NULL){
            q.push(node -> left);
            q.push(node -> right);
        }
    }
    return s ;
}

// the idea behind deserializing is to get the objects one by one from the stream
// initialize the first one as root , then push it onto the queue
// then for the subsequent elem as per the symbol inserted for NULL which is '#' here 
// construct the tree, if the symbol is non-hash, then attach it to the left or right node
// and again push it onto the queue to make further subtrees. 

TreeNode* deserialize(string data){
    if (data.size() == 0) return NULL;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode* root = new TreeNode(stoi(str));
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){

        TreeNode *node = q.front();
        q.pop();

        // check for left node
        getline(s, str, ',');
        if(str == '#'){
            node -> left = NULL;
        }
        else {
            node -> left = new TreeNode(stoi(str));
            q.push(node -> left);
        }

        // check for right node 
        getline(s, str, ',');
        if (str == '#'){
            node -> right = NULL;
        }
        else {
            node -> right = new TreeNode(stoi(str));
            q.push(node -> right);
        }
    }
    return root;
}