class Solution {
public:
    string reverseVowels(string s) {
        // int vowel[] = {'a','e','i','o','u','A','E','I','O','U'};
        
        int i =0;
        int j =s.size()-1;
        
        while(i<=j){
            bool flag1 = false;
            bool flag2 = false;
            char one = s[i];
            char two = s[j];
            
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
                flag1 = true;
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u' || s[j]=='A' || s[j]=='E' || s[j]=='I' || s[j]=='O' || s[j]=='U')
                flag2 = true;
            
            if(flag1 && flag2){
                swap(s[i++], s[j--]);
            }
            else if(!flag1)
                i++;
            else 
                j--;
        }
        return s;
    }
};