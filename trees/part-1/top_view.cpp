// Idea : exactly same to bottom view except that put only unique elements in the map and not the repeated/updated values as they wont 
// be visible from the top

vector<int> topView(Node *root)
    {
        vector<int>ans;
        if (root == NULL)
            return ans ;
            
        map<int,int>m ;
        queue<pair<Node*,int>>q ;
        
        q.push({root,0});
        
        // the idea is to use the index for every left and right children
        // the values corresponding to an index(vertical level) at the end of the complete traversal will give the answer
    
        // The only difference from bottom view is that you have to check whether the index has been stored previously
        // in the map , if no , then only store the value in the map as there will be overrides for the elements not visible from 
        // the top view 
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            Node* curr = it.first;
            int level = it.second ;
            
            if (m.find(level) == m.end())
                m[level] = curr -> data ;
            
            if (curr -> left)
                q.push({curr -> left, level-1});
            if (curr ->right)
                q.push({curr -> right, level+1});
        }
        
        for(auto x: m)
            ans.push_back(x.second);
            
        return ans;
    }

// Time Complexity: O( N logN ), N is number of nodes in tree.
// Note : to optimize the TC to O(N) , make use of min and max variables while keeping track of the index like :
// if(curr->node->left != NULL){
//         mn = min(mn, curr->hd-1);

// if(curr->node->right != NULL){
//         mx = max(mx, curr->hd+1);

// Now traverse from min to max in the map while taking the actual values , this way unordered map will work and 
// there wont be a need of map

// Space Complexity: O(N), N is number of nodes in tree