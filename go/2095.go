package main

type ListNode struct {
	Val  int
	Next *ListNode
}

// func deleteMiddle(head *ListNode) *ListNode {
// 	pr := preMid(head)
// 	if pr == nil {
// 		return nil
// 	}

// 	mid := pr.Next
// 	pr.Next = mid.Next
// 	mid.Next = nil
// 	return head
// }

// func preMid(head *ListNode) *ListNode {
// 	l1 := head
// 	l2 := head.Next
// 	if l2 == nil {
// 		return nil
// 	}

// 	for {
// 		if l2.Next != nil && l2.Next.Next != nil {
// 			l1 = l1.Next
// 			l2 = l2.Next.Next
// 		} else {
// 			break
// 		}
// 	}

// 	fmt.Println(l1.Val)
// 	return l1
// }
