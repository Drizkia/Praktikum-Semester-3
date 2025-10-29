<?php 
    // LOGIKA
    // Ambil Koneksi
    $koneksi = require "config/koneksi.php";

    // Query
    $result = mysqli_query($koneksi, "SELECT * FROM mahasiswa");

    $nomor = 0;
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tampil</title>
    <script src="https://cdn.jsdelivr.net/npm/@tailwindcss/browser@4"></script>
</head>
<body class="min-h-screen flex justify-center items-center flex-col">
    <div class=" flex flex-col">
        <h1 class="text-3xl font-bold mb-4 text-black text-center">Daftar Mahasiswa</h1>
        <table class="border-1 border-black border-collapse">
            <tr>
                <th class="border-1 border-black bg-blue-400 px-3 py-2 text-black">No</th>
                <th class="border-1 border-black bg-blue-400 px-3 py-2 text-black">AKSI</th>
                <th class="border-1 border-black bg-blue-400 px-3 py-2 text-black">NIM</th>
                <th class="border-1 border-black bg-blue-400 px-3 py-2 text-black">NAMA</th>
            </tr>
    
            <?php while( $row = mysqli_fetch_object($result)) : ?>
                <tr>
                    <td class="border-1 border-black px-3 py-2 text-black"><?= $nomor += 1 ?></td>
                    <td class="border border-black px-3 py-2 text-white">
                        <a class="rounded-xs bg-blue-400 text-center text-xs p-1 hover:bg-blue-600 hover:scale-120 active:scale-95 transition-all duration-200" href="logic/update.php?id=<?= $row->id ?>">Ubah</a>
                        <a class="rounded-xs bg-red-400 text-center text-xs p-1 hover:bg-red-600 hover:scale-125 active:scale-95 transition-all duration-200" href="logic/delete.php?id=<?= $row->id ?>">Hapus</a>
                    </td>
                    <td class="border-1 border-black px-3 py-2 text-black text-center"><?= $row->nim ?></td>
                    <td class="border-1 border-black px-3 py-2 text-black text-center"><?= $row->nama ?></td>
                </tr>
            <?php endwhile; ?>
        </table>
        <a href="tambah.php" class=" text-blue-400 hover:text-blue-600 text-center underline">Tambah Data Mahasiswa</a>
    </div>
</body>
</html>