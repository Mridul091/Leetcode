#define p 10000007
class Solution {
public:
    
    bool helper(string s, int len, int size, vector<int> roll, string& ans){
        unordered_map<int, vector<int>> m;
        int hash = 0;
        for(int i=0;i<size;i++){
            hash = (hash*26 + (s[i]-'a'))%p;
        }
        
        m[hash].push_back(0);
        for(int j=size;j<len;j++){
            hash = ((hash-roll[size-1]*(s[j-size]-'a'))%p + p)%p;
            hash = (hash*26 + (s[j]-'a'))%p;
            if(m.find(hash) != m.end()){
                for(auto it: m[hash]){
                    string temp = s.substr(it,size);
                    string curr = s.substr(j-size+1,size);
                    if(temp.compare(curr)==0){
                        ans = temp;
                        return true;
                    }
                }
            }
            m[hash].push_back(j-size+1);
        }
        return false;
        
    }
    
    string longestDupSubstring(string s) {
        int len = s.size();
        if(len==0) return "";
        vector<int> roll(len);
        roll[0] = 1;
        for(int i=1;i<len;++i){
            // storing wts
            roll[i] = (26*roll[i-1])%p;
        }
        // binary search
        
        int l =1, h = len, mid;
        string ans ="", temp;
        while(l<=h){
            temp = "";
            mid= (l+h) >> 1;
            bool flag = helper(s,len,mid,roll, temp);
            if(flag){
                if(temp.size() > ans.size()) ans = temp;
                l = mid+1;
               
            }
             else h = mid - 1;
        }
        return ans;
    }
};