#include <iostream>
#include <string>
using namespace std;
class Solution_76 {
public:
    string minWindow(string s, string t) {
        int tFreq[64] = {0};
        int sFreq[64] = {0};
        for (auto i : t) {
            tFreq[i - 'A']++;
        }
        int left = 0;
        int right = -1;
        int l = 0;
        int r = s.size() - 1;
        bool found = false;
        while (left <= s.size() - t.size()) {
            if (right - left + 1 < t.size()) {
                if (right + 1 < s.size()) {
                    sFreq[s[++right] - 'A']++; 
                    continue;
                } else {
                    break;
                }
            }

            bool ret = isFind(sFreq, tFreq, 64);
            if (ret) {
                if (right - left + 1 == t.size()) {
                    return s.substr(left, right - left + 1);
                } else {
                    found = true;
                    if (right - left < r - l) {
                        l = left;
                        r = right;
                    }
                    sFreq[s[left++] - 'A']--;
                }
            } else {
                if (right + 1 < s.size()) {
                    sFreq[s[++right] - 'A']++;
                } else {
                     sFreq[s[left++] - 'A']--;
                }
            }
        }

        if (found) {
            return s.substr(l, r - l + 1);
        } else {
            return "";
        }
    }
private:
    bool isFind(int *sFreq, int *tFreq, int size)
    {
        for (int i = 0; i < size; ++i) {
            if (sFreq[i] < tFreq[i]) {
                return false;
            }
        }

        return true;
    }
};