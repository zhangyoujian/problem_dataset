#include <iostream>
#include<string>
#include<vector>
using namespace std;

class Solution_93 {
    void Find(const string &s, vector<string> &outPut, vector<string> &current)
    {
        if (s.length() == 0 && current.size() == 4) {
            string ip = current[0] + "." + current[1] + "." + current[2] + '.' + current[3];
            outPut.push_back(ip);
            return;
        } else if (s.length() == 0) {
            return;
        } else if (current.size() > 4) {
            return;
        }
        if (s[0] == '0') {
            current.push_back(s.substr(0, 1));
            Find(s.substr(1), outPut, current);
            current.pop_back();
            return;
        }
        for (int i = 1; i < 4 && (s.length() - i>= 0); ++i) {
            string ip = s.substr(0, i);
            int intVal = atoi(ip.c_str());
            if (intVal > 255) {
                continue;
            }
            if (s.length() - i > (3 - current.size()) * 3) {
                continue;
            }
            current.push_back(ip);
            Find(s.substr(i), outPut, current);
            current.pop_back();
        }
        return;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        if (s.length() < 4 || s.length() > 12) {
            return ret;
        }
        vector<string> cur;
        Find(s, ret, cur);
        return ret; 
    }
};