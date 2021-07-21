#include <iostream>
#include <unordered_map>
#include<string>
using namespace std;
class Solution_30 {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;

        int string_length = s.length();
        int word_nums = words.size();
        int word_size = words[0].length();
        unordered_map<string, int> map;
        for (auto word : words) {
            map[word] = map.count(word) == 0 ? 1 : (map[word] + 1);
        }

        for (int i = 0; i <= string_length - word_size * word_nums; ++i) {
            unordered_map<string, int> tmp = map;
            int start = 0;
            while (start < word_size * word_nums) {
                string key = s.substr(i + start, word_size);
                if (tmp.count(key) == 0) {
                    break;
                } else {
                    tmp[key]--;
                    if (tmp[key] == 0) {
                        tmp.erase(key);
                    }
                }
                start += word_size;
            }
            if (tmp.empty()) {
                ret.push_back(i);
            }
        }

        return ret;
    }
};