// Problem Link : 
// Idea is to make a directed graph using the literals of the string , 
// dictionary simply means arrangement in an order where one literal comes 
// before another , so this can simply be solved using topo sort if we 
// make a directed graph using the string literals

// Also corner cases are there :
// 1. "abcd" 
//    "abc"
// this is not possible , as abc has to come first anyhow to make sense
// 2. If there is cyclic dependency
// "abc", "bad" , "axy" : topo sort can be applied here , also this doesnt 
// make any sense as all the dictionaries follow a certain order where one 
// comes before another

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>>adj(K);
        for (int i = 0 ; i < N-1 ; i++){
            string s1 = dict[i] , s2 = dict[i+1];
            int len = min(s1.length(),s2.length());
            for (int k = 0; k < len ; k++){
                if (s1[k] != s2[k]){
                    adj[s1[k] -'a'].push_back(s2[k] -'a');
                    break;
                }
            }
        }
        vector<int>order = topoSort(K,adj);
        string ans ="";
        for(int i = 0 ; i < order.size();i++){
            ans+= order[i]+'a';
        }
        return ans;
        
    }
    
    private:
    vector<int> topoSort(int V, vector<vector<int>>&adj) 
    {
        vector<int>indegree(V,0);
        // assigning indegree to each vertex
        for(int i = 0 ; i < V ; i++){
            for(auto x:adj[i]){
                indegree[x]++;
            }
        }
        
        queue<int>q ;
        for(int i = 0 ; i < V ; i++){
            if (indegree[i] == 0)
                q.push(i);
        }
        
        vector<int>ans ;
        while(!q.empty()){
            int node = q.front();
            q.pop() ;
            ans.push_back(node);
            
            for(auto x:adj[node]){
                indegree[x]--;
                if (indegree[x] == 0)
                    q.push(x);
            }
        }
        return ans;
    }

};

