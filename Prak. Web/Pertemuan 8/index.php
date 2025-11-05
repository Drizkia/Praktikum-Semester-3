<!DOCTYPE html>
<html lang="">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Login</title>
    <style>
        .login-container {
        max-width: 350px;
        margin: 40px auto;
        padding: 32px 24px;
        background: #f8f9fa;
        border-radius: 12px;
        box-shadow: 0 2px 12px rgba(0, 0, 0, 0.08);
        }

        .login-container h2 {
        text-align: center;
        margin-bottom: 24px;
        color: #333;
        }

        .login-container label {
        display: block;
        margin-bottom: 8px;
        font-weight: 500;
        color: #444;
        }

        .login-container input[type="text"],
        .login-container input[type="password"] {
        width: 100%;
        padding: 10px;
        margin-bottom: 18px;
        border: 1px solid #ccc;
        border-radius: 6px;
        font-size: 16px;
        }

        .login-container button {
        width: 100%;
        padding: 10px;
        background: #007bff;
        color: #fff;
        border: none;
        border-radius: 6px;
        font-size: 16px;
        cursor: pointer;
        transition: background 0.2s;
        }

        .login-container button:hover {
        background: #0056b3;
        }
    </style>
</head>

<body>
    <div class="login-container">
        <h2>Login</h2>
        <form action="proses/login_proses.php" method="post">
            <label for="username">Username</label>
            <input type="text" id="username" name="username" required>
            <label for="password">Password</label>
            <input type="password" id="password" name="password" required>

            <a href="register.php" style="display: block; margin-bottom: 12px;">Register</a>
            <button type="submit">Login</button>
        </form>
    </div>
</body>

</html>