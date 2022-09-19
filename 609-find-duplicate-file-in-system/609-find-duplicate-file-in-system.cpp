class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> mp;
        
        for(auto &i:paths)
        {
            istringstream ss(i);
            string word;
            ss>>word;
            string root=word;
            root+='/';
            while(ss>>word)
            {
                     int pos=word.find('(');
                    string temp=root+word.substr(0,pos);
                    string content=word.substr(pos);
                    mp[content].push_back(temp);
            } 
        }
        vector<vector<string>> ans;
        for(auto &i:mp)
        {
            if(i.second.size()>1)
                ans.push_back(i.second);
                
        }
        return ans;
    }
};