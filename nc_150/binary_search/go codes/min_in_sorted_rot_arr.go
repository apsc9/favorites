// this section is the same as cpp section , refer that once for explanantion

func findMin(nums []int) int {
	n := len(nums)
	l, r := 0, n-1

	for l < r {
		if nums[l] < nums[r] {
			return nums[l]
		}

		mid := l + (r-l)/2
		// now we are sure that arr is rotated as we have come this far
		// so we just need to find the half where it can be present

		if nums[mid] > nums[r] {
			l = mid + 1
		} else {
			r = mid
		}
	}
	return nums[l]
}