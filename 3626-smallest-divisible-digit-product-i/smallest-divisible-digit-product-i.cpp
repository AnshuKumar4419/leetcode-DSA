class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i = n; i <= 100; i++) {
            int num = i;
            int sum = 1;
            while(num > 0) {
                int digit = num % 10;
                sum *= digit;
                num = num / 10;
            }
            if(sum % t == 0) {
                return i;
            }
        }
        return -1;
    }
};