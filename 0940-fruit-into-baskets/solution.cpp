	class Solution {
public:
    int totalFruit(vector<int>& fruits) {
      unordered_map<int,int> mp;
      int i = 0, j =0;
      for( i = 0 ; i < fruits.size() ; i++ ){
        mp[fruits[i]]++ ;
        if( mp.size() > 2){
          mp[fruits[j]]--;
          if( mp[fruits[j]] == 0)
            mp.erase(fruits[j]);
          j++;
        } // if
      } // for
      return i-j;
    }
};  
