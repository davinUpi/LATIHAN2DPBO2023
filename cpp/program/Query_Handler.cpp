#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <cstring>
#include <list>
#include "Mahasiswa.cpp"

enum class ATTRIBUTETYPE{
    ///  
    /// kelas untuk menentukan jenis attribut
    ///
    NAME = 0,
    NIM,
    PRODI,
    FAKULTAS,
    NIK,
    GENDER,
    UNIVERSITY,
    EMAIL
};

enum class QUERY{
    HELP = 0,
    EXIT,
    PRINT,
    ADD,
    CHANGE,
    DELETE,
    NONE
};

class Query_Handler{
    ///
    /// Kelas ini berfungsi untuk memproses query2
    ///
public:
    Query_Handler(){};
    ~Query_Handler(){};
    
    static std::string lowercase(std::string query)
    ///
    /// ubah query menjadi lowercase
    ///
    {
        std::string temp = query;
        for(auto& i:temp)
            i = tolower(i);
        return temp;
    }
    
    static void delFirstWord(std::string* string)
    ///
    /// delete kata pertama dari string, digunakan untuk pembersihan query
    ///
    {
        std::string::size_type n = 0;
        n = (*string).find_first_not_of(" \t", n);
        n = (*string).find_first_of(" \t", n);
        (*string).erase(0, (*string).find_first_not_of(" \t", n));

    }

    static void errorHandler(std::string errorMsg)
    // Metode untuk ngeprint error
    {
        std::cout << "ERROR:\n" << errorMsg << std::endl;
    }

    static QUERY setQueryType(std::string input){
        if(lowercase(input) == "exit") return QUERY::EXIT;
        else if ((lowercase(input) == "help") || (lowercase(input) == "?")) return QUERY::HELP;
        else if (lowercase(input) == "print") return QUERY::PRINT;
        else if (lowercase(input) == "add") return QUERY::ADD;
        else if(lowercase(input) == "change") return QUERY::CHANGE;
        else if(lowercase(input) == "delete") return QUERY::DELETE;
        else return QUERY::NONE;
    }

    static void addMahasiswa
    ///
    /// Metode pembantu untuk memudahkan penambahan objek Mahasiswa
    ///
    (std::string input, std::list<Mahasiswa*> &lsitMhs, std::string* err = NULL)   
    {
        const int input_lenght = input.length();
        char* char_array = new char[input_lenght + 1];
        strcpy(char_array, input.c_str());

        std::string name;
        std::string nim;
        std::string prodi;
        std::string fakultas;
        std::string nik;
        std::string universitas;
        std::string email;
        GENDER gender;

        char *token = strtok(char_array, " ");
        unsigned state = 0;
        std::string temp = "";
        while((token != NULL) && (state != 8)){
            switch(state){
                case 0:
                    name = token;
                break;
                case 1:
                    nim = token;
                break;
                case 2:
                    temp = token;
                    if (lowercase(temp) == "laki-laki") gender = GENDER::MALE;
                    else if (lowercase(temp) == "perempuan") gender = GENDER::FEMALE;
                break;
                case 3:
                    universitas = token;
                break;
                case 4:
                    prodi = token;
                break;
                case 5:
                    fakultas = token;
                break;
                case 6:
                    nik = token;
                break;
                case 7:
                    email = token;
                break;
            }
            state++;
            token = strtok(NULL, " ");
        }

        if((name != "") && (nim != "")){
            lsitMhs.push_back(new Mahasiswa(name, nim, prodi, fakultas, nik, gender, universitas, email));
        }
        else{
            *err = "Atleast field Name and field Nim is fulfileld";
        }
    }
    
    static void changeMahasiswa(std::string input, std::list<Mahasiswa*> listMhs, std::string* err)
    ///
    /// mengubah attribut mahasiswa yang dituju mahasiswa
    ///
    {
        const int input_lenght = input.length();
        char* char_array = new char[input_lenght + 1];
        strcpy(char_array, input.c_str());

        ATTRIBUTETYPE changeType;
        std::string changeVal;
        /// Kedua variabel ini digunakan untuk mengubah nilai suatu atribut Mahasiswa

        ATTRIBUTETYPE serachType;
        std::string searchVal;
        // Kedua variabel ini digunakan untuk mencari Mahasiswa dengan nilai atribut tertentu
        unsigned int state = 0;
        char *token = strtok(char_array, " ");
        ///
        /// Pengulangan untuk mengolah input. Input yang berhubungan dengan
        /// Pencarian dijadikan huruf kecil
        ///
        while((token != NULL) && (state != 5) && (*err == "")){
            switch(state)
            {
                case 0:
                ///
                /// Menentukan atribut apa yang ingin diubah nilainya
                ///
                    if (lowercase(token) == "nama") changeType = ATTRIBUTETYPE::NAME;
                    else if (lowercase(token) == "nim") changeType = ATTRIBUTETYPE::NIM;
                    else if ((lowercase(token) == "prodi") || ((lowercase(token) == "program_studi"))) changeType = ATTRIBUTETYPE::PRODI;
                    else if (lowercase(token) == "fakultas") changeType = ATTRIBUTETYPE::FAKULTAS;
                    else if (lowercase(token) == "gender") changeType = ATTRIBUTETYPE::GENDER;
                    else if(lowercase(token) == "nik") changeType = ATTRIBUTETYPE::NIK;
                    else if (lowercase(token) == "universitas") changeType = ATTRIBUTETYPE::UNIVERSITY;
                    else if (lowercase(token) == "email") changeType = ATTRIBUTETYPE::EMAIL;
                    else
                    {
                        *err = "No Attribut named : ";
                        *err = *err + token;
                    }

                break;
                
                case 1:
                ///
                /// Nilai baru atribut yang diubah
                ///
                    changeVal = token;
                break;
                
                case 2:
                    if (lowercase(token) != "where") *err = "Incorrect query!";
                break;

                case 3:
                ///
                /// Menentukan atribut apa yang dijadikan patokan pencarian
                ///
                    if (lowercase(token) == "nama") serachType = ATTRIBUTETYPE::NAME;
                    else if (lowercase(token) == "nim") serachType = ATTRIBUTETYPE::NIM;
                    else if ((lowercase(token) == "prodi") || ((lowercase(token) == "program_studi"))) changeType = ATTRIBUTETYPE::PRODI;
                    else if (lowercase(token) == "fakultas") serachType = ATTRIBUTETYPE::FAKULTAS;
                    else if (lowercase(token) == "gender") serachType = ATTRIBUTETYPE::GENDER;
                    else if(lowercase(token) == "nik") serachType = ATTRIBUTETYPE::NIK;
                    else if (lowercase(token) == "universitas") serachType = ATTRIBUTETYPE::UNIVERSITY;
                    else if (lowercase(token) == "email") serachType = ATTRIBUTETYPE::EMAIL;
                    else
                    {
                        *err = "No Attribut named : ";
                        *err = *err + token;
                    }
                break;
                case 4:
                ///
                /// Nilai atribut yang dicari
                ///
                    searchVal = token;
                break;

            }

            state++;
            token = strtok(NULL, " ");
        }

        if(state == 5)
        ///
        /// Bila semua data yang dibutuhkan didapatkan, baru melakukan perubahan nilai atribut
        /// Mahasiswa yang dituju
        ///
        {
            Mahasiswa* changeMhs = searchMahasiswa(serachType, listMhs, searchVal);
            if (changeMhs != NULL)
            ///
            /// Bila Mahasiswa yang dicari ada, baru mengubah attributnya
            ///
            {
                if (changeType == ATTRIBUTETYPE::NAME) changeMhs->setName(changeVal);
                else if (changeType == ATTRIBUTETYPE::NIM) changeMhs->setNim(changeVal);
                else if (changeType == ATTRIBUTETYPE::PRODI) changeMhs->setProdi(changeVal);
                else if (changeType == ATTRIBUTETYPE::FAKULTAS) changeMhs->setFac(changeVal);
                else if (changeType == ATTRIBUTETYPE::NIK) changeMhs->setNik(changeVal);
                else if (changeType == ATTRIBUTETYPE::UNIVERSITY) changeMhs->setUniversity(changeVal);
                else if (changeType == ATTRIBUTETYPE::EMAIL) changeMhs->setUnivMail(changeVal);
                else if (changeType == ATTRIBUTETYPE::GENDER){
                    GENDER gender;
                    if (lowercase(changeVal) == "laki-laki") gender = GENDER::MALE;
                    else if (lowercase(changeVal) == "perempuan") gender = GENDER::FEMALE;
                    else gender = GENDER::ATTACK_HELICOPTER;
                    changeMhs->setGender(gender);
                }

            }
            else
            {
                *err = "Mahasiswa not found";
            }
        }
        else
        {
            *err = "Query is incorrect!";
        }
    }
    
    static void deleteMahasiswa(std::string input, std::list<Mahasiswa*> &listMhs, std::string* err)
    //
    /// menghapus mahasiswa tertentu
    //
    {
        const int input_lenght = input.length();
        char* char_array = new char[input_lenght + 1];
        strcpy(char_array, input.c_str());

        std::string deleteVal;
        ATTRIBUTETYPE deleteType;
        /// variabel yang digunakan untuk mencari Mahasiswa yang akan dihapus

        unsigned int state = 0;
        char *token = strtok(char_array, " ");
        //
        /// Pengulangan untuk mengolah input
        //
        while((token != NULL) && (state != 2) && (*err == "")){
            switch(state)
            {
                case 0:
                    if (lowercase(token) == "nama") deleteType = ATTRIBUTETYPE::NAME;
                    else if (lowercase(token) == "nim") deleteType = ATTRIBUTETYPE::NIM;
                    else if ((lowercase(token) == "prodi") || ((lowercase(token) == "program_studi"))) deleteType = ATTRIBUTETYPE::PRODI;
                    else if (lowercase(token) == "fakultas") deleteType = ATTRIBUTETYPE::FAKULTAS;
                    else if (lowercase(token) == "gender") deleteType = ATTRIBUTETYPE::GENDER;
                    else if(lowercase(token) == "nik") deleteType = ATTRIBUTETYPE::NIK;
                    else if (lowercase(token) == "universitas") deleteType = ATTRIBUTETYPE::UNIVERSITY;
                    else if (lowercase(token) == "email") deleteType = ATTRIBUTETYPE::EMAIL;
                    else
                    {
                        *err = "No Attribut named : ";
                        *err = *err + token;
                    }

                break;

                case 1:
                    deleteVal = token;
                break;
            }

            state++;
            token = strtok(NULL, " ");
        }

        if (state == 2)
        //
        /// Bila input sesuai, mencari Mahasiswa yang akan dihapus lalu menghapusnya.
        //
        {
            Mahasiswa* delMhs = searchMahasiswa(deleteType, listMhs, deleteVal);
            if(delMhs != NULL)
            {
                listMhs.remove(delMhs);
                free(delMhs);
            }
            else
            {
                *err = "Mahasiswa not found!";
            }
        }
        else
            *err = "Query incomplete!";
    }
    
    static Mahasiswa* searchMahasiswa (ATTRIBUTETYPE searchType, std::list<Mahasiswa*> listMhs, std::string string)
    //
    /// mencari mahasiswa. Akan mengembalikan null bila tidak ketemu
    //
    {
        Mahasiswa* value = NULL;
        bool found = false;
        string = lowercase(string);
        for (auto const& i : listMhs)
        //
        /// Melakukan pencarian di dalam list
        //
        {
            if (searchType == ATTRIBUTETYPE::NAME)
            {
                if(string == lowercase(i->getName())) found = true;
            }
            else if (searchType == ATTRIBUTETYPE::NIM)
            {
                if (string == i->getNim()) found = true;
            }    
            else if (searchType == ATTRIBUTETYPE::PRODI)
            {
                if (string == lowercase(i->getProdi())) found = true;
            }
            else if (searchType == ATTRIBUTETYPE::FAKULTAS)
            {
                if (string == lowercase(i->getFac())) found = true;
            }
            else if (searchType == ATTRIBUTETYPE::NIK){
                if (string == lowercase(i->getNik())) found = true;
            }
            else if (searchType == ATTRIBUTETYPE::UNIVERSITY){
                if (string == lowercase(i->getUniversity())) found = true;
            }
            else if (searchType == ATTRIBUTETYPE::EMAIL){
                if (string == lowercase(i->getUnivMail())) found = true;
            }
            else if (searchType == ATTRIBUTETYPE::GENDER){
                GENDER temp;
                if (lowercase(string) == "laki-laki") temp = GENDER::MALE;
                else if (lowercase(string) == "perempuan") temp = GENDER::FEMALE;
                else temp = GENDER::ATTACK_HELICOPTER;

                if (temp == i->getGender()) found = true;
            }

            if (found == true)
            {
                value = i;
                break;
            }
        }

        return value;
    }

};
