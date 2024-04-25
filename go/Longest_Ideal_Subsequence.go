package main

func longestIdealString(s string, k int) int {
	dp := make([][]int, len(s))
	for i := 0; i < len(s); i++ {
		dp[i] = make([]int, 27)
		for j := 0; j < 27; j++ {
			dp[i][j] = -1
		}
	}
	var mem func(idx int, prev byte) int
	mem = func(idx int, prev byte) int {
		if idx == len(s) {
			return 0
		}
		ch := int(prev) - int('a')
		if prev == 0 {
			ch = 26
		}
		if dp[idx][ch] != -1 {
			return dp[idx][ch]
		}
		diff := int(s[idx]) - int(prev)
		if diff < 0 {
			diff = -diff
		}
		dp[idx][ch] = mem(idx+1, prev)
		if prev == 0 || diff <= k {
			dp[idx][ch] = max(dp[idx][ch], 1+mem(idx+1, s[idx]))
		}
		return dp[idx][ch]
	}
	return mem(0, 0)
}
