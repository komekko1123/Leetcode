class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
       stack<vector<int>> st;
       vector<bool> open_rooms(rooms.size(),false);
       open_rooms[0] = true;
       st.push(rooms[0]);
       while( !st.empty() ){
         vector<int> temp = st.top();
         st.pop();
         for( int keys : temp){
           if(open_rooms[keys] != true){
             open_rooms[keys] = true;
             st.push(rooms[keys]);            
           } // if
         } // for
       } // while
       
       //vector_print(open_rooms);

       return find(open_rooms.begin(), open_rooms.end(), false) == open_rooms.end() ;
    }

    // void vector_print(vector<bool> v){
    // vector<bool>::iterator it;
    // for(it = v.begin(); it != v.end(); it++){
	//   cout << *it << " ";
    // }
    // cout << endl;
    // }
};


