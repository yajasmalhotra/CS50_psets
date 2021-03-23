SELECT DISTINCT name
FROM directors 
JOIN people ON people.id = directors.person_id
JOIN ratings ON directors.movie_id = ratings.movie_id
WHERE rating >= 9.0;
