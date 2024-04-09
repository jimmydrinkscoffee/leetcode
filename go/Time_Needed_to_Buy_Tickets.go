package main

func timeRequiredToBuy(tickets []int, k int) int {
	tg := tickets[k]
	ans := k
	for i := 0; i < k; i++ {
		if tickets[i] >= tg {
			ans += tg
		} else {
			ans += tickets[i]
		}
	}

	for i := k + 1; i < len(tickets); i++ {
		if tickets[i] >= tg-1 {
			ans += tg - 1
		} else {
			ans += tickets[i]
		}
	}

	return ans
}
