use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut d: HashMap<i32, usize> = HashMap::new();
        for (i, &n) in nums.iter().enumerate() {
            match d.get(&(target - n)) {
                Some(&j) => return vec![i as i32, j as i32],
                None => {
                    d.insert(n, i);
                }
            }
        }
        vec![]
    }
}
