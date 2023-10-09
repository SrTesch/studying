select c.name as name, r.rentals_date as rentals_date
from customers c, rentals r
where r.id_customers = c.id and r.rentals_date like '%09%';