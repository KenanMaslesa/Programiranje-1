/*
Napisati program koji će omogućiti unos cjelobrojnih parnih vrijednosti sa neparnim brojem cifara u jednodimenzionalni niz od 20
elemenata a zatim napraviti funkciju koja ce primati kao argument taj niz. Funkcija treba da izbaci iz niza sve brojeve koji su
djeljivi sa 6 a da ostavi u nizu sve ostale brojeve. Izbacivanje brojeva se treba napraviti tako da se ostatak niza pomjeri u lijevo
da ne bi bilo praznih elemenata. To pomjeranje je potrebno uraditi prilikom izbacivanja svakog elementa a ne na kraju pošto su svi elementi
djeljivi sa 6. 
*/
#include<iostream>
using namespace std;

const int vel = 5;
int BrojCifara(int);
void Unos(int[]);
void Ukloni(int[], int&);


void main()
{
	int niz[vel], stvarnaVel = 0;

	Unos(niz);
	Ukloni(niz, stvarnaVel);

	for (int i = 0; i < stvarnaVel; i++)
	{
		cout << niz[i] << "|";
	}

	system("pause");
}

int BrojCifara(int br)
{
	int brojac = 0;
	while (br > 0)
	{
		br /= 10;
		brojac++;
	}
	return brojac;
}

void Unos(int niz[])
{
	int broj;
	for (int i = 0; i < vel; i++)
	{
		cout << "Unesite " << i + 1 << ". broj" << endl;
		cin >> broj;
		if (broj % 2 == 0 && BrojCifara(broj) % 2 != 0)
			niz[i] = broj;
		else
		{
			cout << "Pogresan unos, unesite paran broj sa neparnim brojem cifara" << endl;
			i--;
		}
	}
}

void Ukloni(int niz[], int& stvarna)
{
	int indeks = 0;
	for (int i = 0; i < vel; i++)
	{
		if (niz[i] % 6 != 0)
		{
			niz[indeks++] = niz[i];
		}
	}
	stvarna = indeks;
}