#include<iostream>
int main()
{
    for(int i=0;i<5;i++)
    for(int j=0;j<=4;j++)
    {
        if(j==3)continue;//If it is true, it will ignore all codes below IN THIS TERM OF LOOP...
        //BUt it will continue...
        std::cout<<i<<" "<<j;
        std::cout<<" mark!\n";
    }
}