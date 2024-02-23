#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <climits>
#include <chrono> 
#include <cmath>
#include <numeric>
#include <iomanip>
#include <algorithm>
#include <random>
#include <string>
#include <vector>

std::random_device rd;
std::mt19937 generuoti(rd());

std::uniform_int_distribution<int> dis(1, 10);
std::uniform_int_distribution<int> dis_lytis(0, 1);

std::vector<std::string> vardaiV = { "Jonas", "Petras", "Antanas", "Juozas", "Kazys", "Darius", "Linas", "Tomas", "Giedrius", "Marius" };
std::vector<std::string> vardaiM = { "Ona", "Maryte", "Aldona", "Gabija", "Dalia", "Danute", "Asta", "Rasa", "Nijole", "Aiste", "Gabriele" };
std::vector<std::string> pavardesV = { "Jonaitis", "Petraitis", "Antanaitis", "Juozaitis", "Kaziukaitis", "Dariukaitis", "Linaitis", "Tomaitis", "Giedraitis", "Mariukaitis" };
std::vector<std::string> pavardesM = { "Jonaite", "Petraityte", "Antanaite", "Juozaite", "Kaziukaite", "Dariukaite", "Linaite", "Tomaite", "Giedraite", "Mariukaite", "Antaniene", "Jonaitiene", "Antaniene" };

char TaipNePaz;
char TaipNe;

struct studentas
{
	std::string vardas;
	std::string pavarde;
	std::vector<int> ND; // Namų darbų rezultatų vektorius
	int EGZ = 0;// Egzamino rezultatas
	double GalutinisV = 0;// Galutinis balas pagal vidurkį
	double GalutinisM = 0; // Galutinis balas pagal medianą
};

void Netinkamas_Char(char& ivestis)
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Ivestas netinkamas simbolis. Bandykite dar karta: ";
	std::cin >> ivestis;
}

void Netinkamas_String(std::string& ivestis)
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Ivesti netinkami duomenys (Negali buti skaiciu ar specialiuju zenklu).Bandykite dar karta: ";
	std::cin >> ivestis;
}

void Netinkamas_Int(int& ivestis)
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Ivestas netinkamas skaitmuo. Bandykite dar karta: ";
	std::cin >> ivestis;
}

void Ivesti_Pazymius(studentas& S)
{
	std::cout << std::endl << "Iveskite namu darbu pazymi: ";
	int pazymys;
	do
	{
		std::cin >> pazymys;
		while (std::cin.fail() || pazymys < 1 || pazymys > 10)
		{
			Netinkamas_Int(pazymys);
		}
		std::cout << "Ar norite ivesti dar viena pazymi? (iveskite T, jei taip , N, jei ne): ";
		std::cin >> TaipNePaz;
		while (TaipNePaz != 'T' && TaipNePaz != 'N')//tikrinama ar ivestas tinkamas simbolis
			Netinkamas_Char(TaipNePaz);
		if (TaipNePaz == 'T')
			std::cout << std::endl << "Iveskite namu darbu pazymi: ";
		S.ND.push_back(pazymys); // pridedamas pazymis i vektoriu

	} while (TaipNePaz == 'T');
}

void GeneruotiNDPazymius(studentas& S)
{
	do
	{
		int pazymys = dis(generuoti); // generuojmas random pazymys
		S.ND.push_back(pazymys); // pridedamas pazymis i vektoriu

		std::cout << std::endl << "Sugeneruotas pazymys: " << pazymys << std::endl;
		std::cout << "Ar norite sugeneruoti dar viena pazymi? (iveskite T, jei taip , N, jei ne): ";
		std::cin >> TaipNePaz;
		while (TaipNePaz != 'T' && TaipNePaz != 'N')//tikrinama ar ivestas tinkamas simbolis
			Netinkamas_Char(TaipNePaz);

	} while (TaipNePaz == 'T');
}

void Ivesti_Varda(studentas& S)
{
	std::cout << std::endl << "Iveskite studento varda: ";
	std::cin >> S.vardas;
	while (!all_of(S.vardas.begin(), S.vardas.end(), ::isalpha))
	{
		Netinkamas_String(S.vardas);
	}

	std::cout << std::endl << "Iveskite studento pavarde: ";
	std::cin >> S.pavarde;
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

std::vector<studentas> Nuskaityti_Is_Failo(const std::string& Failo_Pavadinimas)
{
	// Pradedamas skaiciuti laikas
	auto start = std::chrono::high_resolution_clock::now();
 
	std::ifstream file(Failo_Pavadinimas);
	std::vector<studentas> S;

	if (!file.is_open())
	{
		std::cerr << "Klaida atidarant faila " << Failo_Pavadinimas << std::endl;
		return S;
	}
	// Praleidziama pirma header eilute
	std::string header;
	std::getline(file, header);

	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		studentas student;
		if (!(iss >> student.pavarde >> student.vardas))
		{
			std::cerr << "Klaida nuskaitant nuo failo" << std::endl;
			break;
		}

		int grade;
		while (iss >> grade)
		{
			student.ND.push_back(grade);
		}

		// Patikrina, ar paskutinis pazymys yra egzamino
		if (!student.ND.empty() && student.ND.back() <= 10)
		{
			student.EGZ = student.ND.back();
			student.ND.pop_back();
		}
		else
		{
			std::string nextLine;
			if (std::getline(file, nextLine))
			{
				std::istringstream nextIss(nextLine);
				if (!(nextIss >> student.EGZ))
				{
					std::cerr << "Klaida nuskaitant egzamino bala nuo failo" << std::endl;
					break;
				}
			}
			else
			{
				std::cerr << "Netiketa failo pabaiga" << std::endl;
				break;
			}
		}

		S.push_back(student); // Pridedamas studentas 
	}
	// Baigia skaiciuoti laika
	auto end = std::chrono::high_resolution_clock::now();

	//Apskaicciuoja laika
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);

	std::cout << "Failo nuskaitymas uztruko " << duration.count() << " sekundes(ziu)" << std::endl;
	file.close();
	return S;
}

void Apskaiciuoti_Rezultatus(std::vector<studentas>& S)
{
	for (int i = 0; i < S.size(); i++)
	{
		//apskaiciuojama su vidurkiu
		double suma = std::accumulate(S[i].ND.begin(), S[i].ND.end(), 0);

		S[i].GalutinisV = 0.4 * suma / S[i].ND.size() + 0.6 * S[i].EGZ;

		//apskaiciuojama su mediana
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
				double mediana = (mediana1 + mediana2) * 1.0 / 2.0;
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

bool compareFirstName(const studentas& a, const studentas& b) 
{
	return a.vardas < b.vardas;
}

bool compareLastName(const studentas& a, const studentas& b) 
{
	return a.pavarde < b.pavarde;
}

bool compareExamGrade(const studentas& a, const studentas& b) 
{
	return a.EGZ < b.EGZ;
}

bool compareFinalGradeMedian(const studentas& a, const studentas& b) 
{
	return a.GalutinisM < b.GalutinisM;
}

bool compareFinalGradeAverage(const studentas& a, const studentas& b) 
{
	return a.GalutinisV < b.GalutinisV;
}

void Rusiuoti_Duomenis(std::vector<studentas>& S)
{
	// Rusiavimo pasirinkimai
	std::cout << std::endl << "Rusiuoti pagal:\n 1. Varda\n 2. Pavarde\n 3. Egzamino bala\n 4. Galutini bala, apskaiciuota su mediana\n 5. Galutini bala, apskaiciuota su vidurkiu\n Iveskite pasirinkimo numeri: ";
	int Rusiavimo_Pasirinkimas;
	std::cin >> Rusiavimo_Pasirinkimas;
	// Sorting based on user's choice
	switch (Rusiavimo_Pasirinkimas) {
	case 1:
		std::sort(S.begin(), S.end(), compareFirstName);
		break;
	case 2:
		std::sort(S.begin(), S.end(), compareLastName);
		break;
	case 3:
		std::sort(S.begin(), S.end(), compareExamGrade);
		break;
	case 4:
		std::sort(S.begin(), S.end(), compareFinalGradeMedian);
		break;
	case 5:
		std::sort(S.begin(), S.end(), compareFinalGradeAverage);
		break;
	default:
		std::cout << "Netinkamas pasirinkimas\n";
	}

}

void Spausdinti_Rezultatus(const std::vector<studentas>& S)
{

	std::cout << std::endl << "Kur norite spausdinti resultatus:\n 1. Ekrane \n 2. Faile \"Rezultatai.txt\"\n Iveskite pasirinkimo numeri: ";
	int Spausdinimo_Pasirinkimas;
	std::cin >> Spausdinimo_Pasirinkimas;
	while (Spausdinimo_Pasirinkimas != 1 && Spausdinimo_Pasirinkimas != 2)
	{
		Netinkamas_Int(Spausdinimo_Pasirinkimas);
	}
	if (Spausdinimo_Pasirinkimas == 1)
	{
		std::cout << std::endl;
		for (int i = 0; i < S.size(); i++)
		{
			if (i == 0)
				std::cout << std::setw(5) << "Nr." << std::setw(20) << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << std::endl << std::setfill('-') << std::setw(90) << "-" << std::setfill(' ') << std::endl;

			std::cout << std::setw(5) << i + 1 << std::setw(20) << S[i].pavarde << std::setw(20) << S[i].vardas << std::setw(20) << std::setprecision(3) << S[i].GalutinisV << std::setw(20) << std::setprecision(3) << S[i].GalutinisM << std::endl;


		}
	}

	if (Spausdinimo_Pasirinkimas == 2)
	{
		std::ofstream rezultatu_failas("rezultatai.txt");
		if (!rezultatu_failas.is_open())
		{
			std::cerr << "Klaida atidarant rezultatu faila" << std::endl;
			return;
		}

		for (int i = 0; i < S.size(); i++)
		{
			if (i == 0)
				rezultatu_failas << std::setw(5) << "Nr." << std::setw(20) << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << std::endl << std::setfill('-') << std::setw(90) << "-" << std::setfill(' ') << std::endl;

			rezultatu_failas << std::setw(5) << i + 1 << std::setw(20) << S[i].pavarde << std::setw(20) << S[i].vardas << std::setw(20) << std::setprecision(3) << S[i].GalutinisV << std::setw(20) << std::setprecision(3) << S[i].GalutinisM << std::endl;


		}
		rezultatu_failas.close();
		std::cout << std::endl << "Rezultatai atspausdinti" << std::endl;
	}

}

int main()
{
	std::cout << "Pasirinkite veiksma:\n 1. Suvesti visus studentu duomenis\n 2. Sugeneruoti tik studentu pazymius\n 3. Sugeneruoti studentu vardus ir pazymius\n 4. Nuskaityti studentu duomenis nuo failo\n 5. Baigti darba\n Iveskite pasirinkimo numeri: ";
	int Pasirinkimas;
	std::cin >> Pasirinkimas;
	while (Pasirinkimas != 1 && Pasirinkimas != 2 && Pasirinkimas != 3 && Pasirinkimas != 4 && Pasirinkimas != 5)
	{
		Netinkamas_Int(Pasirinkimas);
	}

	if (Pasirinkimas == 1)
	{
		std::vector<studentas> S;
		studentas naujas;
		do
		{
			Ivesti_Varda(naujas);

			Ivesti_Pazymius(naujas);

			std::cout << std::endl << "Iveskite egzamino pazymi: ";
			std::cin >> naujas.EGZ;
			while (std::cin.fail() || naujas.EGZ < 1 || naujas.EGZ > 10)
			{
				Netinkamas_Int(naujas.EGZ);
			}

			S.push_back(naujas);// pridedamas studentas i vektoriu

			std::cout << std::endl << "Ar norite ivesti dar viena studenta? (T jei taip , N - ne): ";
			std::cin >> TaipNe;
			while (TaipNe != 'T' && TaipNe != 'N')
			{
				Netinkamas_Char(TaipNe);
			}

		} while (TaipNe == 'T');

		Apskaiciuoti_Rezultatus(S);
		Rusiuoti_Duomenis(S);
		Spausdinti_Rezultatus(S);
	}

	if (Pasirinkimas == 2)
	{
		std::vector<studentas> S;
		studentas naujas;
		do
		{
			Ivesti_Varda(naujas);

			GeneruotiNDPazymius(naujas);

			naujas.EGZ = dis(generuoti);
			std::cout << "Sugeneruotas egzamino balas: " << naujas.EGZ << std::endl;

			std::cout << std::endl << std::endl << "Ar norite ivesti dar viena studenta? (T jei taip , N - ne): ";
			std::cin >> TaipNe;
			while (TaipNe != 'T' && TaipNe != 'N')
			{
				Netinkamas_Char(TaipNe);
			}
			S.push_back(naujas); // pridedamas studentas i vektoriu
		} while (TaipNe == 'T');

		Apskaiciuoti_Rezultatus(S);
		Rusiuoti_Duomenis(S);
		Spausdinti_Rezultatus(S);
	}

	if (Pasirinkimas == 3)
	{
		std::vector<studentas> S;
		studentas naujas;
		do
		{
			int lytis = dis_lytis(generuoti);

			if (lytis == 0)
				Generuoti_Varda_V(naujas);
			else
				Generuoti_Varda_M(naujas);

			std::cout << std::endl << "Sugeneruotas vardas ir pavarde: " << naujas.vardas << " " << naujas.pavarde << std::endl;

			GeneruotiNDPazymius(naujas);

			naujas.EGZ = dis(generuoti);
			std::cout << "Sugeneruotas egzamino balas: " << naujas.EGZ << std::endl;

			std::cout << std::endl << std::endl << "Ar norite sugeneruoti dar viena studenta? (T jei taip , N - ne): ";
			std::cin >> TaipNe;
			while (TaipNe != 'T' && TaipNe != 'N')
			{
				Netinkamas_Char(TaipNe);
			}
			S.push_back(naujas); // pridedamas studentas i vektoriu
		} while (TaipNe == 'T');

		Apskaiciuoti_Rezultatus(S);
		Rusiuoti_Duomenis(S);
		Spausdinti_Rezultatus(S);
	}

	if (Pasirinkimas == 4)
	{
		std::vector<studentas> S;
		std::cout << std::endl << "Pasirinkite, is kurio failo norite nuskaityti duomeniis:\n 1. \"kursiokai.txt\" \n 2. \"studentai10000.txt\"\n 3. \"studentai100000.txt\"\n 4. \"studentai1000000.txt\"\n Iveskite pasirinkimo numeri: ";
		int Failo_Pasirinkimas;
		std::cin >> Failo_Pasirinkimas;
		while (Failo_Pasirinkimas != 1 && Failo_Pasirinkimas != 2 && Failo_Pasirinkimas != 3 && Failo_Pasirinkimas != 4)
		{
			Netinkamas_Int(Failo_Pasirinkimas);
		}
		if (Failo_Pasirinkimas == 1) S = Nuskaityti_Is_Failo("kursiokai.txt");
		if (Failo_Pasirinkimas == 2) S = Nuskaityti_Is_Failo("studentai10000.txt");
		if (Failo_Pasirinkimas == 3) S = Nuskaityti_Is_Failo("studentai100000.txt ");
		if (Failo_Pasirinkimas == 4) S = Nuskaityti_Is_Failo("studentai1000000.txt ");
		Apskaiciuoti_Rezultatus(S);
		Rusiuoti_Duomenis(S);
		Spausdinti_Rezultatus(S);
	}
	if (Pasirinkimas == 5)
		std::cout << std::endl << "Darbas baigtas";

	return 0;
}
