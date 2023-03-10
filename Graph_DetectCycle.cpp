//https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int k, int p, vector<int> adj[], vector<int> &visited){
        
        visited[k] = 1;
        bool cycle = 0;
        
        for(auto v : adj[k]){
            
            if(!visited[v]) cycle = dfs(v, k, adj, visited);
            else if(v != p){return 1;}
            
            if(cycle){return 1;}
            
        } 
        return 0;
        
    }
    bool isCycle(int V, vector<int> adj[]) {
       
        vector<int> visited(V, 0);

        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(dfs(i, -1, adj, visited)){ return 1;}
            }
        }
        return 0;
        
    }
};
