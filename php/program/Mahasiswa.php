<?php

include_once("Human.php");
class Mahasiswa extends Human{
    protected $nim;
    protected $prodi;
    protected $fakultas;
    protected $imgPath;

    public function __construct($id, $name, $gender ,$nim, $prodi, $fakultas, $nik){
        $this->id = $id;
        $this->name = $name;
        $this->nim = $nim;
        $this->prodi = $prodi;
        $this->fakultas = $fakultas;
        $this->imgPath = "default.jpg";
        $this->gender = $gender;
        $this->nik = $nik;
    }

    //Setter
    public function setNim($input){
        $this->nim = $input;
    }
    public function setProdi($input){
        $this->prodi = $input;
    }
    public function setFakultas($input){
        $this->fakultas = $input;
    }
    public function setImgPath($input){
        $this->imgPath;
    }

    // Getter
    public function getNim(){
        return $this->nim;
    }
    public function getProdi(){
        return $this->prodi;
    }
    public function getFakultas(){
        return $this->fakultas;
    }
    public function getImgPath(){
        return $this->imgPath;
    }
}
?>