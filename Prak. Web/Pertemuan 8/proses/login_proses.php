<?php 
// TO DO
//! 1. Require Koneksi + SESSION START
    session_start();
    $conn = require "../config/config.php";

//! 2. Tangkap data
    $username = $_POST['username'] ?? "kosong";
    $password = $_POST['password'] ?? "kosong";

//! 3. Query
    $query = "SELECT * FROM user WHERE username= '$username' AND password = '$password'";
    $result = mysqli_query($conn, $query);

//! 4. Ngecek Query
    if (mysqli_num_rows($result) > 0) {

        //! 5. SET SESSION
        $_SESSION['login'] = true;
        $_SESSION['username'] = $username;

        //! 6. Arahin
        header("location:../dashboard.php");
    } else {
        header("location:../index.php?status=error");
    }
?>