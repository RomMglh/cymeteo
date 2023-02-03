set datafile separator ','
set title 'Diagramme de vecteurs'
plot 'sorted_weather_data.csv' using 1:2:3:4 with vectors lc -1 filled
set xlabel 'Longitude (Ouest-Est)'
set ylabel 'Latitude (Sud-Nord)'
set xrange[0:100]
set yrange[0:100]
set grid
