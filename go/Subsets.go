package main

func subsets(n []int) [][]int {
	ans := [][]int{{}}
	var v []int

	var f func(int)
	f = func(prev int) {
		if len(v) == len(n) {
			return
		}

		for i := prev + 1; i < len(n); i++ {
			v = append(v, n[i])
			r := make([]int, len(v))
			copy(r, v)
			ans = append(ans, r)
			f(i)
			v = v[:len(v)-1]
		}
	}

	f(-1)
	return ans
}
