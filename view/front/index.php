<?php
include("../../controller/PostController.php");
$posts = getPosts();
global $postModel;
?>

<!DOCTYPE html>
<html>
<head>
<title>Forum</title>

<!-- CSS LINK -->
<link rel="stylesheet" href="../../assets/css/style.css">

</head>

<body>

<!-- NAV -->
<div class="nav">
    <h2>MiniForum</h2>
    <a class="btn" href="addPost.php">+ Create Post</a>
</div>

<!-- POSTS -->
<?php foreach($posts as $post){ ?>

<div class="card">

    <h3><?= $post['titre'] ?></h3>

    <p><?= $post['contenu'] ?></p>

    <?php if($post['image']){ ?>
        <img src="../../assets/images/<?= $post['image'] ?>">
    <?php } ?>

    <small><?= $post['date_post'] ?></small>

    <br><br>

    <!-- LIKE -->
    <a class="btn"
       href="../../controller/PostController.php?like=<?= $post['id'] ?>">
        👍 Like
    </a>

    <span class="like">
        ❤️ <?= $postModel->countLikes($post['id']) ?>
    </span>

</div>

<?php } ?>

</body>
</html>