package main

import "sort"

func maximumHappinessSum(h []int, k int) int64 {
	sort.Ints(h)
	ans := int64(0)
	for i, j := 0, len(h)-1; i < k && j >= 0; i, j = i+1, j-1 {
		nx := h[j] - i
		if nx < 0 {
			return ans
		}
		ans += int64(nx)
	}
	return ans
}
