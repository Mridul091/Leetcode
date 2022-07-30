class Solution {
public:
    bool match(map<char, int>&targetMap, map<char, int>&currMap)
    {
        for (auto it : targetMap)
        {
            char ch = it.first;
            int count = it.second;
            if (currMap[ch] >= count) continue; 
            else return false; 
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2)
    {
        map<char, int>targetMap; 
        for (string subsetWord : words2) 
        {
            map<char, int>mp;
            for (char ch : subsetWord) mp[ch]++; 
            for (auto it : mp)  
            {
                char ch = it.first;
                int count = it.second;
                if (targetMap[ch] <= count) targetMap[ch] = count;
            }

        }

        vector<string>ans;
        for (string word : words1)
        {
            map<char, int>currMap;
            for (char ch : word) currMap[ch]++;
            if (match(targetMap, currMap)) ans.push_back(word);
        }
        return ans;
    }
};