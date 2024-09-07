package main

func construct2DArray(original []int, m int, n int) [][]int {
	if len(original) != m*n {
		return [][]int{}
	}
	ans := make([][]int, m)
	for i := range m {
		a := make([]int, n)
		for j := range n {
			a[j] = original[m*n+j]
		}
		ans[i] = a
	}
	return ans
}
