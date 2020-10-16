#include<iostream>
#include<string>
#include<cstring>
#include"32_longest_valid_parethess.h"
using namespace std;

int main(int argc, char *argv[])
{
	string str = "()(())";
	Solution A;
	cout<<A.longestValidParentheses(str)<<endl;
	return 0;
}
