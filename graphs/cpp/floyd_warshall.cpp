// Floyd warshall is multi source shortest path algo, using which we can 
// find the shortest distance from any node to any other given node, 
// the idea is to go via every node / edge as intermediate and try to see 
// if you manage to get less distance or not 
// also this can detect negative weight cycle as well
// TC = O(n^3)
// SC = O(1) as no extra space is taken 


void shortest_distance(vector<vector<int>>&matrix){
    int n = matrix.size();
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            if (matrix[i][j] == -1 )
                matrix[i][j] = 1e9 ;
        }
    }
    
    
    for(int k = 0 ; k < n ; k++){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
    
    // for (int i = 0 ; i < n ; i++){
    //     if (matrix[i][i] < 0)
    //         cout << "there is negative edge cycle" << endl;
    // }
    
    for (int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if (matrix[i][j] == 1e9)
                matrix[i][j] = -1 ;
        }
    }
}