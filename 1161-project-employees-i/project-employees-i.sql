# Write your MySQL query statement below

Select  P.project_id ,Round(IFNULL(sum(E.experience_years)/count(e.experience_years),0),2)as average_years
from Project P
Left join  Employee E
on P.employee_id = E.employee_id
group by P.project_id;