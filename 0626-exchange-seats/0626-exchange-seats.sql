# Write your MySQL query statement below
select o.id, if(o.id % 2 = 0,
    (select s.student from Seat s where s.id=o.id-1),
    ifnull((select s.student from Seat s where s.id=o.id+1), o.student))  as student
from Seat o
order by o.id