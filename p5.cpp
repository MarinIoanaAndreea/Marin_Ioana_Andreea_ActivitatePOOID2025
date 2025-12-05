#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Ziar {
private:
    const int idZiar;
    static int nrZiare;

    char* nume;
    string redactie;
    int numarPagini;
    double pret;
    bool esteNational;
    long tiraj;

public:

    void setPret(double pret) {
        if (pret >= 0) {
            this->pret = pret;
        }
    }

    void setNume(const char* nume) {
        if (nume != nullptr && strlen(nume) > 0) {
            if (this->nume != nullptr) {
                delete[] this->nume;
            }
            this->nume = new char[strlen(nume) + 1];
            strcpy_s(this->nume, strlen(nume) + 1, nume);
        }
    }

    void setRedactie(string redactie) {
        if (redactie.length() > 0) {
            this->redactie = redactie;
        }
    }

    void setNumarPagini(int numarPagini) {
        if (numarPagini >= 0) {
            this->numarPagini = numarPagini;
        }
    }

    void setTiraj(long tiraj) {
        if (tiraj >= 0) {
            this->tiraj = tiraj;
        }
    }

    void setEsteNational(bool esteNational) {
        this->esteNational = esteNational;
    }

    double getPret() {
        return this->pret;
    }

    char* getNume() {
        return this->nume;
    }

    string getRedactie() {
        return this->redactie;
    }

    int getNumarPagini() {
        return this->numarPagini;
    }

    long getTiraj() {
        return this->tiraj;
    }

    bool getEsteNational() {
        return this->esteNational;
    }

    int getIdZiar() {
        return this->idZiar;
    }

    static int getNrZiare() {
        return nrZiare;
    }

    static void setNrZiare(int nr) {
        nrZiare = nr;
    }

    Ziar() : idZiar(++nrZiare) {
        this->nume = nullptr;
        this->redactie = "Anonima";
        this->numarPagini = 0;
        this->pret = 0;
        this->esteNational = false;
        this->tiraj = 0;
    }

    Ziar(const char* nume, string redactie, int numarPagini,double pret, bool esteNational, long tiraj)
        : idZiar(++nrZiare)
    {
        if (nume != nullptr) {
            this->nume = new char[strlen(nume) + 1];
            strcpy_s(this->nume, strlen(nume) + 1, nume);
        }
        else {
            this->nume = nullptr;
        }

        this->redactie = redactie;
        this->numarPagini = numarPagini;
        this->pret = pret;
        this->esteNational = esteNational;
        this->tiraj = tiraj;
    }

    Ziar(const Ziar& z) : idZiar(++nrZiare) {
        this->redactie = z.redactie;
        this->numarPagini = z.numarPagini;
        this->pret = z.pret;
        this->esteNational = z.esteNational;
        this->tiraj = z.tiraj;

        if (z.nume != nullptr) {
            this->nume = new char[strlen(z.nume) + 1];
            strcpy_s(this->nume, strlen(z.nume) + 1, z.nume);
        }
        else {
            this->nume = nullptr;
        }
    }

    void operator=(const Ziar& z) {
        this->redactie = z.redactie;
        this->numarPagini = z.numarPagini;
        this->pret = z.pret;
        this->esteNational = z.esteNational;
        this->tiraj = z.tiraj;

        if (this->nume != nullptr) {
            delete[] this->nume;
            this->nume = nullptr;
        }

        if (z.nume != nullptr) {
            this->nume = new char[strlen(z.nume) + 1];
            strcpy_s(this->nume, strlen(z.nume) + 1, z.nume);
        }
        else {
            this->nume = nullptr;
        }
    }

    bool operator<(const Ziar& z) {
        return this->pret < z.pret;
    }

    bool operator!() {
        return this->esteNational == false;
    }

    void afisareZiar() {
        cout << endl << this->getIdZiar() << ". Ziarul ";
        if (this->getNume() != nullptr) {
            cout << this->getNume();
        }
        else {
            cout << "Neidentificat";
        }
        cout << ", redactie: " << this->getRedactie()
            << ", pagini: " << this->getNumarPagini()
            << ", pret: " << this->getPret()
            << " lei, tiraj: " << this->getTiraj()
            << ", tip: " << (this->getEsteNational() ? "National" : "Local");
    }

    friend ostream& operator<<(ostream& out, Ziar& z) {
        out << "ID: " << z.idZiar << endl;
        out << "Nume: ";
        if (z.nume != nullptr) {
            out << z.nume << endl;
        }
        else {
            out << "Neidentificat" << endl;
        }
        out << "Redactie: " << z.redactie << endl;
        out << "Pagini: " << z.numarPagini << endl;
        out << "Pret: " << z.pret << " lei" << endl;
        out << "Tiraj: " << z.tiraj << endl;
        out << "Tip: " << (z.esteNational ? "National" : "Local") << endl;
        return out;
    }

    ~Ziar() {
        if (this->nume != nullptr) {
            delete[] this->nume;
        }
    }
};

int Ziar::nrZiare = 0;

int main() {
    Ziar z1("Adevarul", "Mediafax", 32, 7.5, true, 45000);
    cout << z1 << endl;

    Ziar z2;
    z2.setNume("Libertatea");
    z2.setRedactie("Ringier");
    z2.setNumarPagini(24);
    z2.setPret(6.2);
    z2.setEsteNational(false);
    z2.setTiraj(30000);
    cout << z2 << endl;

    cout << endl << "Am initializat " << Ziar::getNrZiare() << " obiect/e Ziar!" << endl;

    return 0;
}