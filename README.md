# 3Project

## 1 TESTAVIMO APRAŠYMAS

Testavimą atlikau su Catch2. Testai: Default konstruktorius, Parametrizuotas konstruktorius, Copy konstruktorius, Move konstruktorius, Copy priskyrimo operatorius, Move priskyrimo operatorius, Ivesties operatorius, Isvesties operatorius, Push back, size, Capacity, Modifiers, Relational Operators.

## 2 EFEKTYVUMO/SPARTOS ANALIZĖ NAUDOJANT PUSH_BACK()


## 3 ATMINTIES PERSKIRTYMAI


## 4 VECTOR VEIKLOS PALYGINIMAS SU STD::VECTOR


## DIEGIMO INSTRUKCIJA

1.Atsisiųskite ir įdiekite „Visual Studio“ ir „CMake“ bei šios programos failus;

2.Atsivėrę terminalą su komanda cd nueikite į šios programos failų folderį. Tuomet į terminalą įveskite;

* mkdir build;

* cd build;

* cmake ..

* cmake --build .
## NAUDOJIMOSI INSTRUKCIJA

Paleidus programą pradiniame meniu suteikiami 6 pasirinkimai 1 - ranka suvesti visus studentų duomenis, 2 - generuoti pažymius ir suvesti vardus bei pavardes, 3 - generuoti ir pažymius, ir studentų vardus, pavardes, 4 - nuskaityti duomenis iš failo (galima pasirinkti iš 4 skirtingų failų, programa apskaičiuoja ir pateikia, kiek laiko užtruko nuskaityti failą), 5 - sugeneruoti failus (5 dydžių pasirinkimai), 6 - baigti darbą.

Vėliau leidžiama pasirinkti strategiją (1, 2, 3)

Pasirinkus 1 būdą suteikiama galimybė įvesti studento vardą ir pavardę, vėliau pažymius. Po kiekvieno pažymio yra galimmybė pasirinkti, ar norima įvesti dar viena pažymį (įvesti T jei taip, N jei ne). Baigus įvesti pažymius galima įvesti egzamino balą. Tuomet duodama galimybė pasirinkti, ar norima įvesti dar vieną studentą (įvesti T jei taip, N jei ne). Baigus studentų įvedimą duodamas pasirinkimas pasirinkti studentų grupavimą pagal galutinį balą, apskaičiuotą su pažymių mediana arba vidurkiu, vėliau leidžiama pasirinkti rikiavimą pagal vardą, pavardę, galutini balą, apskaičiuotą su mediana arba vidurkiu. Rezultatus galima rasti "Galvociai.txt" ir "Nepazangus.txt" failuose.

Pasirinkus 2 būdą suteikiama galimybė įvesti studento vardą ir pavardę, vėliau prašoma įvesti norimą kiekį namų darbų pažymių.Tuomet duodama galimybė pasirinkti, ar norima įvesti dar vieną studentą (įvesti T jei taip, N jei ne). Baigus studentų įvedimą duodamas pasirinkimas pasirinkti studentų grupavimą pagal galutinį balą, apskaičiuotą su pažymių mediana arba vidurkiu, vėliau leidžiama pasirinkti rikiavimą pagal vardą, pavardę, galutini balą, apskaičiuotą su mediana arba vidurkiu. Rezultatus galima rasti "Galvociai.txt" ir "Nepazangus.txt" failuose.

Pasirinkus 3 būdą prašoma įvesti, kiek norima sugeneruoti studentų ir vėliau kiek norima sugeneruoti jų pažymių. Baigus generavimą duodamas pasirinkimas pasirinkti studentų grupavimą pagal galutinį balą, apskaičiuotą su pažymių mediana arba vidurkiu, vėliau leidžiama pasirinkti rikiavimą pagal vardą, pavardę, galutini balą, apskaičiuotą su mediana arba vidurkiu. Rezultatus galima rasti "Galvociai.txt" ir "Nepazangus.txt" failuose.

Pasirinkus 4 būdą prašoma pasirinkti nuo kurio failo norite nuskaityti duomenis. Tuomet duodamas pasirinkimas pasirinkti studentų grupavimą pagal galutinį balą, apskaičiuotą su pažymių mediana arba vidurkiu, vėliau leidžiama pasirinkti rikiavimą pagal vardą, pavardę, galutini balą, apskaičiuotą su mediana arba vidurkiu. Rezultatus galima rasti "Galvociai.txt" ir "Nepazangus.txt" failuose.

Pasirinkus 5 būda prašoma pasirinkti kūrį failą norite sugeneruoti, jei failas jau egzistuoja nuo jo nuskaitomi duomenis. Tuomet duodamas pasirinkimas pasirinkti studentų grupavimą pagal galutinį balą, apskaičiuotą su pažymių mediana arba vidurkiu, vėliau leidžiama pasirinkti rikiavimą pagal vardą, pavardę, galutini balą, apskaičiuotą su mediana arba vidurkiu. Rezultatus galima rasti "Galvociai.txt" ir "Nepazangus.txt" failuose.

Pasirinkus 6 būda darbas baigiamas.
