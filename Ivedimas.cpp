#include "Ivedimas.h"
#include "Netinkama_Ivestis.h"
#include "Studentai.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

char TaipNePaz;

void Ivesti_Pazymius(studentas& S)
{
	S.ND.clear();
	std::cout << "\nIveskite namu darbu pazymi: ";
	int pazymys;
	do
	{
		while (true)
		{
			try
			{

				std::cin >> pazymys;
				if (std::cin.fail() || std::cin.peek() != '\n' || pazymys < 1 || pazymys > 10)
				{
					throw std::invalid_argument("Netinkama ivestis. Iveskite sveikaji skaiciu nuo 1 iki 10. ");
				}
				break;
			}


			catch (const std::invalid_argument& paz)
			{
				Netinkamas_Ivestis(paz.what());
			}
		}
		S.ND.push_back(pazymys); // pridedamas pazymis i vektoriu


		std::cout << "Ar norite ivesti " << S.ND.size() + 1 << " pazymi? (iveskite T, jei taip , N, jei ne): ";
		while (true)
		{
			try
			{
				std::cin >> TaipNePaz;
				if ((std::cin.fail() || std::cin.peek() != '\n') || (TaipNePaz != 'T' && TaipNePaz != 'N'))
				{
					throw std::invalid_argument("Netinkama ivestis. Iveskite T arba N.  ");
				}

				break;
			}
			catch (const std::invalid_argument& tpp)
			{
				Netinkamas_Ivestis(tpp.what());
			}
		}

		if (TaipNePaz == 'T')
			std::cout << std::endl << "Iveskite namu darbu pazymi: ";

	} while (TaipNePaz == 'T');
}

void Ivesti_Varda(studentas& S)
{
	std::cout << std::endl << "Iveskite studento varda: ";
	while (true)
	{
		try
		{
			std::cin >> S.vardas;
			if (std::cin.fail() || std::cin.peek() != '\n' || !all_of(S.vardas.begin(), S.vardas.end(), ::isalpha))
			{
				throw std::invalid_argument("Netinkama ivestis. Iveskite varda, sudaryta tik is raidziu. ");
			}

			break;
		}
		catch (const std::invalid_argument& v)
		{
			Netinkamas_Ivestis(v.what());
		}
	}



	std::cout << std::endl << "Iveskite studento pavarde: ";

	while (true)
	{
		try
		{
			std::cin >> S.pavarde;
			if (std::cin.fail() || std::cin.peek() != '\n' || !all_of(S.pavarde.begin(), S.pavarde.end(), ::isalpha))
			{
				throw std::invalid_argument("Netinkama ivestis. Iveskite pavarde, sudaryta tik is raidziu. ");
			}

			break;
		}
		catch (const std::invalid_argument& pv)
		{
			Netinkamas_Ivestis(pv.what());
		}
	}

}
