<?php

    include_once "Program.php";
    include_once "Civitas.php";

    $listCivitas = array();
    $driver = new Program();
    $listCivitas = $driver->readcivitasFile();

    if(isset($_GET['id'])){
        $id = $_GET["id"];
        $curCivitas;
        foreach($listCivitas as $civitas){
            if ($id == $civitas->getId()){
                $curCivitas = $civitas;
                break;
            }
        }
        if(isset($curCivitas)){
            $idx = array_search($curCivitas, $listCivitas);
            array_splice($listCivitas, $idx, 1);
            $driver->writecivitasFile($listCivitas);
        }

    }

    header('Location: index.php');

?>