#include "Rezultatu_Apskaiciavimas.h"
#include "Studentai.h"
#include <numeric>
#include <algorithm>

void Apskaiciuoti_Rezultatus(std::vector<studentas>& S)
{
	for (int i = 0; i < S.size(); i++)
	{
		//apskaiciuojama su vidurkiu
		double suma = std::accumulate(S[i].ND.begin(), S[i].ND.end(), 0);

		S[i].GalutinisV = 0.4 * suma / S[i].ND.size() + 0.6 * S[i].EGZ;

		//apskaiciuojama su mediana
		if (S[i].ND.size() == 1)
		{
			S[i].GalutinisM = 0.4 * S[i].ND[0] + 0.6 * S[i].EGZ;
		}
		if (S[i].ND.size() > 1)
		{
			std::sort(S[i].ND.begin(), S[i].ND.end());
			int pazymiu_kiekis = S[i].ND.size();

			if (pazymiu_kiekis % 2 == 0)
			{
				int mediana1 = S[i].ND[pazymiu_kiekis / 2 - 1];
				int mediana2 = S[i].ND[pazymiu_kiekis / 2];
				double mediana = (mediana1 + mediana2) * 1.0 / 2.0;
				S[i].GalutinisM = 0.4 * mediana + 0.6 * S[i].EGZ;
			}
			if (pazymiu_kiekis % 2 != 0)
			{
				int mediana = S[i].ND[pazymiu_kiekis / 2];
				S[i].GalutinisM = 0.4 * mediana + 0.6 * S[i].EGZ;
			}
		}
	}
}
