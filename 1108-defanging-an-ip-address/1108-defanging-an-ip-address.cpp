class Solution {
public:
    string defangIPaddr(string address) {
        string temp = "[.]";
        for(int i=0;i<address.size();i++){
            if(address[i]=='.'){
                address.replace(i,1,temp);
                i+=2;  
            }
            if(i == address.size()-1) break;
        }
        return address;
    }
};