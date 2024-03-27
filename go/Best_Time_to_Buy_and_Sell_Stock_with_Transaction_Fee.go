package main

func maxProfit(prices []int, fee int) int {
	vTrue := 0
	vFalse := 0
	for i := len(prices) - 1; i >= 0; i-- {
		vTrue, vFalse = max(-prices[i]+vFalse, vTrue), max(prices[i]-fee+vTrue, vFalse)
	}

	return vTrue
}
