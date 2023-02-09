class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
      unordered_map<int,unordered_set<string>> mp;
      int i = 0, j = 0, same_element = 0;
      long long ans = 0;
      for( i = 0; i < ideas.size() ; i++)
        mp[ideas[i][0]-'a'].insert(ideas[i].substr(1));
      for( i = 0 ; i < 25 ; i++  ){
        if( mp[i].size() == 0)
            continue;  
        for( j = i + 1 ;  j < 26 ; j++ ){
          if( mp[j].size() == 0)
            continue; 
          for( auto &it: mp[i] ){
            if( mp[j].count(it) )
              same_element++;
          } // for
          ans += (mp[i].size() - same_element) * (mp[j].size() - same_element);
          same_element = 0;
        } // for
      } // for
      return ans * 2;
    }
};
