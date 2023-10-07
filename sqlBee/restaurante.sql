use restaurante;

create table clientes (
	idCliente int primary key auto_increment,
    nomeCliente varchar(100) not null
);

create table telClientes(
	tel char(12),
    idCliente int,
    PRIMARY KEY (idCliente, tel),
    foreign key (idCliente) references clientes(idCliente)
);

create table mesas(
	idMesa int primary key,
    NumeroMesa tinyint unsigned unique key
);

create table pedidos(
	idPedido int primary key auto_increment,
    dtPedido date not null,
    motivoCancel varchar(120),
    situacao char(1) default "0",
    idMesa int not null,
    idCliente int not null,
    foreign key (idMesa) references mesas(idMesa),
    foreign key (idCliente) references clientes(idCliente)
);

create table notas(
	numeroNota int auto_increment,
    dtPagamento date not null,
    idPedido int not null,
    primary key(numeroNota, dtPagamento),
    foreign key (idPedido) references pedidos(idPedido)
);

create table Item_Consumo(
	idItem int primary key,
    nomeItem varchar(40) not null,
    precoUnit double(6,2) not null,
	descricao varchar(180) default null,
    categoria varchar(20) default null
);

create table contem(
	qtd int not null,
    idItem int,
    idPedido int,
    primary key (idPedido, idItem),
    foreign key (idPedido) references pedidos(idPedido),
    foreign key (idItem) references Item_Consumo(idItem)
);