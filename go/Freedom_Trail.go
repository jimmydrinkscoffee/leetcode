package main

import (
	"math"
)

func findRotateSteps(rg string, key string) int {
	m := make(map[byte][]int)
	for i := 0; i < len(rg); i++ {
		m[rg[i]] = append(m[rg[i]], i)
	}
	abs := func(n int) int {
		if n >= 0 {
			return n
		}
		return -n
	}
	prev, cur := make([]int, len(rg)+1), make([]int, len(rg)+1)
	for k := len(key) - 1; k >= 0; k-- {
		for r := len(rg) - 1; r >= 0; r-- {
			if k > 0 && rg[r] != key[k-1] {
				continue
			}
			if key[k] == rg[r] {
				cur[r] = 1 + prev[r]
				continue
			}
			cur[r] = math.MaxInt32
			for _, nx := range m[key[k]] {
				cur[r] = min(cur[r], 1+min(abs(r-nx), len(rg)-nx+r, len(rg)-r+nx)+prev[nx])
			}
		}
		copy(prev, cur)
	}
	return cur[0]
}
