package main

func islandPerimeter(g [][]int) int {
	p := 0
	hz, vt := []int{0, -1}, []int{-1, 0}
	h, v := len(g), len(g[0])
	for x := 0; x < h; x++ {
		for y := 0; y < v; y++ {
			if g[x][y] == 0 {
				continue
			}
			p += 4
			for i := 0; i < 2; i++ {
				nx, ny := x+hz[i], y+vt[i]
				if nx < 0 || ny < 0 || g[nx][ny] == 0 {
					continue
				}
				p -= 2
			}
		}
	}
	return p
}
