#include "Rezultatu_Spausdinimas.h"
#include "Studentai.h"
#include "Netinkama_Ivestis.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>

void Spausdinti_Rezultatus(const std::vector<studentas>& N, const std::vector<studentas>& G)
{

		std::ofstream Galvociu_failas("Galvociai.txt");
		if (!Galvociu_failas.is_open())
		{
			std::cerr << "Klaida atidarant rezultatu faila" << std::endl;
			return;
		}

		for (int i = 0; i < G.size(); i++)
		{
			if (i == 0)
				Galvociu_failas << std::setw(7) << "Nr." << std::setw(20) << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << std::endl << std::setfill('-') << std::setw(90) << "-" << std::setfill(' ') << std::endl;

			Galvociu_failas << std::setw(7) << i + 1 << std::setw(20) << G[i].pavarde << std::setw(20) << G[i].vardas << std::setw(20) << std::setprecision(3) << G[i].GalutinisV << std::setw(20) << std::setprecision(3) << G[i].GalutinisM << std::endl;


		}
		Galvociu_failas.close();

		std::ofstream Nepazangiuju_failas("Nepazangus.txt");
		if (!Nepazangiuju_failas.is_open())
		{
			std::cerr << "Klaida atidarant rezultatu faila" << std::endl;
			return;
		}

		for (int i = 0; i < N.size(); i++)
		{
			if (i == 0)
				Nepazangiuju_failas << std::setw(7) << "Nr." << std::setw(20) << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << std::endl << std::setfill('-') << std::setw(90) << "-" << std::setfill(' ') << std::endl;

			Nepazangiuju_failas << std::setw(7) << i + 1 << std::setw(20) << N[i].pavarde << std::setw(20) << N[i].vardas << std::setw(20) << std::setprecision(3) << N[i].GalutinisV << std::setw(20) << std::setprecision(3) << N[i].GalutinisM << std::endl;


		}
		Nepazangiuju_failas.close();

		std::cout << std::endl << "Rezultatai atspausdinti" << std::endl;
	
}
