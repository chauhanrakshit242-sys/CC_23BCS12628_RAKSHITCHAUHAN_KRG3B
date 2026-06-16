# Write your MySQL query statement below

Select P.product_id, Round(IFNULL(sum(P.price*U.units)/sum(U.units),0),2)as average_price
from Prices P
Left join UnitsSold U 
on P.product_id=U.product_id 
And  U.purchase_date  between P.start_date and P.end_date 
group by P.product_id;