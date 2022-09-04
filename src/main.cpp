#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<stdlib.h>
using namespace std;

typedef enum EnumPriorityE {
	PRI_LESS,
	PRI_GREAT,
	PRI_EQUAL,
	PRI_MAX
} PriorityE;

bool isDigit(char ch)
{
	return (ch >= '0') && (ch <= '9');
}

bool isOperation(char ch)
{
	if (ch == '+'|| ch == '-' || ch == 'x' || ch == '/' || ch == '(' || ch == ')') {
		return true;
	} else {
		return false;
	}
}

PriorityE GetPriority(char lastOp, char curOP)
{
	const char *operationTable = "+-x/()";
	PriorityE priTable[][6] = {
		/*   +          -         x           /          (          )  */
		{PRI_GREAT, PRI_GREAT, PRI_LESS,  PRI_LESS,  PRI_LESS, PRI_GREAT},
		{PRI_GREAT, PRI_GREAT, PRI_LESS,  PRI_LESS,  PRI_LESS, PRI_GREAT},
		{PRI_GREAT, PRI_GREAT, PRI_GREAT, PRI_GREAT, PRI_LESS, PRI_GREAT},
		{PRI_GREAT, PRI_GREAT, PRI_GREAT, PRI_GREAT, PRI_LESS, PRI_GREAT},
		{PRI_LESS,  PRI_LESS,  PRI_LESS,  PRI_LESS,  PRI_LESS, PRI_EQUAL},
		{PRI_GREAT, PRI_GREAT, PRI_GREAT, PRI_GREAT, PRI_MAX,  PRI_GREAT},
	};
	int lastIndex = 0;
	int curIndex = 0;
	for (int i = 0; i < 6; ++i) {
		if (lastOp == operationTable[i]) {
			lastIndex = i;
		}
		if (curOP == operationTable[i]) {
			curIndex = i;
		}
	}
	return priTable[lastIndex][curIndex];
}

double GetResult(char opt, double left, double right)
{
	if (opt == '+') {
		return left + right;
	} 
	if (opt == '-') {
		return left - right;
	}
	if (opt == 'x') {
		return left * right;
	}
	if (opt == '/' && right != 0) {
		return left / right;
	}
	throw("invald expression");
}

void Exexcute(stack<double> &digit, stack<char> &operation, char curOp)
{
	if (operation.empty()) {
		operation.push(curOp);
		return;
	}
	char lastOp = operation.top();
	PriorityE pri = GetPriority(lastOp, curOp);
	switch (pri) {
		case PRI_MAX:
			throw("invald expression");
		case PRI_LESS:
			operation.push(curOp);
			break;
		case PRI_EQUAL:
			operation.pop();
			break;
		case PRI_GREAT:
			// 当前digit栈中一定不止两个数
			if (digit.size() < 2) {
				throw("invald expression");
			}
			double rightVal = digit.top();
			digit.pop();
			double leftVal = digit.top();
			digit.pop();
			
			double result = GetResult(lastOp, leftVal, rightVal);
			digit.push(result);
			operation.pop();
			operation.push(curOp);
			break;
	};
	if (!operation.empty() && operation.top() == ')') {
		operation.pop();
		Exexcute(digit, operation, ')');
	}
}

double Calculate(const string exp)
{
	if (exp.length() == 0) {
		return 0;
	}
	stack<double> digit;
	stack<char> operation;
	const char *ch = exp.c_str();
	while(*ch != '\0') {
		if (isDigit(*ch)) {
			double tmp = 0;
			while(*ch != '\0' && isDigit(*ch)) {
				tmp = tmp * 10 + *ch - '0';
				ch++;
			}
			digit.push(tmp);
		} else if (isOperation(*ch)) {
			Exexcute(digit, operation, *ch);
			ch++;
		} else {
			throw("invald expression");
		}
	}

	while(!operation.empty()) {
		double rightVal = digit.top();
		digit.pop();
		double leftVal = digit.top();
		digit.pop();
		
		double result = GetResult(operation.top(), leftVal, rightVal);
		digit.push(result);
		operation.pop();
	}
	return digit.top();
}

int main()
{
	string exp;
	cin>>exp;
	cout<<Calculate(exp) << endl;
	return 0;
}