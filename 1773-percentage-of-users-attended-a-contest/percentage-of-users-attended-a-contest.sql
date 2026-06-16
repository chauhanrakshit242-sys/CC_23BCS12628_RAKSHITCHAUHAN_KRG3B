# Write your MySQL query statement below
 
Select R.contest_id,Round( count(R.contest_id)*100 /(Select count(*) from  Users) ,2)as percentage
from Register R
group by R.contest_id
order by percentage DESC, R.contest_id Asc;