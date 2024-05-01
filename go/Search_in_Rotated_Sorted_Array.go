package main

func search(nums []int, target int) int {
	if len(nums) == 0 {
		return -1
	}
	if len(nums) == 1 {
		if nums[0] == target {
			return 0
		}
		return -1
	}
	findRot := func() int {
		l, r := 0, len(nums)-1
		for l <= r {
			pv := l + (r-l)/2
			if pv == 0 {
				if nums[pv] < nums[1] {
					return pv
				}
			} else if pv == len(nums)-1 {
				if nums[pv] < nums[len(nums)-2] {
					return pv
				}
			} else if nums[pv] < nums[pv-1] && nums[pv] < nums[pv+1] {
				return pv
			}
			if nums[pv] < nums[r] {
				r = pv - 1
			} else if nums[pv] >= nums[l] {
				l = pv + 1
			}
		}
		return -1
	}
	rot := findRot()
	binSearch := func(l, r int) int {
		for l <= r {
			pv := l + (r-l)/2
			if nums[pv] == target {
				return pv
			}
			if nums[pv] > target {
				r = pv - 1
			} else {
				l = pv + 1
			}
		}
		return -1
	}
	if rot > 0 && target >= nums[0] {
		return binSearch(0, rot-1)
	}
	return binSearch(rot, len(nums)-1)
}
