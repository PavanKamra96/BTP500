/*
* Name: Pavan Kumar Kamra	
* Date: 12/04/2017
* Course: BTP500
* Purpose: to work with stacks to do a bracket check. 
*/

#include "stack.h"
#include <string>
#include <iostream>
using namespace std;

bool bracketCheck(const std::string& s)
{
	// Variable Declaration; empty stack list and a bool check redflag. 
	Stack<char> bracketStack;
	bool value;

	for (int i = 0; i < s.length(); i++)
	{
		// If the character in the string equals to (, {, or { then it gets pushed into the stack list
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			bracketStack.push(s[i]);
		}
		
		// if the character in the string equals to ),],} then it validates that it matches with a opening 
		//paranthesis. 
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
		{
			if (bracketStack.empty() || !ArePaired(bracketStack.top(),s[i]))
			{
				return false;
			}
			else
			{
				bracketStack.pop();
				value = true;
			}
		}
	}

	value=bracketStack.empty() ? true : false;
	return value; 
}
