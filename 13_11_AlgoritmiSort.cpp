#include "iostream"
#include<vector>
#include<list>
#include<algorithm>
#include<numeric>
using namespace std;

class Laptop {
	int RAM;
	char* tipCPU;
	float rezolutieEcran;
	bool cameraWeb;
public:
	int getRAM() {
		return RAM;
	}
	char* getTipCPU() {
		return tipCPU;
	}
	float getRezolutieEcran() {
		return rezolutieEcran;
	}
	bool hasCameraWeb() {
		return cameraWeb;
	}
	void setRAM(int RAM) {
		if (RAM > 0) {
			this->RAM = RAM;
		}
	}
	
	void setTipCPU(const char* tipCPU) {
		if (strlen(tipCPU) > 0) {
			if (this->tipCPU != NULL) {
				delete[]this->tipCPU;
			}
			this->tipCPU = new char[strlen(tipCPU)+1];
			strcpy(this->tipCPU, tipCPU);
		}
	}
	
	void setRezolutieEcran(float rezolutieEcran) {
		if (rezolutieEcran > 10) {
			this->rezolutieEcran = rezolutieEcran;
		}
	}
	
	void setCameraWeb(bool cameraWeb) {
		this->cameraWeb = cameraWeb;
	}

	Laptop() {
		RAM = 16;
		tipCPU = new char[strlen("AMD")+1];
		strcpy(tipCPU, "AMD");
		rezolutieEcran = 13.3;
		this->cameraWeb = true;
	}
	
	Laptop(int RAM, const char* tipCPU, float rezolutie, bool camera) {
		this->RAM = RAM;
		this->tipCPU = new char[strlen(tipCPU) + 1];
		strcpy(this->tipCPU, tipCPU);
		this->rezolutieEcran = rezolutie;
		this->cameraWeb = camera;
	}

	Laptop(const Laptop& l) {
		this->RAM = l.RAM;
		this->tipCPU = new char[strlen(l.tipCPU) + 1];
		strcpy(this->tipCPU, l.tipCPU);
		this->rezolutieEcran = l.rezolutieEcran;
		this->cameraWeb = l.cameraWeb;
	}

	Laptop& operator=(const Laptop& l) {
		this->RAM = l.RAM;
		if (this->tipCPU != NULL) {
			delete[]this->tipCPU;
		}
		this->tipCPU = new char[strlen(l.tipCPU) + 1];
		strcpy(this->tipCPU, l.tipCPU);
		this->rezolutieEcran = l.rezolutieEcran;
		this->cameraWeb = l.cameraWeb;
		return *this;
	}

	virtual ~Laptop() {
		if (this->tipCPU != NULL) {
			delete[]this->tipCPU;
		}
	}
	friend ostream& operator<<(ostream& console, Laptop laptop) {
		console << laptop.RAM << " " << laptop.tipCPU << " ";
		console << laptop.rezolutieEcran << " " << laptop.cameraWeb << endl;
		return console;
	};	
	bool operator<(Laptop l) {
		return this->RAM < l.RAM;
	}

};


bool functieSortareRezolutie(Laptop a, Laptop b) {
	return a.getRezolutieEcran() < b.getRezolutieEcran();
}

bool functieSortareTipCPU(Laptop a, Laptop b) {
	return strcmp(a.getTipCPU(),b.getTipCPU())<0;
}
int functieAdunare(int a, int b) {
	return a + b;
}

int functieInmultire(int a, int b) {
	return a * b;
}

int functieTransformare(int a) {
	return a * a;
}

Laptop functieNoua(Laptop l) {
	l.setRAM(l.getRAM() + 50);
	return l;
}

void main() {

	//vector<Laptop> laptopuri;

	//laptopuri.push_back(Laptop(20,"INTEL",13,true));
	//laptopuri.push_back(Laptop(16, "BBB", 17, false));
	//laptopuri.push_back(Laptop(8, "AMD", 15, false));
	//for (int i = 0; i < laptopuri.size(); i++) {
	//	cout << laptopuri[i]<<" ";
	//}
	//cout<<endl;
	//sort(laptopuri.begin(), laptopuri.end(),  functieSortareRezolutie);
	//cout << endl;
	//for (int i = 0; i < laptopuri.size(); i++) {
	//	cout << laptopuri[i] << " ";
	//}
	//vector<Laptop> v4(laptopuri.size());
	//transform(laptopuri.begin(), laptopuri.end(), laptopuri.begin(), functieNoua);
	//
	//for (int i = 0; i < laptopuri.size(); i++) {
	//	cout << laptopuri[i] << " ";
	//}
	vector<int> v;
	v.push_back(7);
	v.push_back(3);
	v.push_back(8);
	int p = 1;
	for (int i = 0; i < v.size(); i++) {
		p = functieInmultire(p,v[i]);
	}


	cout<<"Total:"<<accumulate(v.begin(), v.end(), 0);

	//vector<int>vectorRezultat(v.size());
	//int f=0;
	//transform(v.begin(), v.end(), vectorRezultat.begin(), functieTransformare);

	//for (int i = 0; i < vectorRezultat.size(); i++) {
	//	cout << vectorRezultat[i] << " ";
	//}
}