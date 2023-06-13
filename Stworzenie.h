//
// Created by maksd on 14.06.2022.
//

#ifndef PROJEKT_STWORZENIE_H
#define PROJEKT_STWORZENIE_H


#include <string>
#include <vector>

enum Rodzaj{WODA,ZIEMIA,POWIETRZE,OGIEN,LOD,STAL};
class Stworzenie {
public:

    Stworzenie();
    Stworzenie(Rodzaj rodzaj, const std::string &nazwaStworzenia, int hp, int sila, int zrecznosc,
               const std::string &nazwaMocy, int maxuzycia, int silaSpec, int wymaganePunktyExp);

    void atak(Stworzenie& stworzenie);
    void atakspecjalny(Stworzenie& stworzenie);
    //void wymiana();
    //void ewolucja();
    bool isAlive();
    double tabelasil(Stworzenie& stworzenie);
    static bool szansanaunik(Stworzenie& stworzenie);
    //static void wypiszStworzenia();
    std::vector<Stworzenie> wszystkieStworzenia;
    static void printvector(std::vector<Stworzenie> myvector);
    //std::ostream & operator<<(std::ostream& ostream,Stworzenie stworzenie);
    friend std::ostream & operator<<(std::ostream& ostream, Stworzenie stworzenie);
    std::string getRodzajString(int a);

    const std::string &getNazwaStworzenia() const;

    void setNazwaStworzenia(const std::string &nazwaStworzenia);

    int getHp();

    int getWymaganePunktyExp() const;

    void setWymaganePunktyExp(int wymaganePunktyExp);

    void setHp(int hp);

    int getSila();

    void setSila(int sila);

    int getZrecznosc() const;

    void setZrecznosc(int zrecznosc);

    const std::string &getNazwaMocy() const;

    void setNazwaMocy(const std::string &nazwaMocy);

    int getMaxuzycia() const;

    void setMaxuzycia(int maxuzycia);

    int getSilaSpec() const;

    void setSilaSpec(int silaSpec);

    int getPunktyExp() const;

    void setPunktyExp(int punktyExp);

    Rodzaj getRodzaj() const;

    void setRodzaj(Rodzaj rodzaj);

private:
    Rodzaj rodzaj;
    std::string nazwaStworzenia;
    int HP;
    int sila;
    int zrecznosc;
    std::string nazwaMocy;
    int maxuzycia;
    int silaSpec;
    int punktyExp;
    int wymaganePunktyExp;
};

#endif //PROJEKT_STWORZENIE_H
