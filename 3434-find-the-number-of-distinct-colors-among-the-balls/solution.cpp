class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_set<int> us;  //  現在有的顏色總量
        unordered_map<int,int> um; // 數子球->顏色
        unordered_map<int,unordered_set<int>> colorToBall; // 顏色找數子球
        vector<int> result;
        for( int i = 0 ; i < queries.size()  ;i++ ){
          if(um.find(queries[i][0]) != um.end()){
            bool do_erase = true;
            colorToBall[um[queries[i][0]]].erase(queries[i][0]); // 刪除原本數字球，顏色找數子球
            if ( colorToBall[um[queries[i][0]]].size() > 0 ){ // 某一球顏色現在有同色
                do_erase = false;
            } // if

            if ( do_erase == true )
              us.erase(um[queries[i][0]]);
          } // if
          um[queries[i][0]] = queries[i][1];
          us.insert(queries[i][1]);   
          result.push_back(us.size());
          colorToBall[queries[i][1]].insert(queries[i][0]); // 加入現在顏色的數字球
        } // for

        return result;
    }
};
