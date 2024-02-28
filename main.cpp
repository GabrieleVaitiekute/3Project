#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <limits>
#include <filesystem>
#include "Studentai.h"
#include "Ivedimas.h"
#include "Generavimas.h"
#include "Netinkama_Ivestis.h"
#include "Nuskaitymas_Failo.h"
#include "Rezultatu_Apskaiciavimas.h"
#include "Duomenu_Rusiavimas.h"
#include "Rezultatu_Spausdinimas.h"

char TaipNe;

int main()
{
	int Pasirinkimas;
	do
	{
		std::cout << "Pasirinkite veiksma:\n 1. Suvesti visus studentu duomenis\n 2. Sugeneruoti tik studentu pazymius\n 3. Sugeneruoti studentu vardus ir pazymius\n 4. Nuskaityti studentu duomenis nuo failo\n 5. Baigti darba\n Iveskite pasirinkimo numeri: ";

		while (true)
		{
			try
			{
				std::cin >> Pasirinkimas;
				if (std::cin.fail() || std::cin.peek() != '\n' || Pasirinkimas < 1 || Pasirinkimas > 5)
				{
					throw std::invalid_argument("Netinkama ivestis. Iveskite sveikaji skaiciu nuo 1 iki 5. ");
				}
				break;
			}
			catch (const std::invalid_argument& p)
			{
				Netinkamas_Ivestis(p.what());
			}
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
				while (true)
				{
					try
					{
						std::cin >> naujas.EGZ;
						if (std::cin.fail() || std::cin.peek() != '\n' || naujas.EGZ < 1 || naujas.EGZ > 10)
						{
							throw std::invalid_argument("Netinkama ivestis. Iveskite sveikaji skaiciu nuo 1 iki 10. ");
						}
						break;
					}
					catch (const std::invalid_argument& e)
					{
						Netinkamas_Ivestis(e.what());
					}
				}



				S.push_back(naujas);// pridedamas studentas i vektoriu
				std::cout << std::endl << "Ar norite ivesti " << S.size() + 1 << " studenta ? (T jei taip, N - ne) : ";
				while (true)
				{
					try
					{
						std::cin >> TaipNe;
						if ((std::cin.fail() || std::cin.peek() != '\n') || (TaipNe != 'T' && TaipNe != 'N'))
						{
							throw std::invalid_argument("Netinkama ivestis. Iveskite T arba N.  ");
						}
						break;
					}
					catch (const std::invalid_argument& tp)
					{
						Netinkamas_Ivestis(tp.what());
					}
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

				std::cout << std::endl << "Kiek namu darbu pazymiu norite sugeneruoti: ";
				int ND_kiekis;
				while (true)
				{
					try
					{
						std::cin >> ND_kiekis;
						if (std::cin.fail() || std::cin.peek() != '\n')
						{
							throw std::invalid_argument("Netinkama ivestis. Iveskite sveikaji skaiciu. ");
						}
						break;
					}
					catch (const std::invalid_argument& ndk)
					{
						Netinkamas_Ivestis(ndk.what());
					}
				}


				GeneruotiNDPazymius(naujas, ND_kiekis);

				S.push_back(naujas); // pridedamas studentas i vektoriu
				std::cout << std::endl << "Ar norite ivesti " << S.size() + 1 << " studenta ? (T jei taip, N - ne) : ";
				while (true)
				{
					try
					{
						std::cin >> TaipNe;
						if ((std::cin.fail() || std::cin.peek() != '\n') || (TaipNe != 'T' && TaipNe != 'N'))
						{
							throw std::invalid_argument("Netinkama ivestis. Iveskite T arba N.  ");
						}
						break;
					}
					catch (const std::invalid_argument& tp)
					{
						Netinkamas_Ivestis(tp.what());
					}
				}


			} while (TaipNe == 'T');

			Apskaiciuoti_Rezultatus(S);
			Rusiuoti_Duomenis(S);
			Spausdinti_Rezultatus(S);
		}

		if (Pasirinkimas == 3)
		{
			std::vector<studentas> S;
			studentas naujas;

			std::cout << std::endl << "Kiek studentu norite sugeneruoti: ";
			int Studentu_kiekis;
			std::cin >> Studentu_kiekis;
			while (true)
			{
				try
				{
					std::cin >> Studentu_kiekis;
					if (std::cin.fail() || std::cin.peek() != '\n')
					{
						throw std::invalid_argument("Netinkama ivestis. Iveskite sveikaji skaiciu. ");
					}
					break;
				}
				catch (const std::invalid_argument& sk)
				{
					Netinkamas_Ivestis(sk.what());


				}

			}

			std::cout << std::endl << "Kiek namu darbu pazymiu norite sugeneruoti: ";
			int ND_kiekis;
			std::cin >> ND_kiekis;
			while (true)
			{
				try
				{
					std::cin >> ND_kiekis;
					if (std::cin.fail() || std::cin.peek() != '\n')
					{
						throw std::invalid_argument("Netinkama ivestis. Iveskite sveikaji skaiciu. ");
					}
					break;
				}
				catch (const std::invalid_argument& ndk)
				{
					Netinkamas_Ivestis(ndk.what());


				}
			}


			for (int i = 0; i < Studentu_kiekis; ++i)
			{

				GeneruotiVardus(naujas);

				GeneruotiNDPazymius(naujas, ND_kiekis);


				S.push_back(naujas); // pridedamas studentas i vektoriu
			}

			Apskaiciuoti_Rezultatus(S);
			Rusiuoti_Duomenis(S);
			Spausdinti_Rezultatus(S);
		}

		if (Pasirinkimas == 4)
		{
			namespace fs = std::filesystem;
			std::vector<studentas> S;
			int Failo_Pasirinkimas;
			std::string Failo_Vieta;

			while (true)
			{
				// Parinkimo meniu ir failo pasirinkimas
				std::cout << "\nPasirinkite, is kurio failo norite nuskaityti duomeniis:\n 1. kursiokai.txt \n 2. studentai10000.txt\n 3. studentai100000.txt\n 4. studentai1000000.txt\n Iveskite pasirinkimo numeri: ";

				std::cin >> Failo_Pasirinkimas;
				// Tikrinimas ar įvestis yra tinkama
				if (std::cin.fail() || std::cin.peek() != '\n' || Failo_Pasirinkimas < 1 || Failo_Pasirinkimas > 4)
				{
					throw std::invalid_argument("Netinkama ivestis. Iveskite sveikaji skaiciu nuo 1 iki 4. ");
				}
				// Nuskaitomas pasirinkto failo kelias
				switch (Failo_Pasirinkimas)
				{
				case 1:
					Failo_Vieta = R"(C:\Users\Gabrielė\Desktop\O.P\v03\kursiokai.txt)";
					break;
				case 2:
					Failo_Vieta = R"(C:\Users\Gabrielė\Desktop\O.P\v03\studentai10000.txt)";
					break;
				case 3:
					Failo_Vieta = R"(C:\Users\Gabrielė\Desktop\O.P\v03\studentai100000.txt)";
					break;
				case 4:
					Failo_Vieta = R"(C:\Users\Gabrielė\Desktop\O.P\v03\studentai1000000.txt)";
					break;
				}
				// Tikrinimas ar pasirinktas failas egzistuoja
				if (!fs::exists(Failo_Vieta))
				{
					Netinkamas_Ivestis("Pasirinktas failas neegzistuoja. Pasirinkite kita faila. ");
					std::cout << "\n";
					continue;

				}
				// Nuskaitymas duomenų iš pasirinkto failo
				S = Nuskaityti_Is_Failo(Failo_Vieta);
				Apskaiciuoti_Rezultatus(S);
				Rusiuoti_Duomenis(S);
				Spausdinti_Rezultatus(S);
			}
		}
		if (Pasirinkimas == 5)
			std::cout << "\n" << "Darbas baigtas";

		std::cout << "\n";
	} while (Pasirinkimas != 5);

	return 0;
}
