class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int cnt = 0;
        int i = 0, j = n-1;
        while(i<j){
            if(power >= tokens[i]){
                cnt++;
                power -= tokens[i++];
            }
            else if(cnt >= 1 && tokens[j] + power >= tokens[i] ){
                cnt--;
                power += tokens[j--];
            }
            else break;
        }
        
        while(i < j+1 && power >= tokens[i]){
            power -= tokens[i++];
            cnt++;
        }
        return cnt;
    }
};