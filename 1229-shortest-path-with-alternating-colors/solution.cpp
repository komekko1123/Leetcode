class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
      vector<vector<pair<int,int>>> graph(n); // 0是紅的藍色是1
      for(auto &r : redEdges){
        graph[r[0]].push_back({r[1],0});
      } // for
      for( auto &b : blueEdges){
       graph[b[0]].push_back({b[1],1});
      } // for
      queue<pair<int,int>> q;
      vector<vector<int>> dist(n,vector<int>(2,INT_MAX));  
      q.push({0,0}); // red
      q.push({0,1}); // blue
      dist[0][0] = 0; // red
      dist[0][1] = 0; // blue
      while( ! q.empty() ){
        int node_q = q.front().first;
        int color_q = q.front().second;
        q.pop();
        for( auto g : graph[node_q]){
          int node_g =  g.first;
          int color_g = g.second;        
          if( dist[node_g][color_g] == INT_MAX && color_q != color_g ){ // 找到新的節點卡連結
            dist[node_g][color_g] = 1 + dist[node_q][color_q];  
            q.push(g);//放入queue  
          } // if    
        } // for
      } // while
      vector<int> ans(n,-1);
      for( int i = 0 ; i < n ; i++){
        if( dist[i][0] != INT_MAX || dist[i][1] != INT_MAX )
          ans[i] = min(dist[i][0], dist[i][1]);
      } // for
      return ans;
    }
};
