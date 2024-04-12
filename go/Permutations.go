package main

import "slices"

func permute(nums []int) [][]int {
	var ans [][]int
	betterPermuteRec(&nums, 0, &ans)
	return ans
}

func permuteRec(n *[]int, m *map[int]bool, cur []int, ans *[][]int) {
	if len(*m) == len(*n) {
		res := make([]int, len(cur))
		copy(res, cur)
		*ans = append(*ans, res)
		return
	}

	for _, v := range *n {
		if _, ok := (*m)[v]; ok {
			continue
		}
		(*m)[v] = true
		permuteRec(n, m, append(cur, v), ans)
		delete(*m, v)
	}
}

func betterPermuteRec(n *[]int, curPos int, ans *[][]int) {
	l := len(*n)
	if curPos == l {
		*ans = append(*ans, slices.Clone(*n))
		return
	}

	betterPermuteRec(n, curPos+1, ans)

	for i := curPos + 1; i < l; i++ {
		(*n)[i], (*n)[curPos] = (*n)[curPos], (*n)[i]
		betterPermuteRec(n, curPos+1, ans)
		(*n)[curPos], (*n)[i] = (*n)[i], (*n)[curPos]
	}
}
