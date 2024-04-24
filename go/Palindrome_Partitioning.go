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
	var sol func(idx int, cur []string)
	sol = func(idx int, cur []string) {
		if idx == len(s) {
			cpy := make([]string, len(cur))
			copy(cpy, cur)
			ans = append(ans, cpy)
			return
		}
		v := ""
		for i := idx; i < len(s); i++ {
			v += string(s[i])
			if checkPal(v) {
				cur = append(cur, v)
				sol(i+1, cur)
				cur = cur[:len(cur)-1]
			}
		}
	}
	sol(0, []string{})
	return ans
}
