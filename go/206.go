package main

func reverseList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	tl := head
	cur := head.Next
	tl.Next = nil
	for cur != nil {
		t := cur.Next
		cur.Next = tl
		tl = cur
		cur = t
	}
	return tl
}

func pairSum(head *ListNode) int {
	cur := head
	l := 0
	for cur != nil {
		l++
		cur = cur.Next
	}
	l /= 2
	s := make([]int, l)
	cur = head
	for i := 0; i < l; i++ {
		s[i] = cur.Val
		cur = cur.Next
	}
	ans := 0
	for i := 0; i < l; i++ {
		ans = max(ans, s[l-i-1]+cur.Val)
		cur = cur.Next
	}
	return ans
}

func max(b int, a int) int {
	if a > b {
		return a
	}
	return b
}
