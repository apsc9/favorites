// Account merge : Disjoint set
// TC : O(N+E) + O(E*4ɑ) + O(N*(ElogE + E)) where N = no. of indices or nodes and E = no. of emails. //
// The first term is for visiting all the emails. The second term is for merging the accounts. 
// And the third term is for sorting the emails and storing them in the answer array

class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i = 1 ; i <= n ; i++){
            parent[i] = i ;
        }
    }

    int findUParent(int node){
        if (parent[node] == node)
            return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if (ulp_u == ulp_v) return ;
        if (rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v ;
        }
        else if (rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u ;
        }
        else {
            parent[ulp_v] = ulp_u ;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if (ulp_u == ulp_v) return ;
        if (size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v ;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u ;
            size[ulp_u] += size[ulp_v];
        }
    }
};


vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();
    DisjointSet ds(n);
    //sort(accounts.begin(), accounts.end());
    // step 1: consider every account as a component 
    // we will map the mails to these components, so we need a map        
    unordered_map<string,int>mapMail ;

    for (int i = 0 ; i < n ; i++){
        for (int j =1 ; j < accounts[i].size() ; j++){
            string mail = accounts[i][j] ; // lets get the mail one by one

            // check if the mail is already in the map or not
            if (mapMail.find(mail) == mapMail.end()) {
                mapMail[mail] = i ; // map the mail to the component
            }     
            else {
                ds.unionBySize(i, mapMail[mail]) ; // else join both the components, so that we can make use of 
                // ultimate parent concept to map it further 
            }
        }
    }

    // step2 : we need a list of mails component wise as we already have mappings ready 
    // so we will have list of mails after merging (component wise)

    vector<string> mergedMail[n] ;
    // now we will pick up each mapping from the map and try to combine them component wise
    for (auto x : mapMail){
        string mail = x.first ;
        int compo = ds.findUParent(x.second); // done to make sure what we combined works 
        mergedMail[compo].push_back(mail);
    }
    // from the above step we have component wise mails ready after merging

    // step 3 : lets get the answer in the asked format

    vector<vector<string>>ans ;

    for (int i = 0 ; i < n ; i++){
        // after merging the component might be empty as well , so just take care of that
        if (mergedMail[i].size() == 0) continue;

        // sort the mails as reqd in the answer
        sort(mergedMail[i].begin(), mergedMail[i].end());
        vector<string>tmp;
        tmp.push_back(accounts[i][0]); // pushing the name
        for (auto x : mergedMail[i]){
            tmp.push_back(x);
        }
        ans.push_back(tmp);
    }
    sort(ans.begin(), ans.end());
    return ans;
}
