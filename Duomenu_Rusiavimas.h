#ifndef DUOMENU_RUSIAVIMAS_H
#define DUOMENU_RUSIAVIMAS_H
#include "Studentai.h"
#include "Netinkama_Ivestis.h"


bool VarduRusiavimas(const studentas& a, const studentas& b);
bool PavardziuRusiavimas(const studentas& a, const studentas& b);
bool MedianuRusiavimas(const studentas& a, const studentas& b);
bool VidurkiuRusiavimas(const studentas& a, const studentas& b);
void Rusiuoti_Duomenis(std::vector<studentas>& S);

#endif