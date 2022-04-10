class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int>ans;
        
        for(int i=0;i<ops.size();i++){
            if(ops[i]=="+"){
                ans.push_back(ans[ans.size()-1] + ans[ans.size()-2]);
            }
            else if(ops[i]=="C")
                ans.pop_back();
            else if(ops[i]=="D"){
                ans.push_back( ans[ans.size()-1]*2);
            }
            else
                ans.push_back(stoi(ops[i]));
        }
        int sum =0;
        for(auto it: ans)
            sum += it;
        
        return sum;
    }
};