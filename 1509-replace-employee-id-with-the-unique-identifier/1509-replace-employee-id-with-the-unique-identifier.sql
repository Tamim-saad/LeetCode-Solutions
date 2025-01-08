SELECT
  U.unique_id,
  E.name
FROM
  Employees E
  left outer join EmployeeUNI U using (id);

-- on (E.id = U.id or E.id not