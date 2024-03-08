#include "Generavimas.h"
#include "Studentai.h"
#include <random>

std::random_device rd;
std::mt19937 generuoti(rd());
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

void GeneruotiFailus(int reserveDydis, std::string failoPav)
{
	// Pradedamas skaiciuti laikas
	auto start = std::chrono::high_resolution_clock::now();

        std::ofstream GFailas (failoPav);

        if (!GFailas.is_open())
        {
            std::cout << "Nepavyko atidaryti failo " << failoPav << std::endl;
            return;
        }
		
        GFailas << std::setw(20) << "Pavarde" << std::setw(20) << std::setw(5) << "Vardas" << std::setw(5) << "ND1" << std::setw(5) << "ND2" << std::setw(5) << "ND3" << std::setw(5) << "ND4" << std::setw(5) << "ND5" << std::setw(5) << "ND6" << std::setw(5) << "ND7" << std::setw(5) << "ND8" << std::setw(5) << "ND9" << std::setw(5) << "ND10" << std::setw(5) << "Egz."  << std::endl;

        for (int i = 0; i < reserveDydis; ++i)
        {
			GFailas << std::setw(20)<< "Vardas" << i + 1 << std::setw(20) << " Pavarde" << i + 1 ;
			for (int j = 0; j < 10; j++)
			{
				GFailas  << std::setw(5)<< dis(generuoti) ;
			}
			GFailas << std::setw(5) << dis(generuoti)  ;
			GFailas << "\n";
        }

        GFailas.close();
		// Baigia skaiciuoti laika
		auto end = std::chrono::high_resolution_clock::now();

		//Apskaiciuoja laika
		auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);

		std::cout << "\nFailo generavimas uztruko " << duration.count() << " sekundes(e)" << std::endl;

}
