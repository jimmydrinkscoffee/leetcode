package main

func doubleIt(head *ListNode) *ListNode {
	var stk []*ListNode
	h := head
	for h != nil {
		stk = append(stk, h)
		h = h.Next
	}
	odd := 0
	for i := len(stk) - 1; i >= 0; i-- {
		nx := stk[i].Val*2 + odd
		if nx > 9 {
			stk[i].Val = nx - 10
			odd = 1
		} else {
			stk[i].Val = nx
			odd = 0
		}
	}
	if odd > 0 {
		return &ListNode{
			Next: head,
			Val:  odd,
		}
	}
	return head
}
