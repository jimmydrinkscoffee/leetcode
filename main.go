package main

import (
	"fmt"
)

func main() {
	cur := &ListNode{
		Val: 0,
	}
	head := cur
	for i := 1; i < 9; i++ {
		cur.Next = &ListNode{
			Val: i,
		}
		cur = cur.Next
	}
	cur = oddEvenList(head)
	cur = reverseList(cur)
	for cur != nil {
		fmt.Println(cur.Val)
		cur = cur.Next
	}
	fmt.Println(pairSum(head))
	arr := []int{1, 2, 3}
	testSlice(arr)
	fmt.Println(arr)
}

func testSlice(arr []int) {
	arr = append(arr, 4)
	fmt.Println(arr)
}

func pathSum(root *TreeNode, targetSum int) int {
	return betterChildSum(root, []int{}, targetSum)
}

func childSum(n *TreeNode, tg int) (int, []int) {
	if n == nil {
		return 0, []int{}
	}

	cnt := 0
	var res []int
	res = append(res, n.Val)
	if n.Val == tg {
		cnt++
	}

	lc, l := childSum(n.Left, tg)
	rc, r := childSum(n.Right, tg)

	cnt += lc + rc

	for _, v := range l {
		res = append(res, n.Val+v)
		if n.Val+v == tg {
			cnt++
		}
	}

	for _, v := range r {
		res = append(res, n.Val+v)
		if n.Val+v == tg {
			cnt++
		}
	}

	return cnt, res
}

func betterChildSum(n *TreeNode, path []int, tg int) int {
	if n == nil {
		return 0
	}

	path = append(path, n.Val)
	s := 0
	cnt := 0
	for i := len(path) - 1; i >= 0; i-- {
		s += path[i]
		if s == tg {
			cnt++
		}
	}

	return cnt + betterChildSum(n.Left, path, tg) + betterChildSum(n.Right, path, tg)
}

func longestZigZag(root *TreeNode) int {
	if root == nil {
		return 0
	}

	ans := 1
	zigZag(root.Left, true, 2, &ans)
	zigZag(root.Right, false, 2, &ans)

	return ans - 1
}

func zigZag(n *TreeNode, left bool, cur int, ans *int) {
	if n == nil {
		return
	}

	*ans = max(*ans, cur)
	if left {
		zigZag(n.Left, true, 2, ans)
		zigZag(n.Right, false, cur+1, ans)
	} else {
		zigZag(n.Left, true, cur+1, ans)
		zigZag(n.Right, false, 2, ans)
	}
}

func searchBST(root *TreeNode, val int) *TreeNode {
	if root == nil || root.Val == val {
		return root
	}

	if root.Val > val {
		return searchBST(root.Left, val)
	}

	return searchBST(root.Right, val)
}

func deleteNode(root *TreeNode, key int) *TreeNode {
	if root == nil {
		return root
	}

	if root.Val != key {
		root.Left = deleteNode(root.Left, key)
		root.Right = deleteNode(root.Right, key)
		return root
	}

	if root.Left != nil {
		if root.Left.Right == nil {
			root.Val = root.Left.Val
			root.Left = root.Left.Left
			return root
		}

		if m := maxNode(root.Left); m != nil {
			root.Val = m.Val
			return root
		}
	}

	if root.Right != nil {
		if root.Right.Left == nil {
			root.Val = root.Right.Val
			root.Right = root.Right.Right
			return root
		}

		if m := minNode(root.Right); m != nil {
			root.Val = m.Val
			return root
		}
	}

	return nil
}

func minNode(n *TreeNode) *TreeNode {
	cur := n
	for cur.Left.Left != nil {
		cur = cur.Left
	}

	m := cur.Left
	cur.Left = m.Right
	return m
}

func maxNode(n *TreeNode) *TreeNode {
	cur := n
	for cur.Right.Right != nil {
		cur = cur.Right
	}

	m := cur.Right
	cur.Right = m.Left
	return m
}

func minCostClimbingStairs(cost []int) int {
	pi_1 := 0
	pi_2 := 0

	for i := 2; i <= len(cost); i++ {
		pi_1, pi_2 = pi_2, min(pi_1+cost[i-2], pi_2+cost[i-1])
	}

	return pi_2
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func lowestCommonAncestor(r, p, q *TreeNode) *TreeNode {
	if r == nil || r == p || r == q {
		return r
	}

	l := lowestCommonAncestor(r.Left, p, q)
	rt := lowestCommonAncestor(r.Right, p, q)

	if l != nil && rt != nil {
		return r
	}

	if l != nil {
		return l
	}

	return rt
}

func myPow(x float64, n int) float64 {
	if x == 0 {
		return 0
	}
	if x == 1 || n == 0 {
		return 1
	}
	p := n
	if p < 0 {
		p = -p
	}
	res := x * x
	ck := 2
	for ck < p {
		res = res * res
		ck *= 2
	}
	for i := p; i < ck; i++ {
		res /= x
	}
	if p/n < 0 {
		return 1 / res
	}
	return res
}

func rightSideView(root *TreeNode) []int {
	return bfsMostRight(root)
}

func mostRight(arr []*TreeNode) []int {
	l := len(arr)
	if l <= 0 {
		return []int{}
	}

	res := []int{arr[l-1].Val}

	var nexts []*TreeNode
	for _, n := range arr {
		if n.Left != nil {
			nexts = append(nexts, n.Left)
		}
		if n.Right != nil {
			nexts = append(nexts, n.Right)
		}
	}

	res = append(res, mostRight(nexts)...)

	return res
}

func bfsMostRight(r *TreeNode) []int {
	if r == nil {
		return []int{}
	}

	var res []int
	q := []*TreeNode{r}
	for len(q) > 0 {
		l := len(q)
		var mr int
		for i := 0; i < l; i++ {
			mr = q[i].Val
			if q[i].Left != nil {
				q = append(q, q[i].Left)
			}
			if q[i].Right != nil {
				q = append(q, q[i].Right)
			}
		}
		q = q[l:]
		res = append(res, mr)
	}

	return res
}

func maxLevelSum(r *TreeNode) int {
	m := r.Val
	mLv := 1
	q := []*TreeNode{}
	if r.Left != nil {
		q = append(q, r.Left)
	}
	if r.Right != nil {
		q = append(q, r.Right)
	}
	curLv := 1
	l := len(q)
	for l > 0 {
		curLv++
		s := 0
		for i := 0; i < l; i++ {
			s += q[i].Val
			if q[i].Left != nil {
				q = append(q, q[i].Left)
			}
			if q[i].Right != nil {
				q = append(q, q[i].Right)
			}
		}
		if s > m {
			m = s
			mLv = curLv
		}
		q = q[l:]
		l = len(q)
	}
	return mLv
}

func canVisitAllRooms(rooms [][]int) bool {
	cur := rooms[0]

	m := make(map[int]bool)
	m[0] = true
	for _, r := range cur {
		m[r] = true
	}

	for len(cur) > 0 {
		l := len(cur)
		for i := 0; i < l; i++ {
			for _, r := range rooms[cur[i]] {
				if _, ok := m[r]; !ok {
					m[r] = true
					cur = append(cur, r)
				}
			}
		}

		cur = cur[l:]
	}

	return len(rooms) == len(m)
}

func findCircleNum(isConnected [][]int) int {
	l := len(isConnected)
	vst := make([]bool, len(isConnected))
	res := 0
	var dfs func(int) int
	dfs = func(i int) int {
		if vst[i] {
			return 0
		}
		vst[i] = true
		for j := 0; j < l; j++ {
			if isConnected[i][j] == 1 {
				dfs(j)
			}
		}
		return 1
	}
	for i := 0; i < l; i++ {
		res += dfs(i)
	}
	return res
}

func minReorder(n int, connections [][]int) int {
	m := make(map[int][]int)
	for _, c := range connections {
		m[c[0]] = append(m[c[0]], c[1])
		m[c[1]] = append(m[c[1]], -c[0])
	}
	res := 0
	vst := make([]bool, n)
	var dfs func(int)
	dfs = func(target int) {
		vst[target] = true
		for _, v := range m[target] {
			u := abs(v)
			if vst[u] {
				continue
			}
			if v > 0 {
				res++
			}
			dfs(u)
		}
	}
	dfs(0)
	return res
}

func abs(n int) int {
	if n > 0 {
		return n
	}
	return -n
}
