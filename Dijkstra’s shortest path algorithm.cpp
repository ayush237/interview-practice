int shortestPath(vector<vector<int>>& times, int n, int k) {
        
        vector< pair<int,int>> adj[n+1];
        
        for(int i=0 ;i<times.size() ; i++){
            adj[times[i][0]].push_back(make_pair(times[i][1], times[i][2]));
        }
        
        priority_queue<pair<int,int> , vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> distance(n+1, INT_MAX);
        
        vector<bool> visited(n+1, false);
        
        distance[k] = 0;
        
        pq.push(make_pair(0,k));
        
        while(!pq.empty()){
            
            pair<int, int> p = pq.top();
            int u = p.second;
            
            if(!visited[u]){
                
                pq.pop();

                 for(auto it: adj[u]){
                    int v = it.first;
                    int w = it.second;
                    if(!visited[v]){
                        if(distance[u] + w < distance[v]){
                            distance[v] = distance[u] + w;
                            pq.push(make_pair(distance[v], v));
                        }

                    } 
                     
                }    
                visited[u] = true;     
            }
            
            else{
                 pq.pop();
            }
  
            
        }
        
        int maxx = 0;
        
        for(int i =1; i<=n;i++){
            maxx = max(distance[i], maxx);
        }
        
        if(maxx == INT_MAX)
            return -1;
        else
            return maxx;
        
        
        
    }
}
