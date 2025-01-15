select
  R.contest_id,
  round(
    (
      select
        count(user_id)
      from
        Register
      where
        contest_id = R.contest_id
    ) / (
      select
        count(*)
      from
        Users
      where
        contest_id = R.contest_id
    ) * 100,
    2
  ) as percentage
from
  Register R
group by
  R.contest_id
order by
  percentage desc, contest_id asc;