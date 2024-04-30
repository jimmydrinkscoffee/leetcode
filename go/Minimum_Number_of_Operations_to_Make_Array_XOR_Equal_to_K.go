package main

func minOperations(nums []int, k int) int {
	n := nums[0]
	for i := 1; i < len(nums); i++ {
		n ^= nums[i]
	}
	ans, xor := 0, n^k
	for xor > 0 {
		ans += xor & 1
		xor >>= 1
	}
	return ans
}
