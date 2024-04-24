package main

func partition(s string) [][]string {
	var ans [][]string
	checkPal := func(v string) bool {
		l := len(v) / 2
		for i := 0; i < l; i++ {
			if v[i] != v[len(v)-1-i] {
				return false
			}
		}
		return true
	}
	var cur []string
	var sol func(idx int)
	sol = func(idx int) {
		if idx == len(s) {
			cpy := make([]string, len(cur))
			copy(cpy, cur)
			ans = append(ans, cpy)
			return
		}
		for i := idx; i < len(s); i++ {
			if checkPal(s[idx : i+1]) {
				cur = append(cur, s[idx:i+1])
				sol(i + 1)
				cur = cur[:len(cur)-1]
			}
		}
	}
	sol(0)
	return ans
}
