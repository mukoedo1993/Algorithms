#include<vector>
#include<iostream>
using namespace std;
class Solution{
    public:
vector<vector<string>> solveNQueens(int n) {
sols_.clear();
board=vector<string>(n,string(n,'.'));
cols_=vector<int>(n,0);
diags1_=vector<int>(2*n-1,0);
diags2_=vector<int>(2*n-1,0);
n_queens(n,0);
return sols_;
}
private:
vector<string>board;
vector<int>cols_;
vector<int>diags1_;
vector<int>diags2_;
vector<vector<string>>sols_;

bool available(int x,int y,int n)
{
    return !cols_[x]
    &&    !diags1_[x+y]
    &&    !diags2_[x-y+n-1];//x-y belongs to an integer set that [-n+1,0]
    //But the index cannot be a minus value, so we add n-1 to amke it [0,n-1]
}
void updateBoard(int x,int y,int n,bool is_put)
{
    cols_[x]=is_put;
    diags1_[x+y]=is_put;
    diags2_[x - y + n - 1] = is_put;
    board[y][x] = is_put ? 'Q' : '.';

}
void n_queens(const int n,const int y){
    if(y==n){
        //find one
        sols_.push_back(board);
        return;
    }
    //Try every column
    for(int x=0;x<n;x++){
        if(!available(x,y,n))continue;
        updateBoard(x,y,n,true);
        n_queens(n,y+1);
        updateBoard(x,y,n,false);
    }

}

};
ostream& operator << (ostream&os,const vector<vector<string>>&orig)
{
    for( const auto& i: orig)
    {os<<"this solution:\n ";
    for( const auto& i1: i)
    {
        
        os<<i1<<'\n';
    }
    }
    return os;
}
int main(){
    Solution soln;
  auto rslt=soln.solveNQueens(7);
  std::cout<<rslt;
}