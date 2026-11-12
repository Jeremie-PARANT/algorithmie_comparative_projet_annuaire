## Question 1 
Grille IOCSF

**Input Quelles Données en entrée ?**
un email -> var char 
un identifiant numérique -> int

**Output quelle sortie**
existe -> bool 

**Contraintes**
Contraintes de temps et d'espace, pas de doublons, gestion des collisions pour la table de hachage
Les trois approches doivent exposer la même interface, c'est-à-dire les mêmes paramètres en 
entrée et le même type de retour pour l'insertion et la recherche, même si le nom de la fonction 
change selon l'approche (seq_, hash_, sorted_).  

performances (comparer les algos)

**Le volume**
Les algorithmes seront testés avec les volumes suivants : 100, 1 000, 10 000, 100 000, 1 000 000 utilisateurs

**La fréquence de recherche**
Voir étape 4 question 5 pour les différents scénarios de recherche.

---

## Question 2
On choisit l'insertion directe qui est plus efficace que l'insertion par tri.
L'insertion directe demande de parcourir le tableau pour trouver la bonne position pour insérer l'élément (recherche dichotomique O(log(n))), puis de décaler les éléments suivants O(n). Tandis que l'insertion par tri demande de trier le tableau après chaque insertion O(n log(n)).