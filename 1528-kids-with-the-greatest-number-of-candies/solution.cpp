class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
      int max = 0;
      for(int i = 0; i < candies.size() ; i++){
        if( max < candies[i])
          max = candies[i];
      } // for 

      vector<bool> result;
      for(int i = 0; i < candies.size() ; i++){
        if( max <= candies[i] + extraCandies )
          result.push_back(true);
        else
          result.push_back(false);
      } // for 
      return result;
    }
};
