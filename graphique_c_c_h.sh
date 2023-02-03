set view map
set dgrid3d 100,100
set xlabel "Longitude (Ouest-Est)"
set ylabel "Latitude (Sud-Nord)"
set cbrange [0:2]
set cbtics format "%.2f"
splot "sorted_weather_data.csv" using 1:2:3 with pm3d
