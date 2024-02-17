// The idea is to tweak dijkstra a little bit as we are given almost the similar case to what 
// we have when we apply dijkstra, i.e varying values and we need to pick min and proceed accordingly
// we need a priority queue to proceed with the lowest min efforts required to reach a location
// the idea here is to just keep track of the min effort required to reach a cell and compare it with the 
// absolute diff , here the max of those two gives the effort and we compare the previous effort already 
// stored to the current effort that we calculated while traversing the path
// an important thing to note here is that, once we reach the destination node by popping it out from the pq
// we wont get any effort minimum that what we have got now, so we end our search there , this is because of the 
// narture of priority queue as it first pops out the entry where min dist is reqd 
// TC : ElogV
// 4 * n*m* log n*m , as we have grid over here so edges will be n*m, also vertices will be the same(n*m)
// SC = O(n*m) , extra space used here 

int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size() , m = heights[0].size();

    priority_queue<pair<int,pair<int,int>>, 
    vector<pair<int,pair<int,int>>>,
    greater<pair<int,pair<int,int>>>>pq;

    vector<vector<int>>dist(n,vector<int>(m,1e9));
    dist[0][0] = 0 ;
    pq.push({0,{0,0}}); // format : {dist, {x,y}}

    vector<vector<int>>dir ={{1,0}, {0,-1}, {-1,0}, {0,1}};

    while(!pq.empty()){
        auto x = pq.top() ; pq.pop();
        int diff = x.first ;
        int row = x.second.first, col = x.second.second ;

        if (row == n-1 && col == m-1) return dist[row][col];

        for(int i = 0 ; i< 4 ;i++){
            int nr = row + dir[i][0];
            int nc = col + dir[i][1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m){
                int effort = max(diff, abs(heights[row][col] - heights[nr][nc]));
                // effort will be max of effor taken to reach to prev locn (row,col)
                // and the absolute difference between the current and the prev locn

                if (dist[nr][nc] > effort){
                    dist[nr][nc] = effort ;// update the dist if min is found 
                    // push it to the pq as we now have a better value of effort
                    pq.push({effort, {nr,nc}});
                }
            }
        }
    }
    return 0 ; // if it is unreachable
}