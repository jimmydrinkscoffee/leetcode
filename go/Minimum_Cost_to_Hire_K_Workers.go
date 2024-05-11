package main

import "sort"

func mincostToHireWorkers(q []int, w []int, k int) float64 {
	l := len(q)
	idx := make([]int, l)
	for i := 0; i < l; i++ {
		idx[i] = i
	}
	sort.Slice(idx, func(i, j int) bool {
		return q[idx[i]]*w[idx[j]] > q[idx[j]]*w[idx[i]]
	})
	wg := idx[k-1]
	ans := q[idx[k-1]] * w[wg]
	for i := 0; i < k-1; i++ {
		ans += q[idx[i]] * w[wg]
	}
	for i := k; i < l; i++ {
		nx := (ans/w[wg] - q[idx[i-k]] + q[idx[i]]) * w[idx[i]]
		if nx*q[wg] < ans*q[idx[i]] {
			ans, wg = nx, idx[i]
		}
	}
	return float64(ans) / float64(q[wg])
}
