#ifndef CLASS_STUDENTAI_H
#define CLASS_STUDENTAI_H

#include <chrono> 
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <limits>
#include <filesystem>
#include <algorithm>
#include <numeric> 
#include <random> 
#include <cassert>

//ZMOGUS
class zmogus {
protected:
	std::string vardas;
	std::string pavarde;
public:
	//Konstruktorius
	zmogus() : vardas("Bevardis"), pavarde("Bepavardis") { std::cout << "Suveike zmogus default konstruktorius\n"; }
	zmogus(const std::string& vardas, const std::string& pavarde)
		: vardas(vardas), pavarde(pavarde) {}

	zmogus::~zmogus() {}

	virtual std::string getVardas() const = 0;
	virtual std::string getPavarde() const = 0;

	// Setter'iai 
	virtual void setVardas(const std::string& newName) { vardas = newName; }
	virtual void setPavarde(const std::string& newSurname) { pavarde = newSurname; }

};

//STUDENTAS
class  studentas : public zmogus {
private:

	std::vector<int> ND;
	int EGZ;
	double GalutinisV;
	double GalutinisM;
	void ApskaiciuotiGalutinius()
	{
		if (!ND.empty())
		{
			GalutinisV = 0.4 * std::accumulate(ND.begin(), ND.end(), 0.0) / ND.size() + 0.6 * EGZ;
			if (ND.size() > 1)
			{
				std::vector<int> sortedND = ND;
				std::sort(sortedND.begin(), sortedND.end());
				size_t mid = sortedND.size() / 2;
				GalutinisM = 0.4 * (sortedND.size() % 2 == 0 ? (sortedND[mid - 1] + sortedND[mid]) / 2.0 : sortedND[mid]) + 0.6 * EGZ;
			}
			else
				GalutinisM = 0.4 * ND[0] + 0.6 * EGZ;
		}
		else
		{
			// Jei ND tuščias
			GalutinisV = GalutinisM = 0.6 * EGZ;
		}
	}

public:
	studentas() : EGZ(0), ND(), GalutinisV(0), GalutinisM(0) {
		std::cout << "Suveike studentas default konstruktorius\n";
	}

	studentas::studentas(const std::string& vardas, const std::string& pavarde, const std::vector<int>& ND, int EGZ)
		: zmogus(vardas, pavarde), ND(ND), EGZ(EGZ) {
		ApskaiciuotiGalutinius();
		std::cout << "Suveike parametrizuotas konstruktorius\n";
	}


	// Implementuojame abstrakčius metodus
	virtual std::string getVardas() const override {
		return vardas;
	}

	virtual std::string getPavarde() const override {
		return pavarde;
	}
	// Destruktorius
	~studentas() { ND.clear();  std::cout << "Suveike destruktorius\n"; }

	// Copy konstruktorius
	studentas::studentas(const studentas& other)
	{
		vardas = other.vardas;
		pavarde = other.pavarde;
		ND = other.ND;
		EGZ = other.EGZ;
		GalutinisV = other.GalutinisV;
		GalutinisM = other.GalutinisM;
		std::cout << "Suveike copy konstruktorius\n";
	}
	// Move konstruktorius
	studentas::studentas(studentas&& other) noexcept
	{
		vardas = std::move(other.vardas);
		pavarde = std::move(other.pavarde);
		ND = std::move(other.ND);
		EGZ = std::move(other.EGZ);
		GalutinisV = std::move(other.GalutinisV);
		GalutinisM = std::move(other.GalutinisM);
		other.clearEverything();
		std::cout << "Suveike move konstruktorius\n";
	}
	// Copy priskyrimo operatorius
	studentas& studentas::operator=(const studentas& other)
	{

		if (this != &other)
		{
			vardas = other.vardas;
			pavarde = other.pavarde;
			ND = other.ND;
			EGZ = other.EGZ;
			GalutinisV = other.GalutinisV;
			GalutinisM = other.GalutinisM;
			std::cout << "Suveike copy priskyrimo operatorius\n";
		}
		return *this;
	}
	// Move priskyrimo operatorius
	studentas& studentas::operator=(studentas&& other) noexcept
	{

		if (this != &other)
		{
			vardas = std::move(other.vardas);
			pavarde = std::move(other.pavarde);
			ND = std::move(other.ND);
			EGZ = std::move(other.EGZ);
			GalutinisV = std::move(other.GalutinisV);
			GalutinisM = std::move(other.GalutinisM);
			other.clearEverything();
			std::cout << "Suveike move priskyrimo operatorius\n";
		}
		return *this;
	}


	// Getter'iai
	std::vector<int> studentas::getND() const { return ND; }
	int studentas::getEGZ() const { return EGZ; }
	double studentas::getGalutinisV() const { return GalutinisV; }
	double studentas::getGalutinisM() const { return GalutinisM; }

	// Setter'iai
	void studentas::setVardas(const std::string& newName) { vardas = newName; }
	void studentas::setPavarde(const std::string& newSurname) { pavarde = newSurname; }
	void studentas::setND(const std::vector<int>& newND) { ND = newND; ApskaiciuotiGalutinius(); }
	void studentas::setEGZ(int newEGZ) {
		EGZ = newEGZ;
		ApskaiciuotiGalutinius();
	}


	friend std::istream& operator>>(std::istream& is, studentas& s)
	{
		s.vardas.clear();
		s.pavarde.clear();
		s.ND.clear();
		s.EGZ = 0;


		if (!(is >> s.vardas >> s.pavarde))
		{
			return is;
		}

		int pazymys;
		std::vector<int> NDpazymiai;
		while (is >> pazymys)
		{
			NDpazymiai.push_back(pazymys);
		}

		// Patikrina, ar pasiekė failo pabaigą
		if (is.eof()) {
			is.clear();
		}
		// Jei įvedimo operacija nepavyko
		else if (is.fail()) {

			is.clear();
			std::string unused;
			std::getline(is, unused);
			return is;
		}

		if (!NDpazymiai.empty())
		{
			s.EGZ = NDpazymiai.back();
			NDpazymiai.pop_back();
			s.ND = NDpazymiai;
		}

		s.ApskaiciuotiGalutinius();
		std::cout << "Suveike ivesties operatorius\n";
		return is;
	}

	friend std::ostream& operator<<(std::ostream& os, const studentas& s)
	{
		os << std::setw(20) << s.pavarde << std::setw(20) << s.vardas << std::setw(20) << std::setprecision(3) << s.GalutinisV << std::setw(20) << std::setprecision(3) << s.GalutinisM << std::endl;
		std::cout << "Suveike isvesties operatorius\n";
		return os;

	}


	void clearEverything()
	{
		this->vardas.clear();
		this->pavarde.clear();
		this->ND.clear();
		this->EGZ = 0;
		this->GalutinisV = 0;
		this->GalutinisM = 0;

	}
};

#endif
