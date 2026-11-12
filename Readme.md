Question 1 

Grille IOCSF

Input Quelles Données en entrée ?
un email -> var char 
un identifiant numérique -> int

Output quelle sortie
existe -> bool 

Contraintes 
Contraintes de temps et d'espace, pas de doublons, gestion des collisions pour la table de hachage
Les trois approches doivent exposer la même interface, c'est-à-dire les mêmes paramètres en 
entrée et le même type de retour pour l'insertion et la recherche, même si le nom de la fonction 
change selon l'approche (seq_, hash_, sorted_).  

performances (comparer les algos)

le volume 
Les algorithmes seront testés avec les volumes suivants : 100, 1 000, 10 000, 100 000, 1 000 000 utilisateurs

la fréquence de recherche
Voir étape 4 question 5 pour les différents scénarios de recherche.