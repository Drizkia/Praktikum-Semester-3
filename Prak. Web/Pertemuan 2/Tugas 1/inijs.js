    function updateStudent(nim) {
        alert("Update Mahasiswa dengan NIM: " + nim);
    }

    function deleteStudent(nim, el) {
        if (confirm("Apakah Anda yakin ingin menghapus mahasiswa?")) {
            const row = el.closest("tr");
            row.remove();
            alert("Mahasiswa dengan NIM: " + nim + " telah dihapus.");
        }
    }