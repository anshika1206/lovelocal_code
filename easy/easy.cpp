// Question : Given a string s consisting of words and spaces, return the length of the last word in the string.

#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(string s)
{
	int n = s.length();
	int length = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (s[i] == ' ')
		{
			if (length > 0)
			{
				break;
			}
		}
		else
		{
			length++;
		}
	}
	return length;
}

int main()
{
	cout << "Enter a string: ";

	string input;
	cin >> input;
	int result = lengthOfLastWord(input);

	cout << "Length of the last word: " << result << endl;

	return 0;
}
