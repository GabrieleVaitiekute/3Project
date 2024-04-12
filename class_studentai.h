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

class Student {
public:
    Student();
    ~Student();

    // Setters
    void setVardas(const std::string& vardas);
    void setPavarde(const std::string& pavarde);
    void addND(int nd);
    void setEGZ(int egz);

    // Getters
    std::string getVardas() const;
    std::string getPavarde() const;
    std::vector<int> getND() const;
    int getEGZ() const;

    // Other methods
    double calculateGalutinisV() const;
    double calculateGalutinisM() const;

private:
    std::string vardas;
    std::string pavarde;
    std::vector<int> ND;
    int EGZ;
};

#endif
#endif
