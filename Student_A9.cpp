#include <iostream>
#include <string>
using namespace std;


/* ************** class Osoba_cls ************** */
class Osoba_cls
{

private:
    string meno_str; //Pouzite premenne typu string z dovodu ze: string je bezpecnejsi ako pouzitie pola znakov
    string priezvisko_str;

public:

    // Konstruktor
    Osoba_cls(string meno_str, string priezvisko_str);

    // Destruktor
    ~Osoba_cls() {}

    // Getter a setter pre meno_str
    string getMeno_str() const;

    void setMeno_str(string meno_str);

    // Getter a setter pre priezvisko_str
    string getPriezvisko_str() const;

    void setPriezvisko_str(string priezvisko_str);

};
/* ************** class Osoba_cls ************** */

/* ************** Osoba_cls::Osoba_cls ************** */
Osoba_cls::Osoba_cls(string meno_str, string priezvisko_str)
{
    this->meno_str = meno_str;
    this->priezvisko_str = priezvisko_str;
}

string Osoba_cls::getMeno_str() const
{
    return meno_str;
}

void Osoba_cls::setMeno_str(string meno_str)
{
    this->meno_str = meno_str;
}

string Osoba_cls::getPriezvisko_str() const
{
    return priezvisko_str;
}

void Osoba_cls::setPriezvisko_str(string priezvisko_str)
{
    this->priezvisko_str = priezvisko_str;
}
/* ************** Osoba_cls::Osoba_cls ************** */

/* ************** class Student_cls ************** */
class Student_cls : public Osoba_cls
{

private:
    int rocnik_int;
    string rocnikInfo_str;
    int typStudia_int; // 1-bakalar; 2-inzinier; 3-doktorand
    int sposobStudia_int; // 1-denne; 2 - externe
    int studijnyProgram_int; // 1-Aplikovana informatika; 2-Aplikovana biologia; 3-Biotechnologie; 4-Chemia

public:
    int pocetZnamok_F_int = 0;
    int pocetZnamok_int = 0;
    int znamky[10]; // pole pre ukladanie znamok

    bool vlozZnamku(int znamka);
    double priemer();

    // Konstruktor
    Student_cls(string meno_str, string priezvisko_str, int rocnik_int, int sposobStudia_int, int typStudia_int, int studijnyProgram_int);

    // Destruktor
    ~Student_cls() {}

    bool Bakalar_bl();

    bool Inzinier_bl();

    bool Doktorand_bl();

    bool DenneStudium_bl();

    bool ExterneStudium_bl();

    bool ProgramStudia_bl();

    void vypis(); //vypis pre uzivatela

};
/* ************** class Student_cls ************** */

/* ************** Student_cls::Student_cls ************** */
Student_cls::Student_cls(string meno_str, string priezvisko_str, int rocnik_int, int sposobStudia_int, int typStudia_int, int studijnyProgram_int) : Osoba_cls(meno_str, priezvisko_str)
{
    // **** typStudia_int ****
    if (typStudia_int >= 1 && typStudia_int <= 2)
    {
        this->typStudia_int = typStudia_int;

        // **** rocnik_int ****
        if (rocnik_int >= 1 && rocnik_int <= 5)
        {
            this->rocnik_int = rocnik_int;
        }
        else
        {
            this->rocnik_int = 0;
            this->rocnikInfo_str = "Zle zadany rocnik!";
        }

    }
    else if (typStudia_int == 3)
    {
        this->typStudia_int = typStudia_int;

        // **** rocnik_int ****
        if (rocnik_int >= 3 && rocnik_int <= 4)
        {
            this->rocnik_int = rocnik_int;
        }
        else
        {
            this->rocnik_int = 0;
            this->rocnikInfo_str = "Zle zadany rocnik!";
        }
    }
    else
    {
        this->typStudia_int = 0;
        this->rocnik_int = 0;
        this->rocnikInfo_str = "Zle zadany rocnik!";
    }


    // **** sposobStudia_int ****
    if (sposobStudia_int >= 1 && sposobStudia_int <= 2)
    {
        this->sposobStudia_int = sposobStudia_int;
    }
    else
    {
        this->sposobStudia_int = 0;
    }

    // **** studijnyProgram_int ****
    if (studijnyProgram_int >= 1 && studijnyProgram_int <= 4)
    {
        this->studijnyProgram_int = studijnyProgram_int;
    }
    else
    {
        this->studijnyProgram_int = 0;
    }

}

bool Student_cls::Bakalar_bl()
{
    if (typStudia_int == 1)
    {
        return (rocnik_int >= 1 && rocnik_int <= 3);
    }
    else
    {
        return false;
    }
}

bool Student_cls::Inzinier_bl()
{
    if (typStudia_int == 2)
    {
        return (rocnik_int >= 4 && rocnik_int <= 5);
    }
    else
    {
        return false;
    }
}

bool Student_cls::Doktorand_bl()
{
    if (typStudia_int == 3)
    {
        return (rocnik_int >= 3 && rocnik_int <= 4);
    }
    else
    {
        return false;
    }

}

bool Student_cls::DenneStudium_bl()
{
    return (sposobStudia_int == 1 );
}

bool Student_cls::ExterneStudium_bl()
{
    return (sposobStudia_int == 2 );
}

void Student_cls::vypis() //vypis pre uzivatela
{
    string Trieda_str = "";
    string sposobStudia_str = "";
    string StudijnyProgram_str = "";

    if (Bakalar_bl()) //ak je true napise Bakalar inak pokracuje na else if
    {
        Trieda_str = "Bakalar";
    }
    else if (Inzinier_bl()) //ak je true napise Inzinier
    {
        Trieda_str = "Inzinier";
    }
    else if (Doktorand_bl()) //ak je true napise Doktorand
    {
        Trieda_str = "Doktorand";
    }
    else if (typStudia_int == 0)
    {
        Trieda_str = "Zle zadany typ studia";
    }


    if (DenneStudium_bl()) //ak je true napise Denne studium inak pokracuje na else if
    {
        sposobStudia_str = "Denne studium";
    }
    else if (ExterneStudium_bl()) //ak je true napise Externe studium
    {
        sposobStudia_str = "Externe studium";
    }
    else if (sposobStudia_int == 0)
    {
        sposobStudia_str = "Zle zadany sposob studia";
    }

    switch (studijnyProgram_int) {
        case 1:
            StudijnyProgram_str = "Aplikovana Informatika";
            break;
        case 2:
            StudijnyProgram_str = "Aplikovana Biologia";
            break;
        case 3:
            StudijnyProgram_str = "Biotechnologie";
            break;
        case 4:
            StudijnyProgram_str = "Chemia";
            break;
        default:
            StudijnyProgram_str = "Neplatne cislo studijneho programu.";
    }



    cout << getMeno_str() << " " << getPriezvisko_str() << " je v " << rocnik_int << " rocniku " << Trieda_str << " | " << rocnikInfo_str << endl;
    cout << getMeno_str() << " " << getPriezvisko_str() << " ma " << sposobStudia_str << endl;
    cout << getMeno_str() << " " << getPriezvisko_str() << " studuje: " << StudijnyProgram_str << endl;
    cout << " " << endl;
}

// Vkladanie znamok

bool Student_cls::vlozZnamku(int znamka)
{
    if (pocetZnamok_int >= 10)
    {
        cout << "POZOR, zadali ste maximalny pocet znamok." << endl;
        cout << "Maximalny pocet pre vypocet priemeru je 10 znakom." << endl;
        return false;
    }

    if (znamka >= 1 && znamka <= 5) // kontrola platnosti znamky
    {
        znamky[pocetZnamok_int++] = znamka;
        return true;
    }
    else
    {
        cout << "Nepodarilo sa pridat znamku. Znamka je mimo rozsahu 1 az 5." << endl;
        return false;
    }
}

double Student_cls::priemer()
{
    double priemer_dbl = 0.0;

    for (int i = 0; i < pocetZnamok_int; i++)
    {
        priemer_dbl += znamky[i];
    }

    if (pocetZnamok_int > 0)
    {
        priemer_dbl /= pocetZnamok_int;
    }
    return priemer_dbl;
}
/* ************** Student_cls::Student_cls ************** */

/* ************** class Zamestnanec_cls ************** */
class Zamestnanec_cls : public Osoba_cls
{
    private:
        int osobneCislo_int;
        int pracovnyPomer_int; // 1-doba neurcita, 2-doba urcita, 3-skratena pracovna doba
        int typZamestnanca_int; // 1-Pedagog, 2-Ostatne
        string titul_str;
        int titul_int;
public:

    // Konstruktor
    Zamestnanec_cls(int osobneCislo_int, string titul_str, string meno_str, string priezvisko_str, int pracovnyPomer_int, int typZamestnanca_int);

    // Destruktor
    ~Zamestnanec_cls() {}

    // Getter a setter pre osobneCislo_int
    int getOsobneCislo_int() const;

    void setOsobneCislo_int(int osobneCislo_int);

    // Getter a setter pre osobneCislo_int
    string getTitul_str() const;

    void setTitul_str(string titul_str);

    bool PracPomNeurcita_bl();

    bool PracPomUrcita_bl();

    bool PracPomSkrateny_bl();

    bool Titul_bl();

    bool TypZamPedagog_bl();

    bool TypZamOstatne_bl();

    void vypis();
};
/* ************** class Zamestnanec_cls ************** */

/* ************** Zamestnanec_cls::Zamestnanec_cls ************** */
Zamestnanec_cls::Zamestnanec_cls(int osobneCislo_int, string titul_str, string meno_str, string priezvisko_str, int pracovnyPomer_int, int typZamestnanca_int) : Osoba_cls(meno_str, priezvisko_str)
{
    // **** osobneCislo_int ****
    this->osobneCislo_int=osobneCislo_int;

    // **** titul_str ****
    this->titul_str = titul_str;


    // **** pracovnyPomer_int ****
    if (pracovnyPomer_int >= 1 && pracovnyPomer_int <= 3)
    {
        this->pracovnyPomer_int = pracovnyPomer_int;
    }
    else
    {
        this->pracovnyPomer_int = 0; //inak pracovnyPomer_int = 0
    }

    // **** typZamestnanca_int ****
    if (typZamestnanca_int >= 1 && typZamestnanca_int <= 2)
    {
        this->typZamestnanca_int = typZamestnanca_int; //ak je v rozsahu 1 ÷ 2 tak typZamestnanca_int = 1 alebo 2
    }
    else
    {
        this->typZamestnanca_int = 0; //inak typZamestnanca_int = 0
    }

}

int Zamestnanec_cls::getOsobneCislo_int() const
{
    return osobneCislo_int;
}

void Zamestnanec_cls::setOsobneCislo_int(int osobneCislo_int)
{
    this->osobneCislo_int=osobneCislo_int;
}

string Zamestnanec_cls::getTitul_str() const
{
    return titul_str;
}

void Zamestnanec_cls::setTitul_str(string titul_str)
{
    this->titul_str=titul_str;
}

bool Zamestnanec_cls::PracPomNeurcita_bl()
{
    return (pracovnyPomer_int == 1 );
}

bool Zamestnanec_cls::PracPomUrcita_bl()
{
    return (pracovnyPomer_int == 2 );
}

bool Zamestnanec_cls::PracPomSkrateny_bl()
{
    return (pracovnyPomer_int == 3 );
}

bool Zamestnanec_cls::Titul_bl()
{
    if (titul_str.length() > 0) //ak je dlzka > 0 tak Titul_bl je TRUE
    {
        return true;
    }
    else
    {
        return false; //inak Titul_bl je FALSE
    }
}

bool Zamestnanec_cls::TypZamPedagog_bl()
{
    return (typZamestnanca_int == 1 );
}

bool Zamestnanec_cls::TypZamOstatne_bl()
{
    return (typZamestnanca_int == 2 );
}

void Zamestnanec_cls::vypis()
{
    string Titul_str = "";
    string DruhPracPom_str = "";
    string TypZamPom_str = "";

    if (Titul_bl())
    {
        Titul_str = titul_str;
    }
    else
    {
        Titul_str = "";
    }

    if(PracPomNeurcita_bl())
    {
        DruhPracPom_str = "pracovny pomer na dobu neurcitu";
    }
    else if(PracPomUrcita_bl())
    {
        DruhPracPom_str = "pracovny pomer na dobu urcitu";
    }
    else if(PracPomSkrateny_bl())
    {
        DruhPracPom_str = "skrateny pracovny pomer";
    }
    else
    {
        DruhPracPom_str = "nespravne zadany typ pracovneho pomeru!";
    }

    if(TypZamPedagog_bl())
    {
       TypZamPom_str = "pedagogicky pracovnikov";
    }
    else if(TypZamOstatne_bl())
    {
       TypZamPom_str = "nepedagogicky pracovnikov";
    }
    else
    {
        TypZamPom_str = "nespravne zadany typ zamestnanca";
    }


     cout << "Osobne cislo: "<< getOsobneCislo_int() << " " << Titul_str << " " << getMeno_str() << " " << getPriezvisko_str() << "." << endl;
     cout << getMeno_str() << " " << getPriezvisko_str() << " ma " << DruhPracPom_str << "." << endl;
     cout << getMeno_str() << " " << getPriezvisko_str() << " je " << TypZamPom_str << "." << endl;
     cout << " * * * * *" << endl;
}
/* ************** Zamestnanec_cls::Zamestnanec_cls ************** */

/* ************** MAIN ************** */
int main(int argc, char** argv)
{

    Student_cls Student_clss[] = //Vlozenie studenta, rocniku, sposobu studia, typu studia a studijny program
    {
        //        meno_str, priezvisko_str, rocnik_int, sposobStudia_int, typStudia_int, studijnyProgram_int
        Student_cls("Lukas","Zaba", 1, 2, 1,1),
        Student_cls("Jano","Kocur", 4, 2, 2,2),
        Student_cls("Peter","Mucha", 1, 2, 1,3),
        Student_cls("Martin","Zajac", 9, 1, 3,9),
        Student_cls("Jozef","Kralik", 3, 2, 1,4)
    };


    int numStudent_int = sizeof(Student_clss) / sizeof(Student_cls); //vypocitanie poctu opakovani pre Student_clss[i]

    for (int i = 0; i < numStudent_int; i++)
    {
        Student_clss[i].vypis();
    }

    cout << " ******** "<< endl;

    Student_cls Jano("Jano","Hrasko", 4, 1,2,1); //vlozenie znamky pre studenta Jano
    Jano.vlozZnamku(4);
    Jano.vlozZnamku(5);
    Jano.vlozZnamku(1);
    Jano.vlozZnamku(3);
    Jano.vlozZnamku(8);
    Jano.vlozZnamku(3);
    Jano.vlozZnamku(6);
    Jano.vlozZnamku(3);
    Jano.vlozZnamku(3);
    Jano.vlozZnamku(3);
    Jano.vlozZnamku(3);
    Jano.vlozZnamku(5);

    /* Rucne zadavanie som vynechal.
        cout << " ******** "<< endl;
        int novaZnamka;

        cout << "Zadajte novu znamku (pre ukoncenie vkladania stlac 0): ";
        cin >> novaZnamka;
        Jano.vlozZnamku(novaZnamka);

        if (novaZnamka != 0) //ak je 0 ukonci vkladanie
        {
            do //vlozenie znamky pre studenta Jano cez do while
            {
                cout << endl;
                cout << "Zadajte dalsiu znamku (pre ukoncenie vkladania stlac 0): ";
                cin >> novaZnamka;

                if (novaZnamka != 0) //ak to nie je 0 tak pokracuj nizsie
                {
                    bool vysledok_TF = Jano.vlozZnamku(novaZnamka); //zisti ci je vlozZnamku TRUE alebo FALSE

                    if (!vysledok_TF) //ak je FALSE informuj
                    {
                        cout << "Nepodarilo sa pridat znamku." << endl;
                    }
                }

            }
            while(novaZnamka!=0);  //ak je 0 ukonci zadavanie novaZnamka
        }

        cout << " ******** "<< endl;
    */

    cout << endl;
    Jano.vypis();
    cout << "Priemer znamok pre studenta " << Jano.getMeno_str() << " je: " << Jano.priemer() << " ." << endl;
    cout << " ******** "<< endl;
    cout << endl;

    cout << " ******** "<< endl;
    cout << " Class Zamestnanec "<< endl;
    Zamestnanec_cls Zamestnanec_clss[] = //Vlozenie studenta, rocniku, sposobu studia, typu studia a studijny program
    {
        //        osobneCislo_int, titul_int, meno_str, priezvisko_str, pracovnyPomer_int, typZamestnanca_int
        Zamestnanec_cls(1501,"Bc.","Juro","Mak", 1, 1),
        Zamestnanec_cls(1503,"","Oto","Mrkva", 3, 2),
        Zamestnanec_cls(1709,"Mgr.","Filip","Datalinka", 1, 1),
        Zamestnanec_cls(1901,"Ing.","Norbert","Petrzlenka", 1, 1),
        Zamestnanec_cls(1915,"","Stefan","Pazitka", 2, 2)
    };


    int numZamestnanec_int = sizeof(Zamestnanec_clss) / sizeof(Zamestnanec_cls); //vypocitanie poctu opakovani pre Zamestnanec_clss[i]

    for (int i = 0; i < numZamestnanec_int; i++)
    {
        Zamestnanec_clss[i].vypis();
    }

    cout << " ******** "<< endl;


    return 0;
}
