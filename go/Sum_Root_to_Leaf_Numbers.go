package main

func sumNumbers(r *TreeNode) int {
	ans := 0
	sumAllRootToLeaf(r, &ans, 0)
	return ans
}

func sumAllRootToLeaf(n *TreeNode, ans *int, cur int) {
	cur = cur*10 + n.Val

	if n.Left == nil && n.Right == nil {
		*ans += cur
		return
	}

	if n.Left != nil {
		sumAllRootToLeaf(n.Left, ans, cur)
	}

	if n.Right != nil {
		sumAllRootToLeaf(n.Right, ans, cur)
	}
}
