# La Ratiothèque
### La fabuleuse bibliothèque des nombres rationnels.

Bienvenue dans une bibliothèque haute en couleurs, qui met en oeuvre les plus sombres logiques des mathématiques, combinées à la programmation.

## Description du projet : 

Ce projet a pour but de créer une structure pour utiliser simplement les nombres rationnels. 

Au sein de la ratiothèque, vous pouvez notamment retrouver :

• des constructeurs par défaut, par copie et par valeurs

• un destructeur

• la surcharge des opérateurs de base (addition, soustraction, multiplication, etc.)

• la surcharge des opérations de comparaison (inférieur ou égal, non-égal, etc.)

• les opérations mathématiques d'algèbre (cosinus, exponentiel, racine carrée, etc.)

• un affichage simplifié des nombres rationnels via la surcharge de l'opérateur <<

## Procédure d'installation pour les collaborateurs :

Depuis la page GitHub, récupérer le lien https par exemple, puis lancer le git clone.

Une fois le clone fait, l'ouvrir dans votre IDE favori (Visual Studio Code est la recommandation du chef), et lancer le build directement grâce aux CMake. 

Pour générer la documentation via Doxygen, se placer dans le dossier du build (cd build), puis lancer la commande make html. 

La documentation sera accessible dans le dossier doc/doc-doxygen, et prendra la forme d'un index.html qui peut être ouvert dans le navigateur.

Pour faire fonctionner les tests unitaires, merci de lancer les tests en local, en ajoutant la lib googletest au clone, pouvant être trouvé ici : [librairie googletest](https://github.com/google/googletest).

## Visionner le rapport en ligne : 

Le rapport écrit relatif à la partie mathématique est accessible via le lien suivant : [lien vers le rapport](https://drive.google.com/file/d/1IQ4zpwf9ZZykNjy3meB1mqTtrApGl_zk/view?usp=sharing).