#ifndef D3_STUDENTAI_H
#define D3_STUDENTAI_H
#include <chrono> 
#include <string>
#include <deque>
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

struct studentas
{
    std::string vardas;
    std::string pavarde;
    std::deque<int> ND;
    int EGZ = 0;
    double GalutinisV = 0;
    double GalutinisM = 0;
};

#endif