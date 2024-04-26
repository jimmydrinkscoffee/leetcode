package main

import "math"

func minFallingPathSum(grid [][]int) int {
	r, c := len(grid), len(grid[0])
	dp := make([][]int, r)
	for i := 0; i < r; i++ {
		dp[i] = make([]int, c)
		for j := 0; j < c; j++ {
			dp[i][j] = -1
		}
	}
	var mem func(row, prevCol int) int
	mem = func(row, prevCol int) int {
		if row == r {
			return 0
		}
		if dp[row][prevCol] != -1 {
			return dp[row][prevCol]
		}
		dp[row][prevCol] = math.MaxInt32
		for i := 0; i < c; i++ {
			if i == prevCol {
				continue
			}
			dp[row][prevCol] = min(dp[row][prevCol], grid[row][i]+mem(row+1, i))
		}
		return dp[row][prevCol]
	}
	ans := math.MaxInt32
	for i := 0; i < c; i++ {
		ans = min(ans, grid[0][i]+mem(1, i))
	}
	return ans
}
