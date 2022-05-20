class Solution {
public:
    string removeSpecialCharacter(string s)
{
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
         
        // Store only valid characters
        if ((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >='a' && s[i] <= 'z')  ||
            (s[i] >= '0' && s[i] <= '9'))
        { 
            s[j] = s[i];
            j++;
        }
    }
    return s.substr(0, j);
}
    bool isPalindrome(string sl) {
        transform(sl.begin(), sl.end(), sl.begin(), ::tolower);
        
        sl = removeSpecialCharacter(sl);
        for(int i=0;i<sl.size();i++)
            cout << sl[i];
        
        int i =0;
        int j = sl.size()-1;
        
        while(i<=j){
            if(sl[i++]!=sl[j--]) return false;
        }
        return true;
    }
};