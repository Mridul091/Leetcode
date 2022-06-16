class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // int start = 0;
        // int end = letters.size()-1;
        // char res = '#';
        // while(start<=end){
        //     int mid = (start+end) >> 1;
        //     if(letters[mid]==target) start = mid+1;
        //     else if (letters[mid]>target){
        //         res = letters[mid];
        //         end = mid-1;
        //     }
        //     else
        //         start = mid+1;
        // }
        // if(res=='#') return letters[0];
        // else return res;
        int index = upper_bound(letters.begin(), letters.end(), target) - letters.begin();
        return index >= letters.size() ? letters[0] : letters[index];
    }
};