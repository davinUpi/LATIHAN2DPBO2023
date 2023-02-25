<?php

include_once("Mahasiswa.php");

class Civitas extends Mahasiswa{

    private $university;
    private $email;
    public function __construct($id, $name, $gender ,$nim, $university, $prodi, $fakultas, $nik, $email){
        $this->id = $id;
        $this->name = $name;
        $this->nim = $nim;
        $this->university = $university;
        $this->prodi = $prodi;
        $this->fakultas = $fakultas;
        $this->imgPath = "default.jpg";
        $this->gender = $gender;
        $this->nik = $nik;
        $this->email = $email;
    }

    public function setUniversity($university){
        $this->university = $university;
    }

    public function setEmail($email){
        $this->email = $email;
    }

    public function getUniversity(){
        return $this->university;
    }

    public function getEmail(){
        return $this->email;
    }
}

?>