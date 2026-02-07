class Solution {
public:
    int maxVowels(string s, int k) {
      int current_sum = 0, max_sum = 0;
      for( int i = 0 ; i < k ; i++){ // 先掃描一半
          current_sum += isVowels(s[i]);
      } // for
      
      max_sum = current_sum;
      for(int i = k ; i < s.size() ; i++){
        current_sum += isVowels(s[i]) - isVowels(s[i-k]);
        max_sum = max(max_sum, current_sum);
      } // for
      
      return max_sum;

    }

    int isVowels(char c){
      if( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' )
        return 1;
      else 
        return 0;
    }
};
