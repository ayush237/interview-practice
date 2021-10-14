vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        
        vector<int> indegree(numCourses, 0);
        
        for(int i =0; i<prerequisites.size(); i++){
            
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            
            indegree[prerequisites[i][0]] ++;
        }
        
        vector<int> finalOrder;
        
        queue<int> q;
        
        for(int i = 0 ;i<numCourses; i++){
            
            if(indegree[i] == 0)
                q.push(i);
        }
        
        int count = 0;
        
        while(!q.empty()){
            
            int temp = q.front();
            q.pop();
            
            
            for(auto it: adj[temp]){
                
                indegree[it]--;
                
                if(indegree[it] == 0)
                    q.push(it);
                
            }
              
            finalOrder.push_back(temp);
            count++;
               
            
        }
        
        if(count!= numCourses)
            return {};
        
        return finalOrder;
    }
