pesudocode: 
available(x,y):
   return !col(x)
   and !diag1(x,y)
   and !diag2(x,y)
   
 
n_queen(y,n,b,ans):
   if y==n:
   ans+=b
   return
   
 for x in range(0,n):
  if !available(x,y): continue
  put(x,y+b)
  n_queen(y+1,n,b,ans)
  remove(x,y,b)

I personally prefer next_permutation, which is slower but easier.
Solution.cpp is Huahua's solution.
