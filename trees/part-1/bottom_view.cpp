// I. The idea is to consider the vertical indexing, and the  last node on every index line will be in bottom view
// This is fone by making index-1 when traversing towards left and index+1 while on right 
// the elements having the same index will be replaced by the latest element in the traversal which form the bottom part of the view
// we will make use of map here to store the values corresponding to an index as we need it sorted
// we make use of queue as we traverse level wise one by one from L to R , store the values corresponding to an index in a map and 
// new node if any, will replace the value in that case


vector <int> bottomView(Node *root) {
        vector<int>ans;
        if (root == NULL)
            return ans ;
            
        map<int,int>m ;
        queue<pair<Node*,int>>q ;
        
        q.push({root,0});
        
        // the idea is to use the index for every left and right children
        // the values corresponding to an index(vertical level) at the end of the complete traversal will give the answer
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            Node* curr = it.first;
            int level = it.second ;
            
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

// Time Complexity: O(NlogN) as map was used

// Note: if unordered map were used, it would have been O(N)
// In that case we needed to have the leftmost index in the map(leftmost = min(ind,leftmost)) and we needed to increment from there and get the value

// Space Complexity: O(N)