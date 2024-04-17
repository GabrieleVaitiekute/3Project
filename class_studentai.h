#ifndef CLASS_STUDENTAI_H
#define CLASS_STUDENTAI_H

#include <chrono> 
#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <limits>
#include <filesystem>
#include <algorithm>
#include <numeric> 
#include <random> 

class studentas {
private:
	std::string vardas;
	std::string pavarde;
	std::vector<int> ND;
	int EGZ = 0;
	double GalutinisV = 0;
	double GalutinisM = 0;

	void calculateFinalScores()
	{
		GalutinisV = 0.4 * std::accumulate(ND.begin(), ND.end(), 0.0) / ND.size() + 0.6 * EGZ;
		if (ND.size() > 1) {
			std::vector<int> sortedND = ND;
			std::sort(sortedND.begin(), sortedND.end());
			size_t mid = sortedND.size() / 2;
			GalutinisM = 0.4 * (sortedND.size() % 2 == 0 ? (sortedND[mid - 1] + sortedND[mid]) / 2.0 : sortedND[mid]) + 0.6 * EGZ;
		}
		else if (!ND.empty()) {
			GalutinisM = 0.4 * ND[0] + 0.6 * EGZ;
		}
	}

public:
	// Constructors
	studentas() = default;
	studentas(const std::string& vardas, const std::string& pavarde, const std::vector<int>& ND, int EGZ)
		: vardas(vardas), pavarde(pavarde), ND(ND), EGZ(EGZ) {
		calculateFinalScores();
	}

	// Destructor
	~studentas() { }

	// Getters
	std::string getVardas() const { return vardas; }
	std::string getPavarde() const { return pavarde; }
	std::vector<int> getND() const { return ND; }
	int getEGZ() const { return EGZ; }
	double getGalutinisV() const { return GalutinisV; }
	double getGalutinisM() const { return GalutinisM; }

	// Setters
	void setVardas(const std::string& newName) { vardas = newName; }
	void setPavarde(const std::string& newSurname) { pavarde = newSurname; }
	void setND(const std::vector<int>& newND) { ND = newND; }
	void setEGZ(int newEGZ) {
		EGZ = newEGZ;
		calculateFinalScores();
	}
};
#endif
