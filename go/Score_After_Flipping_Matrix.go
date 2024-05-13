package main

func matrixScore(grid [][]int) int {
	c, r := len(grid), len(grid[0])
	for j := 0; j < c; j++ {
		if grid[j][0] == 0 {
			for i := 0; i < r; i++ {
				grid[j][i] = 1 - grid[j][i]
			}
		}
	}
	ans := 0
	for i := 0; i < r; i++ {
		cnt := 0
		for j := 0; j < c; j++ {
			cnt += grid[j][i]
		}
		ans = ans*2 + max(cnt, c-cnt)
	}
	return ans
}
