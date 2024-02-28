#include "Rezultatu_Spausdinimas.h"
#include "Studentai.h"
#include "Netinkama_Ivestis.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>

void Spausdinti_Rezultatus(const std::vector<studentas>& S)
{

	std::cout << "\nKur norite spausdinti resultatus:\n 1. Ekrane \n 2. Faile \"rezultatai.txt\"\n Iveskite pasirinkimo numeri: ";
	int Spausdinimo_Pasirinkimas;
	while (true)
	{
		try
		{
			std::cin >> Spausdinimo_Pasirinkimas;

			if (std::cin.fail() || std::cin.peek() != '\n' || Spausdinimo_Pasirinkimas < 1 || Spausdinimo_Pasirinkimas > 2)
			{
				throw std::invalid_argument("Netinkama ivestis. Iveskite 1 arba 2. ");
			}
			break;
		}
		catch (const std::invalid_argument& sp)
		{
			Netinkamas_Ivestis(sp.what());
		}

	}

	if (Spausdinimo_Pasirinkimas == 1)
	{
		std::cout << "\n";
		for (int i = 0; i < S.size(); i++)
		{
			if (i == 0)
				std::cout << std::setw(7) << "Nr." << std::setw(20) << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << std::endl << std::setfill('-') << std::setw(90) << "-" << std::setfill(' ') << "\n";

			std::cout << std::setw(7) << i + 1 << std::setw(20) << S[i].pavarde << std::setw(20) << S[i].vardas << std::setw(20) << std::setprecision(3) << S[i].GalutinisV << std::setw(20) << std::setprecision(3) << S[i].GalutinisM << "\n";


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
				rezultatu_failas << std::setw(7) << "Nr." << std::setw(20) << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << std::endl << std::setfill('-') << std::setw(90) << "-" << std::setfill(' ') << std::endl;

			rezultatu_failas << std::setw(7) << i + 1 << std::setw(20) << S[i].pavarde << std::setw(20) << S[i].vardas << std::setw(20) << std::setprecision(3) << S[i].GalutinisV << std::setw(20) << std::setprecision(3) << S[i].GalutinisM << std::endl;


		}
		rezultatu_failas.close();
		std::cout << std::endl << "Rezultatai atspausdinti" << std::endl;
	}

}
