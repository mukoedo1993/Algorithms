Method 1: brute force:
time complexity(O(n^2))
space complexity(O(1))
For column i, the rain it can trap
min(max(h[0~i]),max(h[i~n]))-h[i]

ans=sum(r[i])
But TSL...

Method 2:
prefix max?
We can pre-compute the max of h[0~i]
and h[i~n-1] in O(n):
l(i):=max(h[0~i])
r(i):=max(h[i~n])

l(i):=max(h[i],l[i-1]) i:0~n-1
r(i):=max(h[i],r[i+1]) i:n-1~0

for each column, query the max
reduced to O(1)

Time complexity: O(n)
Space complexity: O(n)
