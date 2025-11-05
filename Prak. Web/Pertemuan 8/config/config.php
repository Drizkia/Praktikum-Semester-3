<?php 
    $conn = mysqli_connect('localhost', 'root', '', 'p8_spada');
    if (!$conn) {
        die("Koneksi gagal: " . mysqli_connect_error());
    }
    return $conn;
?>