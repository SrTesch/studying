select c.name, sum(amount)
from categories c, products
where c.id = id_categories
group by c.name;