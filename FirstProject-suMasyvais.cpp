#include <iostream>
#include <climits>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

struct studentas
{
    string vardas;
    string pavarde;
    int* ND;
    int EGZ;
    double GalutinisV;
    double GalutinisM;
};

int main()
{
    //studentu skaiciaus ir namu darbu kiekio ivedimas
    int m, n;
    cout << "Iveskite studentu skaiciu: ";
    cin >> m;

    cout << endl << "Iveskite namu darbu skaiciu: ";
    cin >> n;
    //galutinio balo apskaiciavimo budo pasirinkimas
    cout << endl << "Kaip norite apskaiciuoti galutini bala? (iveskite m - jei su mediana, v su vidukriu) ";
    char budas;
    cin >> budas;
    if (budas != 'm' && budas != 'v')
    {
        bool ivedimas = false;
        while (ivedimas == false)
        {
            cout << "Ivestas netinkamas simbolis, bandykite dar karta:";
            cin >> budas;
            if (budas == 'm' || budas == 'v')
                ivedimas = true;
        }
    }

    studentas* S = new studentas[m];
    //studentu informacijos ivedimas
    for (int i = 0; i < m; i++)
    {
        cout << "Iveskite studento varda ir pavarde: ";
        cin >> S[i].vardas >> S[i].pavarde;

        cout << endl << "Iveskite namu darbu rezultatus:";
        S[i].ND = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> S[i].ND[j];
        }

        cout << endl << "Iveskite egzamino rezultata:";
        cin >> S[i].EGZ;

        if (budas == 'v')
        {
            int suma = 0;
            double vid = 0.0;
            for (int j = 0; j < n; j++)
            {
                suma += S[i].ND[j];
            }
            vid = suma * 1.0 / n;
            S[i].GalutinisV = 0.4 * vid + 0.6 * S[i].EGZ;
        }

        if (budas == 'm')
        {
            sort(S[i].ND, S[i].ND + n);
            if (n % 2 == 0)
            {
                int m1 = round(n / 2.0);
                int m2 = m1 - 1;
                S[i].GalutinisM = 0.4 * ((S[i].ND[m1] + S[i].ND[m2]) / 2.0) + 0.6 * S[i].EGZ;
            }
            else
            {
                int mediana = round(n / 2.0) - 1;
                S[i].GalutinisM = 0.4 * S[i].ND[mediana] + 0.6 * S[i].EGZ;
            }
        }
        
    }
  
//rezultatu spausdinimas
    for (int i = 0; i < m; i++)
    {
        if (budas == 'v')
        {
            if (i == 0)
            {
                cout << endl << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Vid.)" << endl;
                cout << setfill('-') << setw(80) << "-" << setfill(' ') << endl;
            }
            cout << setw(20) << S[i].pavarde << setw(20) << S[i].vardas << setw(20) << setprecision(3) << S[i].GalutinisV << endl;
        }
        if (budas == 'm')
        {
            if (i == 0)
            {
                cout << endl << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Med.)" << endl;
                cout << setfill('-') << setw(80) << "-" << setfill(' ') << endl;
            }
            cout << setw(20) << S[i].pavarde << setw(20) << S[i].vardas << setw(20) << setprecision(3) << S[i].GalutinisM << endl;
        }
    }

    delete[] S; 
    return 0;
}
