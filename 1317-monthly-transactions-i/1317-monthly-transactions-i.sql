select
  TO_CHAR(trans_date,'YYYY-MM') as month,
  country,
  count(id) as trans_count,
  sum(case when state='approved' then 1 else 0 end) as approved_count,
  sum(amount) as trans_total_amount,
  sum(case when state='approved' then amount else 0 end) as approved_total_amount
from
  Transactions
group by
  TO_CHAR(trans_date,'YYYY-MM'),
  country
order by
  TO_CHAR(trans_date,'YYYY-MM') asc,
  country asc;