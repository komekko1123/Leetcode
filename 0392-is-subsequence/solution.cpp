class Solution {
public:
    bool isSubsequence(string s, string t) {
      int n = s.size(), n_index = 0;
      for(int i = 0 ; i < t.size() ; i++){
        if(t[i] == s[n_index])
          n_index++;
        if(n == n_index)
          break;
      } // for

      return n == n_index;

    }
};
