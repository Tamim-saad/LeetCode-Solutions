SELECT
  s.user_id,
  (
    round(
      IFNULL (
        sum(
          case
            when c.action = 'confirmed' then 1
            else 0
          end
        ) / count(*),
        0
      ),
      2
    )
  ) as confirmation_rate
FROM
  Signups s
  left join Confirmations c using (user_id)
GROUP BY
  s.user_id;