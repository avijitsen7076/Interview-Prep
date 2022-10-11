impl Solution {
    pub fn next_permutation(nums: &mut Vec<i32>) {
        let l = nums.len();
        let (mut i, mut j) = (l-1, l-1);
		
		// get the index of last increasing subseq elem from right
        while i > 0 && nums[i-1] >= nums[i] { i -= 1; }
		
		// nums[i-1] is the smallest in range (i-1..len-1)
		// elems from (i..len - 1) are in descending
        if i > 0 {
			// get index of the first element >= nums[i-1]
			// equivalent to sorting the element in ascending and get the index of element right after nums[i-1]
             while j >= i && nums[j] <= nums[i-1] { j -= 1; }
			 // swap the smallest and next greater element
             nums.swap(i-1, j);
        }

		// reverse the elements from (i to len - 1) to convert to ascending
        nums[i..l].reverse();
    }
}
