#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

// PROIECT PARTEA 1 - Marin Andreea Ioana
// DOMENIU: Magazin Instrumente Audio (M I A)
// Clase: Microfon, Instrument, Amplificator

class Microfon {
public:
    const int idMicrofon;     
    static int nextId;        

    char* model;              
    string tip;               
    float pret;
    bool areCablu;


    Microfon() : idMicrofon(++nextId) {
        model = new char[strlen("Necunoscut") + 1];
        strcpy(model, "Necunoscut");

        tip = "Necunoscut";
        pret = 0;
        areCablu = false;
    }


    Microfon(const char* model) : idMicrofon(++nextId) {
        if (model != nullptr) {
            this->model = new char[strlen(model) + 1];
            strcpy(this->model, model);
        }
        else {
            this->model = new char[strlen("Necunoscut") + 1];
            strcpy(this->model, "Necunoscut");
        }

        tip = "Necunoscut";
        pret = 0;
        areCablu = false;
    }

    
    Microfon(const char* model, string tip, float pret, bool areCablu)
        : idMicrofon(++nextId)
    {
        if (model != nullptr) {
            this->model = new char[strlen(model) + 1];
            strcpy(this->model, model);
        }
        else {
            this->model = new char[strlen("Necunoscut") + 1];
            strcpy(this->model, "Necunoscut");
        }

        this->tip = tip;
        this->pret = pret;
        this->areCablu = areCablu;
    }

    
    static float calculeazaPretCuTVA(float pret) {
        return pret * 1.19; 
    }

    void afisare() const {
        cout << "Microfon ID: " << idMicrofon
            << " | Model: " << (model ? model : "NULL")
            << " | Tip: " << tip
            << " | Pret: " << pret
            << " | Cablu: " << (areCablu ? "DA" : "NU") << endl;
    }

    ~Microfon() {
        if (model != nullptr) delete[] model;
    }
};
int Microfon::nextId = 0;




class Instrument {
public:
    const int idInstrument;
    static int nextId;

    char* denumire;          
    string categorie;        
    int nrCorzi;             
    float pret;


    Instrument() : idInstrument(++nextId) {
        denumire = new char[strlen("Necunoscut") + 1];
        strcpy(denumire, "Necunoscut");

        categorie = "Necunoscuta";
        nrCorzi = 0;
        pret = 0;
    }


    Instrument(const char* denumire, string categorie) : idInstrument(++nextId) {
        if (denumire != nullptr) {
            this->denumire = new char[strlen(denumire) + 1];
            strcpy(this->denumire, denumire);
        }
        else {
            this->denumire = new char[strlen("Necunoscut") + 1];
            strcpy(this->denumire, "Necunoscut");
        }

        this->categorie = categorie;
        nrCorzi = 0;
        pret = 0;
    }


    Instrument(const char* denumire, string categorie, int nrCorzi, float pret)
        : idInstrument(++nextId)
    {
        if (denumire != nullptr) {
            this->denumire = new char[strlen(denumire) + 1];
            strcpy(this->denumire, denumire);
        }
        else {
            this->denumire = new char[strlen("Necunoscut") + 1];
            strcpy(this->denumire, "Necunoscut");
        }

        this->categorie = categorie;
        this->nrCorzi = nrCorzi;
        this->pret = pret;
    }


    static float reducere(float pret, float procent) {
        return pret - (pret * procent / 100.0);
    }

    void afisare() const {
        cout << "Instrument ID: " << idInstrument
            << " | Denumire: " << (denumire ? denumire : "NULL")
            << " | Categorie: " << categorie
            << " | Nr corzi: " << nrCorzi
            << " | Pret: " << pret << endl;
    }

    ~Instrument() {
        if (denumire != nullptr) delete[] denumire;
    }
};
int Instrument::nextId = 0;



class Amplificator {
public:
    const int idAmplificator;
    static int nextId;

    char* brand;           
    int putereW;
    float pret;
    bool estePortabil;


    Amplificator() : idAmplificator(++nextId) {
        brand = new char[strlen("Necunoscut") + 1];
        strcpy(brand, "Necunoscut");

        putereW = 0;
        pret = 0;
        estePortabil = false;
    }


    Amplificator(const char* brand) : idAmplificator(++nextId) {
        if (brand != nullptr) {
            this->brand = new char[strlen(brand) + 1];
            strcpy(this->brand, brand);
        }
        else {
            this->brand = new char[strlen("Necunoscut") + 1];
            strcpy(this->brand, "Necunoscut");
        }

        putereW = 0;
        pret = 0;
        estePortabil = false;
    }


    Amplificator(const char* brand, int putereW, float pret, bool estePortabil)
        : idAmplificator(++nextId)
    {
        if (brand != nullptr) {
            this->brand = new char[strlen(brand) + 1];
            strcpy(this->brand, brand);
        }
        else {
            this->brand = new char[strlen("Necunoscut") + 1];
            strcpy(this->brand, "Necunoscut");
        }

        this->putereW = putereW;
        this->pret = pret;
        this->estePortabil = estePortabil;
    }


    static int consumEstimativ(int putereW) {
        return putereW * 2;
    }

    void afisare() const {
        cout << "Amplificator ID: " << idAmplificator
            << " | Brand: " << (brand ? brand : "NULL")
            << " | Putere: " << putereW << "W"
            << " | Pret: " << pret
            << " | Portabil: " << (estePortabil ? "DA" : "NU") << endl;
    }

    ~Amplificator() {
        if (brand != nullptr) delete[] brand;
    }
};
int Amplificator::nextId = 0;





int main() {

    cout << "=== MICROFON (M) ===" << endl;
    Microfon m1; 
    Microfon m2("Shure SM58");
    Microfon m3("Rode NT1", "Condensator", 999.99, true);

    m1.afisare();
    m2.afisare();
    m3.afisare();
    cout << "Pret m3 cu TVA: " << Microfon::calculeazaPretCuTVA(999.99) << endl;

    cout << "\n=== INSTRUMENT (I) ===" << endl;
    Instrument i1; 
    Instrument i2("Yamaha P-45", "Pian");
    Instrument i3("Fender Stratocaster", "Chitara", 6, 4200.0);

    i1.afisare();
    i2.afisare();
    i3.afisare();
    cout << "Pret i3 cu reducere 10%: " << Instrument::reducere(4200.0, 10) << endl;

    cout << "\n=== AMPLIFICATOR (A) ===" << endl;
    Amplificator a1; 
    Amplificator a2("Marshall");
    Amplificator a3("Boss Katana", 100, 1850.0f, false);

    a1.afisare();
    a2.afisare();
    a3.afisare();
    cout << "Consum estimativ a3: " << Amplificator::consumEstimativ(100) << endl;

    return 0;
}