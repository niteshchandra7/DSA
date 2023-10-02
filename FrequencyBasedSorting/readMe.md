Given a string A containing lowercase english letters of length N, 
you need to sort it decreasing order based on the frequency of the 
characters and return the sorted string.

Note:
1. If two characters have equal frequency, they should be sorted alphabetically.
2. The frequency of a character is the number of times it appears in the string

Approach:
Priority Queue Based Solution

Time Complexity: O(N + K.logK), where K is number of distinct letters

Space Complexity: O(K)