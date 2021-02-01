#include <iostream>
#include <fstream>

using namespace std;

class licz{
	public:
	void pierwsze();
	void drugie();
};

void licz::pierwsze(){
	ifstream plik1;
	ofstream plik2;
	int t[1000];
	int min,max;
	
	plik1.open("liczby1.txt");
	while(plik1.good()){
		for(int i=0;i<1000;i++){
			plik1 >> t[i];
		}
	}
	int dlugosc = sizeof(t);

	for(int i=1;i<dlugosc;i++) {
		if(min>t[i])
			min = t[i];
	}
	for(int i=1;i<dlugosc;i++) {
		if(max<t[i])
			max = t[i];
	}

	
	while(min){
	min=min%8;
    min/=8;
	}
	
	while(max){
	max=max%8;
    max/=8;
	}
			
	cout<<"Najmniejsza liczba: "<<min<<endl;
	cout<<"Najwieksza liczba: "<<max<<endl;
}

void licz::drugie(){
	ifstream plik3;
	ofstream plik4;
	int t2[1000];
	int najdluzszy=0;
	int najdluzszy2=0;
	int poczatek;
	
	plik3.open("liczby2.txt");
	while(plik3.good()){
		for(int i=0;i<1000;i++){
			plik3 >> t2[i];
		}
	}
	int dlugosc2 = sizeof(t2);
	for(int i=0;i<1000;i++){
		if(t2[i]<t2[i+1]){
			najdluzszy++;
		}else{
			if(najdluzszy>najdluzszy2){
				najdluzszy=najdluzszy2;
				poczatek = t2[i-najdluzszy];
				najdluzszy = 0;
			}else{
				najdluzszy = 0;
			}
		}
	}
	cout<<"Liczba rozpoczynaj¹ca ci¹g: "<<poczatek<<endl;
	cout<<"Dlugosc rosnacego ciagu: "<<najdluzszy2;
}

int main(int argc, char** argv) {
	
	licz l;
	l.pierwsze();
	l.drugie();
	
	return 0;
}
