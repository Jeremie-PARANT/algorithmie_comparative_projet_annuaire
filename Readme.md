## Question 1 - Grille IOCSF  
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
le compilatuer ne doit pas mettre plus de 5 min pour compiler le projet

Le résulat ne doit pas retourner un faux positif, c'est-à-dire que si l'email n'existe pas dans la base de données, la fonction de recherche doit retourner false.

le compilateur doit pouvoir analyser un annuaire vide

**Le volume**  
Les algorithmes seront testés avec les volumes suivants : 100, 1 000, 10 000, 100 000, 1 000 000 utilisateurs

**La fréquence de recherche**  
Voir étape 4 question 5 pour les différents scénarios de recherche.

---

## Question 2  
Je choisie l'insertion directe qui est plus efficace que l'insertion par tri, en effet l'insertion directe à une complexité de O(n) tandis que l'insertion par tri à une complexité de O(n log(n)).

Détails : L'insertion directe demande de parcourir le tableau pour trouver la bonne position pour insérer l'élément (recherche dichotomique O(log(n))), puis de décaler les éléments suivants O(n). Tandis que l'insertion par tri demande de trier le tableau après chaque insertion O(n log(n)).

---

## Étape 3 — Mesure des temps de recherche  
make  
./mesure  

Exemple de sortie (1000 répétitions) :  
taille,sequentielle_s,hachage_s,dichotomique_s  
100,0.000460000,0.000070000,0.000044000  
1000,0.005620000,0.000059000,0.000064000  
10000,0.050415000,0.000082000,0.000083000  
100000,0.644171000,0.000191000,0.000095000  
1000000,7.032235000,0.001761000,0.000104000  