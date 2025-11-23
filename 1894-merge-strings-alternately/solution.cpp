class Solution {
public:
    string mergeAlternately(string word1, string word2) {
       string s;
       int n = ( word1.size() <= word2.size() ) ? word1.size(): word2.size();
       for(int i = 0 ; i < n ; i++){
         s = s + word1[i] + word2[i];
       } // for 
       if( n == word1.size())
         return s + word2.substr(n,word2.size());
       else
         return s + word1.substr(n,word1.size());
    }
};
