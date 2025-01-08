# Write your MySQL query statement below
SELECT
  P.product_name,
  S.year,
  S.price
FROM
  Sales S
  join Product P using (product_id);