class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
      int max_sum = 0, current = 0, z_count = 0, left = 0;
      for( int i = 0  ; i < nums.size(); i++){ // i = right
        current += 1;
        if( nums[i] == 0) 
          z_count++;
        if( z_count > k ){
          while( left < nums.size() ){
            if( nums[left] == 0 ){
              left++;
              current--;
              z_count--;
              break;
            } // if
            left++;
            current--;
          } // while
        } // if
        max_sum = max(max_sum, current);
      } // for

      return max_sum;
    }
};
