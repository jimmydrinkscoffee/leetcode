package main

import "sort"

func kthSmallestPrimeFraction(arr []int, k int) []int {
	var s [][]int
	for i := 0; i < k; i++ {
		for j := i + 1; j < len(arr); j++ {
			s = append(s, []int{arr[i], arr[j]})
		}
	}
	sort.Slice(s, func(i, j int) bool {
		return s[i][0]*s[j][1] < s[i][1]*s[j][0]
	})
	return s[k-1]
}
