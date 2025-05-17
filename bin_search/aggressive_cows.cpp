bool canPlace(int dist, vector<int>&stalls, int cows){
    int cnt = 1, last = stalls[0];
    for(int i = 1; i < stalls.size(); i++){
        if (stalls[i] - last >= dist){
            cnt++;
            last = stalls[i];
        }
    }
    if (cnt >= cows) return true;
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int low = 0, high = stalls[n-1]- stalls[0];

    while(low <= high){
        int mid = low + (high - mid)/2;
        if (canPlace(mid, stalls, k)){
            low = mid + 1;
        }
        else 
            high = mid -1 ;
    }
    return high;
}

