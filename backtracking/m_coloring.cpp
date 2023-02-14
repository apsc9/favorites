#Problem link : https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#

class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    

    // this snippet checks whether it is possibe to fill that particular node with the color chosen
    // this is checked only for the edges going through that node
    bool safe(int node,int color[],bool graph[101][101],int col, int n){
        for(int i = 0 ; i < n ; i++){
            if (i != node && graph[i][node] == 1 && color[i] == col)
                return false ;
        }
        return true ;
    }
    
    // checks whether a particular node can lead to a series where all the remaining nodes can be colored 
    bool solve(int node, int color[], bool graph[101][101], int m, int n){
        if (node == n) 
            return true ; // you have traversed and found a particular combi,so no need to travel more
            
        for(int i = 1; i <= m ; i++){
            if (safe(node,color,graph,i,n)){
                color[node] = i ; // fill the color in that node if its possible
                if(solve(node+1,color,graph,m,n)) return true ; // As you have colored one node , lets now color the rest , if successful for all , return true 
                color[node] = 0;
            }
        }
        return false ; // return false if that node cant be filled by any color
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        int color[n] = {0};
        if (solve(0,color,graph,m, n)) // check whether it is possible to fill all the nodes with given m colors 
            return true ;
        return false;
    }
};