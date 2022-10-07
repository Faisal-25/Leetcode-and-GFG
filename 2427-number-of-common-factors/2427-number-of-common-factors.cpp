class Solution {
public:
    int commonFactors(int a, int b) {
        int res =  1;
        int hi = gcd(a,b);
        for(int i = 2;i<=hi;i++){
            res+= a%i == 0 && b%i == 0;
        }
        return res;
    }
};