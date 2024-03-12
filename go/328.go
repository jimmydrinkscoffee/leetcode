package main

func oddEvenList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	evenHead := head.Next

	even := evenHead
	odd := head

	for {
		if even.Next == nil {
			odd.Next = nil
			break
		}
		odd.Next = even.Next
		odd = odd.Next
		if odd.Next == nil {
			even.Next = nil
			break
		}
		even.Next = odd.Next
		even = even.Next
	}

	odd.Next = evenHead
	return head
}
