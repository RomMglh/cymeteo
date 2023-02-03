# cymeteo

Groupe : Rayane Chafaqi Romain Magalhaes

Rayane Chafaqi : gnuplot

Romain Magalhaes : code C et Shell

Pour compiler il faut utiliser Meteo

Pour utiliser le programme, il faut faire la commande suivante :

./projet_meteo <opt1> <opt2> <opt3> <opt4>

Les options peuvent être les suivantes : 
 
-f suivies du nom du fichier.csv <OBLIGATOIRE> 

La liste des options de limitation géographique est la suivante:  
option -F : (F)rance: France métropolitaine + Corse.
option -G : (G)uyane française.
option -S : (S)aint-Pierre et Miquelon: ile située à l’Est du Canada
option -A : (A)ntilles.
option -O : (O)céan indien.

-w = vent
-h = altitude
-m = humidité

---------------------------------------------------------------------------

Nous n'avons pas réussi à faire -t1 -t2 -t3 / -p1 -p2 -p3 / --abr --tab / -d <min> <max>.
De plus, notre programme C n'arrive pas à remplir correctement le fichier.csv de sorti.
Ainsi magré le fait que notre partie du gnuplot devrait pouvoir fonctionner, sans le fichier.csv de sorti il est impossible de réaliser les graphiques.
