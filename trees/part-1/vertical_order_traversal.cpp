// Here every tree is divided into the verticals from left to right and in every verticals nodes are printed from top to bottom
// If 2 or more values overlap at the same position then they have to be printed in ascending order

// the idea is to assign a vertical for every vertical line and also the levels so as to keep in check the case that multiple nodes can be present 
// at the same level. After assignment , we need to store it in such a ds that left verticals are printed first then right from top to bottom

// We will perform a tree traversal and assign a vertical and level to every node and store it in a data structure
// Here we take the case of level order traversal:

// we make use of queue and we put three variables onto it 
//                                  (node.vertical,level)
//   (left_child,vertical-1, level+1)               (right_child,vertical+1,level+1)

// we make use of map data structure as we need it sorted from left to right as per the vertical , so we make use of map  so that it can store
// nodes as per the vertical values and give the nodes of least value first

// map <vertical,level> , in a single vertical we need the values in the order of levels so we make use of map again to store the values 
// map<vertical,map<level,node>>m
// Also there can be a case where 2 nodes might have the same level and vertical , in that case the nodes will be printed in ascending order.
// for every level, we need a data structure which can store values in a sorted order .Also duplicate values are allowed so we need to take care
// of that as well. This is where multiset is used in cpp. Multiset is similar to a set but keep the elements in the sorted order while also 
// allowing duplicates

// map<vertical,map<level,multiset<int>>>
 

vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>nodes ; 
        // order in the map will be like : vertical, level,list of nodes
        queue <pair<TreeNode*,pair<int,int>>>q ;
        // queue will contain triplet in the order : {node, vertical, level}
        q.push({root,{0,0}});

        while(!q,empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first ;
            int x = it.second.first, y = it.second.second ;

            nodes[x][y].insert(node -> val); // insert node corresponding to the vertical and level
            if (node -> left)
                q.push({node-> left,{x-1,y+1}});
            if (node -> right)
                q.push({node -> right, {x+1,}});
        }

        vector<vector<int>>ans ;

        for(auto x:nodes){
            vector<int>temp ;
            for(auto p: x.second){
                temp.insert(temp.end(),p.second.begin(),p.second.end())
            }
            ans.push_back(temp);
        }
        // if it is confusing you can also do
        // for(auto x:mp){
        // vectornodes;
        // for(auto y:x.second){
        // for(auto z:y.second){
        // nodes.push_back(z);
        // }
}
ans.push_back(nodes);


        return ans ;
}