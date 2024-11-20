// For Detailed approach , refer cpp solution
// 2 pointer method :

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	s1, s2 := len(nums1), len(nums2)

	i, j := 0, 0
	n1, n2 := 0, 0

	for cnt := 0; cnt <= (s1+s2)/2; cnt++ {
		n2 = n1
		if i < s1 && j < s2 {
			if nums1[i] <= nums2[j] {
				n1 = nums1[i]
				i++
			} else {
				n1 = nums2[j]
				j++
			}
		} else if i < s1 {
			n1 = nums1[i]
			i++
		} else {
			n1 = nums2[j]
			j++
		}
	}

	if (s1+s2)%2 == 1 {
		return float64(n1)
	}

	return float64(float64((n1 + n2)) / 2.0)
}

// Efficient approach : Using binary search to traverse through the first half of both the arr
// and eliminating the second half , then traversing as per the situation
// TC = O(log(min(n1,n2)))
// SC = O(1)

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	n1, n2 := len(nums1), len(nums2)
	if n1 > n2 {
		return findMedianSortedArrays(nums2, nums1)
	}

	n := n1 + n2
	left := (n1 + n2 + 1) / 2
	low, hi := 0, n1

	for low <= hi {
		mid1 := (low + hi) / 2
		mid2 := left - mid1

		l1, l2, r1, r2 := math.MinInt, math.MinInt, math.MaxInt, math.MaxInt
		if mid1 < n1 {
			r1 = nums1[mid1]
		}
		if mid2 < n2 {
			r2 = nums2[mid2]
		}
		if mid1-1 >= 0 {
			l1 = nums1[mid1-1]
		}
		if mid2-1 >= 0 {
			l2 = nums2[mid2-1]
		}

		if l1 <= r2 && l2 <= r1 {
			if n%2 == 1 {
				return math.Max(float64(l1), float64(l2))
			}
			return float64(math.Max(float64(l1), float64(l2))+math.Min(float64(r1), float64(r2))) / 2.0
		} else if l1 > r2 {
			hi = mid1 - 1
		} else {
			low = mid1 + 1
		}
	}
	return 0
}