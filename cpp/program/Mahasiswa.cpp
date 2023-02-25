#pragma once

#include <iostream>
#include <string>
#include "Human.cpp"
#include "Academy.cpp"

class Mahasiswa : public Human, public Academy
{

private:
    std::string nim;
    std::string prodi;
    std::string fakultas;

public:
    Mahasiswa(
        std::string newName = "", 
        std::string newNim = "",
        std::string newProdi = "",
        std::string newFac = "",
        std::string newNik = "",
        GENDER newGender = GENDER::ATTACK_HELICOPTER,
        std::string newUniversity = "",
        std::string newUnivMail = "")
        {
            this->name = newName;
            this->nim = newNim;
            this->prodi = newProdi;
            this->fakultas = newFac;
            this->nik = newNik;
            this->gender = newGender;
            this->university = newUniversity;
            this->univ_mail = newUnivMail;
        }

    ~Mahasiswa(){}

    //Setter
    void setNim(std::string newNim)
    {
        this->nim = newNim;
    }
    void setProdi(std::string newProdi)
    {
        this->prodi = newProdi;
    }
    void setFac(std::string newFac)
    {
        this->fakultas = newFac;
    }

    //getter
    std::string getNim()
    {
        return this->nim;
    }
    std::string getProdi()
    {
        return this->prodi;
    }
    std::string getFac()
    {
        return this->fakultas;
    }

};