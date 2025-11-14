<?php 

    if (strtoupper( $_SERVER["REQUEST_METHOD"] == "POST")) {
        //! Untuk cek
        echo "<pre>";
        // var_dump($_FILES);
        // echo "ini post";
        //! deklarasi
        $namaFile = $_FILES["uploadFile"]["name"];
        $ukuranFile = $_FILES["uploadFile"]["size"];
        $tmpNama = $_FILES["uploadFile"]["tmp_name"];

        $ekstensiValid = ["jpg", "jpeg", "png"];
        $ekstensiFile = explode(".", $namaFile); //* untuk cek setelah . pada file
        $ekstensiFile = $ekstensiFile[count($ekstensiFile) - 1]; //* untuk ambil ekstensi file aja
        $ekstensiFile = strtolower($ekstensiFile); //* untuk di cek lebih mudah biar di ekstensi valid

        //! ini buat cek hasil file uploadnya
            // var_dump($ekstensiFile);
            // var_dump($namaFile);
            // var_dump($ukuranFile);
            // var_dump($tmpNama);

        if (!in_array($ekstensiFile, $ekstensiValid)) { //* Gabisa dibalik, karna ekstensi ada di belakang nama file
            echo "Ekstensi file tidak valid";
            exit();
        }

        //! Untuk cek maksimal ukuran
        if ($ukuranFile > 5 * 1000 * 1000) { //* 1000 itu 1 mb
            echo "Ukuran terlalu besar, Max 5MB";
            exit();
        }

        //! Generate Name File Baru
        $namaFileBaru = uniqid() . "." . $ekstensiFile;

        //! Arahin upload ke folder mana
        move_uploaded_file(
            $tmpNama, //* asal folder gambar
            "storage/" . $namaFileBaru //* arah gambar kemana
        );

        //! menghubungkan dengan koneksi
        $konek = new mysqli('localhost', 'root', '', 'upload_file');

        //! Bagian masuk ke dbnya
        $query = "INSERT INTO file (gambar_url) VALUES (?)";
        $stmt = $konek->prepare($query);
        $stmt->bind_param("s", $namaFileBaru);
        $hasil = $stmt->execute();

        if ($hasil) {
        echo "berhasil upload ke db <br>";
        } else {
        echo "<script>alert('Gagal Update Profile')</script>";
        }

        //! Allert wajib
        echo "File Berhasil Di Upload";
        exit();
    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Upload Gambar</title>
</head>
<body>
    <form method="post"enctype="multipart/form-data">
        <label>Upload File Kamu</label>
        <input type="file" name="uploadFile" accept="image/*">
        <button type="submit">Upload Gambar</button>
    </form>
    <div>
        <?php
            $konek = new mysqli('localhost', 'root', '', 'upload_file');

            $stmt = $konek->prepare("SELECT * FROM file");
            $stmt->execute();
            $result = $stmt->get_result();
        ?>

        <h2>Hasil gambar</h2>
        <?php while ($data = mysqli_fetch_assoc($result)) :  ?>
            <div style="display: flex; flex-wrap: wrap; gap: 10px; border: 1px solid black; padding: 10px; margin-bottom: 10px;">
            <p><?= $data['id'] ?></p>
            <p>-</p>
            <img src="storage/<?= $data['gambar_url'] ?>" style="width: 100px;">
            </div>
        <?php endwhile; ?>
    </div>
</body>
</html>