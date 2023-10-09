select codmed
from Medico as m1
where exists
        (select * from medico as m2
        where m1.idade > m2.idade);

/* letra b) */

select codpac
from consulta as c
having c.codmed in (select m.codmed from Médico as m)
group by codpac;

create table Ambulatório(
    codamb int primary key,
    andar char(3),
    capacidade int
);


Create table Paciente(
    codpac int primary key,
    nome varchar(50),
    idade int
);

create table Médico(
    codmed int primary key,
    nome varchar(50),
    idade int,
    especialidade char(10),
    RG varchar(9)
);
create table Consulta(
    codmed int,
    codpac int,
    data_atendimento date,
    foreign key(codmed) references Médico(codmed),
    foreign key(codpac) references Paciente(codpac)
);

/*
letra c) 
Utilizando junção, liste todos os médicos (por meio de seus nome) que já atenderam pelo menos 3 pacientes
*/

t1 <- codmed T count(*) as qtd (Médico |x| Consulta)

t2 <- pi nome(Médico |x| (pi codmed(6 qtd >= 3 (t1))))