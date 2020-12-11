author: mukoedo1993
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
       
       
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
            if(dfs(board,word,i,j))return true;
        return false;
    }
    private:
    
 
   bool dfs( vector<vector<char>>& board, string& curr,int row, int col){
        if(curr.empty()){return true;}
         if(board[row][col]=='.')return false;
           
        if(board[row][col]!=curr[0])return false;

            else{
            char it=curr[0];
            curr.erase(curr.begin());
                if(curr.empty())return true;
           board[row][col]='.';
            if(row>0)
            {if(dfs(board,curr,row-1,col))return true;}
            if(row<board.size()-1)
            {if(dfs(board,curr,row+1,col))return true;}
            if(col>0)
            {if(dfs(board,curr,row,col-1))return true;}
            if(col<board[0].size()-1)
            {if( dfs(board,curr,row,col+1))return true;}
            //backtracking:
            curr=string(1,it)+curr;
            board[row][col]=it;
            return false;
            }
        return false;
    }
    
};
