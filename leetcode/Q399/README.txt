Solution 1:
Graph+ DPS:
A/B=2
g[A][B]=2 /g[B][A]=1/2

time complexity: O(e+q*e)
Space complexity: O(e)


Solution 2:
Union Find:
A/B=2-> parents[A]={B,2}
        parents[B]={B,1.0/2.0}
        
B/C=3 -> parents[C]={B,1.0/3.0}

A/C? p[A].key == p[C].key == B
=p[A].val/p[C].val=2/(1.0/3)=6

Time complexity: O(e+q)
Space complexity: O(e)

