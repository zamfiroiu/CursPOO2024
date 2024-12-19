//#include <iostream>
//using namespace std;
//
//class Tramvai {
//private:
//	static int nrTramvaie;
//	int capacitate;
//	int nrPersoaneImbracate;
//	char* producator;
//
//public:
//	Tramvai() {
//		this->capacitate = 40;
//		this->nrPersoaneImbracate = 35;
//		this->producator = new char[strlen("A") + 1];
//
//		this->nrTramvaie = 30;
//
//	}
//	Tramvai(int capacitate, int persoane, char producator) {
//		this->capacitate = capacitate;
//		this->nrPersoaneImbracate = persoane;
//		this->producator = new char[strlen("A") + 1];
//		for (int i = 0; i < strlen("A"); i++) {
//			this->producator = new char[strlen("A") + 1];
//		}
//	}
//	Tramvai(const Tramvai& t) {
//		this->capacitate = t.capacitate;
//		this->nrPersoaneImbracate = t.capacitate;
//		this->producator = new char[strlen(t.producator) + 1];
//		for (int i = 0; i < strlen(t.producator); i++) {
//			strcpy_s(this->producator, strlen(t.producator) + 1, t.producator);
//		}
//	}
//	~Tramvai() {
//		if (this->producator != 0) {
//			delete[]this->producator;
//		}
//	}
//
//	int  getafisareCapacitate() {
//		return this->capacitate;
//	}
//
//	void setCapacitate(int nouaCapacitate) {
//		if (this->capacitate != NULL) {
//			this->capacitate = nouaCapacitate;
//		}
//	}
//
//	int getafisareNumarDePeroaneImbracata() {
//		if (this->nrPersoaneImbracate < capacitate) {
//			return this->nrPersoaneImbracate;
//		}
//	}
//
//	void setNumarDePersoaneImbracate(int noulNrDePersImbracate) {
//		if (this->nrPersoaneImbracate != NULL) {
//			this->nrPersoaneImbracate = noulNrDePersImbracate;
//		}
//	}
//	void afisare() {
//		cout << "Numarul de tramvaie este: " << this->nrTramvaie << endl;
//		cout << "Capacitate: " << this->capacitate << endl;
//		cout << "Nr de persoane imbracate: " << this->nrPersoaneImbracate << endl;
//		for (int i = 0; i < strlen("A"); i++) {
//			cout << "Producator" << this->producator;
//
//
//		}
//
//	}
//
//};
//int Tramvai::nrTramvaie = 10;
//
//int main() {
//	Tramvai t1;
//	t1.afisare();
//
//	Tramvai t2;
//	t2.setCapacitate(20);
//	t2.setCapacitate(16);
//
//	return 0;
//
//}