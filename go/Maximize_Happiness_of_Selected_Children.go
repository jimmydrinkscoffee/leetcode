package main

import "sort"

func maximumHappinessSum(happiness []int, k int) int64 {
	idx := make([]int, len(happiness))
	for i := 0; i < len(idx); i++ {
		idx[i] = i
	}
	sort.Slice(happiness, func(i, j int) bool {
		return happiness[idx[i]] > happiness[idx[j]]
	})
	ans := int64(0)
	for i := 0; i < k; i++ {
		nx := int64(happiness[idx[i]] - i)
		if nx < 0 {
			return ans
		}
		ans += nx
	}
	return ans
}
