SELECT
  V.customer_id,
  count(*) - count(T.transaction_id) as count_no_trans
FROM
  Visits V
  left join Transactions T on V.visit_id = T.visit_id
group by
  V.customer_id
having
  count_no_trans > 0;
