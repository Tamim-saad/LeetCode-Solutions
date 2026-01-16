select x.product_id, ifnull(y.new_price,10) as price
from Products x left join Products y
    on x.product_id = y.product_id
    and y.change_date = (
        select max(z.change_date)
        from Products z
        where z.product_id = y.product_id 
        and z.change_date < '2019-08-17')
group by x.product_id