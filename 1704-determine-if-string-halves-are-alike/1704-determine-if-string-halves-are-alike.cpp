class Solution {
public:
    bool halvesAreAlike(string s) {
        string a = s.substr(0, s.size() / 2);
        string b = s.substr(s.size() / 2, s.size() / 2);
        transform(a.begin(), a.end(), a.begin(), ::tolower);
        transform(b.begin(), b.end(), b.begin(), ::tolower);
        int temp = 0;
        for(int i = 0;i < a.length();i++){
            if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u'){
                temp += 1;
            }
            if(b[i] == 'a' || b[i] == 'e' || b[i] == 'i' || b[i] == 'o' || b[i] == 'u'){
                temp -= 1;
            }
        }
        return (temp == 0);
    }
};