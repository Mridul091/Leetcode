class Solution {
public:
    int numDecodings(string s) {


        int len=s.length();
        vector<int> dp(len,-1);
        helper(s,0,len,dp);
        return dp[0]==-1 ? 0 : dp[0];
    }
    int  helper(string& s,int ind,int n,vector<int>& dp)
    {
        if(ind==n)
            return 1;
        if(s[ind]=='0') 
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int sum=0;

        sum+=helper(s,ind+1,n,dp);
        
 
        if(ind+1<n && (s[ind]-'0')*10 + (s[ind+1]-'0') <=26)
        {
            sum+=helper(s,ind+2,n,dp);
        }
        dp[ind]=sum;
        return dp[ind];
    }
};