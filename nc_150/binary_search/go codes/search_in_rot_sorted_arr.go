// Approach 1 : find the index of the min elem first, and then try to search in 2 halfs

func search(nums []int, target int) int {
	n := len(nums)
	index := findMinIndex(nums, target)
	left := searchfn(nums, 0, index-1, target)
	right := searchfn(nums, index, n-1, target)

	if left != -1 {
		return left
	} else if right != -1 {
		return right
	} else {
		return -1
	}
}

func searchfn(nums []int, st int, end int, target int) int {
	for st <= end {
		mid := st + (end-st)/2
		if nums[mid] == target {
			return mid
		} else if nums[mid] < target {
			st = mid + 1
		} else {
			end = mid - 1
		}
	}
	return -1
}

func findMinIndex(nums []int, target int) int {
	n := len(nums)
	l, r := 0, n-1

	for l < r {
		mid := l + (r-l)/2
		if nums[l] < nums[r] {
			return l
		}

		// we have come out of this it means , arr is like
		// nums[l] >= nums[r], so is better to check mid wrt last

		if nums[mid] < nums[r] {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return l
}

// Approach 2 : the above method was not an efficient one as we needed to apply binary search
// again and again in that one
// The Idea: for every elem, either the right or the left half is sorted
// we try to find the sorted half first, then see if the target is located inside that,
// eliminate the rest of the half
// TC = O(logn)
// SC = O(1)

func search(nums []int, target int) int {
	n := len(nums)
	l, r := 0, n-1

	// try to identify the sorted half first , then eliminate the other half
	for l <= r {
		mid := l + (r-l)/2

		if nums[mid] == target {
			return mid
		}

		if nums[l] <= nums[mid] { // first half is sorted ,now use bs
			if nums[l] <= target && target <= nums[mid] {
				r = mid - 1
			} else {
				l = mid + 1
			}
		} else { // second half seems to be sorted
			if nums[mid] <= target && target <= nums[r] {
				l = mid + 1
			} else {
				r = mid - 1
			}
		}
	}
	return -1
}

