class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
      double sum = 0, ans = 0;
      for(int i = 0 ; i < nums.size() ; i++){
        sum += nums[i];
        if( i == k -1 )
          ans = sum / k;
        else if( i > k - 1 ){
          sum -= nums[i-k];
          if( ans < sum / k )
            ans = sum / k;
        } // else if
      } // for
      return ans;
    }
};
