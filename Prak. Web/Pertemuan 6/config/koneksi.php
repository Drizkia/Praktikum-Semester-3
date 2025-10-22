<?php 

    $host = "localhost"; // 127.0.0.1
    $port = 3307; // port mysql (opsional)
    $usn = "root";
    $pw = "";

    $datbase = "universitas";

    // My Sql HandShake
        $koneksi = new mysqli($host, $usn, $pw, $datbase, $port);

    // Control Handler
        if ($koneksi) {
            echo "koneksi jalan <br>";
        } else {
            echo "koneksi mati bro";
            die;
        }

?>