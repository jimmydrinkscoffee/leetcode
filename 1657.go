package main

import (
	"math"
	"sort"
	"strconv"
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
	m := make(map[string]int)
	for _, r := range grid {
		s := ""
		for _, c := range r {
			s += "_" + strconv.Itoa((c))
		}
		m[s]++
	}
	l := len(grid[0])
	cl := len(grid)
	ans := 0
	for i := 0; i < cl; i++ {
		s := ""
		for j := 0; j < l; j++ {
			s += "_" + strconv.Itoa((grid[j][i]))
		}
		if val, ok := m[s]; ok {
			ans += val
		}
	}
	return ans
}

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func maxDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}

	return 1 + max(maxDepth(root.Left), maxDepth(root.Right))
}

func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
	var s1 []int
	var s2 []int
	s1 = leafs(root1, s1)
	s2 = leafs(root2, s2)
	l := len(s1)
	if l != len(s2) {
		return false
	}
	for i := 0; i < l; i++ {
		if s1[i] != s2[i] {
			return false
		}
	}
	return true
}

func leafs(r *TreeNode, l []int) []int {
	if r.Left == nil && r.Right == nil {
		l = append(l, r.Val)
		return l
	}
	if r.Left != nil {
		l = leafs(r.Left, l)
	}
	if r.Right != nil {
		l = leafs(r.Right, l)
	}
	return l
}

func goodNodes(root *TreeNode) int {
	return goodNode(root, math.MinInt32)
}

func goodNode(r *TreeNode, mx int) int {
	if r == nil {
		return 0
	}

	if r.Val >= mx {
		return 1 + goodNode(r.Left, r.Val) + goodNode(r.Right, r.Val)
	}

	return goodNode(r.Left, mx) + goodNode(r.Right, mx)
}
