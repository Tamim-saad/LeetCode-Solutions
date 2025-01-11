# Write your MySQL query statement below
SELECT
  e.name
FROM
  Employee e
where
  5 <= (
    select
      count(managerId)
    from
      Employee
    where
      e.id = managerId
  );