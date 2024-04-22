package main

import (
	"strconv"
)

func openLock(dds []string, tg string) int {
	vst := make([]bool, 10000)
	for _, dd := range dds {
		n, _ := strconv.Atoi(dd)
		vst[n] = true
	}
	t, _ := strconv.Atoi(tg)
	cnt := 0
	q := []int{0}
	nx := []int{1, 10, 100, 1000}
	for len(q) > 0 {
		l := len(q)
		for i := 0; i < l; i++ {
			tp := q[0]
			q = q[1:]
			if vst[tp] {
				continue
			}
			vst[tp] = true
			if tp == t {
				return cnt
			}
			for _, n := range nx {
				if (tp/n)%10 == 9 {
					q = append(q, tp-9*n)
				} else {
					q = append(q, tp+n)
				}
				if (tp/n)%10 == 0 {
					q = append(q, tp+9*n)
				} else {
					q = append(q, tp-n)
				}
			}
		}
		cnt++
	}
	return -1
}
