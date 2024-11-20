// for idea : refer cpp soln

func minEatingSpeed(piles []int, h int) int {

	l, r := 1, 1000000000

	for l < r {
		mid := l + (r-l)/2
		if within_time(piles, mid, h) {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return l
}

func within_time(piles []int, mid int, h int) bool {
	time := 0
	for _, num := range piles {
		time += num / mid
		if num%mid != 0 {
			time += 1
		}
	}
	return time <= h
}