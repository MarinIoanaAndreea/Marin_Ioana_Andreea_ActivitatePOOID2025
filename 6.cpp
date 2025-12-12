#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

class Imprimare3D {
private:
    const int idComanda;      
    static int nextId;        

    char* material;           
    int nrExemplare;
    float cost;
    string categorie;
    string imprimanta;

public:

    Imprimare3D() : idComanda(++nextId)
    {
        this->material = nullptr;
        this->nrExemplare = 0;
        this->cost = 0;
        this->categorie = "Necunoscut";
        this->imprimanta = "HP";
    }
   


    Imprimare3D(const char* material, int nrExemplare, float cost, string categorie, string imprimanta)
        : idComanda(++nextId)
    {
        this->material = new char[strlen(material) + 1];
        strcpy(this->material, material);
        this->nrExemplare = nrExemplare;
        this->cost = cost;
        this->categorie = categorie;
        this->imprimanta = imprimanta;
    }


    Imprimare3D(const Imprimare3D& comandaOriginala)
        : idComanda(++nextId)
    {
        this->material = new char[strlen(comandaOriginala.material) + 1];
        strcpy(this->material, comandaOriginala.material);
        this->nrExemplare = comandaOriginala.nrExemplare;
        this->cost = comandaOriginala.cost;
        this->categorie = comandaOriginala.categorie;
        this->imprimanta = comandaOriginala.imprimanta;
    }


    ~Imprimare3D()
    {
        if (this->material != nullptr) {
            delete[] this->material;
        }
    }


    int getIdComanda() const {
        return this->idComanda;
    }


    const char* getMaterial() const {
        return this->material;
    }

    void setMaterial(const char* materialNou) {
        if (materialNou != nullptr && strlen(materialNou) > 0) {

           
            if (this->material != nullptr) {  
                delete[] this->material;
            }

           
            this->material = new char[strlen(materialNou) + 1];
            strcpy(this->material, materialNou);
        }
    }

 
    int getNrExemplare() const {
        return this->nrExemplare;
    }

    void setNrExemplare(int nrNou) {
        if (nrNou >= 0) {
            this->nrExemplare = nrNou;
        }
    }

   
    float getCost() const {
        return this->cost;
    }

    void setCost(float costNou) {
        if (costNou >= 0) {
            this->cost = costNou;
        }
    }

   
    string getCategorie() const {
        return this->categorie;
    }

    void setCategorie(string categorieNoua) {
        if (categorieNoua.length() > 0) {
            this->categorie = categorieNoua;
        }
    }

    
    string getImprimanta() const {
        return this->imprimanta;
    }

    void setImprimanta(string imprimantaNoua) {
        if (imprimantaNoua.length() > 0) {
            this->imprimanta = imprimantaNoua;
        }
    }

   
    friend ostream& operator<<(ostream& out, const Imprimare3D& c);
    bool operator<(const Imprimare3D& other) const;
    Imprimare3D& operator+=(const Imprimare3D& other);

   
    void salveazaBinar(ostream& out);
    void incarcaBinar(ifstream& in);
};


int Imprimare3D::nextId = 0;


ostream& operator<<(ostream& out, const Imprimare3D& c) {
    out << "Comanda ID: " << c.idComanda
        << " | Material: " << (c.material ? c.material : "NULL")
        << " | Nr exemplare: " << c.nrExemplare
        << " | Cost: " << c.cost
        << " | Categorie: " << c.categorie
        << " | Imprimanta: " << c.imprimanta;
    return out;
}


bool Imprimare3D::operator<(const Imprimare3D& other) const {
    return this->cost < other.cost;
}


Imprimare3D& Imprimare3D::operator+=(const Imprimare3D& other) {
    this->nrExemplare += other.nrExemplare;
    this->cost += other.cost;
    return *this;
}


void Imprimare3D::salveazaBinar(ostream& out)
{
    size_t len = material ? strlen(material) : 0;
    out.write((char*)&len, sizeof(len));
    if (len > 0) {
        out.write(material, len);
    }

    out.write((char*)&nrExemplare, sizeof(nrExemplare));
    out.write((char*)&cost, sizeof(cost));

    size_t lenCat = categorie.size();
    out.write((char*)&lenCat, sizeof(lenCat));
    if (lenCat > 0) {
        out.write(categorie.c_str(), lenCat);
    }

    size_t lenImp = imprimanta.size();
    out.write((char*)&lenImp, sizeof(lenImp));
    if (lenImp > 0) {
        out.write(imprimanta.c_str(), lenImp);
    }

   
}


void Imprimare3D::incarcaBinar(ifstream& in)
{
    size_t len = 0;
    in.read((char*)&len, sizeof(len));

    if (material != nullptr) {
        delete[] material;
        material = nullptr;
    }

    if (len > 0) {
        material = new char[len + 1];
        in.read(material, len);
        material[len] = '\0';
    }
    else {
        material = nullptr;
    }

    in.read((char*)&nrExemplare, sizeof(nrExemplare));
    in.read((char*)&cost, sizeof(cost));

    size_t lenCat = 0;
    in.read((char*)&lenCat, sizeof(lenCat));
    if (lenCat > 0) {
        categorie.resize(lenCat);
        in.read(&categorie[0], lenCat);
    }
    else {
        categorie = "";
    }

    size_t lenImp = 0;
    in.read((char*)&lenImp, sizeof(lenImp));
    if (lenImp > 0) {
        imprimanta.resize(lenImp);
        in.read(&imprimanta[0], lenImp);
    }
    else {
        imprimanta = "";
    }

  
}

int main() {

    Imprimare3D comanda1("PLA", 10, 150.5, "Prototip", "Ultimaker");

    ofstream fout("comanda.bin", ios::binary);
    comanda1.salveazaBinar(fout);
    fout.close();

    Imprimare3D comanda2; 
    ifstream fin("comanda.bin", ios::binary);
    comanda2.incarcaBinar(fin);
    fin.close();

    cout << comanda1 << endl;
    cout << comanda2 << endl;

    return 0;
}
