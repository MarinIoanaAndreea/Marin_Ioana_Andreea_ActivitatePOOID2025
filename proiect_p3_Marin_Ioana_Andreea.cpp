#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

// PROIECT PARTEA 3 - Marin Andreea Ioana
// DOMENIU: Magazin Instrumente Audio (M I A)
// Clase: Microfon, Instrument, Amplificator

class Microfon;
class Instrument;
class Amplificator;

float valoarePachet(const Microfon& m, const Instrument& i);
bool amplificatorMaiScumpDecatMicrofon(const Amplificator& a, const Microfon& m);

class Microfon {
private:
    const int idMicrofon;
    static int nextId;
    char* model;
    string tip;
    float pret;
    bool areCablu;

public:
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

    Microfon(const Microfon& other) : idMicrofon(++nextId) {
        if (other.model != nullptr) {
            this->model = new char[strlen(other.model) + 1];
            strcpy(this->model, other.model);
        }
        else {
            this->model = nullptr;
        }
        this->tip = other.tip;
        this->pret = other.pret;
        this->areCablu = other.areCablu;
    }

    ~Microfon() {
        if (model != nullptr) {
            delete[] model;
            model = nullptr;
        }
    }

    static float calculeazaPretCuTVA(float pret) {
        return pret * 1.19f;
    }

    static int getNextId() {
        return nextId;
    }

    int getIdMicrofon() const { return idMicrofon; }
    const char* getModel() const { return model; }
    string getTip() const { return tip; }
    float getPret() const { return pret; }
    bool getAreCablu() const { return areCablu; }

    void setModel(const char* modelNou) {
        if (modelNou != nullptr && strlen(modelNou) > 0) {
            if (this->model != nullptr) delete[] this->model;
            this->model = new char[strlen(modelNou) + 1];
            strcpy(this->model, modelNou);
        }
    }

    void setTip(string tipNou) {
        if (tipNou.length() > 0) this->tip = tipNou;
    }

    void setPret(float pretNou) {
        if (pretNou >= 0) this->pret = pretNou;
    }

    void setAreCablu(bool areCabluNou) {
        this->areCablu = areCabluNou;
    }

    void afisare() const {
        cout << "Microfon ID: " << idMicrofon
            << " | Model: " << (model ? model : "NULL")
            << " | Tip: " << tip
            << " | Pret: " << pret
            << " | Cablu: " << (areCablu ? "DA" : "NU") << endl;
    }

    Microfon& operator=(const Microfon& other);   
    bool operator<(const Microfon& other) const;  
    Microfon operator+(float valoare) const;      
    Microfon& operator++();                       

    friend float valoarePachet(const Microfon& m, const Instrument& i);
    friend bool amplificatorMaiScumpDecatMicrofon(const Amplificator& a, const Microfon& m);
};

int Microfon::nextId = 0;


class Instrument {
private:
    const int idInstrument;
    static int nextId;

    char* denumire;
    string categorie;
    int nrCorzi;
    float pret;

public:
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

    Instrument(const Instrument& other) : idInstrument(++nextId) {
        if (other.denumire != nullptr) {
            this->denumire = new char[strlen(other.denumire) + 1];
            strcpy(this->denumire, other.denumire);
        }
        else {
            this->denumire = nullptr;
        }
        this->categorie = other.categorie;
        this->nrCorzi = other.nrCorzi;
        this->pret = other.pret;
    }

    ~Instrument() {
        if (denumire != nullptr) {
            delete[] denumire;
            denumire = nullptr;
        }
    }

    static float reducere(float pret, float procent) {
        return pret - (pret * procent / 100.0);
    }

    static int getNextId() {
        return nextId;
    }


    int getIdInstrument() const { return idInstrument; }
    const char* getDenumire() const { return denumire; }
    string getCategorie() const { return categorie; }
    int getNrCorzi() const { return nrCorzi; }
    float getPret() const { return pret; }

    void setDenumire(const char* denumireNoua) {
        if (denumireNoua != nullptr && strlen(denumireNoua) > 0) {
            if (this->denumire != nullptr) delete[] this->denumire;
            this->denumire = new char[strlen(denumireNoua) + 1];
            strcpy(this->denumire, denumireNoua);
        }
    }

    void setCategorie(string categorieNoua) {
        if (categorieNoua.length() > 0) this->categorie = categorieNoua;
    }

    void setNrCorzi(int nrNou) {
        if (nrNou >= 0) this->nrCorzi = nrNou;
    }

    void setPret(float pretNou) {
        if (pretNou >= 0) this->pret = pretNou;
    }

    void afisare() const {
        cout << "Instrument ID: " << idInstrument
            << " | Denumire: " << (denumire ? denumire : "NULL")
            << " | Categorie: " << categorie
            << " | Nr corzi: " << nrCorzi
            << " | Pret: " << pret << endl;
    }

    Instrument& operator=(const Instrument& other);     
    bool operator==(const Instrument& other) const;     
    float operator+(const Instrument& other) const;     
    Instrument& operator+=(float valoare);              

    friend float valoarePachet(const Microfon& m, const Instrument& i);
};

int Instrument::nextId = 0;


class Amplificator {
private:
    const int idAmplificator;
    static int nextId;

    char* brand;
    int putereW;
    float pret;
    bool estePortabil;

public:
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

    Amplificator(const Amplificator& other) : idAmplificator(++nextId) {
        if (other.brand != nullptr) {
            this->brand = new char[strlen(other.brand) + 1];
            strcpy(this->brand, other.brand);
        }
        else {
            this->brand = nullptr;
        }
        this->putereW = other.putereW;
        this->pret = other.pret;
        this->estePortabil = other.estePortabil;
    }

    ~Amplificator() {
        if (brand != nullptr) {
            delete[] brand;
            brand = nullptr;
        }
    }

    static int consumEstimativ(int putereW) {
        return putereW * 2;
    }

    static int getNextId() {
        return nextId;
    }

    int getIdAmplificator() const { return idAmplificator; }
    const char* getBrand() const { return brand; }
    int getPutereW() const { return putereW; }
    float getPret() const { return pret; }
    bool getEstePortabil() const { return estePortabil; }

    void setBrand(const char* brandNou) {
        if (brandNou != nullptr && strlen(brandNou) > 0) {
            if (this->brand != nullptr) delete[] this->brand;
            this->brand = new char[strlen(brandNou) + 1];
            strcpy(this->brand, brandNou);
        }
    }

    void setPutereW(int putereNoua) {
        if (putereNoua >= 0) this->putereW = putereNoua;
    }

    void setPret(float pretNou) {
        if (pretNou >= 0) this->pret = pretNou;
    }

    void setEstePortabil(bool portabilNou) {
        this->estePortabil = portabilNou;
    }

    void afisare() const {
        cout << "Amplificator ID: " << idAmplificator
            << " | Brand: " << (brand ? brand : "NULL")
            << " | Putere: " << putereW << "W"
            << " | Pret: " << pret
            << " | Portabil: " << (estePortabil ? "DA" : "NU") << endl;
    }

    Amplificator& operator=(const Amplificator& other);  
    bool operator>(const Amplificator& other) const;     
    Amplificator operator+(int extraPutere) const;       
    bool operator!() const;                              

    friend bool amplificatorMaiScumpDecatMicrofon(const Amplificator& a, const Microfon& m);
};

int Amplificator::nextId = 0;


float valoarePachet(const Microfon& m, const Instrument& i) {
    return m.pret + i.pret;
}

bool amplificatorMaiScumpDecatMicrofon(const Amplificator& a, const Microfon& m) {
    return a.pret > m.pret;
}


Microfon& Microfon::operator=(const Microfon& other) {
    if (this != &other) {
        if (this->model != nullptr) {
            delete[] this->model;
            this->model = nullptr;
        }

        if (other.model != nullptr) {
            this->model = new char[strlen(other.model) + 1];
            strcpy(this->model, other.model);
        }
        else {
            this->model = nullptr;
        }

        this->tip = other.tip;
        this->pret = other.pret;
        this->areCablu = other.areCablu;
    }
    return *this;
}

bool Microfon::operator<(const Microfon& other) const {
    return this->pret < other.pret;
}

Microfon Microfon::operator+(float valoare) const {
    Microfon copie(*this);
    copie.pret += valoare;
    return copie;
}

Microfon& Microfon::operator++() {
    this->pret += 1.0f;
    return *this;
}

Instrument& Instrument::operator=(const Instrument& other) {
    if (this != &other) {
        if (this->denumire != nullptr) {
            delete[] this->denumire;
            this->denumire = nullptr;
        }

        if (other.denumire != nullptr) {
            this->denumire = new char[strlen(other.denumire) + 1];
            strcpy(this->denumire, other.denumire);
        }
        else {
            this->denumire = nullptr;
        }

        this->categorie = other.categorie;
        this->nrCorzi = other.nrCorzi;
        this->pret = other.pret;
    }
    return *this;
}

bool Instrument::operator==(const Instrument& other) const {
    return this->categorie == other.categorie && this->nrCorzi == other.nrCorzi;
}

float Instrument::operator+(const Instrument& other) const {
    return this->pret + other.pret;
}

Instrument& Instrument::operator+=(float valoare) {
    this->pret += valoare;
    return *this;
}


Amplificator& Amplificator::operator=(const Amplificator& other) {
    if (this != &other) {
        if (this->brand != nullptr) {
            delete[] this->brand;
            this->brand = nullptr;
        }

        if (other.brand != nullptr) {
            this->brand = new char[strlen(other.brand) + 1];
            strcpy(this->brand, other.brand);
        }
        else {
            this->brand = nullptr;
        }

        this->putereW = other.putereW;
        this->pret = other.pret;
        this->estePortabil = other.estePortabil;
    }
    return *this;
}

bool Amplificator::operator>(const Amplificator& other) const {
    return this->putereW > other.putereW;
}

Amplificator Amplificator::operator+(int extraPutere) const {
    Amplificator copie(*this);
    copie.putereW += extraPutere;
    return copie;
}

bool Amplificator::operator!() const {
    return !this->estePortabil;
}


int main() {

    cout << "=== MICROFON (M) ===" << endl;
    Microfon m1;
    Microfon m2("Shure SM58");
    Microfon m3("Rode NT1", "Condensator", 999.99, true);

    m1.afisare();
    m2.afisare();
    m3.afisare();

    Microfon m4 = m3;
    cout << "Am facut o copie a lui m3 in m4. m4 este: ";
    m4.afisare();

    m1.setModel("Audio-Technica");
    m1.setTip("Dinamic");
    m1.setPret(450.0);
    m1.setAreCablu(true);

    cout << "Verific m1 cu getteri (id | model | tip | pret | cablu): "
        << m1.getIdMicrofon() << " | "
        << m1.getModel() << " | "
        << m1.getTip() << " | "
        << m1.getPret() << " | "
        << (m1.getAreCablu() ? "DA" : "NU") << endl;

    cout << "Valoare nextId la Microfon (static): " << Microfon::getNextId() << endl;
    cout << "Pretul lui m3 cu TVA inclus: " << Microfon::calculeazaPretCuTVA(m3.getPret()) << endl;


    cout << "\n=== INSTRUMENT (I) ===" << endl;
    Instrument i1;
    Instrument i2("Yamaha P-45", "Pian");
    Instrument i3("Fender Stratocaster", "Chitara", 6, 4200.0);

    i1.afisare();
    i2.afisare();
    i3.afisare();

    Instrument i4 = i3;
    cout << "Am copiat i3 in i4. i4 este: ";
    i4.afisare();

    i1.setDenumire("Casio CT-S1");
    i1.setCategorie("Pian");
    i1.setNrCorzi(0);
    i1.setPret(1200.0);

    cout << "i1 citit cu getteri (id | denumire | categorie | nrCorzi | pret): "
        << i1.getIdInstrument() << " | "
        << i1.getDenumire() << " | "
        << i1.getCategorie() << " | "
        << i1.getNrCorzi() << " | "
        << i1.getPret() << endl;

    cout << "Valoare nextId la Instrument (static): " << Instrument::getNextId() << endl;
    cout << "i3 dupa o reducere de 10% ar costa: " << Instrument::reducere(i3.getPret(), 10) << endl;


    cout << "\n=== AMPLIFICATOR (A) ===" << endl;
    Amplificator a1;
    Amplificator a2("Marshall");
    Amplificator a3("Boss Katana", 100, 1850.0, false);

    a1.afisare();
    a2.afisare();
    a3.afisare();

    Amplificator a4 = a3;
    cout << "Am creat o copie a lui a3 (in a4). a4 este: ";
    a4.afisare();

    a1.setBrand("Fender");
    a1.setPutereW(40);
    a1.setPret(1600.0f);
    a1.setEstePortabil(true);

    cout << "a1 verificat prin getteri (id | brand | putere | pret | portabil): "
        << a1.getIdAmplificator() << " | "
        << a1.getBrand() << " | "
        << a1.getPutereW() << " | "
        << a1.getPret() << " | "
        << (a1.getEstePortabil() ? "DA" : "NU") << endl;

    cout << "Valoare nextId la Amplificator (static): " << Amplificator::getNextId() << endl;
    cout << "Consum estimativ pentru a3 (in functie de putere): " << Amplificator::consumEstimativ(a3.getPutereW()) << endl;


    cout << "\n=== FUNCTII GLOBALE (friend) ===" << endl;
    cout << "Calculez valoarea pachetului (m3 + i3). Rezultat: " << valoarePachet(m3, i3) << endl;

    cout << "Verific daca a3 este mai scump decat m3. Rezultat: ";
    if (amplificatorMaiScumpDecatMicrofon(a3, m3)) cout << "DA" << endl;
    else cout << "NU" << endl;


    cout << "\n=== FAZA 3 - TEST OPERATORI  ===" << endl;


    Microfon m5;
    m5 = m3; 
    cout << "Dupa atribuirea m5 = m3, microfonul m5 arata asa: ";
    m5.afisare();

    cout << "Compar preturile: daca m1 este mai ieftin decat m3, atunci spun DA, altfel NU: ";
    if (m1 < m3) cout << "DA" << endl;
    else cout << "NU" << endl;

    Microfon m6 = m3 + 50.0f; 
    cout << "Creez un microfon nou m6 = m3 + 50 (pretul creste). m6 este: ";
    m6.afisare();

    ++m6; 
    cout << "Aplic ++m6 (pretul creste cu 1). Acum m6 este: ";
    m6.afisare();



    Instrument i5;
    i5 = i3; 
    cout << "\nDupa ce fac i5 = i3, instrumentul i5 devine: ";
    i5.afisare();

    cout << "Verific egalitatea i2 == i3 (categorie si nrCorzi). Daca e adevarat -> DA, altfel -> NU: ";
    if (i2 == i3) cout << "DA" << endl;
    else cout << "NU" << endl;

    float sumaPreturi = i2 + i3; 
    cout << "Adun preturile (i2 + i3) si obtin: " << sumaPreturi << endl;

    i5 += 100.0; 
    cout << "Maresc pretul lui i5 cu 100 folosind i5 += 100. i5 este acum: ";
    i5.afisare();



    Amplificator a5;
    a5 = a3; 
    cout << "\nDupa atribuirea a5 = a3, amplificatorul a5 este: ";
    a5.afisare();

    cout << "Compar puterea: daca a3 are putere mai mare decat a2, afisez DA, altfel NU: ";
    if (a3 > a2) cout << "DA" << endl;
    else cout << "NU" << endl;

    Amplificator a6 = a3 + 20; 
    cout << "Creez a6 = a3 + 20W (puterea creste). a6 este: ";
    a6.afisare();

    cout << "Verific portabilitatea: daca a3 NU este portabil, afisez DA, altfel NU: ";
    if (!a3) cout << "DA" << endl;
    else cout << "NU" << endl;

    return 0;
}