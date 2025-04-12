SELECT title, rating FROM ratings join movies ON movies.id = ratings.movie_id WHERE year = 2010 ORDER BY rating desc, title;
