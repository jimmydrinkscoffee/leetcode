package main

func trap(h []int) int {
	var stk []int
	mx := 0
	ans := 0
	for i := 0; i < len(h); i++ {
		if len(stk) == 0 {
			stk = append(stk, i)
			mx = i
			continue
		}

		if h[i] < h[mx] {
			stk = append(stk, i)
			continue
		}

		sub := 0
		for _, v := range stk {
			sub += h[v]
		}
		ans += (i-mx)*h[mx] - sub

		stk = []int{i}
		mx = i
	}

	if len(stk) > 1 {
		var try []int
		for i := len(stk) - 1; i >= 0; i-- {
			try = append(try, h[stk[i]])
		}
		ans += trap(try)
	}
	return ans
}
