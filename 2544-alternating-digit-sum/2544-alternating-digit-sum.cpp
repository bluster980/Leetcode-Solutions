class Solution {
public:
    int alternateDigitSum(int n) {
        int reminder = 0; int ans = 0;
        for(int i=n; i>0; i/=10){
            reminder = i%10 - reminder;
        }
        return reminder;
    }
};