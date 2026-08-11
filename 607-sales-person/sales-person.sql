# Write your MySQL query statement below
select s.name
from salesperson as s
where sales_id not in 
    (select a.sales_id 
    from orders as a
    join company as b
    on a.com_id = b.com_id
    where b.name = "RED")
;