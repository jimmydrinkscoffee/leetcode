package main

func maximalRectangle(matrix [][]byte) int {
	ans := 0
	h := make([]int, len(matrix[0]))
	for _, r := range matrix {
		for i, c := range r {
			if c == '1' {
				h[i]++
			} else {
				h[i] = 0
			}
		}
		ans = max(ans, largestRectangleArea(h))
	}
	return ans
}
