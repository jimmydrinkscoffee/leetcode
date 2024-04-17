package main

type stack struct {
	v []int
}

func (stk *stack) top() int {
	return stk.v[len(stk.v)-1]
}

func (stk *stack) push(v int) {
	stk.v = append(stk.v, v)
}

func (stk *stack) pop() int {
	v := stk.top()
	stk.v = stk.v[:len(stk.v)-1]
	return v
}

func (stk *stack) empty() bool {
	return len(stk.v) <= 0
}

func largestRectangleArea(ht []int) int {
	ht = append(ht, 0)
	ans := 0
	stk := &stack{
		v: []int{},
	}
	for i, h := range ht {
		for !stk.empty() && h < ht[stk.top()] {
			top := stk.pop()
			l := i
			if !stk.empty() {
				l = i - stk.top() - 1
			}
			ans = max(ans, ht[top]*l)
		}
		stk.push(i)
	}
	return ans
}
