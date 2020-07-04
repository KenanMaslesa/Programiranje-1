/* Kreirati program koji će pronaći i ispisati sve brojeve od X do Y (uključujući granične vrijednosti) koji su djeljivi svim svojim ciframa.
Na primjer, broj 36 je djeljiv brojevima 3 i 6. (36/6=6 i 36/3=12). Brojeve X i Y unosi korisnik i moraju biti u opsegu od 10 do 6000.
Obevezno koristiti bar jednu funkciju. 
Primjer:
Unesite granice intervala: 32 37
Brojevi u navedenom opsegu koji zadovoljavaju uslov su: 33, 36.
*/
#include<iostream>
using namespace std;

bool DjeljivSvimSvojimCiframa(int);

void main()
{
	int x, y;
	do
	{
		cout << "Unesite x" << endl;
		cin >> x;
		cout << "Unesite y" << endl;
		cin >> y;

	} while (x<10 || x>6000 || y<10 || y>6000);

	cout << "___________________" << endl;

	for (int i = x; i <=y; i++)
	{
		if (DjeljivSvimSvojimCiframa(i))
		{
			cout << i << endl;
		}
	}
	system("pause>0");
}

bool DjeljivSvimSvojimCiframa(int br)
{
	int zadnja, temp = br;
	while (br > 0)
	{
		zadnja = br % 10;
		if (zadnja != 0)
		{
			if (temp % zadnja != 0)
				return false;

		}
		br /= 10;
	}
	return true;
}


