<?php 
    session_start();
    if (!isset($_SESSION['username'])) {
        header("location:index.php");
    }
?>

<h1>Ini dashboard</h1>
<h1>Halo <?= htmlspecialchars($_SESSION['username']??"kosong") ?></h1>
<!-- untuk keamanan -->

<a href="proses/logout_proses.php">Tombol LogOut</a>