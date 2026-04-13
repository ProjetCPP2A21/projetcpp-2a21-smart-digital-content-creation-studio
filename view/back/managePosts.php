<?php
include("../../controller/PostController.php");
$posts = getPosts();
?>

<!DOCTYPE html>
<html>
<head>
<title>Admin Dashboard</title>

<!-- CSS LINK -->
<link rel="stylesheet" href="../../assets/css/style.css">

</head>

<body>

<!-- NAV -->
<div class="nav">
    <h2>Admin Panel</h2>
    <a class="btn" href="../front/index.php">Front</a>
</div>

<!-- TABLE POSTS -->
<?php foreach($posts as $post){ ?>

<div class="card">

    <h3><?= $post['titre'] ?></h3>

    <p><?= $post['contenu'] ?></p>

    <?php if($post['image']){ ?>
        <img src="../../assets/images/<?= $post['image'] ?>">
    <?php } ?>

    <small><?= $post['date_post'] ?></small>

    <br><br>

    <a class="btn" href="editPost.php?id=<?= $post['id'] ?>">
        Edit
    </a>

    <a class="btn" style="background:red"
       href="../../controller/PostController.php?delete=<?= $post['id'] ?>">
        Delete
    </a>

</div>

<?php } ?>

</body>
</html>