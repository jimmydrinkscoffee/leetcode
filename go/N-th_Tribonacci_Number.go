package main

func tribonacci(n int) int {
	if n == 0 {
		return 0
	}
	t0, t1, t2 := 0, 1, 1
	for n > 2 {
		t0, t1, t2, n = t1, t2, t0+t1+t2, n-1
	}
	return t2
}
