package main

type landPos struct {
	x, y int
}

func findFarmland(g [][]int) [][]int {
	var ans [][]int
	hz, vt := []int{1, 0}, []int{0, 1}
	h, v := len(g), len(g[0])
	tl, br := landPos{300, 300}, landPos{-1, -1}
	var dfs func(x, y int) bool
	dfs = func(x, y int) bool {
		if g[x][y] == 0 {
			return false
		}
		g[x][y] = 0
		if tl.x > x || tl.y > y {
			tl = landPos{x, y}
		}
		if br.x < x || br.y < y {
			br = landPos{x, y}
		}
		for i := 0; i < 2; i++ {
			nx, ny := x+hz[i], y+vt[i]
			if nx < 0 || ny < 0 || nx >= h || ny >= v {
				continue
			}
			dfs(nx, ny)
		}
		return true
	}
	for x := 0; x < h; x++ {
		for y := 0; y < v; y++ {
			if dfs(x, y) {
				ans = append(ans, []int{tl.x, tl.y, br.x, br.y})
				tl, br = landPos{300, 300}, landPos{-1, -1}
			}
		}
	}
	return ans
}
