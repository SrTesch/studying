select m.id, m.name
from movies m, prices p
where id_prices = p.id and value < 2;