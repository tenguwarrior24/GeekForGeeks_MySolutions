class Solution {
public:
    typedef unordered_set<string> U_SET;
    typedef set<string> SET;
    
    void dfs(int r, int c, string str, vector<vector<char>> &board, vector<vector<int>> &vis, 
    U_SET &dict, U_SET &growth, SET &res){
        
        int row = board.size();
        int col = board[0].size();
        int r1, c1;
        int delta_r[] = {-1, -1, 0, 1, 1, 1, 0, -1}; 
        int delta_c[] = {0, 1, 1, 1, 0, -1, -1, -1,};
        
        vis[r][c] = 1;
        str += board[r][c];
        
        if(!growth.count(str)){vis[r][c] = 0; return;}
        if(dict.count(str) && !res.count(str)){res.insert(str);}
  
        for(int i = 0; i < 8; i++ ){
            r1 = r + delta_r[i];
            c1 = c + delta_c[i];
            if(r1 >= 0 && r1 < row && c1 >= 0 && c1 < col && !vis[r1][c1]){
                dfs(r1, c1, str,  board, vis, dict, growth, res);
      
            }
        }
        vis[r][c] = 0;
        
    }
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    
	    vector<string> result; 
	    
	    U_SET dict;
	    U_SET growth;
        SET res;
        unordered_set<char> s;

        int row = board.size();
        int col = board[0].size();
    
        string str = "";
        
	    for(auto x : dictionary){
	        s.insert(x[0]);
	        dict.insert(x);
	        for(int i= 0; i<x.length(); i++){
	            str+=x[i];
	            growth.insert(str);
	        }
	        str = "";
	    }
	    
	    vector<vector<int>> visited(row, vector<int>(col, 0));
	    
	    for(int r = 0; r < row; r ++){
	        for (int c = 0; c < col; c++){
	            if(s.count(board[r][c])){
	                str = "";
	                dfs(r, c, str, board, visited, dict, growth, res);
	            }
	        }
	    }
	    for(set<string> :: iterator it = res.begin(); it!=res.end(); ++it){
	        result.push_back(*it);
	    }
	    
	    return result;
	    
	}
};
