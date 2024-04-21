package main

func validPath(n int, edges [][]int, src int, d int) bool {
	if n == 1 && src == d && d == 0 {
		return true
	}
	m := make(map[int][]int)
	tom := func(k, v int) {
		if _, ok := m[k]; ok {
			m[k] = append(m[k], v)
			return
		}
		m[k] = []int{v}
	}
	for _, e := range edges {
		tom(e[0], e[1])
		tom(e[1], e[0])
	}
	var q []int
	vst := make([]bool, n)
	vst[src] = true
	q = append(q, m[src]...)
	for len(q) > 0 {
		l := len(q)
		for i := 0; i < l; i++ {
			t := q[0]
			q = q[1:]
			if t == d {
				return true
			}
			if vst[t] {
				continue
			}
			vst[t] = true
			q = append(q, m[t]...)
		}
	}
	return false
}
