// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// class Solution {
//   public:
  
//     // void helper(vector<vector<int>> ans, vector<int>& temp, int sum, int ind, vector<int> A ){
//     //     if(sum==0){
//     //         ans.push_back(temp);
//     //         return;
//     //     }
//     //     if(sum<0) return;
//     //     if(ind == A.size()) return;
       
//     //     helper(ans, temp,sum-A[ind], ind+1, A);
//     //     temp.push_back(A[ind]);
        
//     //     helper(ans, temp,sum, ind, A);
//     //     temp.pop_back();
//     // }
// void helper(int ind, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans, bool prev, int target){
//         if(target==0){
//             ans.push_back(temp);
//             return;
//         }
    
//         if(target<0) return;
//         if(ind==nums.size()) return;
//         else{
//             // to ignore the value
          
//             helper(ind+1, nums, temp, ans, true, target);
//             if(ind>0 && nums[ind]==nums[ind-1] && (prev))
//             return;
            
//             // to take the value in the consideration
//             temp.push_back(nums[ind]);
//             helper(ind+1,nums,temp,ans,false,(target-nums[ind]));
//             temp.pop_back();
//         }
        
//     }
//     //Function to return a list of indexes denoting the required 
//     //combinations whose sum is equal to given number.
//     vector<vector<int> > combinationSum(vector<int> &A, int B) {
//         // Your code here
//         sort(A.begin(), A.end());
//         vector<vector<int>> ans;
//         vector<int> temp;
//         // helper(ans, temp, B, 0, A);
//         helper(0, A, temp, ans, false, B);
//         sort(ans.begin(), ans.end());
//         return ans;
//     }
    
class Solution {
public:
    //1s approach
void helper(int ind, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans, bool prev, int target){
        if(target==0){
            ans.push_back(temp);
            return;
        }
    
        if(target<0) return;
        if(ind>=nums.size()) return;
        else{
            // to ignore the value
          
            helper(ind+1, nums, temp, ans, true, target);
            if(ind>0 && nums[ind]==nums[ind-1] && (prev))
            return;
            
            // to take the value in the consideration
            temp.push_back(nums[ind]);
            helper(ind,nums,temp,ans,false,(target-nums[ind]));
            temp.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0, nums, temp, ans, false, target);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends