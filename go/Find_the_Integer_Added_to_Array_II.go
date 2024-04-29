package main

import (
	"math"
	"sort"
)

func minimumAddedInteger(nums1 []int, nums2 []int) int {
	sort.Ints(nums1)
	sort.Ints(nums2)
	check := func(df int) bool {
		skipped := 0
		for i, j := 0, 0; i < len(nums1) && j < len(nums2); i++ {
			if nums2[j]-nums1[i] != df {
				skipped++
			} else {
				j++
			}
		}
		return skipped <= 2
	}
	ans := math.MaxInt32
	for i := 0; i < 3 && i < len(nums1); i++ {
		diff := nums2[0] - nums1[i]
		if check(diff) {
			ans = min(ans, diff)
		}
	}
	return ans
}
