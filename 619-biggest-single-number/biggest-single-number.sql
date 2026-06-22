# Write your MySQL query statement below
with cte as
(
    select num ,count(num) as cnt 
    from MyNumbers group by num
)
Select max(num) as num 
from cte where cnt=1;