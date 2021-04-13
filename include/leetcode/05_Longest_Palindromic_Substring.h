#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution_04 {
public:
void findlongestSubstring(string s, int left, int right,int &start, int &len)
{
	int n = s.length();
	int m_start = 0;
	int m_len = 0;
	while (left >= 0 && right <= n - 1)
	{
		if (s[left] == s[right])
		{
			m_start = left;
			m_len = right - left + 1;
		}
		else
			break;
		left--;
		right++;
	}

	if (m_len > len)
	{
		start = m_start;
		len = m_len;
	}
}
    string longestPalindrome(string s) {
        if (s.empty())
		return "";
	int start = 0;
	int len = 0;
	for (int i = 0;i < s.length();++i)
	{
		findlongestSubstring(s, i, i, start, len);

		findlongestSubstring(s, i, i+1, start, len);
	}

	return s.substr(start, len);
    }
};