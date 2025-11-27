class Solution {
public:
    string reverseVowels(string s) {
      int left = 0;
      int right=s.size()-1;
      while(left < right){
        if( isVowels(s[left]) && isVowels(s[right]) ){
          swap(s[left],s[right]);
          left++;
          right--;
        } // if

        else if( isVowels(s[left]) ){
          right--;
        } // else if

        else if( isVowels(s[right]) ){
          left++;
        } // else if

        else{
          left++;
          right--;
        } // else
      } // while
      return s;
    }

    bool isVowels(char c){
      if( c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' ||
          c == 'o' || c == 'O' || c == 'u' || c == 'U' )
        return true;
      else 
        return false;
    } // isVowels
};
