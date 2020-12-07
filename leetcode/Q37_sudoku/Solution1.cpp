
//Author: https://www.geeksforgeeks.org/sudoku-backtracking-7/
//modified by: mukoedo1993
class Solution {
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        //The question on leetcode promised that there is EXACTLY one valid solution.
        //So, we could write our code like below:
        // Notice that the board is passed by reference, what a beautiful design!!!
        if(solve(board)) return;
    }
    private:
    
    bool solve(vector<vector<char>>& board){
        int row, col;
        if(!findNoUnassigned(board,row,col))return true;
        for(int c=1;c<=9;c++)
        {
            if(is_legal(board,row,col,'0'+c))
            { board[row][col]='0'+c;
           if(solve(board))return true;
            }
        }
        board[row][col]='.';
        return false;
    }
    
    
    bool 
        constexpr
        findNoUnassigned(const vector<vector<char>>&board, int& row, int &col){
        //Notice that here: row and col are passed by reference... 
        //We could modify row and col here: 
        for(row=0;row<9;row++)
            for(col=0;col<9;col++)
            {
                if(board[row][col]=='.')return true;
            }
        return false;
    }
    
    bool is_legal(const vector<vector<char>>&board,int row, int col,const char c ){
       int row_=3*(row/3),  col_=3*(col/3);
       for(int i=0;i<9;i++)
           if(board[row][i]==c)return false;
        for(int i=0;i<9;i++)
            if(board[i][col]==c)return false;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(board[row_+i][col_+j]==c)return false;
        return true;
    }
    
};
