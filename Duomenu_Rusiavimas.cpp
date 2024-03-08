#include "Studentai.h"
#include "Netinkama_Ivestis.h"
#include "Duomenu_Rusiavimas.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric> 
#include <vector>


bool VarduRusiavimas(const studentas& a, const studentas& b)
{
	return a.vardas < b.vardas;
}

bool PavardziuRusiavimas(const studentas& a, const studentas& b)
{
	return a.pavarde < b.pavarde;
}

bool MedianuRusiavimas(const studentas& a, const studentas& b)
{
	return a.GalutinisM < b.GalutinisM;
}

bool VidurkiuRusiavimas(const studentas& a, const studentas& b)
{
	return a.GalutinisV < b.GalutinisV;
}

void Rusiuoti_Duomenis(std::vector<studentas>& N, std::vector<studentas>& G)
{
	// Rusiavimo pasirinkimai
	std::cout << std::endl << "Rusiuoti pagal:\n 1. Varda\n 2. Pavarde\n 3. Galutini bala, apskaiciuota su mediana\n 4. Galutini bala, apskaiciuota su vidurkiu\n Iveskite pasirinkimo numeri: ";
	int Rusiavimo_Pasirinkimas;
	while (true)
	{
		try
		{
			std::cin >> Rusiavimo_Pasirinkimas;

			if (std::cin.fail() || std::cin.peek() != '\n')
			{
				throw std::invalid_argument("Netinkama ivestis. Iveskite sveikaji skaiciu nuo 1 iki 4. ");
			}
			break;
		}
		catch (const std::invalid_argument& rp)
		{
			Netinkamas_Ivestis(rp.what());


		}

	}

	switch (Rusiavimo_Pasirinkimas)
	{
	case 1:
		std::sort(N.begin(), N.end(), VarduRusiavimas);
		std::sort(G.begin(), G.end(), VarduRusiavimas);
		break;
	case 2:
		std::sort(N.begin(), N.end(), PavardziuRusiavimas);
		std::sort(G.begin(), G.end(), PavardziuRusiavimas);
		break;
	case 3:
		std::sort(N.begin(), N.end(), MedianuRusiavimas);
		std::sort(G.begin(), G.end(), MedianuRusiavimas);
		break;
	case 4:
		std::sort(N.begin(), N.end(), VidurkiuRusiavimas);
		std::sort(G.begin(), G.end(), VidurkiuRusiavimas);
		break;
	}

}
