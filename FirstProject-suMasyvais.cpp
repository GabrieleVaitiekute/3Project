#include <iostream>
#include <climits>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <random>
#include <string>
#include <cstdlib> 
using namespace std;
random_device rd;
mt19937 generuoti(random_device{}());
const int MAX_LENGTH = 11; 
const char raides[] = "abcdefghijklmnopqrstuvwxyz";
uniform_int_distribution<int> index_dist(0, sizeof(raides) - 2);
uniform_int_distribution<int> dis(1, 10);
char TaipNe;
char TaipNePaz;

struct studentas
{
	string vardas;
	string pavarde;
	int* ND;
	int EGZ;
	double GalutinisV;
	double GalutinisM;
};
void rezultatai(int m ,int n, studentas* S)
{
	char budas;
	cout << endl << "Kaip norite apskaiciuoti galutini bala? (iveskite m - jei su mediana, v su vidukriu) ";
	cin >> budas;
	if (budas != 'm' && budas != 'v')//tikrinama ar ivestas tinkamas simbolis
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
	//rezultatu spausdinimas
	for (int i = 0; i < m; i++)
	{
	
		if (budas == 'v')
		{
			int suma = 0;
			double vid = 0.0;
			for (int j = 0; j < n; j++)
			{
				suma += S[m].ND[j];
			}
			vid = suma * 1.0 / n;
			S[m].GalutinisV = 0.4 * vid + 0.6 * S[m].EGZ;
		}

		if (budas == 'm')
		{
			sort(S[m].ND, S[m].ND + n);
			if (n % 2 == 0)
			{
				int m1 = round(n / 2);
				int m2 = m1 - 1;
				S[m].GalutinisM = 0.4 * ((S[m].ND[m1] + S[m].ND[m2]) / 2) + 0.6 * S[m].EGZ;
			}
			else
			{
				int mediana = round(n / 2.0) - 1;
				S[m].GalutinisM = 0.4 * S[m].ND[mediana] + 0.6 * S[m].EGZ;
			}
		}



		if (budas == 'v')
		{
			if (i == 0)
				cout << endl << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Vid.)" << endl << setfill('-') << setw(80) << "-" << setfill(' ') << endl;

			cout << setw(20) << S[i].pavarde << setw(20) << S[i].vardas << setw(20) << setprecision(3) << S[i].GalutinisV << endl;
		}
		if (budas == 'm')
		{
			if (i == 0)
				cout << endl << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Med.)" << endl << setfill('-') << setw(80) << "-" << setfill(' ') << endl;

			cout << setw(20) << S[i].pavarde << setw(20) << S[i].vardas << setw(20) << setprecision(3) << S[i].GalutinisM << endl;
		}
	}
	for (int i = 0; i < m; i++)
		delete[] S[i].ND;
	delete[] S;
}

int main()
{
	int m = 0, n = 0;
	cout << "Pasirinkite veiksma:\n"
		"1. Suvesti visus studentu duomenis\n"
		"2. Sugeneruoti tik studentu pazymius\n"
		"3. Sugeneruoti studentu vardus ir pazymius\n"
		"Iveskite pasirinkimo numeri: ";
	int Pasirinkimas;
	cin >> Pasirinkimas;
		if (Pasirinkimas != 1 && Pasirinkimas != 2 && Pasirinkimas != 3)
		{
			bool ivedimas = false;
			while (ivedimas == false)
			{
				cout << "Ivestas netinkamas simbolis, bandykite dar karta:";
				if (Pasirinkimas == 1 || Pasirinkimas == 2 || Pasirinkimas == 3)
					ivedimas = true;
			}
		}
		if (Pasirinkimas == 1)
		{
			studentas* S = nullptr;
			bool Pazimiai = true;
				do
				{
					studentas* laikinas = new studentas[m + 1];
					for (int i = 0; i < m; ++i)
					{
						laikinas[i] = S[i];
					}
					delete[] S;
					S = laikinas;
					 

					cout << "Iveskite studento varda ir pavarde:";
					cin >> S[m].vardas >> S[m].pavarde;
					cout << endl << "Iveskite namu darbu rezultata:";
					int n = 0;
					S[m].ND = new int[n];
					while (true)
					{
						int pazimys;
						cin >> pazimys;
						S[m].ND[n] = pazimys;
						n++;
						cout << "Ar norite ivesti dar viena pazymi? (T jei taip , N - ne): ";
						cin >> TaipNe;
						if (TaipNe == 'T') Pazimiai = true;
						if (TaipNe == 'N') Pazimiai = false;
					}
					cout << endl << "Iveskite egzamino rezultata: ";
					cin >> S[m].EGZ;//ivedamas egzamino balas

					cout << "Ar norite ivesti dar viena studenta? (T jei taip , N - ne): ";
					cin >> TaipNe;
					if (TaipNe == 'T')
					{
						m++;
					}
					
				} while (TaipNe == 'T');
				rezultatai(m, n, S);
		}

		if (Pasirinkimas == 2)
		{
			
			studentas* S = nullptr;
			
			do
			{
				studentas* laikinas = new studentas[m + 1];
				for (int i = 0; i < m; ++i)
				{
					laikinas[i] = S[i];
				}
				delete[] S;
				S = laikinas;
				cout << "Iveskite studento varda ir pavarde:";
				cin >> S[m].vardas >> S[m].pavarde;

				int n = 0;
				S[m].EGZ = dis(generuoti);
				S[m].ND = new int[n];
				do
				{

					S[m].ND[n] = dis(generuoti);
					cout << "Sugeneruotias pazimys: " << S[m].ND[n] << endl;
					cout << "Ar norite sugeneruoti dar viena pazimi? (iveskite T, jei taip , N, jei ne): ";
					cin >> TaipNe;
					n++;
				} while (TaipNe == 'T');

				cout << "Ar norite ivesti dar viena studenta? (T jei taip , N - ne): ";
				cin >> TaipNe;
				if (TaipNe == 'T')
					m++;
				
			} while (TaipNe == 'T');
			rezultatai(m, n, S);

		}

		if (Pasirinkimas == 3)
		{
			studentas* S = nullptr;
		
			do
			{
				studentas* laikinas = new studentas[m + 1];

				for (int i = 0; i < m; ++i)
				{
					laikinas[i] = S[i];
				}
				delete[] S;
				S = laikinas;

				cout << "Ar norite sugeneruoti studenta? (T, jei taip, N, jei ne): ";
				cin >> TaipNe;
				if (TaipNe == 'T')
				{
					int ilgis = 5 + generuoti() % 6; // Random length for names

					for (int i = 0; i < ilgis; ++i)
					{
						S[m].vardas[i] = raides[index_dist(generuoti)];
						S[m].pavarde[i] = raides[index_dist(generuoti)];
					}
					S[m].vardas[ilgis] = '\0'; // Null-terminate the strings
					S[m].pavarde[ilgis] = '\0';

					S[m].EGZ = dis(generuoti);

				S[m].ND = new int[n];
				do
				{
					S[m].ND[n] = dis(generuoti);
					cout << "Sugeneruotias pazimys: " << S[m].ND[n] << endl;
					cout << "Ar norite sugeneruoti dar viena pazimi? (iveskite T, jei taip , N, jei ne): ";
					cin >> TaipNePaz;
					n++;
				} while (TaipNePaz == 'T');

				}
				
				cout << "Ar norite ivesti dar viena studenta? (T jei taip , N - ne): ";
				cin >> TaipNe;
				if (TaipNe == 'T')
					m++;
				
			} while (TaipNe == 'T');

			rezultatai(m, n, S);
		}
	
	return 0;
}
