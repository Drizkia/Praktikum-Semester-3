<?php 
    session_start();
    session_destroy(); //hapus nilai session

    header('location:../index.php');
?>