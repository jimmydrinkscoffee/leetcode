package main

import (
	"sort"
	"strconv"
)

func findRelativeRanks(score []int) []string {
	idx, res := make([]int, len(score)), make([]string, len(score))
	for i := 0; i < len(idx); i++ {
		idx[i] = i
	}
	sort.Slice(idx, func(i, j int) bool {
		return score[idx[i]] > score[idx[j]]
	})
	for i := 0; i < len(idx); i++ {
		switch i {
		case 0:
			res[idx[i]] = "Gold Medal"
		case 1:
			res[idx[i]] = "Silver Medal"
		case 2:
			res[idx[i]] = "Bronze Medal"
		default:
			res[idx[i]] = strconv.Itoa(i + 1)
		}
	}
	return res
}
