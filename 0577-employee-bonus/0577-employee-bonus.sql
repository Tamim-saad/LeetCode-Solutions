SELECT
  a.name,
  b.bonus
from
  Employee a
  left join Bonus b using (empId)
WHERE
  b.bonus is null || b.bonus < 1000;