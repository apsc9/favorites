// Idea : build a heap first(maxheap). Use the idea from the selection sort algp
// take the last element and keep swapping with the first elem
// keep reducing the size of the arr in the function call and then call heapify
// on the oth element 

// TC = O(N) + O(NlogN)

class Solution {
  public:
    // Function to sort an array using Heap Sort.
    void heapSort(vector<int>& arr) {
        build_heap(arr);
        int n = arr.size();
        for(int i = n-1; i > 0 ; i--){
            swap(arr[i], arr[0]);
            heapify(arr, i, 0);
        }
    }
    
    void build_heap(vector<int>&arr){
        int n = arr.size();
        for (int i = (n-2)/2 ; i >= 0 ; i--)
            heapify(arr, n,i);
    }
    
    void heapify(vector<int>&arr, int size, int i){
        int largest = i ;
        int left = 2*i+1 ;
        int right = 2*i + 2;
        
        
        if (left < size && arr[left] > arr[largest])
            largest = left ;
        
        if (right < size && arr[right] > arr[largest])
            largest = right;
            
        if (largest != i){
            swap(arr[i], arr[largest]);
            heapify(arr, size, largest);
        }
    }
};