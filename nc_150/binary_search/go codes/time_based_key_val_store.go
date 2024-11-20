// we will make use of the condition given in the contraints:
// that the timestamps of the set are strictly increasing
// we will simply apply binary search to find the nearest timestamp for the given key
// and accordingly return the val

type Pair struct {
	value     string
	timestamp int
}

type TimeMap struct {
	mp map[string][]Pair
}

func Constructor() TimeMap {
	return TimeMap{make(map[string][]Pair)}
}

func (this *TimeMap) Set(key string, value string, timestamp int) {
	if _, ok := this.mp[key]; !ok {
		this.mp[key] = make([]Pair, 0)
	}
	this.mp[key] = append(this.mp[key], Pair{value, timestamp})
}

func (this *TimeMap) Get(key string, timestamp int) string {
	vals, ok := this.mp[key]
	if !ok {
		return ""
	}

	var val string
	l, r := 0, len(vals)-1

	for l <= r {
		mid := l + (r-l)/2
		if vals[mid].timestamp <= timestamp {
			val = vals[mid].value
			l = mid + 1
		} else {
			r = mid - 1
		}
	}
	return val
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Set(key,value,timestamp);
 * param_2 := obj.Get(key,timestamp);
 */