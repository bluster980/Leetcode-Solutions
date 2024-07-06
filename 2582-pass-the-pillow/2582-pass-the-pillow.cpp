class Solution {
public:
    int passThePillow(int x, int y) {
        if((y/(x-1))%2 == 0) 
            return y%(x-1) + 1; 
        else{
            return x - y%(x-1);
        }
    }
};