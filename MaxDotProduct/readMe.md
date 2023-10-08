LeetCode 1458
Given two arrays nums1 and nums2.
Return the maximim dot product between non-empty subsequence of nums1
and nums2 with the same length.

# Memoization
dp[i][j] = max(dp[i][j+1],dp[i+1][j])
dp[i][j] = max(dp[i][j],dp[i+1][j+1]+(nums1[i]*nums2[j]))
dp[i][j] = max(dp[i][j],nums1[i]*nums2[j])

# Tabulation

dp[i][j] = max(dp[i-1][j-1]+(nums1[i]*nums2[j]),dp[i][j-1])
dp[i][j] = max(dp[i][j],dp[i-1][j])
dp[i][j] = max(dp[i][j],nums1[i]*nums2[j])

# Time Complexity
O(N*M)
# Space Complexity
O(N*M)