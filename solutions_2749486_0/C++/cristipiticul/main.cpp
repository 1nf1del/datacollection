#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

ifstream fin("data.in");
ofstream fout("data.out");
/*B */
int main()
{
	int T, x, y, test, i;
	fin >> T;

	for(test = 1; test <= T; test++)
	{
		fin >> x >> y;
		fout << "Case #" << test << ": ";
		if(x > 0)
		{
			while(x)
			{
				fout << "WE";
				x--;
			}
		}
		else
		{
			while(x)
			{
				fout << "EW";
				x++;
			}
		}
		if(y > 0)
		{
			while(y)
			{
				fout << "SN";
				y--;
			}
		}
		else
		{
			while(y)
			{
				fout << "NS";
				y++;
			}
		}
		fout << '\n';
	}
}

/*A
bool vowel[255];
char str[1000005];
int main()
{
	vowel['a'] = vowel['e'] = vowel['i'] = vowel['o'] = vowel['u'] = 1;
	int T, n, numcons, i, lastEnd, test, len;
	long long sum;

	fin >> T;

	for(test = 1; test <= T; test++)
	{
		fin >> str >> n;

		numcons = 0;
		lastEnd = n - 2;
		sum = 0;
		len = strlen(str);

		for(i = 0; str[i] != 0; i++)
		{
			if(vowel[str[i]])
				numcons = 0;
			else
			{
				numcons++;
				if(numcons >= n)
				{
					sum += (len - i) * (i - lastEnd);
					lastEnd = i;
				}
			}
		}

		fout << "Case #" <<test<<": "<<sum<<'\n';

	}

    return 0;
}

*/
