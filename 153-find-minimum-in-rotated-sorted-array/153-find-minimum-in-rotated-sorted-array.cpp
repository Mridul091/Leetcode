class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
	    int start = 0;
	    int end = n-1;
	    int min = 0;
	    while(start<=end){
	        if(arr[start]<arr[end]){
	            min = start;
	            break;
	        } 
	        int mid = (start + end ) >> 1;
	        int next = (mid+1)%n;
	        int prev = (mid + n -1)%n;
	        if(arr[mid]<=arr[next] && arr[mid]<=arr[prev]){
                min = mid;
                break;
	        }
	        else if(arr[start]<=arr[mid])
	            start = mid + 1;
	        else
	            end = mid-1;
	    }
	    return arr[min];
    }
};