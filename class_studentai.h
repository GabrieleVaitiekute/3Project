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

class zmogus {
protected:
	std::string vardas;
	std::string pavarde;
public:
	//Konstruktorius
	zmogus() = default;
	zmogus(const std::string& vardas, const std::string& pavarde)
		: vardas(vardas), pavarde(pavarde) {}

	// Destruktorius
	virtual ~zmogus() {}

	// Virtual method for getting full name
	virtual std::string getFullName() const
	{
		return vardas + " " + pavarde;
	}

	// Virtual method for getting age (to make the class abstract)
	virtual int getAge() const = 0;
	// Get'eriai

	std::string getVardas() const { return vardas; }
	std::string getPavarde() const { return pavarde; }
};

class  studentas: public zmogus{
private:

	std::vector<int> ND;
	int EGZ = 0;
	double GalutinisV = 0;
	double GalutinisM = 0;
	void studentas::ApskaiciuotiGalutinius()
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
	studentas::studentas() = default;

	studentas::studentas(const std::string& vardas, const std::string& pavarde, const std::vector<int>& ND, int EGZ)
		: zmogus(vardas, pavarde), ND(ND), EGZ(EGZ) {
		ApskaiciuotiGalutinius(); // Calculate final scores after initialization
	}

	// Destruktorius
	studentas::~studentas() = default;

	// Copy konstruktorius
	studentas::studentas(const studentas& other)
		: zmogus(other.getVardas(), other.getPavarde()), ND(other.ND), EGZ(other.EGZ),
		GalutinisV(other.GalutinisV), GalutinisM(other.GalutinisM) {}

	// Move konstruktorius
	studentas::studentas(studentas&& other) noexcept
		: zmogus(std::move(other.vardas), std::move(other.pavarde)), ND(std::move(other.ND)),
		EGZ(other.EGZ), GalutinisV(other.GalutinisV), GalutinisM(other.GalutinisM) {}

	// Copy priskyrimo operatorius
	studentas& studentas::operator=(const studentas& other)
	{
		if (this != &other) {
			vardas = other.vardas;
			pavarde = other.pavarde;
			ND = other.ND;
			EGZ = other.EGZ;
			GalutinisV = other.GalutinisV;
			GalutinisM = other.GalutinisM;
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
			EGZ = other.EGZ;
			GalutinisV = other.GalutinisV;
			GalutinisM = other.GalutinisM;
		}
		return *this;
	}

	// Getter'iai
	std::string studentas::getVardas() const { return vardas; }
	std::string studentas::getPavarde() const { return pavarde; }
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
		std::vector<int> grades;
		while (is >> pazymys)
		{
			grades.push_back(pazymys);
		}

		if (!grades.empty())
		{
			s.EGZ = grades.back();
			grades.pop_back();
			s.ND = grades;
		}

		s.ApskaiciuotiGalutinius();

		return is;
	}

	friend std::ostream& operator<<(std::ostream& os, const studentas& s)
	{
		os << std::setw(20) << s.pavarde << std::setw(20) << s.vardas << std::setw(20) << std::setprecision(3) << s.GalutinisV << std::setw(20) << std::setprecision(3) << s.GalutinisM << std::endl;

		return os;
	}
	// Virtual method for getting age (required to implement since zmogus is abstract)
	virtual int getAge() const override {
		// Implement this method to return the age of the person if needed
		return 0; // Returning 0 as a placeholder, implement actual logic as needed
	}
};

#endif
