 bool isCycle(vector<vector<int>> &graph, int source, vector<int>&visiting, vector<int> &visited){
        
        visited[source] = 1;
        visiting[source] = 1;
        
        for(auto it: graph[source]){
            
            if(!visited[it]){
                
                if(isCycle(graph, it, visiting, visited))
                    return true;
            }
            
            else if(visiting[it] == 1)
                return true;
        }
        
        visiting[source] = 0;
        return false;
        
    }
    
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      
        vector<int> visited(graph.size(),0);
        vector<int> visiting(graph.size(),0);
        
        vector<int> ans;
        
        for(int i = 0 ; i < graph.size() ; i++){

                if(!isCycle(graph, i, visiting, visited)){
                    ans.push_back(i);
                }
        }
        
        return ans;
    }
