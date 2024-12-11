#include<iostream>
#include<fstream>
using namespace std;

//class Animal {
//
//	virtual void scoateSunete() = 0;
//};
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

class Marker:public InstrumentDeScris {
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
		consola << "Producator:" << m.producator << endl ;
		return consola;
	}

	friend ofstream& operator<<(ofstream& consola, Marker m) {
		consola  << m.culoare << endl;
		consola  << m.greutate << endl;
		consola  << m.lungime << endl;
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



class MarkerDublu:public Marker{
private:
	string culoare2;
	//....
protected:
public:
	void afisareCuloriDeScris() {
		cout << "Markerul scrie cu doua culori"<<endl;
		cout << "1." << this->getCuloare()<<endl;
		cout << "2." << this->culoare2 << endl;
	}

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

	//Marker* pointer;
	//pointer = new Marker("Rosu", 2, 3);

	//pointer->afisareCuloriDeScris();
	//cout << endl;

	//delete pointer;
	//pointer = new MarkerDublu("Rosu", "Albastru", 4, 5);
	//pointer->afisareCuloriDeScris();


	//Marker** vector;
	//vector = new Marker * [5];
	//vector[0] = new Marker();
	//vector[1] = new MarkerDublu("Verde");
	//vector[2] = new MarkerDublu("Galben");
	//vector[3] = new Marker("Magenta", 5, 6);
	//vector[4] = new MarkerDublu("Cyan");

	//for (int i = 0; i < 5; i++) {
	//	vector[i]->afisareCuloriDeScris();
	//	cout << endl << endl;
	//}

	

	//MarkerDublu md;
	//cout<<md.Marker::getCuloare();

	//InstrumentDeScris* ids = new Marker("Rosu",45,15);

	Marker m("Verde", 45, 15);
	try {
		
		m.setCuloare("Verde");
		m.setGreutate(-56);
		m.setLungime(-20);
		cout << m;

	}
	catch (int codEroare) {
		cout << "Avem exceptia cu codul:" << codEroare << endl;
	}
	catch (exceptii::ParametruIncorect pi) {
		cout <<"PI:"<< pi.getMesajExceptie() << endl;
	}
	catch (string exceptie) {
		cout << "Exceptie!!!! ANTENTIE!!! "<<exceptie << endl;
	}
	catch (exception ex) {
		cout << ex.what() << endl;
	}
	catch (exception* ert) {
		cout << ert->what() << endl;
	}
	catch (...) {
		cout << "A fost captata o exceptie necunoscuta"<<endl;
	}

	//delete ids;






}