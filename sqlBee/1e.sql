/* quais projetos (sigla) têm na sua equipe SOMENTE consultores nascidos no Paraná (PR)? OBS: a equipe NÃO pode conter consultores de outros estados */

select sigla_projeto
from equipe
having not exists 
            (select CPF from consultor where UF != 'PR')
group by sigla_projeto;