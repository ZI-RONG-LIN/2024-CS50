select
    title
from
    movies
    join ratings ON movies.id = ratings.movie_id
    join stars ON movies.id = stars.movie_id
where
    person_id = (
        select
            id
        from
            people
        where
            name = "Chadwick Boseman"
    )
order by rating desc
limit 5;



