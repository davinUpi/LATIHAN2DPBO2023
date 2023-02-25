<?php

include_once("Civitas.php");
include_once("Human.php");

class Program{
    private $filepath;
    private $numcivitas;

    public function __construct(){
        $this->filepath = "civitas.dat";
    }

    public function getNumcivitas(){
        return $this->numcivitas;
    }

    public function readCivitasFile(){
        $file = @fopen($this->filepath, 'r');
        if($file){
            $listCivitas = array();
            foreach(file($this->filepath) as $line){
                $this->numcivitas++;
                $datas = explode(' ', $line);

                array_push($listCivitas, new Civitas(
                    $this->numcivitas,$datas[0], $datas[1], $datas[2], $datas[3],
                    $datas[4], $datas[5], $datas[6], $datas[7]
                ));
            }
            fclose($file);
            return $listCivitas;
        }
    }

    public function writeCivitasFile($listCivitas){

        $file = @fopen($this->filepath, "w");
        if($file){
            foreach($listCivitas as $civitas){
                $name = $civitas->getName();
                $gender = $civitas->getGender();
                $nim = $civitas->getNim();
                $university = $civitas->getUniversity();
                $prodi = $civitas->getProdi(); 
                $fakultas = $civitas->getFakultas();
                $nik = $civitas->getNik();
                $email = $civitas->getEmail();
                $data = $name . " " . $gender . " " . $nim . " " . $university . " " . 
                        $prodi . " " . $fakultas . " " . $nik . " " . $email; 
                fwrite($file, $data);
            }
            fclose($file);
        }
    }
}

?>