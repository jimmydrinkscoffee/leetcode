package main

func robotSim(commands []int, obstacles [][]int) int {
	x, y, ans := 0, 0, 0
	dirs := [][]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}
	d, l := 0, len(dirs)
	m := make(map[int]map[int]bool)
	for _, o := range obstacles {
		if _, ok := m[o[0]]; !ok {
			m[o[0]] = make(map[int]bool)
		}
		m[o[0]][o[1]] = true
	}
	move := func(cmd int) {
		switch cmd {
		case -1:
			d = (d + 1) % l
		case -2:
			d = (d - 1 + l) % l
		default:
			for cmd > 0 {
				cmd--
				nx, ny := x+dirs[d][0], y+dirs[d][1]
				if _, ok := m[nx][ny]; ok {
					return
				}
				ans, x, y = max(ans, nx*nx+ny*ny), nx, ny
			}
		}
	}
	for _, cmd := range commands {
		move(cmd)
	}
	return ans
}
