<?php 
// Manggil koneksi
    require "../config/koneksi.php";

// Nangkap Datanya
    $nim = $_POST['nim'];
    $nama = $_POST['nama'];

// Query Cara 2
    $query = "INSERT INTO mahasiswa (nim, nama) VALUES (?, ?)";

$stmt = $koneksi->prepare($query);
$stmt->bind_param("ss", $nim, $nama);

// Error Handling
if ($stmt->execute()) {
    header("Location: ../dashboard.php");
} else {
    echo "Error : $stmt->error";
}

$stmt->close();
$koneksi->close();

exit;

// Query Cara 1
    // $query = "INSERT INTO mahasiswa VALUES ('', '$nim', '$nama')";

// Kalo make cara 1
    // $result = mysqli_query($koneksi, $query);
    // if ($result) {
    //     header("Location: ../dashboard.php");
    // } else {
    //     echo "Error : $stmt->error";
    // }
?>