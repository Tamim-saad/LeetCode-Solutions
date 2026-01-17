# Write your MySQL query statement below
select sell_date, count(product) as num_sold, group_concat(product order by product) as products
from (select distinct * from Activities) as t
group by sell_date