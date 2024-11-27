//#include<iostream>
//#include<fstream>
//
//using namespace std;
//
//class Clasa{
//private:
//	int nrElemente;
//	float* elemente;
//
//};
//
//void main() {
//	//int valoare = 40;
//	//float real = 67.4;
//	//char text[20] = "text salvat";
//	//fstream f("fileBin.txt", ios::out | ios::binary);
//	//
//
//	//f.write((char*)&valoare, sizeof(int));
//	//f.write((char*)&real, sizeof(float));
//	//int lungime = strlen(text) + 1;
//	//f.write((char*)&lungime, sizeof(int));
//	//f.write((char*)text, sizeof(char) * lungime);
//	//f.close();
//
//
//
//	int valCitita;
//	float realCitit;
//	char* textCitit;
//	int lungime;
//	fstream g("fileBin.txt", ios::binary | ios::in);
//	g.read((char*)&valCitita, sizeof(int));
//	g.read((char*)&realCitit, sizeof(float));
//	g.read((char*)&lungime, sizeof(int));
//	textCitit = new char[lungime];
//	g.read((char*)textCitit, lungime);
//
//	g.close();
//	cout << valCitita <<" "<< textCitit<<" ";
//	cout << realCitit <<endl;
//
//	delete[]textCitit;
//}