select d.name as Department, t.name as Employee, t.salary as Salary
from 
(select *, dense_rank() over (
    partition by departmentId
    order by salary desc ) as rnk
from Employee) as t
join Department d
on d.id = t.departmentId
where rnk<=3