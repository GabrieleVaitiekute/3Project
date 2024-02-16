#include <iostream>
#include <climits>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <random>
#include <string>
#include <vector>

using namespace std;

random_device rd;
mt19937 generuoti(rd());

uniform_int_distribution<int> dis(1, 10);
uniform_int_distribution<int> dis_lytis(0, 1);

vector<string> vardaiV = { "Jonas", "Petras", "Antanas", "Juozas", "Kazys", "Darius", "Linas", "Tomas", "Giedrius", "Marius" };
vector<string> vardaiM = { "Ona", "Maryte", "Aldona", "Gabija", "Dalia", "Danute", "Asta", "Rasa", "Nijole", "Aiste", "Gabriele" };
vector<string> pavardesV = { "Jonaitis", "Petraitis", "Antanaitis", "Juozaitis", "Kaziukaitis", "Dariukaitis", "Linaitis", "Tomaitis", "Giedraitis", "Mariukaitis" };
vector<string> pavardesM = { "Jonaite", "Petraityte", "Antanaite", "Juozaite", "Kaziukaite", "Dariukaite", "Linaite", "Tomaite", "Giedraite", "Mariukaite", "Antaniene", "Jonaitiene", "Antaniene" };

char TaipNePaz;
char TaipNe;

struct studentas
{
	string vardas;
	string pavarde;
	vector<int> ND; // Namų darbų rezultatų vektorius
	int EGZ = 0;// Egzamino rezultatas
	double GalutinisV = 0;// Galutinis balas pagal vidurkį
	double GalutinisM = 0; // Galutinis balas pagal medianą
};

void Netinkamas_Char(char& ivestis)
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Ivestas netinkamas simbolis. Bandykite dar karta: ";
	cin >> ivestis;
}

void Netinkamas_String(string& ivestis)
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Ivesti netinkami duomenys (Negali buti skaiciu ar specialiuju zenklu).Bandykite dar karta: ";
	cin >> ivestis;
}

void Netinkamas_Int(int& ivestis)
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Ivestas netinkamas skaitmuo. Bandykite dar karta: ";
	cin >> ivestis;
}

void Ivesti_Pazymius(studentas& S)
{
	cout << endl << "Iveskite namu darbu pazymi: ";
	int pazymys;
	do
	{
		cin >> pazymys;
		if (pazymys < 1 || pazymys > 10)
		{
			cout << "Netinkamas pazymys. Pazymys turi buti intervale [1, 10]. Bandykite dar karta: ";
			continue;
		}
		cout << "Ar norite ivesti dar viena pazymi? (iveskite T, jei taip , N, jei ne): ";
		cin >> TaipNePaz;
		while (TaipNePaz != 'T' && TaipNePaz != 'N')//tikrinama ar ivestas tinkamas simbolis
			Netinkamas_Char(TaipNePaz);
		if (TaipNePaz == 'T') cout << endl << "Iveskite namu darbu pazymi: ";
		S.ND.push_back(pazymys); // pridedamas pazymis i vektoriu

	} while (TaipNePaz == 'T');
}

void GeneruotiNDPazymius(studentas& S)
{
	do
	{
		int pazymys = dis(generuoti); // generuojmas random pazymys
		S.ND.push_back(pazymys); // pridedamas pazymis i vektoriu

		cout << endl << "Sugeneruotas pazymys: " << pazymys << endl;
		cout << "Ar norite sugeneruoti dar viena pazymi? (iveskite T, jei taip , N, jei ne): ";
		cin >> TaipNePaz;
		while (TaipNePaz != 'T' && TaipNePaz != 'N')//tikrinama ar ivestas tinkamas simbolis
			Netinkamas_Char(TaipNePaz);

	} while (TaipNePaz == 'T');
}

void Ivesti_Varda(studentas& S)
{
	cout << endl << "Iveskite studento varda: ";
	cin >> S.vardas;
	while (!all_of(S.vardas.begin(), S.vardas.end(), ::isalpha))
	{
		Netinkamas_String(S.vardas);
	}

	cout << endl << "Iveskite studento pavarde: ";
	cin >> S.pavarde;
	while (!all_of(S.pavarde.begin(), S.pavarde.end(), ::isalpha))
	{
		Netinkamas_String(S.pavarde);
	}
}

void Generuoti_Varda_V(studentas& S)
{
	S.vardas = vardaiV[dis(generuoti) % 10];
	S.pavarde = pavardesV[dis(generuoti) % 10];
}

void Generuoti_Varda_M(studentas& S)
{
	S.vardas = vardaiM[dis(generuoti) % 10];
	S.pavarde = pavardesM[dis(generuoti) % 10];
}

void Apskaiciuoti_Rezultatus(char& budas, vector<studentas>& S)
{
	cout << endl << "Kaip norite apskaiciuoti galutini bala? (iveskite M - jei su mediana, V su vidukriu) ";
	cin >> budas;
	while (budas != 'M' && budas != 'V')
	{
		Netinkamas_Char(budas);
	}

	if (budas == 'V')
	{
		for (int i = 0; i < S.size(); i++) 
		{
			double suma = 0.0;
			for (int j = 0; j < S[i].ND.size(); j++) 
			{
				suma += S[i].ND[j];
			}
			S[i].GalutinisV = 0.4 * suma / S[i].ND.size() + 0.6 * S[i].EGZ;
		}
	}

	if (budas == 'M') 
	{
		for (int i = 0; i < S.size(); i++)
		{
			if (S[i].ND.size() == 1)
			{
				S[i].GalutinisM = 0.4 * S[i].ND[0] + 0.6 * S[i].EGZ;
			}
			if (S[i].ND.size() > 1) 
			{
				sort(S[i].ND.begin(), S[i].ND.end());
				int pazymiu_kiekis = S[i].ND.size();
				
				if (pazymiu_kiekis % 2 == 0)
				{
					int mediana1 = S[i].ND[pazymiu_kiekis / 2 - 1];
					int mediana2 = S[i].ND[pazymiu_kiekis / 2];
					double mediana = (mediana1 + mediana2) / 2.0;
					S[i].GalutinisM = 0.4 * mediana + 0.6 * S[i].EGZ;
				}
				 if (pazymiu_kiekis % 2 != 0)
				{
					 int mediana = S[i].ND[pazymiu_kiekis / 2];
					 S[i].GalutinisM = 0.4 * mediana + 0.6 * S[i].EGZ;
				}
			}
		}
	}
}

void Spausdinti_Rezultatus(char budas, const vector<studentas>& S)
{

	cout << endl;
	for (int i = 0; i < S.size(); i++) {
		if (budas == 'V') {
			if (i == 0)
				cout << setw(5) << "Nr." << setw(25) << "Pavarde" << setw(25) << "Vardas" << setw(25) << "Galutinis (Vid.)" << endl << setfill('-') << setw(90) << "-" << setfill(' ') << endl;

			cout << setw(5) << i + 1 << setw(25) << S[i].pavarde << setw(25) << S[i].vardas << setw(25) << setprecision(3) << S[i].GalutinisV << endl;
		}
		if (budas == 'M') {
			if (i == 0)
				cout << setw(5) << "Nr." << setw(25) << "Pavarde" << setw(25) << "Vardas" << setw(25) << "Galutinis (Med.)" << endl << setfill('-') << setw(90) << "-" << setfill(' ') << endl;

			cout << setw(5) << i + 1 << setw(25) << S[i].pavarde << setw(25) << S[i].vardas << setw(25) << setprecision(3) << S[i].GalutinisM << endl;
		}
	}
}

int main()
{
	cout << "Pasirinkite veiksma:\n 1. Suvesti visus studentu duomenis\n 2. Sugeneruoti tik studentu pazymius\n 3. Sugeneruoti studentu vardus ir pazymius\n 4. Baigti darba\n Iveskite pasirinkimo numeri: ";
	int Pasirinkimas;
	cin >> Pasirinkimas;
	while (Pasirinkimas != 1 && Pasirinkimas != 2 && Pasirinkimas != 3 && Pasirinkimas != 4)
	{
		Netinkamas_Int(Pasirinkimas);
	}

	vector<studentas> S;
	studentas naujas;

	if (Pasirinkimas == 1)
	{
		do
		{
			Ivesti_Varda(naujas);

			Ivesti_Pazymius(naujas);

			cout << endl << "Iveskite egzamino pazymi: ";
			cin >> naujas.EGZ;
			while (cin.fail() || naujas.EGZ < 1 || naujas.EGZ > 10)
			{
				Netinkamas_Int(naujas.EGZ);
			}

			S.push_back(naujas);// pridedamas studentas i vektoriu

			cout << endl << "Ar norite ivesti dar viena studenta? (T jei taip , N - ne): ";
			cin >> TaipNe;
			while (TaipNe != 'T' && TaipNe != 'N')
			{
				Netinkamas_Char(TaipNe);
			}

		} while (TaipNe == 'T');
		char budas;
		Apskaiciuoti_Rezultatus(budas, S);
		Spausdinti_Rezultatus(budas, S);
	}

	if (Pasirinkimas == 2)
	{
		do
		{
			Ivesti_Varda(naujas);

			GeneruotiNDPazymius(naujas);

			naujas.EGZ = dis(generuoti);
			cout << "Sugeneruotas egzamino balas: " << naujas.EGZ << endl;

			cout << endl << endl << "Ar norite ivesti dar viena studenta? (T jei taip , N - ne): ";
			cin >> TaipNe;
			while (TaipNe != 'T' && TaipNe != 'N')
			{
				Netinkamas_Char(TaipNe);
			}
		S.push_back(naujas); // pridedamas studentas i vektoriu
		} while (TaipNe == 'T');
		
		char budas;
		Apskaiciuoti_Rezultatus(budas, S);
		Spausdinti_Rezultatus(budas, S);
	}

	if (Pasirinkimas == 3)
	{
		do
		{

			int lytis = dis_lytis(generuoti);

			if (lytis == 0)
				Generuoti_Varda_V(naujas);
			else
				Generuoti_Varda_M(naujas);

			cout << endl << "Sugeneruotas vardas ir pavarde: " << naujas.vardas << " " << naujas.pavarde << endl;

			GeneruotiNDPazymius(naujas);

			naujas.EGZ = dis(generuoti);
			cout << "Sugeneruotas egzamino balas: " << naujas.EGZ << endl;

			cout << endl << endl << "Ar norite sugeneruoti dar viena studenta? (T jei taip , N - ne): ";
			cin >> TaipNe;
			while (TaipNe != 'T' && TaipNe != 'N')
			{
				Netinkamas_Char(TaipNe);
			}
		S.push_back(naujas); // pridedamas studentas i vektoriu
		} while (TaipNe == 'T');
		char budas;
		Apskaiciuoti_Rezultatus(budas, S);
		Spausdinti_Rezultatus(budas, S);
	}

	if (Pasirinkimas == 4)
		cout << endl << "Darbas baigtas";

	return 0;
}
