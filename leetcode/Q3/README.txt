Solution1.cpp my own's

Solution2.cpp Huahua's: optimized brute force

Comment:
char's range is 0~127.

Huahua's soln and comments:
1: Use Hashtable to store the last index of each character.
2: Keep track the valid starting point,
when there is a match, update the starting point to the current one.

i=max(i,s[j]+1), len=j-i+1
Time complexity(O(n)), 12 ms
Space complexity(O(128))

