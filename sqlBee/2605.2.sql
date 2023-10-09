select prd.name, prv.name
from products prd, providers prv
where id_providers = prv.id
and id_categories = 6;