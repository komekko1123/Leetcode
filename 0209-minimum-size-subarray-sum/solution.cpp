class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) { // sliding window
    int left = 0;
    int right = 0;
    int sum = 0;
    int ans = 0;
    for( int i = 0; i < nums.size() ; i++){
      sum += nums[right++];
      while( sum >= target  ) {
        ans = ( ans == 0) ? right - left: min(ans , right - left ); 
        sum -= nums[left++];  
      } // if
    } // for
    return ans;

    }
};
