class Solution {
public:
    int largestAltitude(vector<int>& gain) {
      int high = 0;
      vector<int> att(gain.size()+1);
      att[0] = 0;
      for(int i = 0 ; i < gain.size() ; i++ ){
        high += gain[i];
        att[i+1] = high;
      } // for

      return *max_element(att.begin(),att.end());;
    }
};
