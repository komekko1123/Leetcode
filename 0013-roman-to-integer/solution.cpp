class Solution {
public:
    int romanToInt(string s) {
      int result = symbolToValue(s[s.size()-1]);  
      for(int i = 0; i < s.size()-1; i++){
        if( symbolToValue(s[i] ) < symbolToValue(s[i+1]) )
          result -= symbolToValue(s[i]); 
        else
          result += symbolToValue(s[i]);  
      } // for

      return result;
    } // romanToInt

    int symbolToValue(char c){
        if( c == 'I' )
            return 1;
        else if( c == 'V')
            return 5;
        else if( c == 'X')
            return 10;      
        else if( c ==  'L')
            return 50;
        else if( c == 'C')
            return 100;         
        else if( c == 'D')
            return 500;
        else
            return 1000; 
    } // symbolToValue
};
