class Solution {
public:
    string convertToTitle(int columnNumber) {
        if(columnNumber == 0) return "";
        
        int digit = (columnNumber - 1) % 26;
        char letterRepresentation = 'A' + digit;
        return convertToTitle((columnNumber - digit) / 26) + letterRepresentation;
    }
};