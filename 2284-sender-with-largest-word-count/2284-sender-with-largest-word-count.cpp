class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int count;
        vector<int> cnt;
        for(int i=0;i<messages.size();i++){
            count  = 1;
            for(int j=0;j<messages[i].size();j++){
                if(messages[i][j]==' ')
                    count++;
            }
            cnt.push_back(count);
        }

        map<string, int> mp;
        int n= senders.size();
        
        for(int i=0;i<n;i++){
            
            mp[senders[i]]+=cnt[i];
        }
        // unordered_map<string, int>::iterator it = mp.begin();
        // while(it!=mp.end())
        //     cout << mp[it] << " ";
        int ans = 0;
        string res;
        for (auto i = mp.begin(); i != mp.end(); i++){
        cout << i->first << "      " << i->second
             << endl;
        }
        for (auto i = mp.begin(); i != mp.end(); i++){
            if(ans<=i->second){
                ans = i->second;
                res = max(i->first, res);
                // if(res<i->first)
                //     res = i->first;
            }
        }
        // cout << i->first << "      " << i->second
        //      << endl;
        return res;
    }
};
// class Solution {
// public:
    
//     int split(string &s){
//         int words = 1;
//         for(char ch: s){
//             words += ch == ' '; //presence of 1 blank space means 1 more word.
//         }
//         return words;
//     }
    
//     string largestWordCount(vector<string>& messages, vector<string>& senders) {
//         map<string,int> cnt;
//         int n = messages.size();
//         for(int i=0;i<n;i++){
//             cnt[senders[i]] += split(messages[i]);
//         }
//         string ans;
//         int max_count = 0;
//         for(auto [s, k]: cnt){
//             if(k >= max_count){
//                 max_count = k;
//                 ans = max(ans, s);
//             }
//         }
//         return ans;
//     }
// };