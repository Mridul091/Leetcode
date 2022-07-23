class Solution {
public:
    
    void merge(int l, int r,vector<pair<int, int>>& v, vector<int>& ans ){
        
        vector<pair<int, int >> temp(r-l+1);
        int i = l;
        int mid = (l+r) >>1;
        int j = mid+1;
        int k = 0;
        
        while(i<=mid && j<=r){
            if(v[i].first <= v[j].first)
                temp[k++] = v[j++];
            else{
                ans[v[i].second]+= r-j+1;
                temp[k++] = v[i++];
            }
        }
        
        while(i<= mid){
            temp[k++] = v[i++];
        }
        while(j<=r) temp[k++] = v[j++];
        
        for(int i =l;i<=r;i++)
            v[i] = temp[i-l];
    }
    
    void mergeSort(int l, int r, vector<pair<int, int>> & v, vector<int>& ans){
        if(l>=r) return;
        
        int mid = (l+r) >> 1;
        
        mergeSort(l, mid, v, ans);
        mergeSort(mid+1, r,v,ans);
        merge(l,r,v,ans);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        
        vector<pair<int, int>> v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i], i});
        }
        
        vector<int> ans(n,0);
        mergeSort(0,n-1,v,ans);
        return ans;
    }
};