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

    void calculateFinalScores();

public:
    // Constructors
    studentas() = default;
    studentas(const std::string& vardas, const std::string& pavarde, const std::vector<int>& ND, int EGZ);

    // Getters
    std::string getVardas() const;
    std::string getPavarde() const;
    std::vector<int> getND() const;
    int getEGZ() const;
    double getGalutinisV() const;
    double getGalutinisM() const;

    // Setters
    void setVardas(const std::string& newName);
    void setPavarde(const std::string& newSurname);
    void setND(const std::vector<int>& newND);
    void setEGZ(int newEGZ);
};
#endif
