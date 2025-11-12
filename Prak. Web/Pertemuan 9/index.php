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
</body>
</html>