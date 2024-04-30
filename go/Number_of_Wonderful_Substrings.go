package main

func wonderfulSubstrings(word string) int64 {
	cnt := make([]int64, 1024)
	cnt[0] = 1
	mask, ans := 0, int64(0)
	for _, c := range word {
		mask ^= 1 << (c - 'a')
		ans += cnt[mask]
		for i := 0; i < 10; i++ {
			ans += cnt[mask^(1<<i)]
		}
		cnt[mask]++
	}
	return ans
}
