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