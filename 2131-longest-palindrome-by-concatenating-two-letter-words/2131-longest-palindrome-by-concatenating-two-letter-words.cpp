class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> mp1;
        map<string, int> mp2;
        int ans = 0;
        for(int i=0;i<words.size();i++){
            if(words[i][0]==words[i][1])
                mp1[words[i]]++;
            else
                mp2[words[i]]++;
        }
        
        for(auto str: mp2){
            string s = str.first;
            reverse(s.begin(), s.end());
            
            if(mp2.find(s)!=mp2.end()){
                ans+=min(mp2[str.first],mp2[s])*4;
                mp2.erase(s);
                mp2.erase(str.first);
            }
        }
        
        int max1 = 0;
        for(auto i:mp1){
            if(i.second%2==0){
                ans+=i.second*2;
                mp1[i.first]=0;
            }
        }
        for(auto i:mp1){
            if(i.second%2)
                max1=max(max1,i.second);
        }
		
        for(auto i:mp1){
            if(i.second==max1){
                ans+=i.second*2;
                mp1[i.first]=0;
                break;
            }
        }
        for(auto i:mp1){
            if(i.second)
                ans+=2*(i.second-1);
        }
        
        return ans;
    }
};