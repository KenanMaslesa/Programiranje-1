/* a) Omogućiti korisniku unos prirodnog broja i nakon toga napraviti funkciju koja će prebrojati koliko taj broj ima cifara
   b) Za taj broj pronaći i ispisati prvu, srednju i zadnju cifu (koristiti zasebne funkcije)
   c) Obrnuti cifre tom broju (npr. ako je broj bio 12345 treba biti 54321) */
#include<iostream>
using namespace std;

int BrojanjeCifara(int);
int PrvaCifra(int);
int SrednjaCifra(int);
int ZadnjaCifra(int);
int ObrniCifre(int);

void main()
{
	int broj;
	cout << "Unesite neki broj" << endl;
	cin >> broj;
	cout << "Broj koji ste unijeli ima " << BrojanjeCifara(broj) <<" cifara" <<endl;
	cout << " Prva cifra broja " << broj << " je: " << PrvaCifra(broj) << endl;
	cout << " Srednja cifra broja " << broj << " je: " << SrednjaCifra(broj) << endl;
	cout << " Zadnja cifra broja " << broj << " je: " << ZadnjaCifra(broj) << endl;
	cout << "Obrnut broj " << broj << " je: " << ObrniCifre(broj) << endl;

	system("pause>0");
}

int BrojanjeCifara(int br)
{
	int brojacCifara = 0;
	while (br > 0)
	{
		br /= 10;
		brojacCifara++;
	}
	return brojacCifara;
}

int PrvaCifra(int br)
{
	while (br >= 10)
	{
		br = br / 10;
	}
	return br;
}

int SrednjaCifra(int br)
{
	int kolikoOtkinuti = BrojanjeCifara(br)/2;
	br = br / pow(10, kolikoOtkinuti);
	return br % 10;
}

int ZadnjaCifra(int br)
{
	return br % 10;
}

int ObrniCifre(int br)
{
	int novi = 0, temp = 0;
	while (br > 0)
	{
		temp = br % 10;
		novi = novi * 10 + temp;
		br /= 10;
	}
	return novi;
}
