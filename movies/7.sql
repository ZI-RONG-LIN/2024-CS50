select title,rating from ratings
join movies on ratings.movie_id = movies.id
where year = 2010
order by rating desc,title;
