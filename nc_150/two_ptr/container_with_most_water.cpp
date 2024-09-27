// Idea is to just use 2 ptr approach :
// just start with the extremes and keep moving the pointers inwards
// as there might be a greater area with more height, so we keep 
// traversing from low height in order to find more area
// TC = O(n)
// SC = O(1)

int maxArea(vector<int>& height) {
    int n = height.size();
    int l = 0, r= n-1 ;
    int area = INT_MIN;

    while(l < r){
        area = max(area, (r-l) * min(height[l], height[r]));
        if (height[l] < height[r])
            l++;
        else 
            r--;
    }
    return area;
}