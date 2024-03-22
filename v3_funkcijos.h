#ifndef V3_FUNKCIJOS_H
#define V3_FUNKCIJOS_H


//// NETINKAMA IVESTIS
void Netinkamas_Ivestis(std::string Problema);

//// RUSIAVIMAS
bool VarduRusiavimas(const studentas& a, const studentas& b);
bool PavardziuRusiavimas(const studentas& a, const studentas& b);
bool MedianuRusiavimas(const studentas& a, const studentas& b);
bool VidurkiuRusiavimas(const studentas& a, const studentas& b);
void Rusiuoti_Duomenis(std::vector<studentas>& S, std::vector<studentas>& N);

//// GENERAVIMAS
void GeneruotiNDPazymius(studentas& S, int ND_kiekis);
void GeneruotiVardus(studentas& S);
void GeneruotiFailus(int reserveDydis, std::string& failoPav);

//// IVEDIMAS
void Ivesti_Pazymius(studentas& S);
void Ivesti_Varda(studentas& S);

//// NUSKAITYMAS NUO FAILO
std::vector<studentas> Nuskaityti_Is_Failo(const std::string& Failo_Pavadinimas, int reserveDydis);

//// APSKAICIAVIMAS IR SKIRSTYMAS I GRUPES
void Apskaiciuoti_Rezultatus(std::vector<studentas>& S, std::vector<studentas>& N);

//// SPAUSDINIMAS
void Spausdinti_Rezultatus(const std::vector<studentas>& S, const std::vector<studentas>& N);

#endif 
