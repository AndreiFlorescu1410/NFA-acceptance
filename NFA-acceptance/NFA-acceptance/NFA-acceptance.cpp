#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

void avanseaza(char cuvant[255], int cuvant_i, int pozitie, int m, int n, int a[255][255], int finale[255], int& acceptat)
{
	//    cout<<"Avansez pe "<<pozitie<<" "<<cuvant_i<<endl;
	if (cuvant_i == m)
		for (int i = 1; i <= m; i++)
			if (pozitie == finale[i])
				acceptat = 1;
	for (int j = 1; j <= n; j++)
	{
		if (a[pozitie][j] == cuvant[cuvant_i])
			avanseaza(cuvant, cuvant_i + 1, j, m, n, a, finale, acceptat);
	}

}


int main()
{

	int n, m, a[255][255], finale[255], acceptat = 0;
	char cuvant[255];
	int i, x, y, nr;
	char b;
	ifstream f("input.in");
	f >> n >> nr;
	for (i = 1; i <= nr; i++)
	{
		f >> x >> y >> b;
		a[x][y] = b;
	}
	f >> m;
	for (i = 1; i <= m; i++)
		f >> finale[i];
	f >> cuvant;
	avanseaza(cuvant, 0, 1, strlen(cuvant), n, a, finale, acceptat);
	if (acceptat == 1)
		cout << "Cuvant acceptat";
	else
		cout << "Cuvant neacceptat";
	//Afisare in fisier
	/*ofstream g("output.out");
	if (acceptat == 1)
		g << "Cuvant acceptat";
	else
		g << "Cuvant neacceptat";*/
	return 0;
}
