空间复杂度 = 每次递归需要占用的新空间*递归的深度 √


Equation	Time	Space	Examples
T(n) = 2*T(n/2) + O(n)	O(nlogn)	O(logn)	quick_sort
T(n) = 2*T(n/2) + O(n)	O(nlogn)	O(n + logn)	merge_sort
T(n) = T(n/2) + O(1)	O(logn)	O(logn)	Binary search
T(n) = 2*T(n/2) + O(1)	O(n)	O(logn)	Binary tree traversal
T(n) = T(n-1) + O(1)	O(n)	O(n)	Binary tree traversal
T(n) = T(n-1) + O(n)	O(n^2)	O(n)	quick_sort(worst case)
T(n) = n * T(n-1)	O(n!)	O(n)	permutation
T(n) = T(n-1)+T(n-2)+…+T(1)	O(2^n)	O(n)	combination
