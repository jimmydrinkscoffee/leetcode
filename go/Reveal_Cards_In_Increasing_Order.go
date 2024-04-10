package main

import (
	"sort"
)

func deckRevealedIncreasing(deck []int) []int {
	sort.Ints(deck)
	ans := []int{deck[len(deck)-1]}
	for i := len(deck) - 2; i >= 0; i-- {
		back := ans[len(ans)-1]
		ans = ans[:len(ans)-1]
		ans = append([]int{deck[i], back}, ans...)
	}
	return ans
}
