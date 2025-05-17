// quicksort :

int partition(vector<int>&arr, int low, int high){
    int pivot = arr[high];

    int i = low -1 ;
    for(int j = low ; j < high ; j++){
        if (arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void qsort(arr, int low, int high){
    if (low < high){
        int elem = partition(arr, low, high);

        qsort(arr, low, elem-1);
        qsort(arr, elem+1, high);
    }
}