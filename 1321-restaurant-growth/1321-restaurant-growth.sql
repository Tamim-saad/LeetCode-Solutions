# Write your MySQL query statement below
select visited_on,
    sum(amount) over(
        order by visited_on
        rows between 6 preceding and current row) as amount,
    Round(avg(amount) over(
        order by visited_on
        rows between 6 preceding and current row),2) as average_amount
from (
    select visited_on, sum(amount) as amount
    from Customer
    group by visited_on
) as t
order by visited_on
limit 100000 offset 6