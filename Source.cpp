#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Produs {
public:
    string denumire;
    int cantitate;
    string raion;
    int pret;

    Produs(){}

    Produs(string denumire, int cantitate, string raion, int pret) {
        this->denumire = denumire;
        this->cantitate = cantitate;
        this->raion = raion;
        this->pret = pret;
    }

    string getDenumire() {
        return this->denumire;
    }

    int getCantitate() {
        return this->cantitate;
    }

    string getRaion() {
        return this->raion;
    }

    int getPret() {
        return this->pret;
    }

    void toString() {
        cout << this->denumire << " " << this->cantitate << " " << this->raion << " " << this->pret << endl;
    }
};


class Ana {
public:
    vector<Produs> lista;

    Ana() {}

    Ana(vector<Produs> lista) {
        this->lista = lista;
    }

    vector<Produs> getLista() {
        return this->lista;
    }

    void toString() {
        for (int i = 0; i < this->lista.size(); i++)
           lista[i].toString();
        cout << endl;
    }

    void sortAlphabeticByRaion() {
        for(int i=0;i<this->lista.size()-1;i++)
            for (int j = i+1; j < this->lista.size(); j++) 
                if (lista[i].getRaion().compare(lista[j].getRaion())>0) {
                    Produs aux(lista[i].getDenumire(), lista[i].getCantitate(), lista[i].getRaion(), lista[i].getPret());
                    lista[i] = lista[j];
                    lista[j] = aux;
                }
    }

    void sortDescByCantitate() {
        for (int i = 0; i < this->lista.size() - 1; i++)
            for (int j = i + 1; j < this->lista.size(); j++)
                if (lista[i].getCantitate() < lista[j].getCantitate()) {
                    Produs aux(lista[i].getDenumire(), lista[i].getCantitate(), lista[i].getRaion(), lista[i].getPret());
                    lista[i] = lista[j];
                    lista[j] = aux;
                }
     }

    void showByRaion(string raion) {
        for (int i = 0; i < this->lista.size(); i++)
            if (lista[i].getRaion() == raion)
                lista[i].toString();
    }

    int totalCheltuieli() {
        int sum = 0;
        for (int i = 0; i < this->lista.size(); i++)
            sum += lista[i].getCantitate() * lista[i].getPret();
        return sum;
    }
};




int main()
{
    Produs lista1("cartofi", 2, "legume", 2);
    Produs lista2("rosii", 2, "legume", 20);
    Produs lista3("suc", 6, "bauturi", 3);
    Produs lista4("chipsuri", 3, "snaksuri", 4);

    vector<Produs> lista;
    lista.push_back(lista1);
    lista.push_back(lista2);
    lista.push_back(lista3);
    lista.push_back(lista4);

    Ana ana(lista);
    cout << "Lista initiala:" << endl;
    ana.toString();

    ana.sortAlphabeticByRaion();
    cout << "Lista ordonata alfabetic dupa raion:" << endl;
    ana.toString();

    ana.sortDescByCantitate();
    cout << "Lista ordonata descrescator dupa cantitate:" << endl;
    ana.toString();

    string raion = "legume";
    cout << "Lista de la raionul " << raion << endl;
    ana.showByRaion(raion);

    cout << endl << "Cheltuieli totale: ";
    cout << ana.totalCheltuieli();

    return 0;
}