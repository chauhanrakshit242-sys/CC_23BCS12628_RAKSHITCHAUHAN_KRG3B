# Write your MySQL query statement below
Select E.unique_id , Em.name 
from EmployeeUNI E
right join Employees Em
on E.id=Em.id;