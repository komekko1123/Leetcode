class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      vector<bool> virtualPF(flowerbed.size(),true);
      for( int i = 0 ; i < flowerbed.size() ; i++){
        if(flowerbed[i] == 1 ){ // 發現有花就去掃描
          virtualPF[i] = false;
        if( i-1 < 0 && i+1 >= flowerbed.size() )
            continue;
        if( i - 1 < 0 ){
            virtualPF[i+1] = false;
            continue;
        } // if
        else if( i+1 >= flowerbed.size() ){
            virtualPF[i-1] = false;
            continue;
        } //else if
        virtualPF[i-1] = false;
        virtualPF[i+1] = false;
        } // if
      } // for    
      
      for(int i =0;i < virtualPF.size() ; i++){
        if(virtualPF[i] == true){ // 種一朵花
          virtualPF[i] == false;
          n--;
          if( i-1 < 0 && i+1 >= flowerbed.size() ){
            continue;
          } // if
          if( i - 1 < 0 ){
            virtualPF[i+1] = false;
            continue;
          } // if
          else if( i+1 >= flowerbed.size() ){
            virtualPF[i-1] = false;
            continue;
          } //else if
          virtualPF[i-1] = false;
          virtualPF[i+1] = false;
        } // if
      } // for
      return n<=0;
    }
};
