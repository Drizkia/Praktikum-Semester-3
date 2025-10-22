<?php 
    require_once "config/koneksi.php";
    var_dump($koneksi);
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Dasboard</title>
</head>
<body>
    <h1>W E L C O M E</h1>
    <?php include "login.php"?>

    <?php if ($_POST["PW"] == "rahasia"): ?> 
            <h1>Selamat Datang <?= $_POST["USN"];?> </h1>
        <?php else : ?>
            <h1>403 Forbiden</h1>
        <?php endif; ?>
</body>
</html>