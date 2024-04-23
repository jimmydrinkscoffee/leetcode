package main

func numberOfSpecialChars(word string) int {
	l, u, rec := make([]bool, 26), make([]bool, 26), make([]bool, 26)
	for _, r := range word {
		if r >= 'a' && r <= 'z' {
			i := r - 'a'
			if rec[i] {
				rec[i] = false
			} else {
				l[i] = true
			}
		} else if r >= 'A' && r <= 'Z' {
			i := r - 'A'
			if u[i] {
				continue
			}
			u[i] = true
			if l[i] {
				rec[i] = true
			}
		}
	}
	ans := 0
	for _, v := range rec {
		if v {
			ans++
		}
	}
	return ans
}
