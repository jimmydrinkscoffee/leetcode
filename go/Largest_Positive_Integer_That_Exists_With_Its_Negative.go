package main

func findMaxK(nums []int) int {
	m, mx := make(map[int]bool), -1
	for _, n := range nums {
		_, ok := m[-n]
		if n > 0 {
			if ok {
				mx = max(mx, n)
			}
		} else if ok {
			mx = max(mx, -n)
		}
		m[n] = true
	}
	return mx
}
