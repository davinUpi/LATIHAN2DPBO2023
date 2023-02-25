<?php

    include "Program.php";
    include_once "Civitas.php";

    $listCivitas = array();
    $driver = new Program();
    $listCivitas = $driver->readCivitasFile();

    $id = $name = $gender = $nim = $university = $prodi = $fakultas = $nik = $email = $imgPath = "";
    $errName = $errGender = $errNim = $errUniversity =  $errProdi = $errFakultas = $errNik = $errEmail = "";

    $curCivitas = "";

    if(isset($_GET["id"])){
        $id = $_GET["id"];
        foreach($listCivitas as $civitas){
            if ($id == $civitas->getId()){
                $curCivitas = $civitas;
                break;
            }
        }

        $name = $curCivitas->getName();
        $gender = $curCivitas->getGender();
        $nim = $curCivitas->getNim();
        $university = $curCivitas->getUniversity();
        $prodi = $curCivitas->getProdi();
        $fakultas = $curCivitas->getFakultas();
        $nik = $curCivitas->getNik();
        $email = $curCivitas->getEmail();
        $imgPath = $curCivitas->getImgPath();
    }

    if ($_SERVER["REQUEST_METHOD"] == "POST"){
        
        if(isset($_POST["id"])){
            $id = $_POST["id"];
        }

        if(empty($_POST["name"]) ){
            $errName = "Name is required";
         }
         else if(strrpos($_POST['name'], ' ')){
            $errName = "Must not contain spaces!";
         }
         else{
             $name = htmlspecialchars(trim($_POST["name"]));
         }

         $gender = htmlspecialchars(trim($_POST['gender']));
         
         if(empty($_POST["nim"])){
             $errNim = "Nim is required";
         }
         else if(strrpos($_POST['nim'], ' ')){
            $errNim = "Must not contain spaces!";
         }
         else{
             $nim = htmlspecialchars(trim($_POST["nim"]));
         }

         if(empty($_POST["university"])){
            $errUniversity = "University is required";
        }
        else if(strrpos($_POST['prodi'], ' ')){
           $errUniversity = "Must not contain spaces!";
        }
        else{
            $universitas = htmlspecialchars(trim($_POST["university"]));
        }
 
         if(empty($_POST["prodi"])){
             $errProdi = "Prodi is required";
         }
         else if(strrpos($_POST['prodi'], ' ')){
            $errProdi = "Must not contain spaces!";
         }
         else{
             $prodi = htmlspecialchars(trim($_POST["prodi"]));
         }
         
         if(empty($_POST["fakultas"])){
             $errFakultas = "Fakultas is required";
         }
         else if(strrpos($_POST['fakultas'], ' ')){
            $errFakultas = "Must not contain spaces!";
         }
         else{
             $fakultas = htmlspecialchars(trim($_POST["fakultas"]));
         }

         if(empty($_POST["nik"])){
            $errNik = "NIK is required";
        }
        else if(strrpos($_POST['nik'], ' ')){
           $errNik = "Must not contain spaces!";
        }
        else{
            $nik = htmlspecialchars(trim($_POST["nik"]));
        }

        if(empty($_POST["email"])){
            $email = "Email is required";
        }
        else if(!filter_var($_POST["email"], FILTER_VALIDATE_EMAIL)){
           $errEmail = "Must be a valid email!";
        }
        else{
            $email = htmlspecialchars(trim($_POST["email"]));
        }

         if(
            empty($errName) &&
            empty($errGender) &&
            empty($errNim) &&
            empty($errUniversity) &&
            empty($errProdi) &&
            empty($errFakultas) &&
            empty($errNik) &&
            empty($errEmail)
         ){
            if(empty($id)){
                array_push($listCivitas, new Civitas($driver->getNumCivitas(), $name, $gender, $nim, $university, $prodi, $fakultas, $nik, $email));
            }else{
                foreach($listCivitas as $civitas){
                    if ($id == $civitas->getId()){
                        $curCivitas = $civitas;
                        break;
                    }
                }
                $curCivitas->setName($name);
                $curCivitas->setGender($gender);
                $curCivitas->setNim($nim);
                $curCivitas->setUniversity($universitas);
                $curCivitas->setProdi($prodi);
                $curCivitas->setFakultas($fakultas);
                $curCivitas->setNik($nik);
                $curCivitas->setEmail($email);
            }
            $driver->writeCivitasFile($listCivitas);
            header('Location: index.php');
         }

    }

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
    <div class="wrapper m-5">
        <h2>Civitas Form</h2>
        <p>Please fill this form to create an account.</p>
        <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post">
            <div class="form-group">
                <label>Nama</label>
                <input type="text" name="name" class="form-control <?php echo (!empty($errName)) ? 'is-invalid' : ''; ?>" value="<?php echo $name; ?>">
                <span class="invalid-feedback"><?php echo $errName; ?></span>
            </div>
            <div class="form-group">
                <div class="form-check form-check-inline">
                    <input class="form-check-input" type="radio" name="gender" id="flexRadioDefault1" value="Laki-laki" <?=($gender == "Laki-laki")? "checked" : " ";?> >
                    <label class="form-check-label" for="flexRadioDefault1">
                        Laki-laki
                    </label>
                    </div>
                <div class="form-check form-check-inline">
                    <input class="form-check-input" type="radio" name="gender" id="flexRadioDefault2" value="Perempuan" <?=($gender == "Perempuan")? "checked" : " ";?> >
                    <label class="form-check-label" for="flexRadioDefault2">
                        Perempuan
                    </label>
                </div>
            </div>
            <div class="form-group">
                <label>Nim</label>
                <input type="text" name="nim" class="form-control <?php echo (!empty($errNim)) ? 'is-invalid' : ''; ?>" value="<?php echo $nim; ?>">
                <span class="invalid-feedback"><?php echo $errNim; ?></span>
            </div>
            <div class="form-group">
                <label>Universitas</label>
                <input type="text" name="university" class="form-control <?php echo (!empty($errUniversity)) ? 'is-invalid' : ''; ?>" value="<?=$university; ?>">
                <span class="invalid-feedback"><?php echo $errUniversity; ?></span>
            </div>
            <div class="form-group">
                <label>Program Studi</label>
                <input type="text" name="prodi" class="form-control <?php echo (!empty($errProdi)) ? 'is-invalid' : ''; ?>" value="<?php echo $prodi; ?>">
                <span class="invalid-feedback"><?php echo $errProdi; ?></span>
            </div>
            <div class="form-group">
                <label>Fakultas</label>
                <input type="text" name="fakultas" class="form-control <?php echo (!empty($errFakultas)) ? 'is-invalid' : ''; ?>" value="<?php echo $fakultas; ?>">
                <span class="invalid-feedback"><?php echo $errFakultas; ?></span>
            </div>
            <div class="form-group">
                <label>NIK</label>
                <input type="text" name="nik" class="form-control <?php echo (!empty($errNik)) ? 'is-invalid' : ''; ?>" value="<?php echo $nik; ?>">
                <span class="invalid-feedback"><?php echo $errNik; ?></span>
            </div>
            <div class="form-group">
                <label>Email</label>
                <input type="text" name="email" class="form-control <?php echo (!empty($errEmail)) ? 'is-invalid' : ''; ?>" value="<?php echo $email; ?>">
                <span class="invalid-feedback"><?php echo $errEmail; ?></span>
            </div>
            <input type="hidden" name="id" id="hiddenField" value="<?php echo $id ?>" />
            <div class="form-group">
                <input type="submit" class="btn btn-primary" value="Submit">
                <input type="reset" class="btn btn-secondary ml-2" value="Reset">
            </div>
        </form>
    </div>
    <script src="https://kit.fontawesome.com/13338d9b84.js" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
</body>
</html>