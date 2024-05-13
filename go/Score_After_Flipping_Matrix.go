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
	v := make([]int, c)
	for i := 0; i < r; i++ {
		cnt := 0
		for j := 0; j < c; j++ {
			if grid[j][i] == 1 {
				cnt++
			} else {
				cnt--
			}
		}
		for j := 0; j < c; j++ {
			n := grid[j][i]
			if cnt < 0 {
				n = 1 - n
			}
			v[j] = v[j]*2 + n
		}
	}
	ans := 0
	for _, n := range v {
		ans += n
	}
	return ans
}
