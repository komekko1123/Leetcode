class Solution {
public:
    string decodeString(string s) {
      int i = 0;
      string ans = decode(s,i);
      return ans;
    }

    string decode(const string &s, int &i){
      
      string str;
      int num = 0;
      while( i < s.size() ){
        char c = s[i];
        if( isdigit(c) ){
          num = num * 10 + (c - '0');
          i++; 
        } // if

        else if( c == ']'){
            i++;
            return str;
        } // else if
        
        else if( c == '['){
            i++;
            string temp = decode(s,i);
            for(int j = 0 ; j < num ; j++){
              str += temp; 
            } // for
            num = 0;
        } // else if

        else{
          str = str + c;
          i++;
        } // else
      } //while 
      return str;
    } // decode
};
