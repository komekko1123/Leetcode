class Solution {
public:
    int jump(vector<int>& nums) {
      int i = 0, ans = 0;
      int j = nums.size()- 1;
      while( j != 0 ){
        for( i = 0 ; i < j ; i++){
          if( i + nums[i] >= j ) {
            ans++;
            j = i;
            i = -1;
          } // if       
        } // for
      } // while
      
      return ans;
    } // for


};
