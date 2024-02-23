package main

import "fmt"

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
