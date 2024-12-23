
SELECT
    name
FROM
    people
    JOIN stars ON people.id = stars.person_id
    JOIN movies ON stars.movie_id = movies.id
WHERE
    movies.year = 2004
order by birth;
