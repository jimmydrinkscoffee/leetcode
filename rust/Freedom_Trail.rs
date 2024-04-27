use std::{cmp, collections::HashMap, usize};

impl Solution {
    pub fn find_rotate_steps(rg: String, key: String) -> i32 {
        let mut m = HashMap::<char, Vec<i32>>::new();
        for (i, c) in rg.chars().enumerate() {
            m.entry(c).or_insert_with(Vec::new).push(i as i32);
        }
        let (mut prev, mut cur): (Vec<i32>, Vec<i32>) =
            (vec![0; rg.len() + 1], vec![0; rg.len() + 1]);
        for k in (0..key.len() - 1).rev() {
            for r in (0..rg.len() - 1).rev() {
                if k > 0 && rg.as_bytes()[r] != key.as_bytes()[k - 1] {
                    continue;
                }
                if rg.as_bytes()[r] == key.as_bytes()[k] {
                    cur[r] = 1 + prev[r];
                    continue;
                }
                cur[r] = i32::MAX;
                for nx in m.get(&key.chars().nth(k).unwrap()).unwrap().iter() {
                    cur[r] = cmp::min(
                        cur[r],
                        1 + cmp::min(
                            i32::abs(r as i32 - nx),
                            cmp::min(
                                rg.len() as i32 - r as i32 + nx,
                                rg.len() as i32 - nx + r as i32,
                            ),
                        ) + prev[*nx as usize],
                    );
                }
            }
            prev = cur.to_vec();
        }
        return cur[0];
    }
}
