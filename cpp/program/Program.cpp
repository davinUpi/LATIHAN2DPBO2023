#pragma once

#include <list>
#include <fstream>
#include <sstream>
#include <limits>
#include "Mahasiswa.cpp"
#include "Query_Handler.cpp"

class Program{

private:
    int numMhs;
    /// Untuk menampung jumlah mahasiswa. Digunakan sebagai ID

    std::list<Mahasiswa*> listMhs;
    /// Untuk menampung objek2 mahasiswa.

public:

    Program()
    {
        this->numMhs = 0;

    };
    ~Program(){};
    
    void start()
    ///
    /// Metode yang dieksekusi pada saat program di mulai
    ///
    {
        std::ifstream fileData;
        fileData.open("mahasiswa.dat", std::ios::out|std::ios::app);
        if(fileData.is_open())
        ///
        ///jika data mahasiswa.dat bukan null maka data-data yang berada di mahasiswa.dat masuk pada class Mahasiswa
        ///

        {
            std::string dataString;
            while(std::getline(fileData, dataString))
            {
                Query_Handler::addMahasiswa(dataString, this->listMhs);
            }
        }
        
        fileData.close();
    }
    
    void run()
    ///
    /// Metode yang dieksekusi selama program berjalan
    ///
    {
        std::string command;
        bool run = true;
        while (run)
        ///
        ///program akan run sampai user input exit
        ///
        {
            std::string err = "";
            std::string input;
            std::cin >> command;
            QUERY query = Query_Handler::setQueryType(command);
            std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if(query == QUERY::EXIT)
            ///
            ///jika input exit maka program akan berhenti run
            ///
            {
                run = false;
            }
            
            else if (query == QUERY::HELP)
            ///
            ///jika input help atau ? maka akan menunjukan cara kerja
            ///
            {
                std::cout << "Queries and how to use them:" << std::endl;
                std::cout << "ketik 'ADD' untuk menambahkan data, lalu masukkan:" << std::endl;
                std::cout << "{nama} {nim} {jenis_kelamin} {universitas} {prodi} {fakultas} {email_universitas} {nik}" << std::endl << std::endl;
                std::cout << "Ketik 'CHANGE' untuk mengubah nilai atribut mahasiswa, lalu masukkan: " << std::endl;
                std::cout << "{change attribute} {change value} where {search attribute} {search value}" << std::endl << std::endl;
                std::cout << "Ketik 'DELETE' untuk menghapus mahasiswa, lalu masukkan:" << std::endl;
                std::cout << "{search attribute} {search value}" << std::endl << std::endl;
                std::cout << "Print: print" << std::endl;
            }
            
            else if (query == QUERY::ADD)
            ///
            ///jika input add maka akan tambah data mahasiswa ke list
            ///
            {
                std::cout << "{nama} {nim} {jenis_kelamin} {universitas} {prodi} {fakultas} {nik} {email_universitas}" << std::endl;
                std::getline(std::cin, input);
                Query_Handler::addMahasiswa(input, listMhs, &err);
            }
            
            else if (query == QUERY::CHANGE)
            ///
            ///jika input change maka akan mengubah data di list menjadi data baru
            ///
            {
                std::cout << "{change attribute} {change value} where {search attribute} {search value}" << std::endl;
                getline(std::cin, input);
                Query_Handler::changeMahasiswa(input, listMhs, &err);
                /// Metode untuk mengubah nilai attribut Mahasiswa
                
            }
            
            else if (query == QUERY::DELETE)
            ///
            ///jika input delete maka akan menghapus data di list yang diinputkan oleh user
            ///
            {
                std::cout << "{search attribute} {search value}" << std::endl;
                getline(std::cin, input);
                Query_Handler::deleteMahasiswa(input, listMhs, &err);
                /// Metode untuk menghapus Mahasiswa
                
            }
            
            else if(query == QUERY::PRINT)
            ///
            ///jika input print maka akan print data yang ada di list
            ///
            {
                for(auto i : listMhs)
                {
                    std::cout << "O" << std::endl;
                    std::cout << "> NAMA         : " << i->getName() << std::endl;
                    std::cout << "> NIM          : " << i->getNim() << std::endl;
                    std::cout << "> JENIS KELAMIN: " << i->getGenderAsString() <<std::endl;
                    std::cout << "> UNIVERSITAS  : " << i->getUniversity() << std::endl;
                    std::cout << "> PROGRAM STUDI: " << i->getProdi() << std::endl;
                    std::cout << "> FAKULTAS     : " << i->getFac() << std::endl;
                    std::cout << "> NIK          : " << i->getNik() << std::endl;
                    std::cout << "> EMAIL        : " << i->getUnivMail() << std::endl;
                    std::cout << "O" << std::endl << std::endl;
                }
            }
            else
                err = "Query not recognizeable!";
            
            if(err != "")Query_Handler::errorHandler(err);
        }
    }
    
    void close ()
    ///
    ///fungsi akan di eksekusi pada saat program berjalan
    ///
    {
        /*
        std::ofstream file;
        file.open("mahasiswa.dat", std::ios::out|std::ios::app);
        if(file.is_open())
        {
            for(auto const i : listMhs)
            {
                file << i->getName() << '\n';
            }
            listMhs.clear();
            
        }
        file.close();
        */
       listMhs.clear();
    }

};
