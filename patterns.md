# Patterns in Algorithms
List of all patterns and subpatterns in algorithms. It lists the patterns of questions and constraints, and the idea and transition.


## DP

- 0-1 Knapsack or Pick-skip: Generally asked in subset / subsequence type problems where a subset is optimal. Constraints are usually `~O(n)`. The idea is that you have 2 choices, Either pick an item or skip it.

- [LCS](https://www.youtube.com/watch?v=sSno9rV8Rhg): Longest Common Subsequence is a known pattern. Constraints are usually about `O(m*n)` where `m` and `n` are lengths of two different sequences. LCS has a clear pattern, `dp[i][j] = 1+dp[i-1][j-1] if i == j else max(dp[i][j-1], dp[i-1][j])`.

- [LIS](https://takeuforward.org/data-structure/longest-increasing-subsequence-dp-41/): Longest Increasing Subsequence. Constraints are usually `~O(n^2)`, but advanced LIS has `O(n log n)`. LIS also has a clear pattern. It answers the question, what is the LIS that strictly includes the *current* element. `dp[i] = max(dp[i], 1+dp[j]) if nums[j] < nums[i]`. 

- Range/Interval DP: Questions are generally about finding the optimal sequence of actions on an array, which transforms the array itself. Constraints allow for a `O(n^3)` solution. For example [Leetcode 312](https://leetcode.com/problems/burst-balloons/). The core idea is an equation like this `dp[l][r] = dp[l][x] + d[x+1][r] + cost` where `l <= x < r`.

- Tree DP: Generally the questions are about trees, like their diameter or, generally re-rooting type questions. Constraints are usually `O(n)`. The idea is to do a `dfs` on an arbitrary node to setup, then a second `dfs` is done and memoized to get the answer. 


