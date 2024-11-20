// idea is to make use of map of vectors which contains pairs of  val, timestamp
// as this stores keys, so something related to map has to be used here
// As the timestamps are strictly increasing, so we can apply binary search on the 
// timestamps and we can return the value corresponding to the key given accordingly
// TC = O(logn)

class TimeMap {
public:
    unordered_map<string, vector<pair<string,int>>>m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(m.find(key) == m.end())
            return "";

        return search(m[key], timestamp);
    }

    string search(vector<pair<string,int>>&vec, int &ts){
        int l = 0, r = vec.size();
        string res = "";
        while (l < r){
            int mid = l + (r-l)/2;
            if (vec[mid].second < ts){
                l = mid + 1;
                res = vec[mid].first;
            } else if (vec[mid].second > ts)
                r = mid ;
            else 
                return vec[mid].first;
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */