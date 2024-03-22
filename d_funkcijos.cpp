#include "d_studentai.h"

//// NETINKAMA IVESTIS
void Netinkamas_Ivestis(std::string Problema)
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cerr << Problema;
}

//// DUOMENU RUSIAVIMAS
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

void Rusiuoti_Duomenis(std::deque<studentas>& N, std::deque<studentas>& G)
{
	// Rusiavimo pasirinkimai
	std::cout << std::endl << "Rusiuoti pagal:\n 1. Varda\n 2. Pavarde\n 3. Galutini bala, apskaiciuota su mediana\n 4. Galutini bala, apskaiciuota su vidurkiu\n Iveskite pasirinkimo numeri: ";
	int Rusiavimo_Pasirinkimas;
	while (true)
	{
		try
		{
			std::cin >> Rusiavimo_Pasirinkimas;

			if (std::cin.fail() || std::cin.peek() != '\n' || Rusiavimo_Pasirinkimas < 1 || Rusiavimo_Pasirinkimas > 4)
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
	// Pradedamas skaiciuoti laikas
	auto RikiavimoPradzia = std::chrono::high_resolution_clock::now();
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
	// Baigia skaiciuoti laika
	auto RikiavimoPabaiga = std::chrono::high_resolution_clock::now();

	//Apskaiciuoja laika
	auto Rikiavimotrukme = std::chrono::duration_cast<std::chrono::duration<double>>(RikiavimoPabaiga - RikiavimoPradzia);

	std::cout << "\nRusiavimas didejancia tvarka uztruko " << Rikiavimotrukme.count() << " sek." << std::endl;
}

//// DUOMENU GENERAVIMAS
std::random_device rd;
std::mt19937 generuoti(rd());
std::uniform_int_distribution<int> nd_kiekis(5, 20);
std::uniform_int_distribution<int> dis(1, 10);
std::uniform_int_distribution<int> dis_lytis(0, 1);

std::deque<std::string> vardaiV = { "Jonas", "Petras", "Antanas", "Juozas", "Kazys", "Darius", "Linas", "Tomas", "Giedrius", "Marius" };
std::deque<std::string> vardaiM = { "Ona", "Maryte", "Aldona", "Gabija", "Dalia", "Danute", "Asta", "Rasa", "Nijole", "Aiste", "Gabriele" };
std::deque<std::string> pavardesV = { "Jonaitis", "Petraitis", "Antanaitis", "Juozaitis", "Kaziukaitis", "Dariukaitis", "Linaitis", "Tomaitis", "Giedraitis", "Mariukaitis" };
std::deque<std::string> pavardesM = { "Jonaite", "Petraityte", "Antanaite", "Juozaite", "Kaziukaite", "Dariukaite", "Linaite", "Tomaite", "Giedraite", "Mariukaite", "Antaniene", "Jonaitiene", "Antaniene" };

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

void GeneruotiFailus(int reserveDydis, std::string& G_Failo_Vieta)
{
	int nd_kiekis_gen = nd_kiekis(generuoti);

	std::ofstream GFailas(G_Failo_Vieta);

	if (!GFailas.is_open())
	{
		std::cout << "Nepavyko atidaryti failo " << G_Failo_Vieta << std::endl;
		return;
	}

	//headline spauSdinimas
	GFailas << std::left << std::setw(20) << "Pavarde" << std::setw(20) << "Vardas";

	for (int i = 0; i < nd_kiekis_gen; i++)
	{
		GFailas << std::left << std::setw(7) << "ND" + std::to_string(i + 1);
	}

	GFailas << std::setw(5) << "Egz." << std::endl;

	//studentu duomenu spasudiniams
	for (int i = 0; i < reserveDydis; i++)
	{
		GFailas << std::left << std::setw(20) << "Pavarde" + std::to_string(i + 1) << std::left << std::setw(20) << "Vardas" + std::to_string(i + 1);
		for (int j = 0; j < nd_kiekis_gen; j++)
		{
			GFailas << std::setw(7) << dis(generuoti);
		}
		GFailas << std::setw(7) << dis(generuoti);
		GFailas << "\n";
	}

	GFailas.close();
}

//// DUOMENU IVEDIMAS
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

//// NUSKAITYMAS NUO FAILO
std::deque<studentas> Nuskaityti_Is_Failo(const std::string& Failo_Pavadinimas, int reserveDydis)
{
	// Pradedamas skaiciuti laikas
	auto start = std::chrono::high_resolution_clock::now();

	// Open the file in binary mode
	std::ifstream file(Failo_Pavadinimas);

	std::deque<studentas> S;

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
	auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);

	file.close();
	std::cout << "\nFailo nuskaitymas uztruko " << duration.count() << " sek." << std::endl;
	return S;
}

//// REZULTATU APSKAICIAVIMAS IR SKIRSTYMAS I GRUPES 
void Apskaiciuoti_Rezultatus(std::deque<studentas>& S, std::deque<studentas>& N, std::deque<studentas>& G)
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
			size_t pazymiu_kiekis = S[i].ND.size();

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
	auto Rusiavimotrukme = std::chrono::duration_cast<std::chrono::duration<double>>(RusaivimoPabaiga - RusavimoPradzia);

	std::cout << "\nRusiavimas i galvocius ir nepazangius uztruko " << Rusiavimotrukme.count() << " sek." << std::endl;
}

//// SPAUSDINIMAS
void Spausdinti_Rezultatus(const std::deque<studentas>& N, const std::deque<studentas>& G)
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
