#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Autobuz {
private:
	static int nrAutobuze;
	const int idAutobuz;
	int capacitate;
	int nrPersoaneImbarcate;
	char* producator;

public:
	//Constructori fara parametrii
	Autobuz() :idAutobuz(++nrAutobuze) {
		this->capacitate = 100;
		this->nrPersoaneImbarcate = 10;
		this->producator = new char[strlen("Bus") + 1];
		strcpy(this->producator, "Bus");
	}

			//Constructori cu parametrii 
	Autobuz(int capacitate, int nrPersoaneImbarcate, const char* producator) :idAutobuz(++nrAutobuze) {
		this->capacitate = capacitate;
		this->nrPersoaneImbarcate = nrPersoaneImbarcate;
		this->producator = new char[strlen(producator) + 1];
		strcpy(this->producator, producator);
	}

	// Constructor de copiere
	Autobuz(const Autobuz& b) :idAutobuz(++nrAutobuze) {
		this->capacitate = b.capacitate;
		this->nrPersoaneImbarcate = b.nrPersoaneImbarcate;
		this->producator = new char[strlen(b.producator) + 1];
		strcpy(this->producator, b.producator);
	}

	//Destructor
	~Autobuz() {
		if (producator != NULL)
			delete[] producator;
	
	}
	// Getter
	int getcapacitate() {
		return capacitate;
	}

	int getnrPersoaneImbarcate() {
		return nrPersoaneImbarcate;
	}

	// Setter
	void setcapacitate(int capacitate) {
		this->capacitate = capacitate;
	}

	void setnrPersoaneImbarcate(int nrPersImb) {
		this->nrPersoaneImbarcate = nrPersImb;
	}
	char* getProducator() {
		return producator;
	}

	Autobuz& operator= (const Autobuz& b) {
		if (this != &b) {
			if (producator != NULL)
				delete[] producator;
			this->capacitate = b.capacitate;
			this->nrPersoaneImbarcate = b.nrPersoaneImbarcate;
			this->producator = new char[strlen(b.producator) + 1];
			strcpy(this->producator, b.producator);

			return*this;
		}

	}

	friend ostream& operator<<(ostream& out, Autobuz& a) {
		out << a.idAutobuz << "; " << a.nrAutobuze << "; " << a.capacitate << "; " << a.nrPersoaneImbarcate << "; " << a.producator<<"; " << endl;
		return out;
	}

	int getNrLocuriLibere() {
		return capacitate - nrPersoaneImbarcate;
	}

	bool operator>(Autobuz& a) {
		return this->capacitate > a.capacitate;
	}
	explicit operator int() {
		return nrPersoaneImbarcate;
	}

};

int Autobuz::nrAutobuze = 4;

void main() {

	Autobuz auto1;
	cout << auto1.getcapacitate()<<endl;
	cout << auto1.getnrPersoaneImbarcate()<<endl;
	cout << auto1.getProducator()<<endl;


	Autobuz auto2(88, 44, "Audi");
	Autobuz auto3(34, 20, "ajhsg");
	cout << auto2.getcapacitate() << endl;
	cout << auto2.getnrPersoaneImbarcate() << endl;
	cout << auto2.getProducator() << endl;
	cout << auto3.getcapacitate() << endl;
	cout << auto3.getnrPersoaneImbarcate() << endl;
	cout << auto3.getProducator() << endl;

	Autobuz auto4 = auto2;
	cout << auto4.getcapacitate() << endl;
	cout << auto4.getnrPersoaneImbarcate() << endl;
	cout << auto4.getProducator() << endl;

	cout << auto1 << auto2 << endl;
	cout << auto1.getnrPersoaneImbarcate() << endl;

	if (auto1 > auto2) {
		cout << "adevarat" << endl;
	}
	else {
		cout << "fals" << endl;
	}

	cout << auto2.operator int() << endl;
}