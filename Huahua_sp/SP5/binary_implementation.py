
def binary_search(l,r):
  while l<r:
    m=l+(r-l)#2
    if(f(m)):return m
    if(g(m)):
      r=m     #return m#optional
    else:
      l=m+1   #new range[m+1,r)
    return l # or not found
  """
  Time complexity: 
  O(log(n))*O(f(m)+g(m))
  Space complexity:
  O(1)
  """
 
      
