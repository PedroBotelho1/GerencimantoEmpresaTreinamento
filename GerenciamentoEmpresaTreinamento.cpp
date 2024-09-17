#include <iostream>
#include <string>

using namespace std;

struct Cidade {
	int cod_cidade;
	string nome;
	string UF;
};

void leitura_cidade(struct Cidade cid[], int &cont) {
	int i = 0;
	for (int saida = 1; i < 20 && saida != 0; i++) {
		cout << "\n\nCódigo da cidade: ";
		cin >> cid[i].cod_cidade;
		if(cid[i].cod_cidade > 0) {
			cout << "Nome: ";
			cin >> cid[i].nome;
			cout << "UF: ";
			cin >> cid[i].UF;
		}
		else saida = 0;
	}
	cont = i - 1;
}

//==========================================================

struct Curso {
	int cod_curso;
	string descricao;
	string valor_por_aula;
};

struct endCurso {
	int cod_curso;
	int end_curso;
};

void leitura_curso(struct Curso curs[], int &cont) {
	int i = 0;
	for (int saida = 1; i < 20 && saida != 0; i++) {
		cout << "\n\nCódigo do curso: ";
		cin >> curs[i].cod_curso;
		if(curs[i].cod_curso > 0) {
			cout << "Descrição do curso: ";
			cin >> curs[i].descricao;
			cout << "Valor por aula: ";
			cin >> curs[i].valor_por_aula;
		}
		else saida = 0;
	}
	cont = i - 1;
}

void leitura_indice_curso (struct endCurso cur[], int cont) {
	for(int i = 0; i < cont; i++) {
		cout << "\n\nCódigo do indice: ";
		cin >> cur[i].cod_curso;
		cout << "Endereco Fisico na area de dados: ";
		cin >> cur[i].end_curso;
	}
}

//==========================================================

struct Turma {
	int cod_turma;
	int cod_curso;
	int cod_instrutor_turma;
	int total_participantes;
	int quant_max_participantes;
};

struct endTurma {
	int cod_turma;
	int end_turma;
};

void buscar_cursos(struct Curso cur[], int &cont, int cod_curso) {
	for(int i = 0; i < cont; i++) {
		if(cod_curso == cur[i].cod_curso) {
			cout << "\n** CURSO **" << endl;
			cout << "Descrição: " << cur[i].descricao << endl;
			cout << "Valor por aula: " << cur[i].valor_por_aula << endl;
		}
		else {
			cout << "\n** CÓDIGO DIGITADO NÃO EXISTE! **.";
		}
	}
}


void leitura_turmas(struct Turma tur[], int &cont, struct Curso cur[], int &cont_curso) {
	int i = 0;
	for (int saida = 1; i < 20 && saida != 0; i++) {
		cout << "\n\nCódigo da turma: ";
		cin >> tur[i].cod_turma;
		if(tur[i].cod_turma > 0) {
			cout << "Código do curso: ";
			cin >> tur[i].cod_curso;
			cout << "Código do instrutor: ";
			cin >> tur[i].cod_instrutor_turma;
			cout << "Total de participantes: ";
			cin >> tur[i].total_participantes;
			cout << "Quantidade máxima de participantes: ";
			cin >> tur[i].quant_max_participantes;
			
			buscar_cursos(cur, cont_curso, tur[i].cod_curso);
		}
		else saida = 0;
	}
	cont = i - 1;
}

void leitura_indice_turma (struct endTurma idx[], int cont){
    for (int i = 0; i < cont; i++){
        cout << "\n\nCodigo do Indice " << (i+1) << ": ";
        cin >> idx[i].cod_turma;
        cout << "Endereco Fisico na Area de Dados: ";
        cin >> idx[i].end_turma;
    }
}

void inclusao_turma (struct Turma tur[], int &cont, struct endTurma idx[], int contT, int cod){
    // inclusao do novo registro na area de dados
    cout << "Código da turma: ";
    cin >> tur[cont].cod_turma;
    cout << "Código do curso: ";
    cin >> tur[cont].cod_curso;
    cout << "Código do instrutor: ";
    cin >> tur[cont].cod_instrutor_turma;
    cout << "Total de participantes: ";
    cin >> tur[cont].total_participantes; 
    cout << "Quantidade máxima de participantes: ";
    cin >> tur[cont].quant_max_participantes;
    
    
    // inclusao na area de indices
    int i;
    for (i = contT - 1; i >= 0 && idx[i].cod_turma > cod; i--){
        idx[i+1].cod_turma = idx[i].cod_turma;
        idx[i+1].end_turma = idx[i].end_turma;
    }
    idx[i + 1].cod_turma = cod;
    idx[i + 1].end_turma = contT;
    
    cout << "\n\nInclusao realizada com Sucesso";
    
    cont++;
    contT++;
}

//==========================================================

struct indice_instrutor {
	int codigo;
	int ender;
};

struct Instrutores {
	int cod_instrutor;
	string nome;
	string endereco;
	int cod_cidade;
	int status;
};

void buscar_cidades(struct Cidade cid[], int &cont, int cod_cidade) {
	for(int i = 0; i < cont; i++) {
		if(cod_cidade == cid[i].cod_cidade) {
			cout << "\n** CIDADE **" << endl;
			cout << "Nome: " << cid[i].nome << endl;
			cout << "UF: " << cid[i].UF << endl;
		}
		else {
			cout << "\n** CÓDIGO DIGITADO NÃO EXISTE! **.";
		}
	}
}


void leitura_instrutor(struct Instrutores intr[], int &cont, struct Cidade cid[], int &cont_cidades) {
	int i = 0;
	for (int saida = 1; i < 20 && saida != 0; i++) {
		cout << "\n\nCódigo do instrutor: ";
		cin >> intr[i].cod_instrutor;
		if(intr[i].cod_instrutor > 0) {
			cout << "Nome: ";
			cin >> intr[i].nome;
			cout << "Endereço: ";
			cin >> intr[i].endereco;
			cout << "Código da cidade: ";
			cin >> intr[i].cod_cidade;
			intr[i].status = 0;
			
			buscar_cidades(cid, cont_cidades, intr[i].cod_cidade);
		}
		else saida = 0;
	}
	cont = i - 1;
}

void leitura_indice_instrutor (struct indice_instrutor idx[], int contT){
    for (int i = 0; i < contT; i++){
        cout << "\n\nCodigo do Indice " << (i+1) << ": ";
        cin >> idx[i].codigo;
        cout << "Endereco Fisico na Area de Dados: ";
        cin >> idx[i].ender;
    }
}


void inclusao_instrutores (struct Instrutores intr[], int &cont, struct indice_instrutor idx[], int contT, int cod, struct Cidade cid[], int &cont_cidades){
    // inclusao do novo registro na area de dados
    cout << "Código do instrutor: ";
    cin >> intr[cont].cod_instrutor;
    cout << "Nome: ";
    cin >> intr[cont].nome;
    cout << "Endereco: ";
    cin >> intr[cont].endereco;
    cout << "Código da cidade: ";
    cin >> intr[cont].cod_cidade; 
    
    intr[cont].status = 0;
    
    // inclusao na area de indices
    int i;
    for (i = contT - 1; i >= 0 && idx[i].codigo > cod; i--){
        idx[i+1].codigo = idx[i].codigo;
        idx[i+1].ender = idx[i].ender;
    }
    idx[i + 1].codigo = cod;
    idx[i + 1].ender = cont;
    
    cout << "\n\nInclusao realizada com Sucesso";
    
    buscar_cidades(cid, cont_cidades, intr[cont].cod_cidade);
    
    cont++;
    contT++;
}

void busca_aleat_instrutor (struct Instrutores intr[], int &cont, struct indice_instrutor idxT[], int contT, int cod, struct Cidade cid[], int &cont_cidades){
    int i = 0, f = cont-1;
    int m = (i + f) / 2;
    for (; f >= i && cod != intr[m].cod_instrutor; m = (i + f) / 2){
        if (cod > intr[m].cod_instrutor)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == intr[m].cod_instrutor){
    	if(intr[m].status == 1) {
    		cout << "\n\n Instrutor estava excluído - será cadastrado novamente!" << endl;
            inclusao_instrutores(intr, cont, idxT, contT, cod, cid, cont_cidades);
            
		} else {
    		cout << "\n\n Instrutor já cadastrado - não pode ser cadastrado novamente!";
			cout << "\nCódigo do instrutor: " << intr[m].cod_instrutor;
			cout << "\nNome do instrutor: " << intr[m].nome;
			cout << "\nEndereço do instrutor: " << intr[m].endereco;
			cout << "\nCódigo da cidade do instrutor: " << intr[m].cod_cidade;
		
			buscar_cidades(cid, cont_cidades, intr[cont].cod_cidade);
		}	
    }
	
	else {
    	inclusao_instrutores(intr, cont, idxT, contT, cod, cid, cont_cidades);
	}
}


void exclusao_instrutores (struct indice_instrutor idx[], struct Instrutores intr[], int &cont, int cod, struct Turma tur[], int &cont_turmas){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].codigo; m = (i + f) / 2){
        if (cod > idx[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    i = idx[m].ender;
    if ((cod == idx[m].codigo) && intr[i].status == 0){
    	bool possui_turma = false;
        for (int j = 0; j < cont_turmas; j++) {
            if (tur[j].cod_instrutor_turma == cod) {
                possui_turma = true;
                break;
            }
        }

        if (possui_turma) {
            cout << "\n\nErro: O instrutor possui turmas cadastradas e não pode ser excluído!" << endl;
        } else {
            // Excluir o instrutor
            intr[i].status = 1;
            cout << "\n\nInstrutor excluído com sucesso" << endl;
        }
    } else {
        cout << "Instrutor não cadastrado" << endl;
    }
    
    cout << "\n\nInstrutores ainda ativos:\n";
    for (int k = 0; k < cont; k++) {
        if (intr[k].status == 0) { 
            cout << "Código: " << intr[k].cod_instrutor << " | Nome: " << intr[k].nome << endl;
        }
    }
}

//==========================================================


struct Matricula {
	int cod_matricula;
	int cod_aluno;
	int cod_turma;
	int quant_aulas;
	double valor_total;
};

struct endMatricula {
	int cod_matricula;
	int end_matricula;
};



//==========================================================

struct Aluno {
	int cod_aluno;
	string nome;
	string endereco;
	int cod_cidade;
	int status;
};

struct endAluno {
	int codigo;
	int ender;
};

void leitura_Aluno(struct Aluno alu[], int &cont, struct Cidade cid[], int &cont_cidades) {
	int i = 0;
	for (int saida = 1; i < 20 && saida != 0; i++) {
		cout << "\n\nCódigo do Aluno: ";
		cin >> alu[i].cod_aluno;
		if(alu[i].cod_aluno > 0) {
			cout << "Nome: ";
			cin >> alu[i].nome;
			cout << "Endereço: ";
			cin >> alu[i].endereco;
			cout << "Código da cidade: ";
			cin >> alu[i].cod_cidade;
			alu[i].status = 0;
			
			buscar_cidades(cid, cont_cidades, alu[i].cod_cidade);
		}
		else saida = 0;
	}
	cont = i - 1;
}

void leitura_indice_aluno (struct endAluno idx[], int contT){
    for (int i = 0; i < contT; i++){
        cout << "\n\nCodigo do Indice " << (i+1) << ": ";
        cin >> idx[i].codigo;
        cout << "Endereco Fisico na Area de Dados: ";
        cin >> idx[i].ender;
    }
}


void inclusao_aluno(struct Aluno alu[], struct endAluno idxA[], int contA, int &cont, int cod, struct Cidade cid[], int &cont_cidades){
    // inclusao do novo registro na area de dados
    cout << "Código do aluno: ";
    cin >> alu[cont].cod_aluno;
    cout << "Nome: ";
    cin >> alu[cont].nome;
    cout << "Endereco: ";
    cin >> alu[cont].endereco;
    cout << "Código da cidade: ";
    cin >> alu[cont].cod_cidade; 
    
    alu[cont].status = 0;
    
    // inclusao na area de indices
    int i;
    for (i = contA - 1; idxA[i].codigo > cod; i--){
        idxA[i+1].codigo = idxA[i].codigo;
        idxA[i+1].ender = idxA[i].ender;
    }
    idxA[i+1].codigo = cod;
    idxA[i+1].ender = cont;
    
    buscar_cidades(cid, cont_cidades, alu[cont].cod_cidade);
    
    cout << "\n\nInclusao realizada com Sucesso";
	
	cont++;
	contA++;
}   

void busca_aleat_aluno (struct Aluno alu[], struct endAluno idxA[], int contA, int &cont, int cod, struct Cidade cid[], int &cont_cidades){
    int i = 0, f = cont - 1;
    int m = (i + f) / 2;
    for (; f >= i && cod != alu[m].cod_aluno; m = (i + f) / 2){
        if (cod > alu[m].cod_aluno)
            i = m + 1;
        else
            f = m - 1;
    }
    if (alu[m].cod_aluno == cod){
        cout << "\n\n Aluno já cadastrado - não pode ser cadastrado novamente!";
		cout << "\nCódigo do aluno: " << alu[m].cod_aluno;
		cout << "\nNome do aluno: " << alu[m].nome;
		cout << "\nEndereço do aluno: " << alu[m].endereco;
		cout << "\nCódigo da cidade do aluno: " << alu[m].cod_cidade;
    }
    else
        inclusao_aluno(alu, idxA, contA, cont, cod, cid, cont_cidades);
}


void exclusao_alunos (struct endAluno idxA[], struct Aluno alu[], int &cont, int cod, struct Matricula ma[], int &cont_matricula){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idxA[m].codigo; m = (i + f) / 2){
        if (cod > idxA[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    i = idxA[m].ender;
    if ((cod == idxA[m].codigo) && alu[i].status == 0){
    	bool possui_turma = false;
        for (int j = 0; j < cont_matricula; j++) {
            if (ma[j].cod_aluno == cod) {
                possui_turma = true;
                break;
            }
        }

        if (possui_turma) {
            cout << "\n\nErro: O aluno possui matriculas cadastradas e não pode ser excluído!" << endl;
        } else {
            // Excluir o instrutor
            alu[i].status = 1;
            cout << "\n\nAluno excluído com sucesso" << endl;
        }
    } else {
        cout << "Aluno não cadastrado" << endl;
    }
    
    cout << "\n\nAlunos ainda ativos:\n";
    for (int j = 0; j < cont; j++) {
        if (alu[j].status == 0) { 
            cout << "Código: " << alu[j].cod_aluno << " | Nome: " << alu[j].nome << endl;
        }
    }
}

//==========================================================

int main() {
	setlocale(LC_ALL, "portuguese");
	
	Cidade cid[20];
	int contadorCidade = 0;
	
	Curso curs[20];
	int contadorCurso = 0;
	
	Instrutores intr[20];
	indice_instrutor idxI[20];
	int contadorInstrutor = 0, cod;
	
	Aluno alu[20];
	endAluno idxA[20];
	int contadorAluno = 0;
	
	Turma tur[20];
	endTurma idxT[20];
	int contadorTurmas = 0;
	
	Matricula ma[20];
	endMatricula idxM[20];
	int contadorMatricula = 0;
	
	int opcao = 30;
    while(opcao != 0) {
        cout << "\n\t** AGÊNCIA DE TURISMO **" << endl;
        cout << "-----------------------------------------------------"<< endl;
        cout << "| [1] - Leitura das Cidades:                         |"<< endl;
        cout << "| [2] - Leitura dos Cursos:                          |"<< endl;
        cout << "| [3] - Leitura dos instrutores                      |"<< endl;
        cout << "| [4] - Leitura das turmas:                          |"<< endl;
        cout << "| [5] - Leitura dos Alunos:                          |"<< endl;
        cout << "|----------------------------------------------------|"<< endl;
        cout << "| [6] - Inclusão dos Instrutores:                    |"<< endl;
        cout << "| [7] - Inclusão dos Alunos:                         |"<< endl;
        cout << "|----------------------------------------------------|"<< endl;
        cout << "| [8] - Exclusão dos Instrutores:                    |"<< endl;
        cout << "| [9] - Exclusão dos Alunos:                         |"<< endl;
        cout << "-----------------------------------------------------"<< endl; 
        
        cout << "[0] - Sair" << endl;
        cin >> opcao;
        
        switch(opcao) {
        	case 1:
        		system("cls");
                cout << "Leitura da cidade:" << endl;
                leitura_cidade(cid, contadorCidade);
                break;
                
            case 2: 
            	system("cls");
            	cout << "Leitura de cursos:" << endl;
            	leitura_curso(curs, contadorCurso);
            	break;
            	
            case 3: 
            	system("cls");
            	cout << "Leitura de instrutores:" << endl;
            	leitura_instrutor(intr, contadorInstrutor, cid, contadorCidade);
            	leitura_indice_instrutor(idxI, contadorInstrutor);
            	break;
				            	
            case 4:
            	system("cls");
    			cout << "Leitura de Turmas: " << endl;
    			leitura_turmas(tur, contadorTurmas, curs, contadorCurso);
    			leitura_indice_turma(idxT, contadorTurmas);
    			break;
    			
    		case 5:
    			system("cls");
    			cout << "leitura de Alunos:" << endl;
    			leitura_Aluno(alu, contadorAluno, cid, contadorCidade);
    			leitura_indice_aluno(idxA, contadorAluno);
    			break;
            	
            case 6:
            	system("cls");
            	cout << "Inclusão de instrutores:" << endl;
            	 for(long int codpesq = 9; codpesq != 0;){
        			cout << "\n\nInforme o código do instrutor a ser Incluido (0 para Encerrar)" << endl;
        			cin >> codpesq;
        			if (codpesq != 0)
            			busca_aleat_instrutor(intr, contadorInstrutor, idxI, contadorInstrutor, codpesq, cid, contadorCidade);
    			}
            	break;
            	
    		case 7: 
    			system("cls");
            	cout << "Inclusão de alunos:" << endl;
            	for(long int codAluno = 9; codAluno != 0;){
        			cout << "\n\nInforme o código do aluno a ser Incluido (0 para Encerrar)" << endl;
        			cin >> codAluno;
        			if (codAluno != 0)
            			busca_aleat_aluno(alu, idxA, contadorAluno, contadorAluno, codAluno, cid, contadorCidade);
    			}
            	break;
    			
    		case 8:
            	system("cls");
            	cout << "Exclusão de instrutores: " << endl;
            	for (int codex = 9; codex != 0;){
        		cout << "\n\nInforme o Codigo do Cliente a ser Exclu?do (0 para Encerrar): ";
        		cin >> codex;
        		if (codex != 0)
            		exclusao_instrutores(idxI, intr, contadorInstrutor, codex, tur, contadorTurmas);
    			}
    			break;
    			
    		case 9:
    			system("cls");
    			cout << "Exclusão de alunos:" << endl;
    			for (int codex = 9; codex != 0;){
        		cout << "\n\nInforme o Codigo do Cliente a ser Exclu?do (0 para Encerrar): ";
        		cin >> codex;
        		if (codex != 0)
            		exclusao_alunos(idxA, alu, contadorInstrutor, codex, ma, contadorMatricula);
    			}
    			break;
		}
	}
}
	
