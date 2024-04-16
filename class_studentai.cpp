#include "class_studentai.h"

// Constructors
studentas::studentas(const std::string& vardas, const std::string& pavarde, const std::vector<int>& ND, int EGZ)
    : vardas(vardas), pavarde(pavarde), ND(ND), EGZ(EGZ) {
    calculateFinalScores();
}

// Getters
std::string studentas::getVardas() const { return vardas; }
std::string studentas::getPavarde() const { return pavarde; }
std::vector<int> studentas::getND() const { return ND; }
int studentas::getEGZ() const { return EGZ; }
double studentas::getGalutinisV() const { return GalutinisV; }
double studentas::getGalutinisM() const { return GalutinisM; }

// Setters
void studentas::setVardas(const std::string& newName) { vardas = newName; }
void studentas::setPavarde(const std::string& newSurname) { pavarde = newSurname; }
void studentas::setND(const std::vector<int>& newND) { ND = newND; }
void studentas::setEGZ(int newEGZ) {
    EGZ = newEGZ;
    calculateFinalScores();
}

void studentas::calculateFinalScores() {
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