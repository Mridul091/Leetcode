class Solution {
public:
    string convert(string s, int numRows) {
        
        string ans = "";
        if(numRows==1) return s;
        for(int i =0;i<numRows;i++){
            for(int j=i;j<s.size();j++){
                ans.push_back(s[j]);
                j += (numRows - j % (numRows - 1) - 1) * 2-1;
            }
        }
        return ans;
    }
};