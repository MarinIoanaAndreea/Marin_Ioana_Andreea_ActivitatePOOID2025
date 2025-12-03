#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Marker {
private:
    const int id;
    char* culoare;
    int dimensiune;
    string producator;
    int capacitate;
    int* nrRezerve;

public:
    Marker() : id(1) {
        this->culoare = new char[strlen("rosu") + 1];
        strcpy(this->culoare, "rosu");
        this->dimensiune = 6;
        this->producator = "Bic";
        this->capacitate = 2;
        this->nrRezerve = new int[this->capacitate];
        for (int i = 0; i < this->capacitate; i++) {
            this->nrRezerve[i] = (i == 0 ? 5 : 9);
        }
    }

    Marker(const int id, const char* culoare, int dimensiune,
        string producator, int capacitate, int* nrRezerve) : id(id) {
        this->culoare = new char[strlen(culoare) + 1];
        strcpy(this->culoare, culoare);
        this->dimensiune = dimensiune;
        this->producator = producator;
        this->capacitate = capacitate;
        this->nrRezerve = new int[this->capacitate];
        for (int i = 0; i < this->capacitate; i++) {
            this->nrRezerve[i] = nrRezerve[i];
        }
    }

    Marker(const Marker& m) : id(m.id) {
        this->culoare = new char[strlen(m.culoare) + 1];
        strcpy(this->culoare, m.culoare);
        this->dimensiune = m.dimensiune;
        this->producator = m.producator;
        this->capacitate = m.capacitate;
        this->nrRezerve = new int[m.capacitate];

        for (int i = 0; i < this->capacitate; i++) {
            this->nrRezerve[i] = m.nrRezerve[i];
        }
    }

    Marker& operator=(const Marker& m) {
        if (this != &m) {
            if (this->culoare != NULL)
                delete[] this->culoare;
            if (this->nrRezerve != NULL)
                delete[] this->nrRezerve;

            this->culoare = new char[strlen(m.culoare) + 1];
            strcpy(this->culoare, m.culoare);
            this->dimensiune = m.dimensiune;
            this->producator = m.producator;
            this->capacitate = m.capacitate;
            this->nrRezerve = new int[m.capacitate];

            for (int i = 0; i < this->capacitate; i++) {
                this->nrRezerve[i] = m.nrRezerve[i];
            }
        }
        return *this;
    }

    ~Marker() {
        if (this->culoare != NULL)
            delete[] this->culoare;
        if (this->nrRezerve != NULL)
            delete[] this->nrRezerve;
    }

    friend ostream& operator<<(ostream& out, Marker& m) {
        out << m.id << endl;
        out << m.culoare << endl;
        out << m.dimensiune << endl;
        out << m.producator << endl;
        out << m.capacitate << endl;
        for (int i = 0; i < m.capacitate; i++)
        return out;
    }

    void setCuloare(const char* culoareNoua) {
        if (culoareNoua != NULL) {
            if (this->culoare != NULL) {
                delete[] this->culoare;
            }
            this->culoare = new char[strlen(culoareNoua) + 1];
            strcpy(this->culoare, culoareNoua);
        }
        else {
            if (this->culoare != NULL)
                delete[] this->culoare;
            this->culoare = new char[strlen("rosu") + 1];
            strcpy(this->culoare, "rosu");
        }
    }

    char* getCuloare() {
        return culoare;
    }

    void setnrRezerve(int capacitate, int* nrRezerve) {
        if (this->nrRezerve != NULL) {
            delete[] this->nrRezerve;
        }
        this->capacitate = capacitate;
        this->nrRezerve = new int[capacitate];
        for (int i = 0; i < capacitate; i++) {
            this->nrRezerve[i] = nrRezerve[i];
        }
    }

    int getNrRezerve(int index) {
        if (index >= 0 && index < capacitate && nrRezerve != NULL) {
            return nrRezerve[index];
        }
        else {
            throw exception();
        }
    }

    bool operator==(Marker& m) {
        if (producator == m.producator &&
            dimensiune == m.dimensiune &&
            strcmp(m.culoare, this->culoare) == 0)
            return true;
        else
            return false;
    }

    friend int totalRezerve(int nrMarkere, Marker* marker);

    friend istream& operator>>(istream& in, Marker& m) {
        char buffer[100];
        in >> buffer;
        delete[] m.culoare;
        m.culoare = new char[strlen(buffer) + 1];
        strcpy(m.culoare, buffer);
        in >> m.dimensiune;
        in >> m.producator;
        in >> m.capacitate;

        if (m.nrRezerve != NULL)
            delete[] m.nrRezerve;
        m.nrRezerve = new int[m.capacitate];

        for (int i = 0; i < m.capacitate; i++)
            in >> m.nrRezerve[i];
        return in;
    }
};

int totalRezerve(int nrMarkere, Marker* marker) {
    float suma = 0;
    for (int i = 0; i < nrMarkere; i++) {
        for (int j = 0; j < marker[i].capacitate; j++) {
            suma += marker[i].nrRezerve[j];
        }
    }
    return (int)suma;
}

int main() {

    Marker m1;
    cout << m1 << endl;

    Marker m2(2, "Albastru", 5, "DBSN", 4, new int[4] { 3, 7, 8, 21 });
    cout << m2 << endl;

    m2.setnrRezerve(2, new int[2] { 6, 1 });
    cout << m2.getNrRezerve(0) << endl;
    cout << m2.getNrRezerve(1) << endl;

    Marker markere[2]{ m1, m2 };
    cout << totalRezerve(2, markere) << endl;

    cout << "---------------------------" << endl;
    if (m1 == m2)
        cout << "Egale" << endl;
    else
        cout << "Nu sunt egale" << endl;

    cout << "------------------------" << endl;

    m1.setCuloare(NULL);
    cout << m1.getCuloare() << endl;

    try {
        cout << m1.getNrRezerve(-5) << endl;
    }
    catch (exception e) {
        cout << e.what() << endl;
    }

    cin >> m1;

    return 0;
}