#include "Generavimas.h"
#include "Studentai.h"
#include <random>

std::random_device rd;
std::mt19937 generuoti(rd());
std::uniform_int_distribution<int> nd_kiekis(5, 20);
std::uniform_int_distribution<int> dis(1, 10);
std::uniform_int_distribution<int> dis_lytis(0, 1);

std::vector<std::string> vardaiV = { "Jonas", "Petras", "Antanas", "Juozas", "Kazys", "Darius", "Linas", "Tomas", "Giedrius", "Marius" };
std::vector<std::string> vardaiM = { "Ona", "Maryte", "Aldona", "Gabija", "Dalia", "Danute", "Asta", "Rasa", "Nijole", "Aiste", "Gabriele" };
std::vector<std::string> pavardesV = { "Jonaitis", "Petraitis", "Antanaitis", "Juozaitis", "Kaziukaitis", "Dariukaitis", "Linaitis", "Tomaitis", "Giedraitis", "Mariukaitis" };
std::vector<std::string> pavardesM = { "Jonaite", "Petraityte", "Antanaite", "Juozaite", "Kaziukaite", "Dariukaite", "Linaite", "Tomaite", "Giedraite", "Mariukaite", "Antaniene", "Jonaitiene", "Antaniene" };

int lytis = dis_lytis(generuoti);

void GeneruotiNDPazymius(studentas& S, int ND_kiekis)
{
	for (int j = 0; j < ND_kiekis; j++)
	{
		int pazymys = dis(generuoti); // generuojmas random pazymys
		S.ND.push_back(pazymys); // pridedamas pazymis i vektoriu
	}

	S.EGZ = dis(generuoti);
}

void GeneruotiVardus(studentas& S)
{
	int lytis = dis_lytis(generuoti);

	if (lytis == 0)
	{
		S.vardas = vardaiV[dis(generuoti) % 10];
		S.pavarde = pavardesV[dis(generuoti) % 10];
	}

	else
	{
		S.vardas = vardaiM[dis(generuoti) % 10];
		S.pavarde = pavardesM[dis(generuoti) % 10];
	}

}

void GeneruotiFailus(int reserveDydis, std::string& G_Failo_Vieta)
{

	// Pradedamas skaiciuti laikas
	auto start = std::chrono::high_resolution_clock::now();
	
	int nd_kiekis_gen = nd_kiekis(generuoti);

	std::ofstream GFailas(G_Failo_Vieta);

	if (!GFailas.is_open())
	{
		std::cout << "Nepavyko atidaryti failo " << G_Failo_Vieta << std::endl;
		return;
	}
	//headline spasudinimas
	GFailas << std::left << std::setw(20) << "Pavarde" << std::setw(20) << "Vardas";

	for (int i = 0; i < nd_kiekis_gen; i++)
	{
		GFailas << std::left << std::setw(7) << "ND" + std::to_string(i + 1);
	}

	GFailas << std::setw(5) << "Egz." << std::endl;

	//studentu duomenu spasudiniams
	for (int i = 0; i < reserveDydis; ++i)
	{
		GFailas << std::left << std::setw(20) << "Pavarde" + std::to_string(i + 1) << std::left << std::setw(20) << "Vardas" + std::to_string(i + 1);
		for (int j = 0; j < nd_kiekis_gen; j++)
		{
			GFailas << std::setw(7) << dis(generuoti);
		}
		GFailas << std::setw(7) << dis(generuoti);
		GFailas << "\n";
	}

	GFailas.close();
	// Baigia skaiciuoti laika
	auto end = std::chrono::high_resolution_clock::now();

	//Apskaiciuoja laika
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);

	std::cout << "\nFailo kurimas uztruko " << duration.count() << " sek." << std::endl;

}
