CREATE TABLE Estudante (
    cod_matricula VARCHAR(10) PRIMARY KEY NOT NULL,
    nome VARCHAR(100) NOT NULL,
    idioma CHAR(1) NOT NULL CHECK (idioma IN ('I', 'E', 'A')), 
    data_nascimento DATE NOT NULL, 
    idade INT NOT NULL CHECK (idade > 12), 
    sexo CHAR(1) NOT NULL CHECK (sexo IN ('M', 'F')), 
    endereco VARCHAR(80) NOT NULL, 
    telefone VARCHAR(12) NOT NULL,
    email VARCHAR(50) NOT NULL UNIQUE
);

CREATE TABLE Professor (
    cod_prof INT PRIMARY KEY NOT NULL,
    nome_prof VARCHAR(100) NOT NULL,
    especialidade CHAR(1) NOT NULL CHECK (especialidade IN ('I', 'E', 'A'))
);

CREATE TABLE Materia (
    cod_materia INT PRIMARY KEY NOT NULL,
    nome CHAR(1) NOT NULL CHECK (nome IN ('I', 'E', 'A'))
);

CREATE TABLE Turma (
    cod_turma INT PRIMARY KEY NOT NULL,
    Ano INT NOT NULL,
    fk_cod_materia INT NOT NULL,
    fk_prof INT NOT NULL,
    FOREIGN KEY (fk_cod_materia) REFERENCES Materia(cod_materia),
    FOREIGN KEY (fk_prof) REFERENCES Professor(cod_prof)
);

CREATE TABLE Matricula (
    cod_matricula VARCHAR(10) NOT NULL,
    cod_turma INT NOT NULL,
    data_matricula DATE NOT NULL,
    status CHAR(1) DEFAULT 'A' CHECK (status IN ('A', 'T', 'C')),
    PRIMARY KEY (cod_matricula, cod_turma),
    FOREIGN KEY (cod_matricula) REFERENCES Estudante(cod_matricula),
    FOREIGN KEY (cod_turma) REFERENCES Turma(cod_turma)
);