#include "Rezultatu_Apskaiciavimas.h"
#include "Studentai.h"

void Apskaiciuoti_Rezultatus(std::vector<studentas>& S, std::vector<studentas>& N, std::vector<studentas>& G)
{
	std::cout << "\nAr norite studentus surusiuoti pagal mediana ar vidurki? M jei mediana, V jei vidurki: ";
	char RusiavimoPasirinkimas;
	while (true)
	{
		try
		{
			std::cin >> RusiavimoPasirinkimas;
			if (std::cin.fail() || std::cin.peek() != '\n' || (RusiavimoPasirinkimas != 'V' && RusiavimoPasirinkimas != 'M'))
			{
				throw std::invalid_argument("Netinkama ivestis. Iveskite M arba V: ");
			}
			break;
		}
		catch (const std::invalid_argument& rp)
		{
			Netinkamas_Ivestis(rp.what());
		}
	}
	// Pradedamas skaiciuti laikas
	auto RusavimoPradzia = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < S.size(); i++)
	{
		//apskaiciuojama su vidurkiu
		double suma = std::accumulate(S[i].ND.begin(), S[i].ND.end(), 0);

		S[i].GalutinisV = 0.4 * suma / S[i].ND.size() + 0.6 * S[i].EGZ;

		//apskaiciuojama su mediana
		if (S[i].ND.size() == 1)
		{
			S[i].GalutinisM = 0.4 * S[i].ND[0] + 0.6 * S[i].EGZ;
		}
		if (S[i].ND.size() > 1)
		{
			std::sort(S[i].ND.begin(), S[i].ND.end());
			int pazymiu_kiekis = S[i].ND.size();

			if (pazymiu_kiekis % 2 == 0)
			{
				int mediana1 = S[i].ND[pazymiu_kiekis / 2 - 1];
				int mediana2 = S[i].ND[pazymiu_kiekis / 2];
				double mediana = (mediana1 + mediana2) * 1.0 / 2.0;
				S[i].GalutinisM = 0.4 * mediana + 0.6 * S[i].EGZ;
			}
			if (pazymiu_kiekis % 2 != 0)
			{
				int mediana = S[i].ND[pazymiu_kiekis / 2];
				S[i].GalutinisM = 0.4 * mediana + 0.6 * S[i].EGZ;
			}
		}


		if (RusiavimoPasirinkimas == 'V')
		{

			if (S[i].GalutinisV < 5)
			{
				N.push_back(S[i]);
			}
			else
			{
				G.push_back(S[i]);
			}
		}
		if (RusiavimoPasirinkimas == 'M')
		{

			if (S[i].GalutinisM < 5)
			{
				N.push_back(S[i]);
			}
			else
			{
				G.push_back(S[i]);
			}
		}

	}

	// Baigia skaiciuoti laika
	auto RusaivimoPabaiga = std::chrono::high_resolution_clock::now();

	//Apskaiciuoja laika
	auto Rusiavimotrukme = std::chrono::duration_cast<std::chrono::seconds>(RusaivimoPabaiga - RusavimoPradzia);

	std::cout << "\nRusiavimas i galvocius ir nepazangius uztruko " << Rusiavimotrukme.count() << " sek." << std::endl;
}
