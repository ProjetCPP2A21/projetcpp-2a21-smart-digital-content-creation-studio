<?php
session_start();
include("../../config/database.php");

if(isset($_POST['login'])){
    $u = $_POST['username'];
    $p = $_POST['password'];

    $res = mysqli_query($conn,
        "SELECT * FROM admin WHERE username='$u' AND password='$p'"
    );

    if(mysqli_num_rows($res) > 0){
        $_SESSION['admin'] = $u;
        header("Location: dashboard.php");
    } else {
        echo "Login incorrect";
    }
}
?>

<form method="POST">
<input name="username" placeholder="Username">
<input name="password" type="password" placeholder="Password">
<button name="login">Login</button>
</form>