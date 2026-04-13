<?php
session_start();
if(!isset($_SESSION['admin'])){
    header("Location: login.php");
}

include("../../controller/PostController.php");
$posts = getPosts();
?>

<h1>Admin Dashboard</h1>

<p>Total Posts: <?= count($posts) ?></p>

<a href="managePosts.php">Manage Posts</a>