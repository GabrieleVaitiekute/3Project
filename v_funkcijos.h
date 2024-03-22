#ifndef V_FUNKCIJOS_H
#define V_FUNKCIJOS_H
#include "v_studentai.h"

////////// NETINKAMA IVESTIS //////////////
void Netinkamas_Ivestis(std::string Problema);

//////// DUOMENU RUSIAVIMAS ///////////
bool VarduRusiavimas(const studentas& a, const studentas& b);
bool PavardziuRusiavimas(const studentas& a, const studentas& b);
bool MedianuRusiavimas(const studentas& a, const studentas& b);
bool VidurkiuRusiavimas(const studentas& a, const studentas& b);
void Rusiuoti_Duomenis(std::vector<studentas>& N, std::vector<studentas>& G);

///////// GENERAVIMAS /////////////////////
void GeneruotiNDPazymius(studentas& S, int ND_kiekis);
void GeneruotiVardus(studentas& S);
void GeneruotiFailus(int reserveDydis, std::string& failoPav);

////////// IVEDIMAS ///////////////////////
void Ivesti_Pazymius(studentas& S);
void Ivesti_Varda(studentas& S);

////////// NUSKAITYMAS NUO FAILO /////////////////
std::vector<studentas> Nuskaityti_Is_Failo(const std::string& Failo_Pavadinimas, int reserveDydis);

////////// REZULTATU SPAUSDINIMAS IR SKIRSTYMAS I GRUPES ////////////
void Apskaiciuoti_Rezultatus(std::vector<studentas>& S, std::vector<studentas>& N, std::vector<studentas>& G);

///////// REZULTATU SPAUSDINIMAS ///////////////////////////
void Spausdinti_Rezultatus(const std::vector<studentas>& N, const std::vector<studentas>& G);

#endif