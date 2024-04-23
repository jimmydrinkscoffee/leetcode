package main

func bullshitMinHeightTrees(n int, edges [][]int) []int {
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
	treeHeight := func(i int) int {
		cnt := 0
		vst := make([]bool, n)
		var q []int
		q = append(q, i)
		for len(q) > 0 {
			l := len(q)
			for j := 0; j < l; j++ {
				t := q[0]
				q = q[1:]
				if vst[t] {
					continue
				}
				vst[t] = true
				q = append(q, m[t]...)
			}
			cnt++
		}
		return cnt
	}
	hm := make([]int, n)
	mn := 20000
	for i := 0; i < n; i++ {
		hm[i] = treeHeight(i)
		mn = min(mn, hm[i])
	}
	var ans []int
	for k, v := range hm {
		if v == mn {
			ans = append(ans, k)
		}
	}
	return ans
}

func findMinHeightTrees(n int, edges [][]int) []int {
	if n == 1 {
		return []int{0}
	}
	m := make([][]int, n)
	dg := make([]int, n)
	for _, e := range edges {
		m[e[0]] = append(m[e[0]], e[1])
		m[e[1]] = append(m[e[1]], e[0])
		dg[e[0]]++
		dg[e[1]]++
	}
	var q []int
	for i, d := range dg {
		if d == 1 {
			q = append(q, i)
		}
	}
	var ans []int
	for len(q) > 0 {
		l := len(q)
		ans = make([]int, 0)
		for i := 0; i < l; i++ {
			t := q[0]
			q = q[1:]
			ans = append(ans, t)
			for _, v := range m[t] {
				dg[v]--
				if dg[v] == 1 {
					q = append(q, v)
				}
			}
		}
	}
	return ans
}
