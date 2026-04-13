<?php
require_once __DIR__ . "/../model/Post.php";

$postModel = new Post();

if(isset($_POST['addPost'])){

    $titre = $_POST['titre'];
    $contenu = $_POST['contenu'];

    $image = $_FILES['image']['name'];
    $tmp = $_FILES['image']['tmp_name'];

    $image = str_replace(" ", "_", $image);

    if($image != ""){
        move_uploaded_file($tmp, __DIR__."/../assets/images/".$image);
    }

    $postModel->addPost($titre,$contenu,$image);

    header("Location: ../view/front/index.php");
}

if(isset($_GET['delete'])){
    $postModel->deletePost($_GET['delete']);
    header("Location: ../view/back/managePosts.php");
}

if(isset($_POST['updatePost'])){

    $id = $_POST['id'];
    $titre = $_POST['titre'];
    $contenu = $_POST['contenu'];

    $image = $_FILES['image']['name'];
    $tmp = $_FILES['image']['tmp_name'];

    $image = str_replace(" ", "_", $image);

    if($image != ""){
        move_uploaded_file($tmp, __DIR__."/../assets/images/".$image);
    }

    $postModel->updatePost($id,$titre,$contenu,$image);

    header("Location: ../view/back/managePosts.php");
}

// FUNCTIONS VIEW
function getPosts(){
    global $postModel;
    return $postModel->getAllPosts();
}

function getPost($id){
    global $postModel;
    return $postModel->getPostById($id);
}
?>