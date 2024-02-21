package main

import "fmt"

func main() {
	cur := &ListNode{
		Val: 0,
	}
	head := cur
	for i := 1; i < 9; i++ {
		cur.Next = &ListNode{
			Val: i,
		}
		cur = cur.Next
	}
	cur = oddEvenList(head)
	cur = reverseList(cur)
	for cur != nil {
		fmt.Println(cur.Val)
		cur = cur.Next
	}
	fmt.Println(pairSum(head))
}
