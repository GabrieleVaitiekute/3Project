#include "class_studentai.h"
#include "class_funkcijos.h"


//////////////// NETINKAMA IVESTIS ///////////////////////
void Netinkamas_Ivestis(std::string Problema)
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cerr << Problema;
}

//////////////// GENERAVIMAS ////////////////////////////

std::random_device rd;
std::mt19937 generuoti(rd());
std::uniform_int_distribution<int> nd_kiekis(5, 20);
std::uniform_int_distribution<int> dis(1, 10);
std::uniform_int_distribution<int> dis_lytis(0, 1);

std::vector<std::string> vardaiV = { "Jonas", "Petras", "Antanas", "Juozas", "Kazys", "Darius", "Linas", "Tomas", "Giedrius", "Marius" };
std::vector<std::string> vardaiM = { "Ona", "Maryte", "Aldona", "Gabija", "Dalia", "Danute", "Asta", "Rasa", "Nijole", "Aiste", "Gabriele" };
std::vector<std::string> pavardesV = { "Jonaitis", "Petraitis", "Antanaitis", "Juozaitis", "Kaziukaitis", "Dariukaitis", "Linaitis", "Tomaitis", "Giedraitis", "Mariukaitis" };
std::vector<std::string> pavardesM = { "Jonaite", "Petraityte", "Antanaite", "Juozaite", "Kaziukaite", "Dariukaite", "Linaite", "Tomaite", "Giedraite", "Mariukaite", "Antaniene", "Jonaitiene", "Antaniene" };

int lytis = dis_lytis(generuoti);

////////// PAZYMIU GENERAVIMAS ////////////
void GeneruotiNDPazymius(studentas& S, int ND_kiekis)
{
	std::vector<int> pazymiai;
	for (int i = 0; i < ND_kiekis; ++i) {
		pazymiai.push_back(dis(generuoti));
	}
	S.setND(pazymiai);
	S.setEGZ(dis(generuoti));
}

///////////// VARDU GENERAVIMAS ////////////////
void GeneruotiVardus(studentas& S)
{
	int lytis = dis_lytis(generuoti);

	if (lytis == 0)
	{
		S.setVardas(vardaiV[dis(generuoti) % 10]);
		S.setPavarde(pavardesV[dis(generuoti) % 10]);
	}

	else
	{
		S.setVardas(vardaiM[dis(generuoti) % 10]);
		S.setPavarde(pavardesM[dis(generuoti) % 10]);
	}

}

///////////// FAILU GENERAVIMAS ////////////////
void GeneruotiFailus(int reserveDydis, std::string& G_Failo_Vieta)
{
	int nd_kiekis_gen = nd_kiekis(generuoti);

	std::ofstream GFailas(G_Failo_Vieta);

	if (!GFailas.is_open())
	{
		std::cout << "Nepavyko atidaryti failo " << G_Failo_Vieta << std::endl;
		return;
	}

	//headline spausdinimas
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

///////// IVEDIMAS //////////////////

void Ivesti_Pazymius(studentas& S)
{
	std::vector<int> pazymiai;
	char TaipNePaz;
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

				if (pazymys >= 1 && pazymys <= 10)
				{
					pazymiai.push_back(pazymys);// pridedamas pazymis i vektoriu
				}
				break;
			}

			catch (const std::invalid_argument& paz)
			{
				Netinkamas_Ivestis(paz.what());
			}
		}

		std::cout << "Ar norite ivesti dar viena pazymi? (iveskite T, jei taip , N, jei ne): ";
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

	S.setND(pazymiai);

	int egz;
	std::cout << std::endl << "Iveskite egzamino pazymi: ";
	while (true)
	{
		try
		{
			std::cin >> egz;
			if (std::cin.fail() || std::cin.peek() != '\n' || egz < 1 || egz > 10)
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
	S.setEGZ(egz);
}

void Ivesti_Varda(studentas& S)
{
	std::string vardas, pavarde;
	std::cout << std::endl << "Iveskite studento varda: ";
	while (true)
	{
		try
		{
			std::cin >> vardas;
			if (std::cin.fail() || std::cin.peek() != '\n' || !all_of(vardas.begin(), vardas.end(), ::isalpha))
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
			std::cin >> pavarde;
			if (std::cin.fail() || std::cin.peek() != '\n' || !all_of(pavarde.begin(), pavarde.end(), ::isalpha))
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
	S.setVardas(vardas);
	S.setPavarde(pavarde);
}

/////////// NUSKAITYMAS NUO FAILO /////////////

std::vector<studentas> Nuskaityti_Is_Failo(const std::string& Failo_Pavadinimas, int reserveDydis)
{
	// Pradedamas skaiciuti laikas
	auto start = std::chrono::high_resolution_clock::now();

	std::ifstream file(Failo_Pavadinimas);
	std::vector<studentas> studentai;
	studentai.reserve(reserveDydis);  // Iš anksto rezervuojama atmintis

	if (!file.is_open())
	{
		std::cerr << "Klaida atidarant faila " << Failo_Pavadinimas << std::endl;
		return studentai;
	}
	// Praleidziama pirma header eilute
	std::string header;
	std::getline(file, header);

	std::string eilute;
	while (std::getline(file, eilute))
	{
		std::istringstream iss(eilute);
		studentas student;
		if (iss >> student)
		{
			studentai.push_back(student);
		}
		else
		{
			std::cerr << "Klaida nuskaitant duomenis iš eilutės: " << eilute << std::endl;
		}
	}

	// Baigia skaiciuoti laika
	auto end = std::chrono::high_resolution_clock::now();

	//Apskaiciuoja laika
	auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);

	file.close();
	std::cout << "\nFailo nuskaitymas uztruko " << duration.count() << " sek." << std::endl;
	return studentai;
}

///// DUOMENU RUSIAVIMAS////////

void Rikiuoti_Duomenis(std::vector<studentas>& S)
{

	// Rusiavimo pasirinkimai
	std::cout << std::endl << "Rikiuoti pagal:\n 1. Varda\n 2. Pavarde\n 3. Galutini bala, apskaiciuota su mediana\n 4. Galutini bala, apskaiciuota su vidurkiu\n Iveskite pasirinkimo numeri: ";
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
		std::sort(S.begin(), S.end(), [](const studentas& a, const studentas& b)
			{
				return a.getVardas() < b.getVardas(); // Rūšiuojama pagal vardą
			});

		break;
	case 2:
		std::sort(S.begin(), S.end(), [](const studentas& a, const studentas& b)
			{
				return a.getPavarde() < b.getPavarde(); // Rūšiuojama pagal pavarde
			});
		break;
	case 3:
		std::sort(S.begin(), S.end(), [](const studentas& a, const studentas& b)
			{
				return a.getGalutinisM() < b.getGalutinisM(); // Rūšiuojama pagal GalutiniM
			});
		break;
	case 4:
		std::sort(S.begin(), S.end(), [](const studentas& a, const studentas& b)
			{
				return a.getGalutinisV() < b.getGalutinisV(); // Rūšiuojama pagal GalutiniV
			});
		break;
	}
	// Baigia skaiciuoti laika
	auto RikiavimoPabaiga = std::chrono::high_resolution_clock::now();

	//Apskaiciuoja laika
	auto Rikiavimotrukme = std::chrono::duration_cast<std::chrono::duration<double>>(RikiavimoPabaiga - RikiavimoPradzia);

	std::cout << "\nRikiavimas didejancia tvarka pagal pasirinkta kriteriju uztruko " << Rikiavimotrukme.count() << " sek." << std::endl;
}

//// STUDENTU SKIRSTYMAS I GRUPES 
void Skirstyti_Studentus(std::vector<studentas>& S, std::vector<studentas>& N, std::vector<studentas>& G, int Strategija)
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


	if (Strategija == 1)
	{

		for (auto& studentas : S)
		{
			if (RusiavimoPasirinkimas == 'V')
			{
				if (studentas.getGalutinisV() < 5)
					N.push_back(studentas);
				else
					G.push_back(studentas);
			}
			else if (RusiavimoPasirinkimas == 'M')
			{
				if (studentas.getGalutinisM() < 5)
					N.push_back(studentas);
				else
					G.push_back(studentas);
			}
		}
	}
	if (Strategija == 2)
	{

		auto i = S.begin();
		while (i != S.end())
		{
			if (RusiavimoPasirinkimas == 'V')
			{
				if (i->getGalutinisV() < 5)
				{
					N.push_back(*i);
					i = S.erase(i);
					continue;
				}
			}
			else if (RusiavimoPasirinkimas == 'M')
			{
				if (i->getGalutinisM() < 5)
				{
					N.push_back(*i);
					i = S.erase(i);
					continue;
				}
			}
			++i;
		}
	}

	if (Strategija == 3)
	{
		auto i = std::remove_if(S.begin(), S.end(), [&](const auto& studentas)
			{
				bool istrinti = false;
				if (RusiavimoPasirinkimas == 'V')
				{
					if (studentas.getGalutinisV() < 5)
					{
						istrinti = true;
					}
				}
				else if (RusiavimoPasirinkimas == 'M')
				{
					if (studentas.getGalutinisM() < 5)
					{
						istrinti = true;
					}
				}
				if (istrinti)
				{
					N.push_back(studentas);
				}
				return istrinti;
			});

		S.erase(i, S.end());

	}

	// Baigia skaiciuoti laika
	auto RusaivimoPabaiga = std::chrono::high_resolution_clock::now();

	//Apskaiciuoja laika
	auto Rusiavimotrukme = std::chrono::duration_cast<std::chrono::duration<double>>(RusaivimoPabaiga - RusavimoPradzia);

	std::cout << "\nRusiavimas i galvocius ir nepazangius uztruko " << Rusiavimotrukme.count() << " sek." << std::endl;
}

//////////// REZULTATU SPAUSDINIMAS //////////////
void Spausdinti_Rezultatus(const std::vector<studentas>& N, const std::vector<studentas>& G)
{
	std::ofstream Galvociu_failas("Galvociai.txt");
	if (!Galvociu_failas.is_open())
	{
		std::cerr << "Klaida atidarant rezultatu faila" << std::endl;
		return;
	}
	int i = 0;
	for (auto& studentas : G)
	{
		if (i == 0)
			Galvociu_failas << std::setw(7) << "Nr." << std::setw(20) << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << std::endl << std::setfill('-') << std::setw(90) << "-" << std::setfill(' ') << std::endl;

		Galvociu_failas << std::setw(7) << i + 1 << studentas;
		i++;

	}
	Galvociu_failas.close();

	std::ofstream Nepazangiuju_failas("Nepazangus.txt");
	if (!Nepazangiuju_failas.is_open())
	{
		std::cerr << "Klaida atidarant rezultatu faila" << std::endl;
		return;
	}
	i = 0;
	for (auto& studentas : N)
	{
		if (i == 0)
			Nepazangiuju_failas << std::setw(7) << "Nr." << std::setw(20) << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << std::endl << std::setfill('-') << std::setw(90) << "-" << std::setfill(' ') << std::endl;

		Nepazangiuju_failas << std::setw(7) << i + 1 << studentas;
		i++;

	}
	Nepazangiuju_failas.close();

	std::cout << std::endl << "Rezultatai atspausdinti" << std::endl;
}

void Testavimas()
{

	// Testuojamas numatytasis konstruktorius
	{
		studentas s;
		assert(s.getVardas().empty() && s.getPavarde().empty() && s.getND().empty() && s.getEGZ() == 0);
		std::cout << "Numatytasis konstruktorius veikia teisingai." << std::endl;
	}

	// Testuojamas parametrizuotas konstruktorius ir getter'iai
	{
		std::string vardas = "Jonas";
		std::string pavarde = "Jonaitis";
		std::vector<int> nd = { 5, 7, 8 };
		int egz = 9;
		studentas s(vardas, pavarde, nd, egz);
		assert(s.getVardas() == vardas && s.getPavarde() == pavarde && s.getND() == nd && s.getEGZ() == egz);
		std::cout << "Parametrizuotas konstruktorius ir getter'iai veikia teisingai." << std::endl;
	}

	// Testuojamas kopijavimo konstruktorius
	{
		std::vector<int> K{ 10, 9, 8 };//toki ND vector turi gauti
		studentas s1("Petras", "Petraitis", { 10, 9, 8 }, 10);
		studentas s2 = s1;
		assert(s2.getVardas() == "Petras" && s2.getPavarde() == "Petraitis" && s2.getND() == K && s2.getEGZ() == 10);
		std::cout << "Kopijavimo konstruktorius veikia teisingai." << std::endl;
	}

	// Testuojamas move konstruktorius
	{
		studentas s1("Kazys", "Kazlauskas", { 6, 5, 7 }, 8);
		studentas s2 = std::move(s1);
		assert(s2.getVardas() == "Kazys" && s2.getPavarde() == "Kazlauskas" && !s2.getVardas().empty()); // move semantika palieka s1 objektą neapibrėžtu stoviu
		std::cout << "Move konstruktorius veikia teisingai." << std::endl;
	}

	// Testuojamas kopijavimo priskyrimo operatorius
	{
		std::vector<int> V{ 9, 8, 10 };//toki ND vector turi gauti
		studentas s1("Antanas", "Antanaitis", V, 7);
		studentas s2;
		s2 = s1;
		assert(s2.getVardas() == "Antanas" && s2.getPavarde() == "Antanaitis" && s2.getND() == V && s2.getEGZ() == 7);
		std::cout << "Kopijavimo priskyrimo operatorius veikia teisingai." << std::endl;
	}

	// Testuojamas move priskyrimo operatorius
	{
		studentas s1("Aldona", "Aldoniene", { 7, 8, 9 }, 10);
		studentas s2;
		s2 = std::move(s1);
		assert(s2.getVardas() == "Aldona" && s2.getPavarde() == "Aldoniene" && !s2.getVardas().empty()); // move semantika palieka s1 objektą neapibrėžtu stoviu
		std::cout << "Move priskyrimo operatorius veikia teisingai." << std::endl;
	}
	// Destruktoriaus patikrinimas
	{
		// Sukuriamas dynamic studentas 
		studentas* s1 = new studentas();

		// I ji pridedamepazymius
		s1->setND({ 10, 9, 8 });

		// Istriname 
		delete s1;

		// Sukuriam nauja
		studentas s2;

		// Patikrinam ar jame nebeliko s1 pazymiu
		assert(s2.getND().empty());
		std::cout << "Destruktorius veikia teisingai." << std::endl;
		
	}
	// Testuojamas įvedimo operatorius
	{
		std::vector<int> I = { 5, 6, 7, 8 };//toki ND vector turi gauti
		std::istringstream iss("Mindaugas Mindaugaitis 5 6 7 8 9");
		studentas s;
		iss >> s;
		assert(s.getVardas() == "Mindaugas");
		assert(s.getPavarde() == "Mindaugaitis");
		assert(s.getND() == I);
		assert(s.getEGZ() == 9);
		std::cout << "Ivedimo operatorius veikia teisingai." << std::endl;
	}


	// Testuojamas išvedimo operatorius
	{
		std::istringstream iss("Lina Linaityte 4 5 9 9");
		studentas s;
		iss >> s;
		std::ostringstream oss;
		oss << s;
		std::string tikimasi = "           Linaityte                Lina                 7.8                 7.4\n";
		assert(oss.str() == tikimasi);
		std::cout << "Isvedimo operatorius veikia teisingai." << std::endl;
	}
			
}
