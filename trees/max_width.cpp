// Width for a level is defined as the maximum number of nodes between the leftmost and rightmost node of the level
// (including the end nodes and the null nodes between the end nodes). 

// Idea :
// max width is defined as the maximum number of nodes between the two extreme nodes in the tree , so in order to 
// find the max width we simply need to assign the indices to the nodes at every level so that we can find the difference betweeen 
// the leftmost and the rightmost nodes at that level. As we need the difference of nodes at the same level so we make use of level order traversal
// here null nodes do not impact indexing in any way. 
// maxwidth = rightmost - leftmost +1 

// There are mainly 2 ways to do it , either we can look at the constraints and make sure that indexing wont go out of bounds for int(for 2*int),
// If that is the case, we make use of the min_index at the current level and make sure that index is under limits

// Approach 1 :

int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*,unsigned int>>q ;
        q.push({root,0}); // use 0 based indexing

        while(!q.empty()){
            int level_min = q.front().second ; // to find the min index at that level , so that others can be adjusted wrt it
            int n = q.size(), l , r;

            for(int i = 0 ; i < n ; i++){
                int curlevel = q.front().second - level_min ; // optimized level
                TreeNode* node = q.front().first ;
                q.pop();

                if (i == 0) l = curlevel ; // if it is the first elem , assign to left
                if (i == n-1) r = curlevel ; // if it is the last elem, assign to right 

                if (node -> left) q.push({node ->left,(unsigned int)2*curlevel+1}); // if 
                if (node -> right) q.push({node -> right,(unsigned int) 2*curlevel+2});
            }
            ans = max(ans, r-l+1); // at the end just calculate the max width 
        }
        return ans ;
    }

// This has its own limitations as in case of skewed it goes out of bounds, if done 2*val
// Time complexity = O(N)  as it is simply a level order traversal , where every node is traversed just once
// Space complexity = O(N) 

// Approach 2:
// Simply make use of unsigned int or long so as to handle out of bounds situation 

int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*,unsigned int>>q ;
        q.push({root,0}); // use 0 based indexing

        while(!q.empty()){
            unsigned int l = q.front().second , r = l ; // initially for a level track left
            int n = q.size();

            for(int i = 0 ; i < n ; i++){
                r = q.front().second ; // keep pushing the nodes as per this level's children
                TreeNode* node = q.front().first ;
                q.pop();

                if (node -> left) q.push({node ->left,2*r+1});
                if (node -> right) q.push({node -> right,2*r+2});
            }
            ans = max(ans, (int) (r-l+1)); // try to find the max val between the nodes at the end when you have final value of r
        }
        return ans ;
    } 

// TC and SC same as above as no change in approach , just one minor change 
