package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func sumOfLeftLeaves(root *TreeNode) int {
	if root == nil {
		return 0
	}

	return leftSum(root.Left, true) + leftSum(root.Right, false)
}

func leftSum(n *TreeNode, l bool) int {
	if n == nil {
		return 0
	}

	if l && n.Left == nil && n.Right == nil {
		return n.Val
	}

	return leftSum(n.Left, true) + leftSum(n.Right, false)
}
