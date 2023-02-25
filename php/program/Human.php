<?php

enum GENDER{
    case MALE;
    case FEMALE;
    case M4A1E7_SHERMAN_JUMBO;

}
class Human{
        protected $id;
        protected $name;
        protected $nik;
        protected $gender;

        public function __construct($id, $name, $nik, $gender){
            $this->id = $id;
            $this->name = $name;
            $this->nik = $nik;
            $this->gender = $gender;
        }

        # Setter
        public function setId($input){
            $this->id = $input;
        }

        public function setName($name){
            $this->name = $name;
        }

        public function setNik($nik){
            $this->nik = $nik;
        }

        public function setGender($gender){
            $this->gender = $gender;
        }

        # GEtter
        public function getId(){
            return $this->id;
        }
        public function getName(){
            return $this->name;
        }

        public function getNik(){
            return $this->nik;
        }

        public function getGender(){
            return $this->gender;
        }

        # accessories
}
?>