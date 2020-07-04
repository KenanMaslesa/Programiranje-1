/*Napisati program koji omogućava unos pozitivnog broja n te pronalazi njegove parne cifre i formira novi broj u kojem su parne cifre zamijenjene cifrom 5.
Dodatno program treba ispisati razliku unesenog i broja koji se dobije nakon zamjene cifara.*/

#include<iostream>
using namespace std;

int ZamjenaCifara(int);

void main()
{
	int n, zamijenjenBroj;
	do {
		cout << "Unesite neki prirodan broj" << endl;
		cin >> n;
	} while (n < 1);
	zamijenjenBroj = ZamjenaCifara(n);
	cout << zamijenjenBroj << "-" << n << " = " << zamijenjenBroj - n << endl;

	system("pause>0");
}

int ZamjenaCifara(int br)
{
	int novi = 0, temp = 0, potencija = 0;
	while (br > 0)
	{
		temp = br % 10;
		if (temp % 2 == 0)
		{
			novi += 5 * pow(10, potencija);
		}
		else
		{
			novi += temp * pow(10, potencija);
		}
		br /= 10;
		potencija++;
	}
	return novi;
}
