class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <=0)return false;
         if(n == 1)return true;
     
        while(n>1){
            cout<<n<<endl;
            if(n%3 !=0)return false;
            n = n/3;
        }
       
        return true;
    }
};