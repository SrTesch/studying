/* proj nome (SELEÇÃO  (SELEÇÃO CPF_consultor = CPF (consultor x equipe)))*/

select nome
from Consultor where(select max(count(sigla_projeto)), CPF_consultor
from Equipe
group by CPF_consultor);