#include <iostream>
#include <string>
using namespace std;
class Solution_71 {
private:
    
public:
    string simplifyPath(string path) {
        char *str = new char[path.length()];
        int index = 0;
        str[index++] = path[0];
        for (int i = 1; i < path.length(); ++i) {
            if (path[i] == '/' && str[index - 1] == '/') {
                continue;
            }

            str[index++] = path[i];
        }
    }
};