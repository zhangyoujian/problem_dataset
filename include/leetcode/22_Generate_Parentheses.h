#include <iostream>
using namespace std;
class Solution_22 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        generateParenthesisInner(ret, "", n, 0);
        return ret;
    }
private:
    void generateParenthesisInner(vector<string> &result, string parentheses, int left, int right)
    {
        if (left == 0 && right == 0) {
            result.push(parentheses);
            return;
        }
        if (left > 0) {
            generateParenthesisInner(result, parentheses + "(", left - 1, right + 1);
        }
        if (right > 0) {
            generateParenthesisInner(result, parentheses + ")", left, right - 1);
        }
    }
};