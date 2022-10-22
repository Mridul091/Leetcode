class Solution {
public:
string minWindow(string s, string t) {
        int st=1,e=0,c;
        map<char,int>m;
        for(int i=0;i<t.size();i++){
            m[t[i]]++;
        }
        c=m.size();
        int ans=s.size()+1,i=0,j=0;
        while(j<s.size()){
            if(m.find(s[j])!=m.end()){
                if(m[s[j]]==1){
                    c--;
                }
                m[s[j]]--;
                if(c==0){
                    while(c==0 && i<=j){
                        if(ans>j-i+1){
                            ans=j-i+1;
                            st=i;
                            e=j;
                        }
                            if(m.find(s[i])!=m.end()){
                                if(m[s[i]]==0){
                                    c++;
                                }
                                m[s[i]]++;
                            }
                        i++;
                    }
                }
            }
            j++;
        }
        if(st>e)return "";
        else{
            string a="";
            for(i=st;i<=e;i++){
                a+=s[i];
            }
            return a;
        }
    }
};