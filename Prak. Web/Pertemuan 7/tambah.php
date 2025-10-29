<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tambah Data</title>
    <script src="https://cdn.jsdelivr.net/npm/@tailwindcss/browser@4"></script>
</head>
<body class=" min-h-screen flex justify-center items-center">
    <div class=" flex-col border-1">
    <h1 class=" text-3xl font-bold md-4 p-9 text-center">INPUT DATA MAHASISWA</h1>
        <form action="logic/create.php" method="post" class="flex justify-center items-center mb-5">
            <ul class="flex item-center flex-col justify-center">
                <li class="flex flex-col">
                    <label for="nim" class=" gap-3">NIM: </label>
                    <input type="text" name="nim" id="nim" placeholder="Input Nama" class=" border-1 m-2">
                </li>
                <li class="flex flex-col">
                    <label for="nama" class=" gap-2">NAMA: </label>
                    <input type="text" name="nama" id="nama" placeholder="Input NIM" class="border-1 m-2">
                </li>
                <button type="submit" name="submit" class=" bg-blue-400 hover:bg-blue-500">SUBMIT</button>
            </ul>
        </form>
    </div>
</body>
</html>