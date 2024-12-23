select name from stars a
join people b on a.person_id = b.id
where movie_id = (
    select id from movies
    where title = "Toy Story"
);
