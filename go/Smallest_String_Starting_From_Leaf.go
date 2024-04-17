package main

func smallestFromLeaf(n *TreeNode) string {
	ans := ""
	findSmallest(n, &ans, "")
	return ans
}

func findSmallest(n *TreeNode, ans *string, cur string) {
	cur = string('a'+rune(n.Val)) + cur
	if n.Left == nil && n.Right == nil {
		if len(*ans) <= 0 || cur < *ans {
			*ans = cur
		}
		return
	}

	if n.Left != nil {
		findSmallest(n.Left, ans, cur)
	}

	if n.Right != nil {
		findSmallest(n.Right, ans, cur)
	}
}
