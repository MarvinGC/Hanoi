#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<vector<int>> t;

void resol(int ini, int fin, int plat,int tPartida, int tObjetivo, int band)
{
	int i = 0;
	int med = (ini+fin)/2;
	t[med-1][0] = plat;
	t[med-1][1] = tPartida;
	t[med-1][2] = tObjetivo;

	(plat%2 == band) ? i = -1 :	i = 1;

	int tOb = (tObjetivo+i)%3;
	if(tOb == 0) tOb = 3;

	int tPr = (tPartida-i)%3;
	if(tPr == 0) tPr = 3;

	if(plat > 1){
		resol(med+1, fin, plat-1,tPr, tObjetivo,band);
		resol(ini, med, plat-1, tPartida, tOb,band);  
	}	
}
int main()
{
	int nMov;
	int plat;
	cout << "Escribe el numero de platillos"<<endl;
	cin >> plat;
	nMov = pow(2,plat);

	for(int i=0;i<nMov;i++){
		vector<int> e{0,0,0};
		t.push_back(e);
	}
	
	if(plat%2==0)
		resol(0,nMov,plat,1,3,0);
	else
		resol(0,nMov,plat,1,3,1);
	
	for(int i = 0; i<nMov-1; i++)
	{
		cout << "Mover Platillo " << t[i][0] << " ";
		cout << "de torre " << t[i][1] << " ";
		cout << "a torre " << t[i][2] << " " << endl;
	}
	cout<<"\nnumero de movimientos "<<nMov-1<<endl;
	return 0;
}