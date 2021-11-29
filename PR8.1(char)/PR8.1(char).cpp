#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

bool Include(const char* str, const char* cs)
{
	bool r = true;
	for (int i = 0; cs[i] != '\0'; i++)
		r = r && (strchr(str, cs[i]));

	return r;
}
char* Change(char* str)
{
	char* t = new char[strlen(str)];
	char* p;
	int pos1 = 0;
	int pos2 = 0;
	*t = 0;

	while (p = strchr(str + pos1, 'w'))
	{
		if (str[p - str + 1] == 'h' && str[p - str + 2] == 'i'
			&& str[p - str + 3] == 'l' && str[p - str + 4] == 'e')
		{
			pos2 = p - str + 5;
			strncat(t, str + pos1, pos2 - pos1 - 5);
			strcat(t, "**");
			pos1 = pos2;
		}
	}
	strcat(t, str + pos1);
	strcpy(str, t);
	return t;
}
int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);

	char cs[] = "while";
	if (Include(str, cs))
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	char* dest = new char[151];
	dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;

	return 0;
}