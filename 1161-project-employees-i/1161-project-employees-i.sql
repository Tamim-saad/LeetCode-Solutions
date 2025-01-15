# Write your MySQL query state atment below
SELECT P.project_id, round(avg( E.experience_years),2) as average_years
FROM Project P join Employee E using (employee_id)
group by P.project_id; 
