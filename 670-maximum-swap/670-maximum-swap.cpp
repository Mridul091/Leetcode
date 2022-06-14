class Solution {
public:
    int maximumSwap(int num) {
        string s1 = to_string(num);
        string s2 = s1;
        
        for(int i=0;i<s1.size();i++){
            for(int j=i+1;j<s1.size();j++){
                swap(s2[i], s2[j]);
                int temp = stoi(s2);
                // cout << temp << endl;
                num = max(num, temp);
                // if(temp>num)
                //     num = temp;
                s2 = s1;
            }
        }
        return num;
    }
};

//     int maximumSwap(int num) {
//         string s=to_string(num);
//         string new1=s;
        
        
//         for(int i=0;i<new1.size();i++){
//             for(int j=i+1;j<new1.size();j++){
//                 swap(new1[i],new1[j]);
//                 int max=stoi(new1);
                
//                 if(max>num){
//                     num=max;
//                 }
//                 new1=s;
//             }
            
//        }
        
//         return num;