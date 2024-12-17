#include<iostream>
#include<fstream>
using namespace std;

namespace exceptii {
	class ParametruIncorect :public exception {
	private:
		string mesaj;
	public:
		ParametruIncorect(string mesaj) {
			this->mesaj = mesaj;
		}
		string getMesajExceptie() {
			return mesaj;
		}
	};
}

class InstrumentDeScris {
	string culoare;
public:
	InstrumentDeScris() {
		this->culoare = "Albastru";
	}
	virtual ~InstrumentDeScris() {

	}
	virtual void afisare() = 0;
	virtual void afisare2() = 0;
};

class Marker :public InstrumentDeScris {
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

	Marker operator+(const Marker& m)const {
		Marker aux = *this;
		aux.lungime = this->lungime + m.lungime;
		return aux;
	}
	void afisare2() {}
	virtual void afisareCuloriDeScris() {
		cout << "Culoare 1:" << this->culoare;
	}

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
			if (m.producator) {
				this->producator = new char[strlen(m.producator) + 1];
				strcpy_s(this->producator, strlen(m.producator) + 1, m.producator);
			}
			else {
				this->producator = NULL;
			}
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
		else {
			throw exception("Culoarea nu are lungimea necesara");
		}
	}

	void setGreutate(float greutate) {
		if (greutate > 0) {
			this->greutate = greutate;
		}
		else {
			throw exceptii::ParametruIncorect("Greutatea este prea mica");
		}
	}

	void setLungime(int lungime) {
		if (lungime > 0) {
			this->lungime = lungime;
		}
		else {
			throw exceptii::ParametruIncorect("Lungimea este prea mica");
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

	explicit operator int() {
		return this->lungime;
	}

	explicit operator float() {
		return this->greutate;
	}

	friend ostream& operator<<(ostream& consola, Marker m) {
		consola << "ID:" << m.id << endl;
		consola << "Culoare:" << m.culoare << endl;
		consola << "Greutate:" << m.greutate << endl;
		consola << "Lungime:" << m.lungime << endl;
		if (m.producator) {
			consola << "Producator:" << m.producator << endl;
		}
		else {
			consola << "Nu are producator" << endl;
		}
		return consola;
	}

	friend ofstream& operator<<(ofstream& consola, Marker m) {
		consola << m.culoare << endl;
		consola << m.greutate << endl;
		consola << m.lungime << endl;
		consola << m.producator << endl;
		return consola;
	}

	friend ifstream& operator>>(ifstream& f, Marker& m) {
		f >> m.culoare;
		f >> m.greutate;
		f >> m.lungime;
		if (m.producator) {
			delete[]m.producator;
		}
		char buffer[50];
		f.getline(buffer, 2);
		f.getline(buffer, 50);
		m.producator = new char[strlen(buffer) + 1];
		strcpy_s(m.producator, strlen(buffer) + 1, buffer);
		return f;
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



class MarkerDublu :public Marker {
private:
	string culoare2;
	//....
protected:
public:
	void afisareCuloriDeScris() {
		cout << "Markerul scrie cu doua culori" << endl;
		cout << "1." << this->getCuloare() << endl;
		cout << "2." << this->culoare2 << endl;
	}

	MarkerDublu() :Marker("Rosu", 90, 20) {
		this->culoare2 = "Magenta";
	}
	MarkerDublu(string culoare1, string culoare2, int lungime, float greutate)
		:Marker(culoare1, greutate, lungime) {
		this->culoare2 = culoare2;
	}
	MarkerDublu(string culoare2) :Marker("Rosu", 150, 25) {
		this->culoare2 = culoare2;
	}
	MarkerDublu(const MarkerDublu& md) :Marker(md) {
		this->culoare2 = md.culoare2;
	}

	MarkerDublu(const Marker& m) :Marker(m) {
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
		o << "Culoare 2:" << md.culoare2 << endl;
		return o;
	}


};



//int suma(int a, int b) {
//	return a + b;
//}
//
//float suma(float a, float b) {
//	return a + b;
//}

template <class T>
T suma(T a, T b) {
	return a + b;
}

template <typename T1, class T2>
T1 adunare(T2 a, T2 b) {
	return (T1)(a + b);
}

template<class T>
class Colectionar {
	string nume;
	int nrElemente;
	T* elemente;
public:
	Colectionar() {
		this->nume = "N/A";
		this->nrElemente = 0;
		this->elemente = NULL;
	}
	Colectionar(string nume, int nr, T* elemente) {
		this->nume = nume;
		this->nrElemente = nr;
		this->elemente = new T[nr];
		for (int i = 0; i < nr; i++) {
			this->elemente[i] = elemente[i];
		}
	}

	Colectionar(const Colectionar& c) {
		this->nume = c.nume;
		this->nrElemente = c.nrElemente;
		this->elemente = new T[c.nrElemente];
		for (int i = 0; i < c.nrElemente; i++) {
			this->elemente[i] = c.elemente[i];
		}
	}
	Colectionar operator=(const Colectionar& c) {
		if (&c != this) {
			this->nume = c.nume;
			this->nrElemente = c.nrElemente;
			if (this->elemente) {
				delete[]this->elemente;
			}
			this->elemente = new T[c.nrElemente];
			for (int i = 0; i < c.nrElemente; i++) {
				this->elemente[i] = c.elemente[i];
			}
		}
		return *this;
	}

	~Colectionar() {
		if (this->elemente) {
			delete[]this->elemente;
		}
	}

	Colectionar operator+=(T element) {
		T* aux = new T[this->nrElemente + 1];
		for (int i = 0; i < this->nrElemente; i++) {
			aux[i] = this->elemente[i];
		}
		if (this->elemente) {
			delete[]this->elemente;
		}
		aux[this->nrElemente] = element;
		this->nrElemente++;
		this->elemente = aux;
		return *this;
	}

	friend ostream& operator<<(ostream& o, Colectionar<T> c) {
		o << "Nume colectionar:" << c.nume<<endl;
		o << "Are in colectie " << c.nrElemente << " elemente:" << endl;
		for (int i = 0; i < c.nrElemente; i++) {
			o << c.elemente[i]<<endl;
		}
		return o;
	}

};


//relatia de has-a
template<class T>
class AsociatieColectionari {
	int nrMembri;
	Colectionar<T>* membri;
};

template<class T>
//relatia is-a
class ColectionarCuExpozitii : public Colectionar<T> {
	int nrExpozitii;
};

void main() {

	//int a = 6;
	//int b = 7;
	//cout << "Suma:" << suma(a, b)<<endl;

	//float x = 7.5;
	//float y = 9.7;

	//cout << "SUma:" << suma(x, y);

	//Marker m1("Rosu", 20, 10);
	//Marker m2("Albastru", 30, 15);

	//cout << "Suma:" << suma(m1, m2) << endl;

	//cout << "Adunare:" << adunare<int, float>(x, y);


	Colectionar<int> colectieDeIntregi;
	colectieDeIntregi += 5;
	colectieDeIntregi += 20;
	colectieDeIntregi += 7;
	cout << colectieDeIntregi<<endl;


	Marker m1;
	Marker m2("Rosu", 20, 13);
	Marker m3("Albastru", 40, 15);

	Colectionar<Marker> colectionarMarkere;

	colectionarMarkere += m1;
	colectionarMarkere += m2;
	colectionarMarkere += m3;

	cout << colectionarMarkere;

	
}