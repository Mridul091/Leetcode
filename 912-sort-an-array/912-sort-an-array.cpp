class Solution {
public:
    
    void merge(vector<int>& arr, int start, int end){
        int mid = (start + end) >> 1;
        int len1 = mid-start + 1;
        int len2 = end - mid;

        int *first = new int[len1];
        int *second = new int[len2];

        int k = start;
        for(int i =0;i<len1;i++) first[i] = arr[k++];
        for(int i=0;i<len2;i++) second[i] = arr[k++];

        int ind1 = 0;
        int ind2 = 0;
        k = start;
        while(ind1 < len1 && ind2 < len2){
            if(first[ind1] < second[ind2]){
                arr[k++] = first[ind1++];
            }
            else arr[k++] = second[ind2++];
        }
        while(ind1 < len1) arr[k++] = first[ind1++];
        while(ind2 < len2) arr[k++] = second[ind2++];
    }
    
    void mergeSort(vector<int>& arr, int start, int end){
        if(start >= end) return;
        int mid = (start + end) >> 1;
        mergeSort(arr,start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, end);
    }
    
    vector<int> sortArray(vector<int>& arr) {
        int n = arr.size();
        mergeSort(arr, 0 ,n-1);
        return arr;
    }
};