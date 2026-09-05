class Solution {
public:
    bool isPalindrome(int x) {
        
        if ( x < 0 ) return false;

        int num = x;

        int dig = 0;
        int res = 0;

        while ( num > 0){
            dig = num%10;
            res = res*10 + dig;
            num /= 10;
        }

        if ( x != res) return false;
        return true;



        
    }
};