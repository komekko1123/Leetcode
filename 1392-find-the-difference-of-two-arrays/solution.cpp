class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
      unordered_set <int> st1,st2;
      vector<int> ans1,ans2;
      for(int i = 0 ; i < nums1.size() ; i++){
        st1.insert(nums1[i]);
      } // for
      for(int i = 0 ; i < nums2.size() ; i++){
        st2.insert(nums2[i]);
      } // for

      for (auto it = st1.begin(); it != st1.end(); ++it) {
        if( st2.count(*it) == 0 )
          ans1.push_back(*it);  
      } //for

      for (auto it = st2.begin(); it != st2.end(); ++it){
        if( st1.count(*it) == 0 )
          ans2.push_back(*it);  
      } // if 
      return {ans1,ans2};
    }
};
