#ifndef GENERAVIMAS_H
#define GENERAVIMAS_H

#include "Studentai.h"
#include <random>
#include <chrono>
void GeneruotiNDPazymius(studentas& S, int ND_kiekis);

void GeneruotiVardus(studentas& S);

void GeneruotiFailus(int reserveDydis, std::string& failoPav);
#endif 
