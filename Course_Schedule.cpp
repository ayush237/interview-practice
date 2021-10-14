bool bfs(vector<vector<int>> adj, vector<int> &visited, vector<int> &indegree, int numCourses){
        
        queue<int> q;
        
        for(int i = 0; i<numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        int ct =0;
        
        while(!q.empty()){
            
            int temp = q.front();
            q.pop();
            
            for(auto it: adj[temp]){
                
                indegree[it]--;
                
                if(indegree[it] == 0)
                    q.push(it);
            }
            
            visited[temp] = 1;
            ct++;
            
        }
        
        if(ct == numCourses)
            return true;
        
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
       vector<vector<int>> adj(numCourses);
        
        vector<int> indegree(numCourses, 0);
        
        vector<int> visited(numCourses, 0);
        
        
        for(int i =0; i<prerequisites.size() ; i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]]++;
            
        }
        
        return bfs(adj, visited, indegree, numCourses);
        
    }
