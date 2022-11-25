class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        int ans=0,n=arr.size();
        int j;
        long mod=1e9+7;
        vector<int> sums(n,0);
        
        for(int i=0;i<n;i++){
            
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            j=st.empty()?-1:st.top();    // j is indecating the prev index of prev lesser value
            
            sums[i]=((j>=0?sums[j]:0)+(i-j)*arr[i])%mod;
            st.push(i);
        }
        
        for(int i=0;i<n;i++){
            ans=(ans+sums[i])%mod;
        }
        return ans;
    }
};