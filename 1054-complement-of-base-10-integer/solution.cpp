class Solution {
public:
    int bitwiseComplement(int n) {
      if( n == 0)
        return 1;
      int a = 0, b = n;
      while( b > 0 ){
         b >>= 1;
         a++;
      } // while
      a = pow(2,a); 
      return  n ^ a-1;
    }
};
