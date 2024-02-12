#include <iostream>
#include <climits>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;
//studentu duomenu struktura
struct studentas
{
    string vardas;
    string pavarde;
    vector<int> ND; 
    int EGZ;
    double GalutinisV;
    double GalutinisM;
};

int main()
{
    //ivedami studentu ir namu darbu skaiciai
    int m, n;
    cout << "Iveskite studentu skaicius: ";
    cin >> m;

    cout << endl << "Iveskite namu darbu skaiciu: ";
    cin >> n; 
    
    cout << endl << "Kaip norite apskaiciuoti galutini bala? (iveskite m - jei su mediana, v su vidukriu) "; //balo apskaiciavimo budas
    char budas;
    cin >> budas;
    if (budas != 'm' && budas != 'v') //tikrinama ar ivestas tinkamas simbolis
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
    
    vector<studentas> S(m); 
    //duomenu ivedimas ir apdorojimas
    for (int i = 0; i < m; i++)
    {
         
        cout <<  "Iveskite studento varda ir pavarde: "; //vardas ir pavarde
        cin >> S[i].vardas >> S[i].pavarde;

        cout << endl << "Iveskite namu darbu rezultatus:"; //namu darbu rezultatu ivedimas
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            S[i].ND.push_back(temp); 
        }

        cout << endl << "Iveskite egzamino rezultata:"; 
        cin >> S[i].EGZ;//ivedamas egzamino balas


        if (budas == 'v') //galutinis balas apskaiciuojamas su vidurkiu
        {
            int suma = 0;
            double vid = 0.0;
            for (int j = 0; j < n; j++)
            {
                suma = suma + S[i].ND[j];
            }
            vid = suma * 1.0/ n ;
            S[i].GalutinisV = 0.4 * vid + 0.6 * S[i].EGZ;
            
        }

        if (budas == 'm') //galutinis balas apskaiciuojamas su mediana
        {
            int mediana;
            sort(S[i].ND.begin(), S[i].ND.end()); 
            if (n % 2 == 0)
            {
                int m1 = round(n / 2.0);
                int m2 = m1 - 1;
               S[i].GalutinisM = 0.4 *((S[i].ND[m1] + S[i].ND[m2])/2.0 ) + 0.6 * S[i].EGZ;

            }
            else
            {
                mediana = round(n / 2.0) - 1;
                S[i].GalutinisM = 0.4 * S[i].ND[mediana] + 0.6 * S[i].EGZ;
            }   
            
        }
        cout << endl;
    }
    // rezultatu spausdinimas
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
            return 0;
}
