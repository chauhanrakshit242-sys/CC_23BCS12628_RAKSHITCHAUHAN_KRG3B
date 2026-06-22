# Write your MySQL query statement below
with cte as
(
    Select class , count(student) as cnt 
    from Courses group by class
)
Select class 
from  cte where cnt >=5;