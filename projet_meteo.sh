#!/bin/bash

make

options=$@

verification=0
nom_du_fichier=''
placement_fichier=0
var=0
lim_geo=''
nb_lignes=0
type_donne=''

donne_filtre="donne_filtre.csv"
donne_sorti="donne_sorti.csv"

touch donne_sorti.csv

# Boucle pour parcourir les options
for i in $options
do
  var=$var+1
  if [ "$i" == "-F" ] || [ "$i" == "-G" ] || [ "$i" == "-S" ] || [ "$i" == "-A" ] || [ "$i" == "-O" ] || [ "$i" == "-Q" ]; then
    lim_geo=$i
  fi
  if [ "$i" == "-f" ]; then
    verification=1
    placement_fichier=$(( var + 1 ))
  fi
  if [ "$i" == "--help" ]; then
    echo "A faire plus tard"
  fi
done

var=0

for i in $options
do
   var=$(( var + 1 ))
   if (( $var == $placement_fichier )); then
      nom_du_fichier=$i
   fi
done
   
# Vérification de la valeur de verification
if [ $verification -eq 1 ]; then
  echo "L'option -f a été trouvée"
else
  echo "L'option -f n'a pas été trouvée"
fi


for opt in $options
do
  if [ "$opt" == "-w" ]; then
      if [ "$lim_geo" == "-F" ]; then
         awk -F, '$16 >=0 && $16 <= 96000 {print $1 "," $4 "," $5 "," $10 "," $11}' $nom_du_fichier > filtered_weather_data.csv
      elif [ "$lim_geo" == "-G" ]; then
         awk -F, '$16 >=97300 && $16 <= 97390 {print $1 "," $4 "," $5 "," $10 "," $11}' $nom_du_fichier > filtered_weather_data.csv
      elif [ "$lim_geo" == "-A" ]; then
         awk -F, '$16 >=97200 && $16 <= 97290 {print $1 "," $4 "," $5 "," $10 "," $11}' $nom_du_fichier > filtered_weather_data.csv
      elif [ "$lim_geo" == "-O" ]; then
         awk -F, '$16 >=98411 && $16 <= 98415 {print $1 "," $4 "," $5 "," $10 "," $11}' $nom_du_fichier > filtered_weather_data.csv
      elif [ "$lim_geo" == "-S" ]; then
         awk -F, '$10 ==46.766333 && $11 == -56.179167 {print $1 "," $4 "," $5 "," $10 "," $11}' $nom_du_fichier > filtered_weather_data.csv
      else
         awk -F, '{print $1 "," $4 "," $5 "," $10 "," $11}' $nom_du_fichier > filtered_weather_data.csv
      fi
      nb_lignes=$(awk '/./ { COUNT+=1 } END { print COUNT }' filtered_weather_data.csv)
      ./Meteo $donne_filtre $donne_sorti $nb_lignes $opt
      ./vecteurs.sh
  fi
  if [ "$opt" == "-m" ]; then
      if [ "$lim_geo" == "-F" ]; then
         awk -F, '$16 >=0 && $16 <= 96000 {print $1 "," $6 "," $10 "," $11}' $nom_du_fichier > filtered_weather_data.csv
      elif [ "$lim_geo" == "-G" ]; then
         awk -F, '$16 >=97300 && $16 <= 97390 {print $1 "," $6 "," $10 "," $11}' $nom_du_fichier > filtered_weather_data.csv
      elif [ "$lim_geo" == "-A" ]; then
         awk -F, '$16 >=97200 && $16 <= 97290 {print $1 "," $6 "," $10 "," $11}' $nom_du_fichier > filtered_weather_data.csv
      elif [ "$lim_geo" == "-O" ]; then
         awk -F, '$16 >=98411 && $16 <= 98415 {print $1 "," $6 "," $10 "," $11}' $nom_du_fichier > filtered_weather_data.csv
      elif [ "$lim_geo" == "-S" ]; then
         awk -F, '$10 ==46.766333 && $11 == -56.179167 {print $1 "," $6 "," $10 "," $11}' $nom_du_fichier > filtered_weather_data.csv
      else
         awk -F, '{print $1 "," $6 "," $10 "," $11}' $nom_du_fichier > filtered_weather_data.csv
      fi
      nb_lignes=$(awk '/./ { COUNT+=1 } END { print COUNT }' filtered_weather_data.csv)
      ./Meteo $donne_filtre $donne_sorti $nb_lignes $opt
      ./graphique_c_c_m.sh
   fi
   if [ "$opt" == "-h" ]; then
      if [ "$lim_geo" == "" ]; then
         awk -F, '{print $1 "," $15 "," $10 "," $11}' $nom_du_fichier > filtered_weather_data.csv
      if [ "$lim_geo" == "-F" ]; then
         awk -F, '$16 >=0 && $16 <= 96000 {{print $1 "," $15 "," $10 "," $11}' $nom_du_fichier > filtered_weather_data.csv
      if [ "$lim_geo" == "-G" ]; then
         awk -F, '$16 >=97300 && $16 <= 97390 {{print $1 "," $15 "," $10 "," $11}' $nom_du_fichier > filtered_weather_data.csv
      if [ "$lim_geo" == "-A" ]; then
         awk -F, '$16 >=97200 && $16 <= 97290 {{print $1 "," $15 "," $10 "," $11}' $nom_du_fichier > filtered_weather_data.csv
      if [ "$lim_geo" == "-O" ]; then
         awk -F, '$16 >=98411 && $16 <= 98415 {{print $1 "," $15 "," $10 "," $11}' $nom_du_fichier > filtered_weather_data.csv
      if [ "$lim_geo" == "-S" ]; then
         awk -F, '$10 ==46.766333 && $11 == -56.179167 {{print $1 "," $15 "," $10 "," $11}' $nom_du_fichier > filtered_weather_data.csv
      else
         awk -F, '{print $1 "," $15 "," $10 "," $11}' $nom_du_fichier > filtered_weather_data.csv
      fi
      nb_lignes=$(awk '/./ { COUNT+=1 } END { print COUNT }' filtered_weather_data.csv)
      ./Meteo $donne_filtre $donne_sorti $nb_lignes $opt
      ./graphique_c_c_h.sh
   fi
done
