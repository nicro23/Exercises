SELECT AVG(rating) FROM ratings join movies ON movies.id = ratings.movie_id WHERE year = 2012;
