SELECT
  a.student_id,
  a.student_name,
  c.subject_name,
  (
    SELECT
      count(student_id)
    from
      Examinations
    where
      student_id = a.student_id
      and subject_name = c.subject_name
  ) as attended_exams
from
  Students a
  join Subjects c
group by
  a.student_id,
  a.student_name,
  c.subject_name
order by
  a.student_id;