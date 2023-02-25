<?php

    include "Program.php";
    include_once "Civitas.php";

    $listCivitas = array();
    $mainDriver = new Program();
    $listCivitas = $mainDriver->readCivitasFile();

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>

    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">

</head>
<body>
    <div class="sticky-top">
        <header class="d-flex navbar navbar-primary p-3 flex-row justify-content-end nav-tabs flex-nowrap" id="mainNav">
            <div class="ml-2 d-block">
                <a href="form.php">
                    <button class="btn btn-primary"><i class="fa-solid fa-plus"></i></button>
                </a>
            </div>
        </header>
    </div>
    <div class="d-block ml-5">
        <main class="d-flex container flex-wrap flex-row justify-content-start m-5">
            <?php
                foreach($listCivitas as $civitas){
            ?>
            <div class="card m-5">
                <button type="button" class="btn" data-bs-toggle="modal" data-bs-target="#civitaModal<?=$civitas->getId()?>">
                    <img src="image/<?=$civitas->getImgPath()?>" alt="<?=$civitas->getName()?> image" class="card-image-top img-fluid img-thumbnail" style="
                            width: 234px;
                            height: 234px;
                            object-fit:cover;
                            object-position:50% 5%;
                            ">
                    <div class="card-body">
                        <h5 class="card-title m-2">
                            <span class="d-inline-block text-truncate" style="max-width: 200px; color:black;">
                                <?=$civitas->getName()?>
                            </span>
                        </h5>
                        <p class="card-text m-2">
                            <span class="d-inline-block text-truncate" style="max-width: 200px; color:black;">
                                <?=$civitas->getNim()?>
                            </span>
                        </p>
                        <p class="card-text m-2">
                            <span class="d-inline-block text-truncate" style="max-width: 200px; color:black;">
                                <?=$civitas->getProdi()?>
                            </span>
                        </p>
                        <p class="card-text m-2">
                            <span class="d-inline-block text-truncate" style="max-width: 200px; color:black;">
                                <?=$civitas->getFakultas()?>
                            </span>
                        </p>
                    </div>
                </button>
                <div class="card-footer">
                    <div>
                        <a href="form.php?id=<?=$civitas->getId()?>" style="text-decoration: none;" class="mx-1">
                            <button class="btn btn-warning"><i class="fa-solid fa-wrench"></i></button>
                        </a>
                        <a href="delete.php?id=<?=$civitas->getId()?>" style="text-decoration: none;" class="mx-1">
                            <button class="btn btn-danger"><i class="fa-solid fa-trash"></i></button>
                        </a>
                    </div>
                </div>
            </div>
            <div class="modal fade" id="civitaModal<?=$civitas->getId()?>" tabindex="-1" aria-labelledby="civitasModalLabel" aria-hidden="true">
                <div class="modal-dialog modal-dialog-centered">
                    <div class="modal-content">
                        <div class="card mb-3">
                            <div class="row g-0">
                                <div class="col-md-4">
                                    <img src="image/<?=$civitas->getImgPath()?>" class="img-fluid rounded-start">
                                </div>
                                <div class="col-md-8">
                                    <div class="card-body">
                                        <h5 class="card-title"><?=$civitas->getName()?></h5>
                                        <p class="card-text"><?=$civitas->getGender()?></p>
                                        <p class="card-text"><?=$civitas->getEmail()?></p>
                                        <p class="card-text"><?=$civitas->getNik()?></p>
                                        <p class="card-text"><?=$civitas->getNim()?></p>
                                        <p class="card-text"><?=$civitas->getUniversity()?></p>
                                        <p class="card-text"><?=$civitas->getProdi()?></p>
                                        <p class="card-text"><?=$civitas->getFakultas()?></p>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
            <?php } ?>
        </main>
    </div>
    
    <script src="https://kit.fontawesome.com/13338d9b84.js" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
</body>
</html>