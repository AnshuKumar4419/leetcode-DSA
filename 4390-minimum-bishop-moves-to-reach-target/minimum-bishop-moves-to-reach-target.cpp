class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int x = source[0];
        int y = source[1];
        int a = target[0];
        int b = target[1];
        if(x - y == a - b) {
            return 1;
        }
        else if(x + y == a + b) {
            return 1;
        }
        else if(((x + y) % 2) == ((a + b) % 2)) {
            return 2;
        }
        else {
            return -1;
        }
    }
};