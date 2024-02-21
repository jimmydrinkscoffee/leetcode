package main

import (
	"sort"
)

// func closeStrings(word1 string, word2 string) bool {
// 	if len(word1) != len(word2) {
// 		return false
// 	}
// 	m1 := make(map[rune]int)
// 	m2 := make(map[rune]int)
// 	for _, c := range word1 {
// 		m1[c]++
// 	}
// 	for _, c := range word2 {
// 		m2[c]++
// 	}
// 	m12 := make(map[int]int)
// 	m22 := make(map[int]int)
// 	for _, v := range m1 {
// 		m12[v]++
// 	}
// 	for _, v := range m2 {
// 		m22[v]++
// 	}
// 	for k, v := range m12 {
// 		if v != m22[k] {
// 			return false
// 		}
// 	}
// 	return true
// }

func closeStrings(word1 string, word2 string) bool {
	l := len(word1)
	if l != len(word2) {
		return false
	}
	m1 := make([]int, 26)
	m2 := make([]int, 26)
	for i := 0; i < l; i++ {
		m1[word1[i]-'a']++
		m2[word2[i]-'a']++
	}
	for i := 0; i < l; i++ {
		if (m1[i] == m2[i] && m1[i] <= 0) || (m1[i] > 0 && m2[i] > 0) {
			continue
		}
		return false
	}
	sort.Ints(m1)
	sort.Ints(m2)
	for i := 0; i < 26; i++ {
		if m1[i] != m2[i] {
			return false
		}
	}
	return true
}

func equalPairs(grid [][]int) int {
	return 0
}
