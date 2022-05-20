//https://leetcode.com/problems/integer-to-roman/

class Solution {
public:
    string intToRoman(int num) {
        int intarr[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string strarr[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int i=0;
        string ans = "";
        while(num>0 && i<13) {
            if(num-intarr[i]>=0) {
                //cout<<strarr[i]<<endl;
                ans += strarr[i];
                num = num-intarr[i];
            }
            else {
                i++;
            }
        }
        
        return ans;
    }
};
