package main

func combinationSum(c []int, tg int) [][]int {
	var ans [][]int
	combSumBack(&c, &tg, []int{}, 0, 0, &ans)
	return ans
}

func combSumBack(c *[]int, tg *int, cur []int, curSum, prevIdx int, ans *[][]int) {
	if curSum == *tg {
		res := make([]int, len(cur))
		copy(res, cur)
		*ans = append(*ans, res)
		return
	}

	for i := prevIdx; i < len(*c); i++ {
		s := curSum + (*c)[i]
		if s > *tg {
			continue
		}

		combSumBack(c, tg, append(cur, (*c)[i]), s, i, ans)
	}
}
