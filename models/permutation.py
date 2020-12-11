#Permutation:
#pseudocode only!!!!!

nums=[...]
ans= []
used=False*nums.size()


# p(m,n)
def  dfs(n,cur):
 if(cur.size()==n):
    ans.append(cur)
    return
    
 for i=0 to nums.size():
     if used[i]: continue
     used[i]=True
     cur.append(nums[i])
     dfs(n,cur)
     cur.pop()
     used[i]=False
     
for i=0 to nums.size():
  dfs(i,0,[])
