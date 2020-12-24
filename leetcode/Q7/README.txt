pop operation:
pop=x%10
x/=10

//push operation:
temp=rev*10+pop
rev=temp


However, this apporach is dangerous, because the statement 
temp=rev*10+pop can cause overflow if:
If x is positive
either rev>INT_MAX/10 or rev==INT_MAX/10 and pop>7

else:
rev<INT_MIN/10 or rev==INT_MIN/10 and pop<-8
