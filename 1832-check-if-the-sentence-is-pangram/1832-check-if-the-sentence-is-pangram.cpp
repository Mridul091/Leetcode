class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        int n = sentence.size();
        if(n<26) return false;
        vector<int> arr(26,0);
        for(int i = 0;i<sentence.size();i++){
           arr[sentence[i]-'a']++;
        }
        
        for(int i = 0;i<arr.size();i++){
            if(arr[i]<1) return false;
        }
        return true;
    }
};