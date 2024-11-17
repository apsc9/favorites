// Nothing fancy here, just a simple binary search algo implementation

func search(nums []int, target int) int {
	n := len(nums)
	l, r := 0, n-1

	for l <= r {
		mid := l + (r-l)/2
		val := nums[mid]

		if val == target {
			return mid
		} else if val < target {
			l = mid + 1
		} else {
			r = mid - 1
		}
	}
	return -1
}