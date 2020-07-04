/*
Napisati program koji će učitati prirodni broj n<=10, a zatim n cijelih brojeva. Za svaki broj treba ispitati radi li se o broju koji je
'dobar'. Zatim sve dobre brojeve prebaciti u novi niz te ispisati njegove elemente i veličinu. Koristiti zasebne funkcije za unos i
provjeru je li broj dobar.
Napomena: Broje je 'dobar' ako je svaka njegova cifra veća od zbira cifara koji se nalaze desno od nje.
Na primjer, 9620 je 'dobar' jer je 2>0, 6>2+0, 9>6+2+0. Drugi primjeri: 8421, 95210, 732, 621, 852 itd.
*/
#include<iostream>
using namespace std;

const int vel = 10;
void Unos(int[], int);
void SortiranjePoSrednjojCifri(int[], int);
void ObicnoSortiranje(int[], int);

void main()
{
	int n, niz[vel];
	do
	{
		cout << "Koliko brojeva zelite unijeti" << endl;
		cin >> n;

	} while (n < 1 || n>10);

	Unos(niz, n);
	SortiranjePoSrednjojCifri(niz, n);
	cout << "Sortiranje po srednjoj cifri  ";
	for (int i = 0; i < n; i++)
	{
		cout << niz[i] << "|";
	}

	ObicnoSortiranje(niz, n);
	cout <<endl<< "Obicno Sortiranje  ";
	for (int i = 0; i < n; i++)
	{
		cout << niz[i] << "|";
	}

	system("pause");
}

void Unos(int niz[], int vel)
{
	int broj;
	for (int i = 0; i < vel; i++)
	{
		cout << "Unesite " << i + 1 << ". broj" << endl;
		cin >> broj;
		if (broj > 99 && broj < 1000)
			niz[i] = broj;
		else
		{
			i--;
			cout << "Pogresan unos" << endl;
		}
	}
}

void SortiranjePoSrednjojCifri(int niz[], int vel)
{
	bool promjena = true;
	int temp, srednja1, srednja2;
	while (promjena)
	{
		promjena = false;
		for (int i = 0; i < vel - 1; i++)
		{
			srednja1 = (niz[i] / 10) % 10;
			srednja2 = (niz[i + 1] / 10) % 10;
			if (srednja1 > srednja2)
			{
				temp = niz[i];
				niz[i] = niz[i + 1];
				niz[i + 1] = temp;
				promjena = true;
			}
		}
	}
}

void ObicnoSortiranje(int niz[], int vel)
{
	bool promjena = true;
	int temp;
	while (promjena)
	{
		promjena = false;
		for (int i = 0; i < vel - 1; i++)
		{
			if (niz[i] > niz[i+1])
			{
				temp = niz[i];
				niz[i] = niz[i + 1];
				niz[i + 1] = temp;
				promjena = true;
			}
		}
	}
}
