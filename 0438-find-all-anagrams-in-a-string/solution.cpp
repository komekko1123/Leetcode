class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
      vector <int> a1(26,0);
      vector <int> a2(26,0);    
      vector <int> ans;
      int i=0, l1 = 0, l2 = 0;
      l1 = s.length();
      l2 = p.length();
      for(i = 0 ; i < l2 ; i++ )
        a2[p.at(i)-'a']++;
      for(i = 0 ; i < l1 ; i++ ){
        if ( i >= l2 )
          a1[s.at(i-l2)-'a']--;
        a1[s.at(i)-'a']++;
        if ( a1 == a2 )
          ans.push_back(i-l2+1);
      } // for
      return ans;
    }
};
