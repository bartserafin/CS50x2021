SELECT name FROM people
JOIN stars ON stars.person_id=people.id
JOIN movies ON stars.movie_id=movies.id
WHERE movies.id in
(SELECT movies.id FROM movies
JOIN people ON stars.person_id=people.id
JOIN stars ON stars.movie_id=movies.id
WHERE people.name="Kevin Bacon"
AND people.birth=1958)
AND people.name != "Kevin Bacon";


-- all movies where Kevin Bacon starred
-- SELECT title FROM movies
-- JOIN stars ON movies.id = stars.movie_id
-- JOIN people ON stars.person_id = people.id
-- WHERE name = "Kevin Bacon" AND birth = 1958;


-- In 13.sql, write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
-- Your query should output a table with a single column for the name of each person.
-- There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.
-- Kevin Bacon himself should not be included in the resulting list.

-- Executing 13.sql results in a table with 1 column and 176 rows.