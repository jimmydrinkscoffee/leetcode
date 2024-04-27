package main

import "math"

func findRotateSteps(rg string, key string) int {
	m := make(map[byte][]int)
	for i := 0; i < len(rg); i++ {
		m[rg[i]] = append(m[rg[i]], i)
	}
	dp := make([][]int, len(key))
	for i := 0; i < len(key); i++ {
		dp[i] = make([]int, len(rg))
		for j := 0; j < len(rg); j++ {
			dp[i][j] = -1
		}
	}
	abs := func(n int) int {
		if n >= 0 {
			return n
		}
		return -n
	}
	var mem func(k, r int) int
	mem = func(k, r int) int {
		if k == len(key) {
			return 0
		}
		if dp[k][r] != -1 {
			return dp[k][r]
		}
		if key[k] == rg[r] {
			dp[k][r] = 1 + mem(k+1, r)
		}
		dp[k][r] = math.MaxInt32
		for _, nx := range m[key[k]] {
			dp[k][r] = min(dp[k][r], 1+min(abs(r-nx), len(rg)-nx+r, len(rg)-r+nx)+mem(k+1, nx))
		}
		return dp[k][r]
	}
	return mem(0, 0)
}
