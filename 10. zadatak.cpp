/*
Dat je 2D niz koji simulira šahovsku tablu. Omogućiti korisniku unos cjelobrojnih elemenata 2D niza tako da se u svako 
crno polje unese parni broj sa neparnim brojem cifara a u bijelo polje neparni broj sa parnim brojem cifara. Provjeriti
da li je matrica centralno simetrična po glavnoj dijagonali (dakle da li je broj na poziciji 1.0 jednak broju na poziciji 0.1,
na 0.2 jednak onom na 2.0, na 3.1 jednak onome na 1.3 itd..) te ako jeste simetricna naci i ispisati indeks reda sa najvecim
prosjekom elemenata, a ako nije u potpunosti simetricna naci i ispisati indeks kolone sa najmanjim prosjekom elemenata.
*/
#include<iostream>
using namespace std;

const int vel = 3;
int BrojCifara(int);
void Unos(int[][vel]);
void Ispis(int[][vel]);
bool SimetricnaPoGlavnoj(int[][vel]);
int IndeksReda(int[][vel]);
int IndeksKoloneSaNajmanjimProsjekom(int[][vel]);


void main()
{
	int niz[vel][vel];
	Unos(niz);
	Ispis(niz);

	if (SimetricnaPoGlavnoj(niz))
		cout << "Indeks reda sa najvecim prosjekom elemenata je:" << IndeksReda(niz) << endl;
	else
		cout << "Indeks kolone sa najmanjim prosjekom elemenata je:" << IndeksKoloneSaNajmanjimProsjekom(niz) << endl;

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

void Unos(int niz[][vel])
{
	for (int i = 0; i < vel; i++)
	{
		for (int j = 0; j < vel; j++)
		{
			if ((i + j) % 2 == 0)
				cout << "Unosite broj u crno polje (mora biti paran sa neparnim brojem cifara)" << endl;
			else
				cout << "Unosite broj u bijelo polje (mora biti neparan sa parnim brojem cifara)" << endl;
			cin >> niz[i][j];
			if ((i + j) % 2 == 0 && BrojCifara(niz[i][j]) % 2 != 0 && niz[i][j] % 2 == 0)
			{
				continue;
			}
			else if ((i + j) % 2 != 0 && BrojCifara(niz[i][j]) % 2 == 0 && niz[i][j] % 2 != 0)
			{
				continue;
			}
			else
			{
				j--;
				cout << "Pogresan unos" << endl;
			}
		}
	}
	
}

void Ispis(int niz[][vel])
{
	cout << endl << endl;
	for (int i = 0; i < vel; i++)
	{
		for (int j = 0; j < vel; j++)
		{
			cout << niz[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;

}

bool SimetricnaPoGlavnoj(int niz[][vel])
{
	int brojac = 0;
	for (int i = 0; i < vel; i++)
	{
		for (int j = 0; j < vel; j++)
		{
			if (j - i == 2)
			{
				if (niz[j][i] == niz[i][j])
					brojac++;
			}
			else if (j - i == 1)
			{
				if (i == 0 || i == 1 || i == vel || i == vel - 1)
				{
					if (niz[i][j] == niz[j][i])
						brojac++;
				}
			}
		}
	}
	if (brojac == vel)
		return true;
	else
		return false;
}

int IndeksReda(int niz[][vel])
{
	double prosjekReda = 0, najveciProsjek = 0;
	int indeks = -1;

	for (int i = 0; i < vel; i++)
	{
		for (int j = 0; j < vel; j++)
		{
			prosjekReda += niz[i][j];

		}
		prosjekReda /= vel;
		if (prosjekReda > najveciProsjek)
		{
			najveciProsjek = prosjekReda;
			indeks = i;
		}
		prosjekReda = 0;
	}
	return indeks;
}

int IndeksKoloneSaNajmanjimProsjekom(int niz[][vel])
{
	double prosjekKolone = 0, najmanjiProsjek = INT_MAX;
	int indeks = -1;

	for (int i = 0; i < vel; i++)
	{
		for (int j = 0; j < vel; j++)
		{
			prosjekKolone += niz[i][j];

		prosjekKolone /= vel;

		if (prosjekKolone < najmanjiProsjek)
		{
			najmanjiProsjek = prosjekKolone;
			indeks = j;
		}
		}
		prosjekKolone = 0;

	}
	return indeks;
}