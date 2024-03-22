#ifndef D_FUNKCIJOS_H
#define D_FUNKCIJOS_H
#include "d_studentai.h"

//// NETINKAMA IVESTIS
void Netinkamas_Ivestis(std::string Problema);

//// DUOMENU RUSIAVIMAS
bool VarduRusiavimas(const studentas& a, const studentas& b);
bool PavardziuRusiavimas(const studentas& a, const studentas& b);
bool MedianuRusiavimas(const studentas& a, const studentas& b);
bool VidurkiuRusiavimas(const studentas& a, const studentas& b);
void Rusiuoti_Duomenis(std::deque<studentas>& N, std::deque<studentas>& G);

//// DUOMENU GENERAVIMAS
void GeneruotiNDPazymius(studentas& S, int ND_kiekis);
void GeneruotiVardus(studentas& S);
void GeneruotiFailus(int reserveDydis, std::string& failoPav);

//// DUOMENU IVEDIMAS
void Ivesti_Pazymius(studentas& S);
void Ivesti_Varda(studentas& S);


//// NUSKAITYMAS NUO FAILO
std::deque<studentas> Nuskaityti_Is_Failo(const std::string& Failo_Pavadinimas, int reserveDydis);

//// REZULTATU APSKAICIAVIMAS IR SKIRSTYMAS I GRUPES 
void Apskaiciuoti_Rezultatus(std::deque<studentas>& S, std::deque<studentas>& N, std::deque<studentas>& G);

//// SPAUSDINIMAS
void Spausdinti_Rezultatus(const std::deque<studentas>& N, const std::deque<studentas>& G);
#endif 