# Write your MySQL query statement below
select distinct num as ConsecutiveNums 
from Logs l
where   num = (select x.num from Logs x where x.id = l.id+1)
    and num = (select y.num from Logs y where y.id = l.id+2);