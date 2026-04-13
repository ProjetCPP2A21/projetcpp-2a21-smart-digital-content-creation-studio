<?php

class Database {
    private $host = "localhost";
    private $dbname = "voyagio";
    private $user = "root";
    private $pass = "";

    public $conn;

    public function getConnection(){
        $this->conn = null;

        try {
            $this->conn = new PDO(
                "mysql:host=".$this->host.";dbname=".$this->dbname,
                $this->user,
                $this->pass
            );

            $this->conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

        } catch(PDOException $e){
            die("Erreur connexion: " . $e->getMessage());
        }

        return $this->conn;
    }
}
?>