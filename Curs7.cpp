#include<iostream>
using namespace std;

class Marker {
private:
	static int numarObiecte;
	const int id;
	string culoare;
	float greutate;
	int lungime;
	char* producator;
public:

	Marker operator++() {
		this->lungime = this->lungime + 1;
		return *this;
	}
	Marker operator++(int) {
		Marker aux = *this;
		this->lungime = this->lungime + 1;
		return aux;
	}

	class Capac {
	private:
		int lungime;
	public:
		Capac() {
			this->lungime = 3;
		}
		Capac(int lungime) {
			this->lungime = lungime;
		}
	};

	Marker operator!() {
		Marker temp = *this;
		temp.lungime = 0;
		return temp;
	}

	Marker() :id(++numarObiecte), greutate(45) {
		this->culoare = "Albastru";
		//this->greutate = 45;
		this->lungime = 12;
		this->producator = NULL;
	}

	Marker(string culoare, float greutate, int lungime) : id(++numarObiecte) {
		this->culoare = culoare;
		this->greutate = greutate;
		this->lungime = lungime;
		this->producator = new char[strlen("B4U") + 1];
		strcpy_s(this->producator, strlen("B4U") + 1, "B4U");
	}

	Marker(const Marker& m) : id(++numarObiecte) {
		this->culoare = m.culoare;
		this->greutate = m.greutate;
		this->lungime = m.lungime;
		if (m.producator != NULL) {
			this->producator = new char[strlen(m.producator) + 1];
			strcpy_s(this->producator, strlen(m.producator) + 1, m.producator);
		}
		else {
			this->producator = NULL;
		}
	}

	Marker operator=(const Marker& m) {
		if (&m != this) {
			this->culoare = m.culoare;
			this->greutate = m.greutate;
			this->lungime = m.lungime;
			if (this->producator != NULL) {
				delete this->producator;
			}
			this->producator = new char[strlen(m.producator) + 1];
			strcpy_s(this->producator, strlen(m.producator) + 1, m.producator);
		}
		return *this;
	}

	string getCuloare() {
		return this->culoare;
	}

	void setCuloare(string nouaCuloare) {
		if (nouaCuloare.length() > 2) {
			this->culoare = nouaCuloare;
		}
	}

	void afisare() {
		cout << "ID:" << this->id << endl;
		cout << "Culoare:" << (*this).culoare << endl;
		cout << "Greutate:" << this->greutate << endl;
		cout << "Lungime:" << this->lungime << endl << endl;
	}

	~Marker() {
		if (this->producator != NULL) {
			delete[]this->producator;
		}
	}

	static int getNumarObiecte() {
		return numarObiecte;
	}

	operator int() {
		return this->lungime;
	}

	operator float() {
		return this->greutate;
	}

	friend ostream& operator<<(ostream& consola, Marker m) {
		consola << "ID:" << m.id << endl;
		consola << "Culoare:" << m.culoare << endl;
		consola << "Greutate:" << m.greutate << endl;
		consola << "Lungime:" << m.lungime << endl << endl;
		return consola;
	}



	friend class Birou;
	friend void functieGlobala(Marker m);
};
int Marker::numarObiecte = 0;


void functieGlobala(Marker m) {
	m.culoare = "Rosu";
}

class Birou {
	int nrMarkere;
	Marker* markere;
public:
	Birou() {
		this->nrMarkere = 10;
		this->markere = new Marker[this->nrMarkere];
		for (int i = 0; i < this->nrMarkere; i++) {
			this->markere[i].lungime = i;
		}
	}

	Marker operator[](int index) {
		if (index >= 0 && index < this->nrMarkere) {
			return this->markere[index];
		}
	}

	Birou operator=(Birou b) {
		//de completat
	}

	int operator()() {
		int s = 0;
		for (int i = 0; i < this->nrMarkere; i++) {
			s += markere[i].lungime;
		}
		return s;
	}
	int operator()(int index) {
		if (index >= 0 && index < this->nrMarkere) {
			return this->markere[index].lungime;
		}
		else {
			return 0;
		}
	}
	int operator()(int start, int finish) {
		if (start >= 0 && finish < this->nrMarkere) {
			int s = 0;
			for (int i = start; i < finish; i++) {
				s += markere[i].lungime;
			}
			return s;
		}
		else {
			return 0;
		}
	}

	void metoda() {
		this->markere[0].culoare = "verde";
	}

};

void f(int a) {

}

void f(float b) {

}

void main() {
	Marker marker1("Rosu", 53, 10);
	Marker marker2("Albastru", 45, 12);
	//op+
	//marker1 + marker2  ;
	//marker1 + 6;
	//6 + marker1;


	marker2=++marker1;
	marker2=marker1++;


	//int a = 5;
	//int b = 7;
	//b = ++a;
	////a=?, 5, 6   ---   b=?, 6, 7
	////a=6 --- b=6

	//int a = 5;
	//int b = 7;
	//b = a++;
	////a=?, 5,5 , 6  ---   b=?, 6, 8, 5
	////a=6, b=5

	//float x = 7.8;
	//int y = (int)x;
	//char z = 0;
	//f(z);

	int lungime = 3;
	Marker* pointer = new Marker("Rosu", 20, 11);
	Marker* vector = new Marker[lungime];

	vector[0] = *pointer;
	vector[1] = marker1;

	cout << *pointer<<endl<<endl;

	for (int i = 0; i < lungime; i++) {
		cout << vector[i]<<endl;
	}

	Marker** vectorPointeri = new Marker * [lungime+1];
	vectorPointeri[0] = pointer;
	vectorPointeri[1] = &marker1;
	vectorPointeri[2] = &vector[1];//vector+1
	vectorPointeri[3] = new Marker("Verde", 56, 9);

	vector[2] = *vectorPointeri[1];


	delete pointer;
	delete[] vector;
	
	//for (int i = 0; i < lungime; i++) {
	//	delete vectorPointeri[i];
	//}
	delete vectorPointeri[3];

	delete[]vectorPointeri;

	Marker** matrice;
	matrice = new Marker*[lungime];
	for (int i = 0; i < lungime; i++) {
		matrice[i] = new Marker[lungime];
	}

	for (int i = 0; i < lungime; i++) {
		delete[]matrice[i];
	}
	delete[]matrice;


	Marker::getNumarObiecte();
	marker1.getNumarObiecte();
	functieGlobala(marker1);
}