class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(arr[i]==0) cnt++;
        }

        for(int i=n-1;i>=0;i--){
            if(arr[i]==0){
                if(cnt < 1)
                    arr[n+cnt-1] = 0;
                cnt--;
            }

            if(cnt < 1) 
                arr[n+cnt-1] = arr[i];
            cnt--;
        }
    }
};