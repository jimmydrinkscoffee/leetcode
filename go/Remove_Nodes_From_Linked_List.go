package main

func removeNodes(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	for head.Next != nil && head.Next.Val > head.Val {
		head = head.Next
	}
	head.Next = removeNodes(head.Next)
	for head.Next != nil && head.Next.Val > head.Val {
		head = head.Next
	}
	return head
}
