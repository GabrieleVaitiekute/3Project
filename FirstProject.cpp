#include <iostream>
#include <climits>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

struct studentas
{
    string vardas;
    string pavarde;
    vector<int> ND; 
    double vid;
    int EGZ;
    double GalutinisV;
    double GalutinisM;
};

int main()
{
    int m, n;
    cout << "Iveskite studentu skaicius: ";
    cin >> m;

    cout << endl << "Iveskite namu darbu skaiciu: ";
    cin >> n;

    vector<studentas> C(m); 

    for (int i = 0; i < m; i++)
    {
        cout << "Iveskite studento varda ir pavarde: "; //vardas ir pavarde
        cin >> C[i].vardas >> C[i].pavarde;

        cout << endl << "Iveskite namu darbu rezultatus:"; //namu darbu rezultatu ivedimas
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            C[i].ND.push_back(temp); 
        }

        cout << endl << "Iveskite egzamino rezultata:"; 
        cin >> C[i].EGZ;//ivedamas egzamino balas

        cout << endl << "Kaip norite apskaiciuoti galutini bala? (iveskite m - jei su mediana, v su vidukriu) "; //balo apskaiciavimo budas
        char budas;
        cin >> budas;

        if (budas == 'v') //galutinis balasa apskaiciuojamas su vidurkiu
        {
            int suma = 0;
            for (int j = 0; j < n; j++)
            {
                suma += C[i].ND[j];
            }
            C[i].vid = suma * 1.0 / n;
            C[i].GalutinisV = 0.4 * C[i].vid + 0.6 * C[i].EGZ;
            cout << endl  << "Pavarde \t Vardas \t Galutinis (Vid. )" << endl;
            cout << "-----------------------------------------------" << endl;
            cout << C[i].pavarde << " \t " << C[i].vardas << " \t " << setprecision(2) << C[i].GalutinisV << endl;
        }
        if (budas == 'm') //galutinis balasa apskaiciuojamas su mediana
        {
            sort(C[i].ND.begin(), C[i].ND.end()); 
            int mediana = round(n / 2.0);
            C[i].GalutinisM = 0.4 * C[i].ND[mediana] + 0.6 * C[i].EGZ;
            cout << endl  << "Pavarde \t Vardas \t  Galutinis (Med. )" << endl;
            cout << "------------------------------------------------------" << endl;
            cout << C[i].pavarde << " \t " << C[i].vardas << " \t " << setprecision(2) << C[i].GalutinisM << endl;
        }
    }
    return 0;
}
