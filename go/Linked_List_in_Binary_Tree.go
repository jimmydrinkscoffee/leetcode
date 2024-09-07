package main

func isSubPath(head *ListNode, root *TreeNode) bool {
	var check func(*ListNode, *TreeNode) bool
	check = func(head *ListNode, root *TreeNode) bool {
		return head == nil || (root != nil && head.Val == root.Val &&
			(check(head.Next, root.Left) || check(head.Next, root.Right)))
	}
	return check(head, root) ||
		(root != nil && (isSubPath(head, root.Left) || isSubPath(head, root.Right)))
}
