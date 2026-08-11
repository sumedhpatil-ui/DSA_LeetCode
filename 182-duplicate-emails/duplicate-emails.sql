# Write your MySQL query statement below
SELECT email as Email 
from person 
group by email 
having count(id) >= 2;