//#include<iostream>
//using namespace std;
//
//class Marker {
//private:
//	static int numarObiecte;
//	const int id;
//	string culoare;
//	float greutate;
//	int lungime;
//	char* producator;
//public:
//
//	class Capac {
//	private:
//		int lungime;
//	public:
//		Capac() {
//			this->lungime = 3;
//		}
//		Capac(int lungime) {
//			this->lungime = lungime;
//		}
//	};
//
//	Marker operator!() {
//		Marker temp = *this;
//		temp.lungime = 0;
//		return temp;
//	}
//
//	Marker() :id(++numarObiecte), greutate(45) {
//		this->culoare = "Albastru";
//		//this->greutate = 45;
//		this->lungime = 12;
//		this->producator = NULL;
//	}
//
//	Marker(string culoare, float greutate, int lungime) : id(++numarObiecte) {
//		this->culoare = culoare;
//		this->greutate = greutate;
//		this->lungime = lungime;
//		this->producator = new char[strlen("B4U") + 1];
//		strcpy_s(this->producator, strlen("B4U") + 1, "B4U");
//	}
//
//	Marker(const Marker& m) : id(++numarObiecte) {
//		this->culoare = m.culoare;
//		this->greutate = m.greutate;
//		this->lungime = m.lungime;
//		if (m.producator != NULL) {
//			this->producator = new char[strlen(m.producator) + 1];
//			strcpy_s(this->producator, strlen(m.producator) + 1, m.producator);
//		}
//		else {
//			this->producator = NULL;
//		}
//	}
//	
//	Marker operator=(const Marker& m)  {
//		if (&m != this) {
//			this->culoare = m.culoare;
//			this->greutate = m.greutate;
//			this->lungime = m.lungime;
//			if (this->producator != NULL) {
//				delete this->producator;
//			}
//			this->producator = new char[strlen(m.producator) + 1];
//			strcpy_s(this->producator, strlen(m.producator) + 1, m.producator);
//		}
//		return *this;
//	}
//
//	string getCuloare() {
//		return this->culoare;
//	}
//
//	void setCuloare(string nouaCuloare) {
//		if (nouaCuloare.length() > 2) {
//			this->culoare = nouaCuloare;
//		}
//	}
//
//	void afisare() {
//		cout << "ID:" << this->id << endl;
//		cout << "Culoare:" << (*this).culoare << endl;
//		cout << "Greutate:" << this->greutate << endl;
//		cout << "Lungime:" << this->lungime << endl << endl;
//	}
//
//	~Marker() {
//		if (this->producator != NULL) {
//			delete[]this->producator;
//		}
//	}
//
//	static int getNumarObiecte() {
//		return numarObiecte;
//	}
//
//	operator int() {
//		return this->lungime;
//	}
//
//	operator float() {
//		return this->greutate;
//	}
//
//	friend ostream& operator<<(ostream& consola, Marker m) {
//		consola << "ID:" << m.id << endl;
//		consola << "Culoare:" << m.culoare << endl;
//		consola << "Greutate:" <<m.greutate << endl;
//		consola << "Lungime:" << m.lungime << endl << endl;
//		return consola;
//	}
//
//
//
//	friend class Birou;
//	friend void functieGlobala(Marker m);
//};
//int Marker::numarObiecte = 0;
//
//
//void functieGlobala(Marker m) {
//	m.culoare = "Rosu";
//}
//
//class Birou {
//	int nrMarkere;
//	Marker* markere;
//public:
//	Birou() {
//		this->nrMarkere = 10;
//		this->markere = new Marker[this->nrMarkere];
//		for (int i = 0; i < this->nrMarkere; i++) {
//			this->markere[i].lungime = i;
//		}
//	}
//
//	Marker operator[](int index) {
//		if (index >= 0 && index < this->nrMarkere) {
//			return this->markere[index];
//		}
//	}
//
//	Birou operator=(Birou b) {
//		//de completat
//	}
//
//	int operator()() {
//		int s = 0;
//		for (int i = 0; i < this->nrMarkere; i++) {
//			s += markere[i].lungime;
//		}
//		return s;
//	}
//	int operator()(int index) {
//		if (index >= 0 && index < this->nrMarkere) {
//			return this->markere[index].lungime;
//		}
//		else {
//			return 0;
//		}
//	}
//	int operator()(int start, int finish) {
//		if (start >= 0 && finish < this->nrMarkere) {
//			int s = 0;
//			for (int i = start; i < finish; i++) {
//				s += markere[i].lungime;
//			}
//			return s;
//		}
//		else {
//			return 0;
//		}
//	}
//
//	void metoda() {
//		this->markere[0].culoare = "verde";
//	}
//
//};
//
//void main() {
//	cout << Marker::getNumarObiecte() << endl;
//
//	Marker marker1;
//	//marker1.afisare();
//	//cout << marker1.getCuloare() << endl;
//	marker1.setCuloare("Verde");
//	//cout << marker1.getCuloare() << endl;
//
//
//	Marker marker2("Rosu", 53, 10);
//	//marker2.afisare();
//
//	Marker* pMarker = new Marker();
//	delete pMarker;
//
//	Marker marker3 = marker2;
//	/*strcpy_s(marker3.producator, 4, "qwe");
//	cout << marker2.producator << endl;*/
//
//	Marker marker4(marker1);
//
//	Marker marker5;
//	marker5 = marker2;
//
//	Marker::Capac *capac = new Marker::Capac();
//
//	float valoare = 5.7;
//	int a = valoare;
//	int b = marker2;
//
//	cout << marker2<<endl;
//	
//	Birou birou;
//	cout << birou[4];
//
//	Marker marker6 = !marker2;
//
//	cout << birou()<<endl;
//	cout << birou(4)<<endl;
//	cout << birou(2,4)<<endl;
//}