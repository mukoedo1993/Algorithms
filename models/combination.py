#pesudocode

#Combination
nums=[...]#change here...
ans=[]

#C(m,n)# m==nums.size()
func dfs(n,s,cur):
   if(cur.size()==n)
     ans.append(cur)
     return
 
 for i= s to num.size():
   cur.append(nums[i])
   dfs(n,i+1,cur)
   cur.pop()

#call the dfs(...)here:....
for i= 0 to nums.size():
   dfs(i,0,[])
