SELECT
  V.customer_id,
  count(*) as count_no_trans
FROM
  Visits V
  left join Transactions T using (visit_id)
where
  T.transaction_id is null
group by
  V.customer_id;