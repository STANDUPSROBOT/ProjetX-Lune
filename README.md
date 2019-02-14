ProjetX-Lune

School project

Comment cloner ce magnifique dépot en ligne localement chez vous
================================================================
1) Crééz un dossier chez vous localement positionnez vous dedans et avec l'interface GIT BASH GUI ou GIT BASH (en ligne de commande)-> (recommandé pour ma part pour comprendre ce que vous faites). donc avec votre alternative favorite clonez ce dépôt https://github.com/STANDUPSROBOT/ProjetX-Lune.git (git clone https://github.com/STANDUPSROBOT/ProjetX-Lune.git).

2) Déplacez vous dans Dev => git branch Dev

3) Amusez vous (cf consignes d'ajout).

Quelques petites consignes d'ajout au dépot:
==============================================
Déposer le code dans la branche Dev ou bien créez vous une branche depuis Dev => 
    git branch votrenomdebranche 
    git checkout votrenomdebranche 
    
Et vous pourrez vous amuser sans limites.

Quand vous déposez des fichiers ou crééz des répertoires dans Dev procéder de la sorte:

    git pull // on tire la branche dans son répertoire local + précisément les potentielles maj qu'on fait les autres
    git add . // on ajoute ce que nous on a fait localement à un fichier temporaire
    git commit -m "la description de ce que vous avez ajouté/fait" // enregistrement local
    git push // pousse vos modification dans la branche de développement.
