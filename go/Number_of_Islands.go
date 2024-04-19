package main

func numIslands(g [][]byte) int {
	ans := 0
	hz, vt := []int{1, -1, 0, 0}, []int{0, 0, -1, 1}
	h, v := len(g), len(g[0])
	var dfs func(int, int) int
	dfs = func(x, y int) int {
		if g[x][y] == '0' {
			return 0
		}
		g[x][y] = '0'
		for i := 0; i < 4; i++ {
			nx, ny := x+hz[i], y+vt[i]
			if nx < 0 || ny < 0 || nx >= h || ny >= v {
				continue
			}
			dfs(nx, ny)
		}
		return 1
	}
	for x := 0; x < h; x++ {
		for y := 0; y < v; y++ {
			ans += dfs(x, y)
		}
	}
	return ans
}
