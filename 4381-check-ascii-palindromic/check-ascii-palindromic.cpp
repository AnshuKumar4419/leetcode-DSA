class Solution {
public:
    bool isPalindromic(string s) {

        int size = s.size();

        string str;

        for( int i = 0 ; i < size ; i++ ){

            long long val = s[i];
            long long ans = 0;
            long long digit = 0;
            long long pow = 1;
              
                while( val > 0 ){

                    digit = val%2;

                    ans = ans + digit*pow;

                    pow = pow*10;

                    val = val/2;

                }

            string part = "0" + to_string(ans);

            str = str + part;

        }

        int start = 0;
        int end = str.size()-1;

        while( start <= end ){

            if( str[start] != str[end] ){

                return false;
            }

            start++;
            end--;
        }

        return true;


        
    }
};