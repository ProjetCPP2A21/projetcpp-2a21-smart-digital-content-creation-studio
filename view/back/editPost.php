<?php
include("../../controller/PostController.php");
$post = getPost($_GET['id']);
?>

<!DOCTYPE html>
<html>
<head>

<title>Modifier Post</title>

<!-- CSS LINK (IMPORTANT) -->
<link rel="stylesheet" href="../../assets/css/style.css">

</head>

<body>

<!-- NAV -->
<div class="nav">
    <h2>Modifier Post</h2>
    <a class="btn" href="managePosts.php">Back</a>
</div>

<!-- FORM CARD -->
<div class="card" style="width:60%; margin:auto; margin-top:30px;">

<form action="../../controller/PostController.php"
      method="POST"
      enctype="multipart/form-data">

    <input type="hidden" name="id" value="<?= $post['id'] ?>">

    <label>Titre :</label><br>
    <input type="text" name="titre" value="<?= $post['titre'] ?>"><br><br>

    <label>Contenu :</label><br>
    <textarea name="contenu"><?= $post['contenu'] ?></textarea><br><br>

    <label>Image actuelle :</label><br>
    <img src="../../assets/images/<?= $post['image'] ?>" width="150"><br><br>

    <label>Nouvelle image :</label><br>
    <input type="file" name="image"><br><br>

    <button class="btn" type="submit" name="updatePost">
        Modifier
    </button>

</form>

</div>

</body>
</html>