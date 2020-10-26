#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<vector<int>> t;

void resol(int ini, int fin, int plat, int torre, int band)
{
	int i = 0;
	int med = (ini+fin)/2;
	t[med-1][0] = plat;
	t[med-1][1] = torre;
	if(plat > 1){
		resol(med+1, fin, plat-1, torre,band);
	
		if(plat%2 == band)
			i = -1;
		else
			i = 1;
		torre = (torre+i)%3;
		if(torre == 0)
			torre = 3;
		
		resol(ini, med, plat-1, torre,band);  
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
		vector<int> e{0,0};
		t.push_back(e);
	}
	
	if(plat%2==0)
		resol(0,nMov,plat,3,0);
	else
		resol(0,nMov,plat,3,1);
	
	for(int i = 0; i<nMov-1; i++)
	{
		cout<<"Mover Platillo "<<t[i][0]<<" ";
		cout<<"a torre "<<t[i][1]<<" "<<endl;
	}
	cout<<"\nnumero de movimientos "<<nMov-1<<endl;
	return 0;
}