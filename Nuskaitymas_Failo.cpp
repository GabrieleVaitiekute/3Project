#include "Nuskaitymas_Failo.h"
#include "Studentai.h"
#include <chrono> 
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>


std::vector<studentas> Nuskaityti_Is_Failo(const std::string& Failo_Pavadinimas, int reserveDydis)
{
	// Pradedamas skaiciuti laikas
	auto start = std::chrono::high_resolution_clock::now();

	// Open the file in binary mode
	std::ifstream file(Failo_Pavadinimas);

	
	std::vector<studentas> S;
	S.reserve( reserveDydis);

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


		S.push_back(student); // Pridedamas studentas 
	}

	
	// Baigia skaiciuoti laika
	auto end = std::chrono::high_resolution_clock::now();

	//Apskaiciuoja laika
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);

	std::cout << "\nFailo nuskaitymas uztruko " << duration.count() << " sekundes(e)" << std::endl;
	file.close();
	return S;
}
