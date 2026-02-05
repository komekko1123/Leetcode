class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
    // 想法 sort後，左右指標
      sort(nums.begin(), nums.end());
      int left = 0, right = nums.size()-1 , ans = 0;
      while( left < right ){
        if( nums[left] + nums[right] == k){
          left++;
          right--; //左右指標都往前
          ans++;
        } // if
        else if( nums[left] + nums[right] > k)
          right--; // 太大所以動右指標
        else
          left++;
      } // for 
      return ans;
    }
};
