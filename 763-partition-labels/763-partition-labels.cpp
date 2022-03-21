class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26,0);
        vector<int> ans;
        for(int i=0;i<s.length();i++)
            last[s[i]-'a']=i;
        int i=0, j=0;
        for(int k=0;k<s.length();k++){
            j=max(j,last[s[k]-'a']);
            
            if(k==j){
                ans.push_back(k-i+1);
                i=k+1;
            }
            
        }
        return ans;
    }
};