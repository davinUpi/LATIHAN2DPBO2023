#pragma once

#include <string>

using namespace std;

enum class GENDER{
    MALE = 0,
    FEMALE,
    ATTACK_HELICOPTER
};

class Human{

protected:
    string nik;
    string name;
    GENDER gender;

public:

    Human(string nik = "", string name = "", GENDER gender = GENDER::ATTACK_HELICOPTER){
        this->nik = nik;
        this->name = name;
        this->gender = gender;
    }

    ~Human(){};

    //
    // Setters, to set the values
    //
    void setNik(string nik){
        this->nik = nik;
    }

    void setName(string name){
        this->name = name;
    }

    void setGender(GENDER gender){
        this->gender = gender;
    }

    //
    // Getters, to get val
    //

    string getNik(){
        return this->nik;
    }

    string getName(){
        return this->name;
    }

    GENDER getGender(){
        return this->gender;
    }

    string getGenderAsString(){
        if(this->gender == GENDER::MALE) return "Laki-laki";
        else if (this->gender == GENDER::FEMALE) return "Perempuan";
        else return "Attack helicopter";
    }

};