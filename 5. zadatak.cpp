/* Svaki paran broj se može prikazati kao suma dvaju prostih brojeva (tkzv. Goldbachovo pravilo).
Razraditi logiku programa koji će najprije učitati dva prirodna broja n1 i n2. Ako je n1<n2 zamijeniti n1 sa n2.
Prikazati sve parne brojeve u intervalu od n1 do n2 kao sumu dvaju prostih brojeva. U glavnom programu samo unijeti navedena dva broja
i pozvati funkciju koja obavlja zadani posao.
*/
#include<iostream>
using namespace std;

bool Prost(int);
void Goldbach(int, int);


void main()
{
	int n1, n2, temp;
	cout << "Unesite n1 i n2" << endl;
	cin >> n1 >> n2;

	if (n1 > n2)
	{
		temp = n1;
		n1 = n2;
		n2 = temp;
	}

	Goldbach(n1, n2);

	system("pause>0");
}

bool Prost(int br)
{
	if (br == 1)
		return false;

	for (int i = 2; i < br; i++)
	{
		if (br % i == 0)
			return false;
	}
	return true;
}

void Goldbach(int n1, int n2)
{
	//Broj 2 se ne može prikazati kao suma dvaju prostih brojeva (može kao 1+1 ali 1 nije prost broj) tako da ispisujemo od 4
	if (n1 < 4)
		n1 = 4;

	if (n1 % 2 != 0)
		n1++;

	for (int i = 2; i < n2; i++)
	{
		for (int j = 2; j < n2; j++)
		{
			if (Prost(i) && Prost(j))
			{
				if (i + j == n1)
				{
					cout << n1 << " = " << i << " + " << j << endl;
					n1 += 2;
				}
			}

			if (n1 > n2)
				return;
		}
	
	}
}