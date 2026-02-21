class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
      vector<int> ans;
      int top = 0;
      for(int i = 0 ; i < asteroids.size() ; i++){
        if( top > 0 &&  asteroids[i] > 0 || top < 0 &&  asteroids[i] < 0 || top == 0 ){
          ans.push_back(asteroids[i]);
          top = ans.back();
        } // if
        else if( top == asteroids[i] * -1 && top > 0 ){
          ans.pop_back();
          top = ans.empty() ? 0 : ans.back();
        } // else if

        else if( abs(top) < abs (asteroids[i]) && asteroids[i] < 0 ){
          ans.pop_back();
          top = ans.empty() ? 0 : ans.back();
          i--;
        } // else if

        else if( abs(top) > abs (asteroids[i]) && asteroids[i] >  0 ){
          ans.push_back(asteroids[i]);
          top = ans.back();
        } // else if

        else if( abs(top) < abs (asteroids[i]) && asteroids[i] >  0 ){
          ans.push_back(asteroids[i]);
          top = ans.back();
        } // else if

        else if(  top == asteroids[i] * -1 && top < 0 ){
          ans.push_back(asteroids[i]);
          top = ans.back();
        } // else if
        else{
          continue;
        } // else 
          
      } // for
      return ans;
    }
};
