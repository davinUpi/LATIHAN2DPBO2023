#pragma once

#include <string>

using namespace std;

class Academy{

protected:
    string university;
    string univ_mail;

public:

    Academy(string university = "", string univ_mail = ""){
        this->university = university;
        this->univ_mail = univ_mail;
    }

    /*
    * Setter
    */
   void setUniversity(string university){
        this->university = university;
   }

   void setUnivMail(string univ_mail){
        this->univ_mail = univ_mail;
   }

   /*
   * Getter
   */
  string getUniversity(){
    return this->university;
  }

  string getUnivMail(){
    return this->univ_mail;
  }

};