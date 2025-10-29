<?php 
// Manggil koneksi.php
$koneksi = require "../config/koneksi.php";

// Nangkap Datanya
$id = $_POST['id'];
$nama = $_POST['nama']; 
$nim = $_POST['nim'];

// Query Cara 2
$sql = "UPDATE mahasiswa SET nama='$nama', nim='$nim' WHERE id='$id'";
$result = mysqli_query($koneksi, $sql);
if ($result) {
    header("Location: ../dashboard.php");
}else{
    echo "Error : Gagal";
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tambah Mahasiswa</title>
</head>
<body>
    <?php 
    // Ambil ID
    $id = $_GET['id'];
    // Query
    $sql = "SELECT * FROM mahasiswa WHERE id='$id'";
    $result = mysqli_query($koneksi, $sql);
    $data = mysqli_fetch_object($result);
    ?>
    <form action="logic/update.php" method="post">
        <!-- ID Hidden -->
        <input type="text" name="id" value="<?= $data->id ?>" hidden>
        <!-- NAMA -->
        <label for="">Nama : </label>
        <input type="text" name="nama" placeholder="Input Nama" value="<?= $data->nama ?>">
        <br>
        <!-- NIM -->
        <label for="">NIM : </label>
        <input type="text" name="nim" placeholder="Input NIM" value="<?= $data->nim ?>">
        <br>
        <!-- Button -->
        <button type="submit">Tambah Data</button>
    </form>
</body>
</html>