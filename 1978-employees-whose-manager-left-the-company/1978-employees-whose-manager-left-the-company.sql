# Write your MySQL query statement below
select employee_id
from Employees
where salary < 30000 and manager_id not in (
    select e.employee_id
    from Employees e
)
order by employee_id