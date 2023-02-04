class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      int i = 0, l1 =0, l2 = 0;
      l1 = s1.length();
      l2 = s2.length();
      vector <int> a1(26,0);
      vector <int> a2(26,0);
      if ( l1 > l2) 
        return false;
      for( i = 0 ; i < l1 ; i++ )
        a1[s1.at(i) - 'a']++ ;
      for( i = 0 ; i < l2 ; i++){
        if ( i >= l1)
          a2[s2.at(i-l1) - 'a']-- ;
        a2[s2.at(i) - 'a']++ ;
        if ( a1 == a2 )
          return true;
      } // for
      return false;
    }
};
