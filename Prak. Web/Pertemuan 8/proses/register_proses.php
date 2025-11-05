<?php 
// TO DO
//! 1. require koneksi

    $conn = require "../config/config.php";

//! 2. tangkap data
    $username = $_POST['username'] ?? "kosong";
    $password = $_POST['password'] ?? "kosong";

//! 3. Query
    $query = "INSERT INTO user (username, password) VALUES ('$username', '$password')";
        $result = mysqli_query($conn, $query);

//! 4. Ngarahin
    if (mysqli_num_rows($result) > 0) {
        header("location:../index.php");
    } else {
        header("location:../register.php?status=error");
    }
?>