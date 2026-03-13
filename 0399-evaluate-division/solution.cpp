class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) { // HARD
      unordered_map<string,vector<pair<string,double>>> graph;
      vector<double> ans;
      for( int i = 0 ; i < equations.size() ; i++){
        graph[equations[i][0]].push_back( { equations[i][1], values[i]} ) ; 
        graph[equations[i][1]].push_back( { equations[i][0], double( 1 / values[i]) } ); 
      } // for 

      for( auto &c : queries){
        unordered_map<string,bool> visited; 
        ans.push_back(dfs(visited,graph,c));
      } // for  
      return ans;
    }

    double dfs(  unordered_map<string,bool>& visited, unordered_map<string,vector<pair<string,double>>> &graph , vector<string>& queries){
      if( graph.find(queries[0]) == graph.end() || graph.find(queries[1]) == graph.end() )
        return -1;
      if( queries[0] == queries[1] )
        return 1;
      visited[queries[0]] = true;
      for( auto &c : graph[queries[0]]){
        if( !visited[c.first]){       
          if( c.first == queries[1] )
            return c.second;
          else{
            vector<string> q = {c.first, queries[1]};
            double ans =  dfs(visited,graph,q);
            if( ans != -1)
              return ans * c.second;
          } // else
        } // if
      } // for

      return -1;
    } // double dfs
};
