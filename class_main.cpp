#include "class_studentai.h"
#include "class_funkcijos.h"

char TaipNe;
namespace fs = std::filesystem;
int main()
{
	int Pasirinkimas, Strategija;
	std::vector<studentas> S;
	std::vector<studentas> N;//nuskriaustieji
	std::vector<studentas> G;//galvociai

	std::cout << "Pasirinkite veiksma:\n 1. Suvesti visus studentu duomenis\n 2. Sugeneruoti tik studentu pazymius\n 3. Sugeneruoti studentu vardus ir pazymius\n 4. Nuskaityti studentu duomenis nuo failo\n 5. Generuoti failus\n 6. Baigti darba\n 7. Testuoti \n Iveskite pasirinkimo numeri: ";

	while (true)
	{
		try
		{
			std::cin >> Pasirinkimas;
			if (std::cin.fail() || std::cin.peek() != '\n' || Pasirinkimas < 1 || Pasirinkimas > 7)
			{
				throw std::invalid_argument("Netinkama ivestis. Iveskite sveikaji skaiciu nuo 1 iki 7. ");
			}
			break;
		}
		catch (const std::invalid_argument& p)
		{
			Netinkamas_Ivestis(p.what());
		}
	}
	if (Pasirinkimas >= 1 && Pasirinkimas <= 5)
	{
		std::cout << "\nKuria strategija norite naudoti: 1, 2, 3: ";
		while (true)
		{
			try
			{
				std::cin >> Strategija;
				if (std::cin.fail() || std::cin.peek() != '\n' || Strategija < 1 || Strategija > 3)
				{
					throw std::invalid_argument("Netinkama ivestis. Iveskite skaiciu nuo 1 iki 3: ");
				}
				break;
			}
			catch (const std::invalid_argument& s)
			{
				Netinkamas_Ivestis(s.what());
			}
		}

		std::cout << std::endl << "VECTOR " << Strategija << " STRATEGIJA\n\n";

	}

	if (Pasirinkimas == 1)
	{
		studentas naujas;
		do
		{
			Ivesti_Varda(naujas);

			Ivesti_Pazymius(naujas);

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

		Rikiuoti_Duomenis(S);
		Skirstyti_Studentus(S, N, G, Strategija);

		if (Strategija == 1)
			Spausdinti_Rezultatus(N, G);

		if (Strategija == 2)
			Spausdinti_Rezultatus(N, S);

		if (Strategija == 3)
			Spausdinti_Rezultatus(N, S);
	}

	if (Pasirinkimas == 2)
	{

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

		Rikiuoti_Duomenis(S);
		Skirstyti_Studentus(S, N, G, Strategija);

		if (Strategija == 1)
			Spausdinti_Rezultatus(N, G);

		if (Strategija == 2)
			Spausdinti_Rezultatus(N, S);

		if (Strategija == 3)
			Spausdinti_Rezultatus(N, S);
	}

	if (Pasirinkimas == 3)
	{

		studentas naujas;

		std::cout << std::endl << "Kiek studentu norite sugeneruoti: ";
		int Studentu_kiekis;
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

		Rikiuoti_Duomenis(S);

		Skirstyti_Studentus(S, N, G, Strategija);

		if (Strategija == 1)
			Spausdinti_Rezultatus(N, G);

		if (Strategija == 2)
			Spausdinti_Rezultatus(N, S);

		if (Strategija == 3)
			Spausdinti_Rezultatus(N, S);
	}

	if (Pasirinkimas == 4)
	{
		int Failo_Pasirinkimas;
		std::string Failas;

		while (true)
		{
			// Parinkimo meniu ir failo pasirinkimas
			std::cout << "\nPasirinkite, is kurio failo norite nuskaityti duomenis:\n 1. 1 000\n 2. 10 000\n 3. 100 000\n 4. 1 000 000\n 5. 10 000 000 \n Iveskite pasirinkimo numeri: ";

			std::cin >> Failo_Pasirinkimas;
			// Tikrinimas ar įvestis yra tinkama
			if (std::cin.fail() || std::cin.peek() != '\n' || Failo_Pasirinkimas < 1 || Failo_Pasirinkimas > 5)
			{
				throw std::invalid_argument("Netinkama ivestis. Iveskite sveikaji skaiciu nuo 1 iki 5. ");
			}
			int reserveDydis = 0;
			// Nuskaitomas pasirinkto failo kelias
			switch (Failo_Pasirinkimas)
			{
			case 1:
				Failas = "Studentai1000.txt";
				reserveDydis = 1000;
				break;
			case 2:
				Failas = "Studentai10000.txt";
				reserveDydis = 10000;
				break;
			case 3:
				Failas = "Studentai100000.txt";
				reserveDydis = 100000;
				break;
			case 4:
				Failas = "Studentai1000000.txt";
				reserveDydis = 1000000;
				break;

			case 5:
				Failas = "Studentai10000000.txt";
				reserveDydis = 10000000;
				break;

			}
			// Tikrinimas ar pasirinktas failas egzistuoja
			if (!fs::exists(Failas))
			{
				Netinkamas_Ivestis("Pasirinktas failas neegzistuoja. Pasirinkite kita faila. ");
				std::cout << "\n";
				continue;

			}
			// Nuskaitymas duomenų iš pasirinkto failo
			S = Nuskaityti_Is_Failo(Failas, reserveDydis);
			Rikiuoti_Duomenis(S);
			Skirstyti_Studentus(S, N, G, Strategija);

			if (Strategija == 1)
				Spausdinti_Rezultatus(N, G);

			if (Strategija == 2)
				Spausdinti_Rezultatus(N, S);

			if (Strategija == 3)
				Spausdinti_Rezultatus(N, S);
			break; // Išeiti iš ciklo, kai buna pasirinktas tinkamas failas 
		}

	}

	if (Pasirinkimas == 5)
	{
		std::cout << "Pasirinkite kiek studentu norite sugeneruoti:\n 1. 1 000\n 2. 10 000\n 3. 100 000\n 4. 1 000 000\n 5. 10 000 000 \n Iveskite pasirinkimo numeri: ";

		std::string G_Failas;
		int G_Failo_Pasirinkimas;
		int reserveDydis = 0;
		while (true)
		{
			try
			{
				std::cin >> G_Failo_Pasirinkimas;
				if (std::cin.fail() || std::cin.peek() != '\n' || G_Failo_Pasirinkimas < 1 || G_Failo_Pasirinkimas > 5)
				{
					throw std::invalid_argument("Netinkama ivestis. Iveskite sveikaji skaiciu nuo 1 iki 5. ");
				}
				break;
			}
			catch (const std::invalid_argument& pfg)
			{
				Netinkamas_Ivestis(pfg.what());
			}
		}


		switch (G_Failo_Pasirinkimas)
		{
		case 1:
			G_Failas = "Studentai1000.txt";
			reserveDydis = 1000;
			break;
		case 2:
			G_Failas = "Studentai10000.txt";
			reserveDydis = 10000;
			break;
		case 3:
			G_Failas = "Studentai100000.txt";
			reserveDydis = 100000;
			break;
		case 4:
			G_Failas = "Studentai1000000.txt";
			reserveDydis = 1000000;
			break;

		case 5:
			G_Failas = "Studentai10000000.txt";
			reserveDydis = 10000000;
			break;

		}

		//jei failas jau egzistuoja, tiesiog nuskaitoma nuo jo
		if (fs::exists(G_Failas))
		{
			std::cout << "Pasirinktas failas jau egzistuoja, dabar nuo jo bus nuskaitoma";
			S = Nuskaityti_Is_Failo(G_Failas, reserveDydis);
		}
		else //jei failas neegzistuoja, tai ji sugeneruoja ir tada nuskaito
		{
			std::cout << "Pasirinktas failas neegzistuoja, jis generuojamas";
			GeneruotiFailus(reserveDydis, G_Failas);
			S = Nuskaityti_Is_Failo(G_Failas, reserveDydis);
		}
		Rikiuoti_Duomenis(S);
		Skirstyti_Studentus(S, N, G, Strategija);

		if (Strategija == 1)
			Spausdinti_Rezultatus(N, G);

		if (Strategija == 2)
			Spausdinti_Rezultatus(N, S);

		if (Strategija == 3)
			Spausdinti_Rezultatus(N, S);
	}


	if (Pasirinkimas == 6)
		std::cout << "\n" << "Darbas baigtas";

	if (Pasirinkimas == 7)
		Testavimas();



	std::cout << "\n";
	return 0;
}
