package main

func removeKdigits(num string, k int) string {
	var stk []rune
	var sl int

	for _, r := range num {
		sl = len(stk)
		for sl > 0 && k > 0 && stk[sl-1] > r {
			stk = stk[:sl-1]
			k--
			sl--
		}
		stk = append(stk, r)
	}

	sl = len(stk)
	for sl > 0 && k > 0 {
		stk = stk[:sl-1]
		sl--
		k--
	}

	for sl > 0 && stk[0] == '0' {
		stk = stk[1:]
		sl--
	}

	if sl <= 0 {
		return "0"
	}

	return string(stk)
}
