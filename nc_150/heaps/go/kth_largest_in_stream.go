// Idea : use min heap of size k , the top element with be the kth largest elem
// when you have the last set of k elem, all the elem after the first are large only and the
// first one can be rightly said as the kth largest element
// optimization: if an elem is smaller than the current top of pq and the queue is already full
// then pushing a smaller elem makes no sense as one of the elem has to be popped off to maintain
// the length equal to k , and clearly it is the smallest elem that is popped off

// TC = O((n-k)logk)
// SC = O(k)

import (
	"container/heap"
	"fmt"
)

type KthLargest struct {
	pq   *Minheap
	size int
}

func Constructor(k int, nums []int) KthLargest {
	h := &Minheap{}
	heap.Init(h)

	for _, x := range nums {
		heap.Push(h, x)
		if h.Len() > k {
			heap.Pop(h)
		}
	}
	return KthLargest{
		pq:   h,
		size: k,
	}
}

func (this *KthLargest) Add(val int) int {
	heap.Push(this.pq, val)
	if this.pq.Len() > this.size {
		heap.Pop(this.pq)
	}
	return (*this.pq)[0]
}

type Minheap []int

func (h Minheap) Len() int           { return len(h) }
func (h Minheap) Less(i, j int) bool { return h[i] < h[j] }
func (h Minheap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *Minheap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *Minheap) Pop() interface{} {
	v := (*h)[len(*h)-1]
	*h = (*h)[:len(*h)-1]
	return v
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * obj := Constructor(k, nums);
 * param_1 := obj.Add(val);
 */