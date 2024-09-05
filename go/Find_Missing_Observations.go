package main

func missingRolls(rolls []int, mean int, n int) []int {
	needs := 0
	for _, r := range rolls {
		needs += r
	}
	needs = mean*(len(rolls)+n) - needs
	if needs < n || n*6 < needs {
		return []int{}
	}
	i, mod := needs/n, needs%n
	ans := make([]int, n)
	for j := 0; j < mod; j++ {
		ans[j] = i + 1
	}
	for j := mod; j < n; j++ {
		ans[j] = i
	}
	return ans
}
