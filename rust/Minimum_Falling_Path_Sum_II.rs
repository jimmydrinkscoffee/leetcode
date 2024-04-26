use std::cmp::min;

impl Solution {
    pub fn min_falling_path_sum(grid: Vec<Vec<i32>>) -> i32 {
        let r = grid.len();
        let c = grid[0].len();
        let mut dp: Vec<Vec<i32>> = vec![vec![-1; c]; r];
        fn mem(
            row: usize,
            prev_col: usize,
            r: usize,
            c: usize,
            dp: &mut Vec<Vec<i32>>,
            grid: &Vec<Vec<i32>>,
        ) -> i32 {
            if row == r {
                return 0;
            }
            if dp[row][prev_col] != -1 {
                return dp[row][prev_col];
            }
            dp[row][prev_col] = i32::MAX;
            for i in 0..c {
                if i == prev_col {
                    continue;
                }
                dp[row][prev_col] = min(
                    dp[row][prev_col],
                    grid[row][i] + mem(row + 1, i, r, c, dp, grid),
                );
            }
            dp[row][prev_col]
        };
        let mut ans = i32::MAX;
        for i in 0..c {
            ans = min(ans, grid[0][i] + mem(1, i, r, c, &mut dp, &grid));
        }
        ans
    }
}
