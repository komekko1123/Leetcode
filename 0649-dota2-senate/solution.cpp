class Solution {
public:
    string predictPartyVictory(string senate) {
      queue<int> Rq, Dq;
      for(int i = 0 ; i < senate.size() ;i++){
        if( senate[i] == 'D')
          Dq.push(i);
        else
          Rq.push(i);    
      } // for
      while( ! Dq.empty() &&  ! Rq.empty() ){
        int Ri = Rq.front();
        int Di = Dq.front();
        Rq.pop();
        Dq.pop();
        if(Ri < Di )
          Rq.push(Ri+senate.size());
        else
          Dq.push(Di+senate.size());
      } // return

      if( ! Dq.empty() )
        return "Dire";
      else
        return "Radiant";
    }
};
