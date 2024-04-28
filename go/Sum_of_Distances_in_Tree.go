package main

func sumOfDistancesInTree(n int, edges [][]int) []int {
	ans, subs := make([]int, n), make([]int, n)
	m := make([][]int, n)
	for _, ed := range edges {
		m[ed[0]] = append(m[ed[0]], ed[1])
		m[ed[1]] = append(m[ed[1]], ed[0])
	}

	var dfs func(par, cur int)
	dfs = func(par, cur int) {
		for _, nx := range m[cur] {
			if nx == par {
				continue
			}
			dfs(cur, nx)
			subs[cur] += subs[nx]
			ans[cur] += ans[nx] + subs[nx]
		}
		subs[cur]++
	}

	var reRoot func(par, cur int)
	reRoot = func(par, cur int) {
		for _, nx := range m[cur] {
			if nx == par {
				continue
			}
			ans[nx] = ans[cur] + n - 2*subs[nx]
			reRoot(cur, nx)
		}
	}

	dfs(-1, 0)
	reRoot(-1, 0)

	return ans
}
