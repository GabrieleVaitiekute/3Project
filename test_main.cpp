#define CATCH_CONFIG_MAIN
#include "Catch2/catch.hpp"
#include "studentai.h"
 

TEST_CASE("Default konstruktorius", "[Default konstruktorius]")
{
	WARN("REQUIRE stops at [Default konstruktorius] failure: ");
	studentas s;
	REQUIRE(s.getVardas() == "Bevardis");
	REQUIRE(s.getPavarde() == "Bepavardis");
	REQUIRE(s.getEGZ() == 0);
	REQUIRE(s.getND().empty());
	REQUIRE(s.getGalutinisV() == 0);
	REQUIRE(s.getGalutinisM() == 0);
}


TEST_CASE("Parametrizuotas konstruktorius", "[Parametrizuotas konstruktorius]")
{
	WARN("REQUIRE stops at [Parametrizuotas konstruktorius] failure: ");
	std::string vardas = "Jonas";
	std::string pavarde = "Jonaitis";
	Vector<int> nd = { 5, 7, 6, 9 };
	int egz = 9;
	studentas s(vardas, pavarde, nd, egz);
	REQUIRE(s.getVardas() == vardas);
	REQUIRE(s.getPavarde() == pavarde);
	REQUIRE(s.getEGZ() == egz);
	REQUIRE(s.getND() == nd);
	REQUIRE(s.getGalutinisV() == 8.1);
	REQUIRE(s.getGalutinisM() == 8);
}


TEST_CASE("Copy konstruktorius", "[Copy konstruktorius]")
{
	WARN("REQUIRE stops at [Copy konstruktorius] failure: ");
	studentas s1("Petras", "Petraitis", { 10, 9, 8 }, 10);
	studentas s2(s1);
	REQUIRE(s1.getVardas() == s2.getVardas());
	REQUIRE(s1.getPavarde() == s2.getPavarde());
	REQUIRE(s1.getEGZ() == s2.getEGZ());
	REQUIRE(s1.getND() == s2.getND());
	REQUIRE(s1.getGalutinisV() == s2.getGalutinisV());
	REQUIRE(s1.getGalutinisM() == s2.getGalutinisM());
}

TEST_CASE("Move konstruktorius", "[Move konstruktorius]")
{
	WARN("REQUIRE stops at [Move konstruktorius] failure: ");
	std::string vardas = "Kazys";
	std::string pavarde = "Kazlauskas";
	Vector<int> nd = { 5, 7, 6, 9 };
	int egz = 9;
	studentas s1(vardas, pavarde, nd, egz);
	studentas s2(std::move(s1));

	REQUIRE(s1.getVardas().empty());
	REQUIRE(s1.getPavarde().empty());
	REQUIRE(s1.getEGZ() == 0);
	REQUIRE(s1.getND().empty());
	REQUIRE(s1.getGalutinisV() == 0);
	REQUIRE(s1.getGalutinisM() == 0);

	REQUIRE(s2.getVardas() == vardas);
	REQUIRE(s2.getPavarde() == pavarde);
	REQUIRE(s2.getEGZ() == egz);
	REQUIRE(s2.getND() == nd);
	REQUIRE(s2.getGalutinisV() == 8.1);
	REQUIRE(s2.getGalutinisM() == 8);

}


TEST_CASE("Copy priskyrimo operatorius", "[Copy priskyrimo operatorius]")
{
	WARN("REQUIRE stops at [Copy priskyrimo operatorius] failure: ");
	studentas s1, s2;
	s2 = s1;
	REQUIRE(s1.getVardas() == s2.getVardas());
	REQUIRE(s1.getPavarde() == s2.getPavarde());
	REQUIRE(s1.getEGZ() == s2.getEGZ());
	REQUIRE(s1.getND() == s2.getND());
	REQUIRE(s1.getGalutinisV() == s2.getGalutinisV());
	REQUIRE(s1.getGalutinisM() == s2.getGalutinisM());
}


TEST_CASE("Move priskyrimo operatorius", "[Move priskyrimo operatorius]")
{
	WARN("REQUIRE stops at [Move priskyrimo operatorius] failure: ");
	std::string vardas = "Kazys";
	std::string pavarde = "Kazlauskas";
	Vector<int>  nd = { 5, 7, 6, 9 };
	int egz = 9;
	studentas s1(vardas, pavarde, nd, egz);
	studentas s2;
	s2 = std::move(s1);

	REQUIRE(s1.getVardas().empty());
	REQUIRE(s1.getPavarde().empty());
	REQUIRE(s1.getEGZ() == 0);
	REQUIRE(s1.getND().empty());
	REQUIRE(s1.getGalutinisV() == 0);
	REQUIRE(s1.getGalutinisM() == 0);

	REQUIRE(s2.getVardas() == vardas);
	REQUIRE(s2.getPavarde() == pavarde);
	REQUIRE(s2.getEGZ() == egz);
	REQUIRE(s2.getND() == nd);
	REQUIRE(s2.getGalutinisV() == 8.1);
	REQUIRE(s2.getGalutinisM() == 8);

}


TEST_CASE("Destruktorius", "[Destruktorius]")
{
	WARN("REQUIRE stops at [Destruktorius] failure: ");

	// Sukuriamas dynamic studentas 
	studentas* s1 = new studentas();
	Vector<int> I = { 10, 9, 8 };

	// I ji pridedame pazymius
	s1->setND(I);

	// Istriname 
	delete s1;

	// Sukuriam nauja
	studentas s2;

	// Patikrinam ar jame nebeliko s1 pazymiu
	REQUIRE(s2.getND().empty());
}


TEST_CASE("Ivesties operatorius", "[Ivesties operatorius]")
{
	WARN("REQUIRE stops at [Ivesties operatorius] failure: ");
	Vector<int> I = { 5, 6, 7, 8 };//toki ND vector turi gauti
	std::istringstream iss("Mindaugas Mindaugaitis 5 6 7 8 9");
	studentas s;
	iss >> s;
	REQUIRE(s.getVardas() == "Mindaugas");
	REQUIRE(s.getPavarde() == "Mindaugaitis");
	REQUIRE(s.getND() == I);
	REQUIRE(s.getEGZ() == 9);
	std::cout << std::endl;
}

TEST_CASE("Isvesties operatorius", "[Isvesties operatorius]")
{
	WARN("REQUIRE stops at [Isvesties operatorius] failure: ");
	std::istringstream iss("Lina Linaityte 4 5 9 9");
	studentas s;
	iss >> s;
	std::ostringstream oss;
	oss << s;
	std::string tikimasi = "           Linaityte                Lina                 7.8                 7.4\n";
	REQUIRE(oss.str() == tikimasi);
	std::cout << std::endl;
}
