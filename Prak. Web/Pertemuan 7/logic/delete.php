<?php
// panggil koneksi
include "../config/koneksi.php";

//ambil data
$id = $_GET['id'];

// query
$sql = "DELETE FROM mahasiswa WHERE id='$id'";
$result = mysqli_query($koneksi, $sql);
if ($result) {
    header("location: ../dashboard.php");
}else {
    echo "error : $stmt->error";
    die();
    header("location: ../dashboard.php?status=gagal");
}
?>