package main

func maximalRectangle(matrix [][]byte) int {
	ans := 0
	ht := make([]int, len(matrix[0])+1)
	for _, r := range matrix {
		for i, c := range r {
			if c == '1' {
				ht[i]++
			} else {
				ht[i] = 0
			}
		}
		var stk []int
		for i, h := range ht {
			for len(stk) > 0 && h < ht[stk[len(stk)-1]] {
				top := stk[len(stk)-1]
				stk = stk[:len(stk)-1]
				l := i
				if len(stk) > 0 {
					l = i - stk[len(stk)-1] - 1
				}
				ans = max(ans, ht[top]*l)
			}
			stk = append(stk, i)
		}
	}
	return ans
}
