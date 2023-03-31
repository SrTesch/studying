select p.id, p.name
from products p
    join categories ctg on p.id_categories = ctg.id
where ctg."name" like 'super%';