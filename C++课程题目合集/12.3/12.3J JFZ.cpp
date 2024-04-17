#include<iostream>
#include<string>
using namespace std;

int ref(char c)
{
	int n;
	switch (c)
	{
		case 'A':n = 1; break;
		case '1':n = 10; break;
		case '2':n = 2; break;
		case '3':n = 3; break;
		case '4':n = 4; break;
		case '5':n = 5; break;
		case '6':n = 6; break;
		case '7':n = 7; break;
		case '8':n = 8; break;
		case '9':n = 9; break;
		case '0':n = 10; break;
		case 'J':n = 11; break;
		case 'Q':n = 12; break;
		case 'K':n = 13; break;
		default:break;
	}
	return n;
}

int main()
{
	string s;
	char a[2];
	while (cin >> s >> a)
	{
		int na = 0, nsa = 0, nso = 0, l;
		for (l = 0; s[l] != '\0'; l++);
		l--;
		na = ref(a[0]);
		nsa = ref(s[0]);
		nso = ref(s[l]);
		if ((na == 1 && nsa == 2) || (na == 13 && nso == 12))
			cout << "Yes" << endl;
		else if (nsa == na + 1 || nso == na - 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
