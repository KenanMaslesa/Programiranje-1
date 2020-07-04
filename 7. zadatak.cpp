/* 
Napisati program koji će učitati prirodni broj n<=10, a zatim n cijelih brojeva. Za svaki broj treba ispitati radi li se o broju koji je
'dobar'. Zatim sve dobre brojeve prebaciti u novi niz te ispisati njegove elemente i veličinu. Koristiti zasebne funkcije za unos i 
provjeru je li broj dobar.
Napomena: Broje je 'dobar' ako je svaka njegova cifra veća od zbira cifara koji se nalaze desno od nje.
Na primjer, 9620 je 'dobar' jer je 2>0, 6>2+0, 9>6+2+0. Drugi primjeri: 8421, 95210, 732, 621, 852 itd.
*/
#include<iostream>
using namespace std;

int PrvaCifra(int);
bool Dobar(int);
int SumaSvihCifaraOsimPrve(int);
void Unos(int[], int, int&);
void Ispis(int[], int);

const int vel = 10;

void main()
{
	int n, niz[vel], stvarnaVel = 0;
	do
	{
		cout << "Koliko brojeva zelite unijeti(<=10)?" << endl;
		cin >> n;

	} while (n<1 || n>10);

	Unos(niz, n, stvarnaVel);
	cout << "Velicina niza je: " << stvarnaVel << endl;
	Ispis(niz, stvarnaVel);
	
    system("pause");
}

int PrvaCifra(int br)
{
	while (br >= 10)
	{
		br /= 10;
	}
	return br;
}
int SumaSvihCifaraOsimPrve(int br)
{
	int suma = 0, temp;
	while (br >= 10)
	{
		temp = br % 10;
		suma += temp;
		br /= 10;
	}
	return suma;
}
bool Dobar(int br)
{
	if (PrvaCifra(br) > SumaSvihCifaraOsimPrve(br))
		return true;
	else
		return false;
}

void Unos(int niz[], int n, int& stvarnaVel)
{
	int broj, indeks = 0;
	for (int i = 0; i < n; i++)
	{
		cout << "Unesite " << i + 1 << ". broj" << endl;
		cin >> broj;
		if (Dobar(broj))
		{
			niz[indeks++] = broj;
		}
	}
	stvarnaVel = indeks;
}
void Ispis(int niz[], int vel)
{
	for (int i = 0; i < vel; i++)
	{
		cout << niz[i] << endl;
	}
}