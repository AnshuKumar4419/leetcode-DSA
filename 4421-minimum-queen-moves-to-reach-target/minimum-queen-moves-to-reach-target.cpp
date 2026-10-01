class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int x = source[0];
        int y = source[1];
        int a = target[0];
        int b = target[1];
        if(x == a && y == b) {
            return 0;
        }
        else if(x == a) {
            return 1;
        } 
        else if(y == b) {
            return 1;
        } 
        else if(x + y == a + b) {
            return 1;
        } 
        else if(x - y == a - b) {
            return 1;
        } else if(y - x == b - a) {
            return 1;
        } else {
            return 2;
        }
    }
};