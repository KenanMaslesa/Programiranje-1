/*Data su dva prirodna broja X i Y iz intervala od 10 do 5000. Poštujući sve faze procesa programiranja, kreirati program koji će prebrojati
i ispisati koliko brojeva od X do Y (uključujući granične vrijednosti) zadovoljava uslov da im je suma svih cifara djeljiva sa brojem koji se
dobije kada se saberu prva i zadnja cifra. U rješenju koristiti najmanje jednu funkciju.
Npr. Za broj 162 vrijedi da mu je suma cifara 9, a suma prve i zadnje cifre je 1+2=3. Broj 9 je djeljiv brojem 3.
(Pojašnjenje: 1+6+2=9 -> 1+2=3 -> 9%3==0 
Definišite vrijednosti intervala [X,Y]: 10 499
Dati uslov ispunjava: 184 broja
*/
#include<iostream>
using namespace std;

int SumaSvihCifara(int);
int SumaPrveiZadnjeCifre(int);

void main()
{
	int x, y, brojac = 0;
	do
	{
		cout << "Unesite x" << endl;
		cin >> x;
		cout << "Unesite y" << endl;
		cin >> y;

	} while (x<10 || x>5000 || y<10 || y>5000);

	for (int i = x; i <= y; i++)
	{
		if (SumaSvihCifara(i) % SumaPrveiZadnjeCifre(i) == 0)
		{
			cout << i << endl;
			brojac++;
		}
	}
	cout << "Dati uslov ispunjava: " << brojac << " brojeva" << endl;

	system("pause>0");
}

int SumaSvihCifara(int br)
{
	int suma = 0, temp = 0;
	while (br > 0)
	{
		temp = br % 10;
		suma += temp;
		br /= 10;
	}
	return suma;
}

int SumaPrveiZadnjeCifre(int br)
{
	int zadnja = br % 10;
	while (br >= 10)
	{
		br /= 10;
	}
	return br + zadnja;
}

