package main

import (
	"math"
)

func minimumOperations(g [][]int) int {
	r, c := len(g), len(g[0])
	cols := make([][]int, c)
	for i := 0; i < c; i++ {
		cols[i] = make([]int, 10)
		for j := 0; j < r; j++ {
			cols[i][g[j][i]]++
		}
	}
	return tabMinOperations(r, c, cols)
}

func tabMinOperations(r, c int, cols [][]int) int {
	dp := make([][]int, c+1)
	for i := 0; i < c+1; i++ {
		dp[i] = make([]int, 10)
	}
	for i := c - 1; i >= 0; i-- {
		for j := 0; j < 10; j++ {
			dp[i][j] = math.MaxInt32
			for k := 0; k < 10; k++ {
				if j != k {
					dp[i][j] = min(dp[i][j], r-cols[i][j]+dp[i+1][k])
				}
			}
		}
	}
	ans := math.MaxInt32
	for i := 0; i < 10; i++ {
		ans = min(ans, dp[0][i])
	}
	return ans
}

func memMinOperations(r, c int, cols [][]int) int {
	dp := make([][]int, c+1)
	for i := 0; i < c+1; i++ {
		dp[i] = make([]int, 11)
		for j := 0; j < 11; j++ {
			dp[i][j] = -1
		}
	}
	var sol func(i, prev int) int
	sol = func(i, prev int) int {
		if i >= c {
			return 0
		}
		if dp[i][prev] != -1 {
			return dp[i][prev]
		}
		dp[i][prev] = math.MaxInt32
		for j := 0; j < 10; j++ {
			if j != prev {
				dp[i][prev] = min(dp[i][prev], r-cols[i][j]+sol(i+1, j))
			}
		}
		return dp[i][prev]
	}
	return sol(0, 10)
}
