package main

func generateParenthesis(n int) []string {
	var ans []string
	back(n, n, "", &ans)
	return ans
}

func back(l, r int, cur string, ans *[]string) {
	if l == 0 && r == 0 {
		*ans = append(*ans, cur)
	}

	if l == 0 {
		for r > 0 {
			cur += ")"
			r--
		}
		*ans = append(*ans, cur)
		return
	}

	if r == 0 {
		return
	}

	back(l-1, r, cur+"(", ans)
	if l == r {
		return
	}

	back(l, r-1, cur+")", ans)
}
