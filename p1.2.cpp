#define _CRT_SECURE_NO_WARNINGS
#include<iostream>


using namespace std;

class FurnizorEnergie {
private:
	char* numeClient;
	int luna;
	int* consumLunarEfectiv;
	int consumLunarEstimat;
	const int nrContract;
	int durataContract;
	float pretKWh;
public:
	FurnizorEnergie() : nrContract(1) {
		this->numeClient = new char[strlen("Andrei") + 1];
		strcpy(this->numeClient, "Andrei");
		this->consumLunarEstimat = 15;
		this->luna = 2;
		this->consumLunarEfectiv = new int[2];
		consumLunarEfectiv[0] = 20;
		consumLunarEfectiv[1] = 13;
		this->durataContract = 6;
		this->pretKWh = 4.5;
	}
	FurnizorEnergie(const int nrContract, const char* numeClient, int luna, int* consumLunarEfectiv, int consumLunarEstimat, int durataContract, float pretKWh) : nrContract(nrContract) {
		this->numeClient = new char[strlen(numeClient) + 1];
		strcpy(this->numeClient, numeClient);
		this->luna = luna;
		this->consumLunarEfectiv = new int[this->luna];
		for (int i = 0; i < this->luna; i++) {
			this->consumLunarEfectiv[i] = consumLunarEfectiv[i];
		}
		this->consumLunarEstimat = consumLunarEstimat;
		this->durataContract = durataContract;
		this->pretKWh = pretKWh;
	}
	FurnizorEnergie(const FurnizorEnergie& e) : nrContract(e.nrContract) {
		this->numeClient = new char[strlen(e.numeClient) + 1];
		strcpy(this->numeClient, e.numeClient);
		this->luna = e.luna;
		this->consumLunarEfectiv = new int[e.luna];
		for (int i = 0; i < e.luna; i++) {
			this->consumLunarEfectiv[i] = e.consumLunarEfectiv[i];
		}
		this->consumLunarEstimat = e.consumLunarEstimat;
		this->durataContract = e.durataContract;
		this->pretKWh = e.pretKWh;
	}
	FurnizorEnergie& operator=(const FurnizorEnergie& e) {
		if (this->numeClient != NULL) {
			delete[] this->numeClient;
		}
		if (this->consumLunarEfectiv != NULL) {
			delete[] this->consumLunarEfectiv;
		}
		this->numeClient = new char[strlen(e.numeClient) + 1];
		strcpy(this->numeClient, e.numeClient);
		this->luna = e.luna;
		this->consumLunarEfectiv = new int[e.luna];
		for (int i = 0; i < e.luna; i++) {
			this->consumLunarEfectiv[i] = e.consumLunarEfectiv[i];
		}
		this->consumLunarEstimat = e.consumLunarEstimat;
		this->durataContract = e.durataContract;
		this->pretKWh = e.pretKWh;
		return *this;
	}
	~FurnizorEnergie() {
		if (this->numeClient != NULL) {
			delete[] this->numeClient;
		}
	}
	void setnumeClientNou(const char* newName) {
		if (newName != NULL) {
			if (this->numeClient != NULL) {
				delete[] numeClient;
				this->numeClient = new char[strlen(newName) + 1];
				strcpy(this->numeClient, newName);
			}
		}
		else {
			delete[]numeClient;
			this->numeClient = new char[strlen("Andrei") + 1];
			strcpy(this->numeClient, "Andrei");
		}
	}
	char* getnumeClient() {
		return numeClient;
	}
	friend ostream& operator<<(ostream& out, FurnizorEnergie& e) {
		out << e.nrContract << endl;
		out << e.numeClient << endl;
		out << e.luna << endl;
		for (int i = 0; i < e.luna; i++) {
			out << e.consumLunarEfectiv[i] << endl;
		};
		out << e.consumLunarEstimat << endl;
		out << e.durataContract << endl;
		out << e.pretKWh << endl;
		return out;
	}
	void operator()(int pozitie, int newValue) {
		if (pozitie >= 0 && pozitie < this->luna) {
			this->consumLunarEfectiv[pozitie] = newValue;
		}
		else {
			cout << "Index invalid!" << endl;
		}
	}
	operator double() {
		double sumaDiferente = 0;
		for (int i = 0; i < luna; i++) {
			sumaDiferente += consumLunarEfectiv[i] - consumLunarEstimat;
		}
		return sumaDiferente;
	}
	double totalDiferente() {
		int sumaDiferente = 0;
		for (int i = 0; i < luna; i++) {
			sumaDiferente += consumLunarEfectiv[i] - consumLunarEstimat;
		}
		return (double)sumaDiferente;//implicit
	}
	int getTotalConsumEfectiv() {
		int total = 0;
		for (int i = 0; i < luna; i++) {
			total += consumLunarEfectiv[i];
		}
		return total;
	}
};
int main() {

	FurnizorEnergie f1;
	cout << f1 << endl;

	int consum2[3] = { 36, 7, 21 };
	FurnizorEnergie f2(2, "Vlad", 3, consum2, 20, 6, 5.3f);
	cout << f2 << endl;

	FurnizorEnergie f3(f1);
	cout << f3 << endl;

	f2.setnumeClientNou(NULL);
	cout << f2.getnumeClient() << endl;

	cout << "---------------------------" << endl;

	f2.operator()(1, 54);
	cout << f2;

	cout << "------" << endl;
	cout << f2.totalDiferente() << endl;
	cout << (double)f2 << endl;



}

