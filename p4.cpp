#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;


class CastiAudio {
private:
    const int idCasti;
    char* marca;
    string culoare;
    float pret;
    bool suntWireless;

public:
    CastiAudio() : idCasti(0) {
        this->marca = new char[strlen("Necunoscuta") + 1];
        strcpy_s(this->marca, strlen("Necunoscuta") + 1, "Necunoscuta");

        this->culoare = "Necunoscuta";
        this->pret = 0.0;
        this->suntWireless = false;
    }

    CastiAudio(int idCasti, const char* marca, string culoare,float pret, bool suntWireless): idCasti(idCasti)
    {
        this->marca = new char[strlen(marca) + 1];
        strcpy_s(this->marca, strlen(marca) + 1, marca);

        this->culoare = culoare;
        this->pret = pret;
        this->suntWireless = suntWireless;
    }

    CastiAudio(const CastiAudio& c) : idCasti(c.idCasti) {
        this->marca = new char[strlen(c.marca) + 1];
        strcpy_s(this->marca, strlen(c.marca) + 1, c.marca);

        this->culoare = c.culoare;
        this->pret = c.pret;
        this->suntWireless = c.suntWireless;
    }

    ~CastiAudio() {
        if (this->marca != nullptr) {
            delete[] this->marca;
        }
    }

    void operator=(const CastiAudio& c) {
        this->culoare = c.culoare;
        this->pret = c.pret;
        this->suntWireless = c.suntWireless;

        if (this->marca != nullptr) {
            delete[] this->marca;
            this->marca = nullptr;
        }

        if (c.marca != nullptr) {
            this->marca = new char[strlen(c.marca) + 1];
            strcpy_s(this->marca, strlen(c.marca) + 1, c.marca);
        }
        else {
            this->marca = nullptr;
        }
    }

    float getPret() {
        return this->pret;
    }

    char* getMarca() {
        return this->marca;
    }

    string getCuloare() {
        return this->culoare;
    }

    bool getSuntWireless() {
        return this->suntWireless;
    }

    int getIdCasti() {
        return this->idCasti;
    }

    void setPret(float pret) {
        if (pret >= 0) {
            this->pret = pret;
        }
    }

    void setMarca(const char* marcaNoua) {
        if (strlen(marcaNoua) > 0) {
            if (this->marca != nullptr) {
                delete[] this->marca;
            }
            this->marca = new char[strlen(marcaNoua) + 1];
            strcpy_s(this->marca, strlen(marcaNoua) + 1, marcaNoua);
        }
    }

    void setCuloare(string culoareNoua) {
        if (culoareNoua.length() > 0) {
            this->culoare = culoareNoua;
        }
    }

    void setSuntWireless(bool wireless) {
        this->suntWireless = wireless;
    }

    bool operator!() {
        return !suntWireless;
    }

    bool operator<(CastiAudio& c) {
        return this->pret < c.pret;
    }

    void afisareCasti() {
        cout << endl << "Casti " << this->idCasti << ": "
            << (this->marca != nullptr ? this->marca : "Necunoscute")
            << ", culoare " << this->culoare
            << ", pret " << this->pret
            << " lei, tip " << (this->suntWireless ? "wireless" : "cu fir");
    }

    friend ostream& operator<<(ostream& out, CastiAudio& c) {
        out << "ID casti: " << c.idCasti << endl;
        out << "Marca: " << c.marca << endl;
        out << "Culoare: " << c.culoare << endl;
        out << "Pret: " << c.pret << " lei" << endl;
        out << "Tip: " << (c.suntWireless ? "Wireless" : "Cu fir") << endl;
        return out;
    }
};

void main() {
    CastiAudio c1;
    cout << "Casti 1 (default):" << endl;
    cout << c1 << endl;

    CastiAudio c2(101, "Sony", "Negru", 299.99, true);
    cout << "Casti 2:" << endl;
    cout << c2 << endl;

    CastiAudio c3(102, "JBL", "Alb", 199.99, false);
    cout << "Casti 3:" << endl;
    cout << c3 << endl;

    CastiAudio c4 = c2; 
    cout << "Casti 4" << endl;
    cout << c4 << endl;

    if (c3 < c2)
        cout << "Casti 3 sunt mai ieftine decat Casti 2." << endl;
    else
        cout << "Casti 2 sunt mai ieftine sau egale ca pret cu Casti 3." << endl;

    if (!c2)
        cout << "Casti 2 sunt CU FIR." << endl;
    else
        cout << "Casti 2 sunt WIRELESS." << endl;

    cout << endl;
    c1.afisareCasti();
    c2.afisareCasti();
    c3.afisareCasti();
}
