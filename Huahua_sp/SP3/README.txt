Motivation:
 Given a 1D array of n elements [2,5,-1,3,6]
 range sum query: what's the sum from 2nd element to 4th element query(2,4)? 5+ -1 +3=7
 
 Naive implementation: O(n) per query.
 Use DP to pre-compute the prefix sums in O(n) [2,5,-1,3,6]->[2,7,6,9,15]
 reduce query to O(1). query(2,4)=sum(n1,...n4)-sum(n1,...n1)=9-2=7
 WHat if the values of elements can change? O(n)
 
 Fenwick tree was proposed to solve the prefix sum problem:
 The idea is to store partial sum in each node and get total sum by traversing the tree from leaf to root.
 The tree has a height of log(n)
 Query: O(log(n))
 Update: O(log(n))
 
