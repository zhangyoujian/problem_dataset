#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution_14 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() < 1) {
            return "";
        }
        string ref = strs[0];
        int length = 0;
        while (length < ref.size()) {
            bool flag = true;
            char ch = ref.at(length);
            for (int i = 1; i < strs.size(); ++i) {
                if (strs.at(i)[length] != ch || strs.at(i)[length] == '\0') {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                break;
            }
            length++;
        }
        return ref.substr(length);
    }
};