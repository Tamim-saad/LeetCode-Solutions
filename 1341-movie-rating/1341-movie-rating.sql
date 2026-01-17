# Write your MySQL query statement below
(select u.name as results
from Users u
join MovieRating m
using (user_id)
group by user_id
order by count(*) desc, u.name asc
limit 1
)

union all

(select m.title as results
from Movies m
join MovieRating mr
using (movie_id)
where mr.created_at between '2020-02-01' and '2020-02-29'
group by movie_id
order by avg(rating) desc, m.title asc
limit 1
)