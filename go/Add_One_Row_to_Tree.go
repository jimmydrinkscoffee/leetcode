package main

func addOneRow(n *TreeNode, val int, d int) *TreeNode {
	if d == 1 {
		return &TreeNode{Val: val, Left: n}
	}

	if n == nil {
		return nil
	}

	if d > 2 {
		addOneRow(n.Left, val, d-1)
		addOneRow(n.Right, val, d-1)
		return n
	}

	l, r := n.Left, n.Right
	n.Left = &TreeNode{Val: val, Left: l}
	n.Right = &TreeNode{Val: val, Right: r}

	return n
}
