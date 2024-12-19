//#include<iostream>
//#include<fstream>
//
//using namespace std;
//
//class Produs {
//	int cod;
//	char* denumire;
//	float pret;
//public:
//	Produs() {
//		this->cod = 0;
//		this->denumire = nullptr;
//		this->pret = 0;
//	}
//	Produs(int cod, const char* denumire, float pret) {
//		this->cod = cod;
//		if (denumire != nullptr) {
//			this->denumire = new char[strlen(denumire) + 1];
//			strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
//		}
//		else {
//			this->denumire = nullptr;
//		}
//		this->pret = pret;
//	}
//
//	Produs(Produs & p) {
//		this->cod = p.cod;
//		if (p.denumire != nullptr) {
//			this->denumire = new char[strlen(p.denumire) + 1];
//			strcpy_s(this->denumire, strlen(p.denumire) + 1, p.denumire);
//		}
//		else {
//			this->denumire = nullptr;
//		}
//		this->pret = p.pret;
//	}
//
//
//
//	friend ostream& operator<<(ostream& out, const Produs& p)
//	{
//		out <<"Codul este:" << p.cod << ", Denumire:" << p.denumire << ", Pret:" << p.pret << endl;
//		return out;
//
//	}
//
//	friend ofstream& operator<<(ofstream& out, const Produs& p)
//	{
//		out << p.cod << " " << p.denumire << " " << p.pret << endl;
//		return out;
//
//	}
//
//	friend ifstream& operator>>(ifstream& f, Produs& p) {
//		f >> p.cod;
//		char buffer[50];
//		f >> buffer;
//		if (p.denumire != nullptr) {
//			delete[] p.denumire;
//		}
//		p.denumire = new char[strlen(buffer) + 1];
//		strcpy_s(p.denumire, strlen(buffer) + 1, buffer);
//		f >> p.pret;
//		return f;
//
//	}
//
//	void writeFile(fstream& file) {
//		file.write((char*)&this->cod, sizeof(int));
//		file.write((char*)&this->pret, sizeof(float));
//		int lungime = strlen(this->denumire);
//		file.write((char*)&lungime, sizeof(int));
//		for (int i = 0; i < lungime; i++) {
//			file.write((char*)&this->denumire[i], sizeof(char));
//		}
//	}
//
//	void readFile(fstream& file) {
//		file.read((char*)&this->cod, sizeof(int));
//		file.read((char*)&this->pret, sizeof(float));
//		int lungime = 0;
//		file.read((char*)&lungime, sizeof(int));
//		if (this->denumire != nullptr) {
//			delete[]this->denumire;
//		}
//		this->denumire = new char[lungime+1];
//		for (int i = 0; i < lungime; i++) {
//			file.read((char*)&this->denumire[i], sizeof(char));
//		}
//		this->denumire[lungime] = '\0';
//	}
//
//};
//
//int main() {
//
//	//ofstream file("fisier.dat", ios::app);
//	//Produs p(101, "Termos", 10);
//	//file << p;
//	//cout << p;
//	//file.close();
//
//	//ifstream f("fisier.txt", ios::in);
//	//Produs p;
//	//f >> p;
//	//cout << p;
//	//f >> p;
//	//cout << p;
//
//	//f.close();
//
//	fstream fbin("fisierBinar.txt", ios::out | ios::binary);
//	Produs p(643, "Termos", 456);
//
//	p.writeFile(fbin);
//
//	fbin.close();
//
//
//	fstream fReadBin("fisierBinar.txt", ios::binary | ios::in);
//	Produs p2;
//	p2.readFile(fReadBin);
//	cout << p2;
//
//	return 84334;
//}