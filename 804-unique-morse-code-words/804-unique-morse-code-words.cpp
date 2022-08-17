class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> mp;
        vector<string> code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."} ;
        
        for(auto str: words){
            string ans = "";
            for(int i =0;i<str.size();i++){
                ans += code[str[i]-'a'];
                // cout << code[str[i]-'0'] << endl;
            }
            
            mp.insert(ans);
        }
        return mp.size();
    }
};