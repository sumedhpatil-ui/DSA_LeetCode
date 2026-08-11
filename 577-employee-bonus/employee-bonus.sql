# Write your MySQL query statement below
select name, bonus
from ( 
    select a.name as name, b.bonus as bonus
    from employee as a
    left join bonus as b
    on a.empid = b.empid
) as temp
where bonus is null or bonus < 1000;