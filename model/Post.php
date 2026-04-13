<?php

require_once __DIR__ . "/../config/database.php";

class Post {

    private $conn;

    public function __construct(){
        $db = new Database();
        $this->conn = $db->getConnection();
    }

    // =====================
    // POSTS
    // =====================
    public function getAllPosts(){
        $sql = "SELECT * FROM post ORDER BY date_post DESC";
        $stmt = $this->conn->prepare($sql);
        $stmt->execute();

        return $stmt->fetchAll(PDO::FETCH_ASSOC);
    }

    public function addPost($titre, $contenu, $image){
        $sql = "INSERT INTO post(titre, contenu, image)
                VALUES(:titre, :contenu, :image)";

        $stmt = $this->conn->prepare($sql);

        return $stmt->execute([
            ':titre' => $titre,
            ':contenu' => $contenu,
            ':image' => $image
        ]);
    }

    public function deletePost($id){
        $sql = "DELETE FROM post WHERE id=:id";
        $stmt = $this->conn->prepare($sql);

        return $stmt->execute([':id'=>$id]);
    }

    public function getPostById($id){
        $sql = "SELECT * FROM post WHERE id=:id";
        $stmt = $this->conn->prepare($sql);

        $stmt->execute([':id'=>$id]);
        return $stmt->fetch(PDO::FETCH_ASSOC);
    }

    public function updatePost($id, $titre, $contenu, $image){

        if($image == ""){
            $sql = "UPDATE post SET titre=:titre, contenu=:contenu WHERE id=:id";
            $stmt = $this->conn->prepare($sql);

            return $stmt->execute([
                ':titre'=>$titre,
                ':contenu'=>$contenu,
                ':id'=>$id
            ]);
        } else {
            $sql = "UPDATE post 
                    SET titre=:titre, contenu=:contenu, image=:image 
                    WHERE id=:id";

            $stmt = $this->conn->prepare($sql);

            return $stmt->execute([
                ':titre'=>$titre,
                ':contenu'=>$contenu,
                ':image'=>$image,
                ':id'=>$id
            ]);
        }
    }

    // =====================
    // 👍 LIKES
    // =====================

    public function likePost($post_id){

        $ip = $_SERVER['REMOTE_ADDR'];

        // check exist
        $sql = "SELECT * FROM likes WHERE post_id=:pid AND user_ip=:ip";
        $stmt = $this->conn->prepare($sql);

        $stmt->execute([
            ':pid'=>$post_id,
            ':ip'=>$ip
        ]);

        if($stmt->rowCount() == 0){

            $sql = "INSERT INTO likes(post_id, user_ip)
                    VALUES(:pid, :ip)";

            $stmt = $this->conn->prepare($sql);

            $stmt->execute([
                ':pid'=>$post_id,
                ':ip'=>$ip
            ]);
        }
    }

    // =====================
    // ❤️ COUNT LIKES
    // =====================
    public function countLikes($post_id){

        $sql = "SELECT COUNT(*) as total FROM likes WHERE post_id=:id";
        $stmt = $this->conn->prepare($sql);

        $stmt->execute([':id'=>$post_id]);

        $row = $stmt->fetch(PDO::FETCH_ASSOC);

        return $row['total'];
    }
}

?>