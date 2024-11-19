#include<iostream>
using namespace std;

class Marker {
private:
	static int numarObiecte;
	const int id;
protected:
	string culoare;
private:
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
		consola << "Lungime:" << m.lungime << endl ;
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


class MarkerDublu:public Marker{
private:
	string culoare2;
	//....
protected:
public:
	MarkerDublu() :Marker("Rosu",90,20) {
		this->culoare2 = "Magenta";
	}
	MarkerDublu(string culoare1, string culoare2, int lungime, float greutate)
				:Marker(culoare1,greutate,lungime) {
		this->culoare2 = culoare2;
	}
	MarkerDublu(string culoare2) :Marker("Rosu", 150, 25) {
		this->culoare2 = culoare2;
	}
	MarkerDublu(const MarkerDublu& md):Marker(md) {
		this->culoare2 = md.culoare2;
	}

	MarkerDublu(const Marker& m):Marker(m) {
		this->culoare2 = "Cyan";
	}

	~MarkerDublu() {
		//nu avem ce dezlaoca deoarece nu avem campuri alocate dinamic
	}

	MarkerDublu operator=(const MarkerDublu& md) {
		if (&md != this) {
			(Marker)*this = (Marker)md;
		}
		return *this;
	}
	string getCuloare() {
		return this->culoare;
	}
	friend ostream& operator<<(ostream& o, const MarkerDublu& md) {
		o << (Marker)md;
		o <<"Culoare 2:" << md.culoare2 << endl;
		return o;
	}
};

void main() {

	MarkerDublu md;
	md.setCuloare("Verde");
	//cout<<md.getCuloare()<<endl;
	//cout << md;

	Marker m;
	m.setCuloare("verde");
	//cout << m.getCuloare()<<endl;

	MarkerDublu md2("Gri", "Bej", 19, 70);
	cout << md2;

	MarkerDublu md3("Galben");
	MarkerDublu md4("Mov");


}