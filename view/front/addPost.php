<!DOCTYPE html>
<html>
<head>

<title>Ajouter Post</title>

<link rel="stylesheet" href="../../assets/css/style.css">

<style>
.error{
    color:red;
    font-weight:bold;
    margin-bottom:10px;
}
</style>

<script>
function validateForm(){

    let titre = document.forms["f"]["titre"].value.trim();
    let contenu = document.forms["f"]["contenu"].value.trim();

    let error = "";

    // 🔥 CHAMP VIDE
    if(titre == ""){
        error += "❌ Titre obligatoire<br>";
    }

    if(contenu == ""){
        error += "❌ Contenu obligatoire<br>";
    }

    // 🔥 MAX MOTS
    if(titre.split(" ").length > 3){
        error += "❌ Titre max 3 mots<br>";
    }

    if(contenu.split(" ").length > 9){
        error += "❌ Contenu max 9 mots<br>";
    }

    // 🔥 AFFICHER ERREUR
    if(error != ""){
        document.getElementById("errorBox").innerHTML = error;
        return false;
    }

    return true;
}
</script>

</head>

<body>

<div class="nav">
    <h2>Créer Post</h2>
</div>

<div class="card" style="width:60%; margin:auto; margin-top:30px;">

<!-- MESSAGE ERREUR -->
<div id="errorBox" class="error"></div>

<form name="f"
      action="../../controller/PostController.php"
      method="POST"
      enctype="multipart/form-data"
      onsubmit="return validateForm()">

    <label>Titre</label><br>
    <input type="text" name="titre"><br><br>

    <label>Contenu</label><br>
    <textarea name="contenu"></textarea><br><br>

    <label>Image</label><br>
    <input type="file" name="image"><br><br>

    <button class="btn" type="submit" name="addPost">
        Publier
    </button>

</form>

</div>

</body>
</html>