select m.id, m.name
from movies m, genres g
where id_genres = g.id and g.description = 'Action';