package main

type RecentCounter struct {
	queue []int
}

func Constructor() RecentCounter {
	return RecentCounter{
		queue: make([]int, 0),
	}
}

func (r *RecentCounter) dequeue() {
	if len(r.queue) > 0 {
		r.queue = r.queue[1:]
	}
}

func (r *RecentCounter) Ping(t int) int {
	for len(r.queue) > 0 && r.queue[0] < t-3000 {
		r.dequeue()
	}

	r.queue = append(r.queue, t)
	return len(r.queue)
}
