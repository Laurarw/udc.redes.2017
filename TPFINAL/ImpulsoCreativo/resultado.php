<?php
session_start();

$answer1 = $_POST['primera'];
$answer2 = $_POST['segunda'];
$answer3 = $_POST['tercera'];
$answer4 = $_POST['cuarta'];
$answer5 = $_POST['quinta'];
$answer6 = $_POST['sexta'];
$answer7 = $_POST['septima'];
$answer8 = $_POST['octava'];
$answer9 = $_POST['novena'];
$answer10 = $_POST['decima'];
$answer11 = $_POST['decima_primera'];
$answer12 = $_POST['decima_segunda'];
$totalCorrect = 0;

switch ($answer1) {
    case "A":
        $totalCorrect= $totalCorrect;
        break;
    case "B":
        $totalCorrect= $totalCorrect+2;
        break;
    default:
        $totalCorrect= $totalCorrect+1;
}

switch ($answer2) {
    case "A":
        $totalCorrect= $totalCorrect+2;
        break;
    case "B":
        $totalCorrect= $totalCorrect;
        break;
    default:
        $totalCorrect= $totalCorrect+1;
}

switch ($answer3) {
    case "A":
        $totalCorrect= $totalCorrect;
        break;
    case "B":
        $totalCorrect= $totalCorrect+1;
        break;
    default:
        $totalCorrect= $totalCorrect+2;
}

switch ($answer4) {
    case "A":
        $totalCorrect= $totalCorrect;
        break;
    case "B":
        $totalCorrect= $totalCorrect+2;
        break;
    default:
        $totalCorrect= $totalCorrect+1;
}

switch ($answer5) {
    case "A":
        $totalCorrect= $totalCorrect;
        break;
    case "B":
        $totalCorrect= $totalCorrect+2;
        break;
    default:
        $totalCorrect= $totalCorrect+1;
}

switch ($answer6) {
    case "A":
        $totalCorrect= $totalCorrect;
        break;
    case "B":
        $totalCorrect= $totalCorrect+1;
        break;
    default:
        $totalCorrect= $totalCorrect+2;
}

switch ($answer7) {
    case "A":
        $totalCorrect= $totalCorrect+2;
        break;
    case "B":
        $totalCorrect= $totalCorrect+1;
        break;
    default:
        $totalCorrect= $totalCorrect;
}

switch ($answer8) {
    case "A":
        $totalCorrect= $totalCorrect;
        break;
    case "B":
        $totalCorrect= $totalCorrect+1;
        break;
    default:
        $totalCorrect= $totalCorrect+2;
}

switch ($answer9) {
    case "A":
        $totalCorrect= $totalCorrect+1;
        break;
    case "B":
        $totalCorrect= $totalCorrect;
        break;
    default:
        $totalCorrect= $totalCorrect+2;
}

switch ($answer10) {
    case "A":
        $totalCorrect= $totalCorrect+2;
        break;
    case "B":
        $totalCorrect= $totalCorrect+1;
        break;
    default:
        $totalCorrect= $totalCorrect;
}

switch ($answer11) {
    case "A":
        $totalCorrect= $totalCorrect;
        break;
    case "B":
        $totalCorrect= $totalCorrect+2;
        break;
    default:
        $totalCorrect= $totalCorrect+1;
}

switch ($answer12) {
    case "A":
        $totalCorrect= $totalCorrect+2;
        break;
    case "B":
        $totalCorrect= $totalCorrect;
        break;
    default:
        $totalCorrect= $totalCorrect+1;
};

header("location: respuestafinal.php?resp=".$totalCorrect) ; 


?>