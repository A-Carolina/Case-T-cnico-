#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#define MAX 1

//Prototipos
void cadastroClientes();
void listarClientes();
void categorizarClientes();
void menu();
//Funcoes
struct cliente {
	char nome[20];
	int idade;
} Cliente;


void cadastroClientes(){ 
	int i,j,contador = 0;
	char resposta,r;
	cliente pessoa[MAX];
	FILE*registros;
	registros = fopen("registros2.txt","ab");
	if(registros == NULL){
		printf("ERRO ao abrir o arquivo.");
	} else{
			do{
				system("cls");
				system("color F1");
				printf("\t============== CADASTRO ==============\n\n");
				printf("\tATENÇÃO: Você pode realizar %d cadastro/s por vez.\n\n",MAX);
				for(i = 0; i<MAX; i++){
				printf("\t%d.Insira o nome do/a cliente: ",contador++);
				scanf(" %s",&pessoa[i].nome);
				printf("\t%d.Insira a idade do/a cliente: ",contador++);
				scanf(" %d",&pessoa[i].idade);
					if(pessoa[i].idade<=0 or pessoa[i].idade>=122){
						system("color F4");					
						printf("Número inválido. Certifique-se de colocar a idade correta.\n");
						exit(1);
					} // fim do if de verificacao de idade 
					fwrite(&pessoa,sizeof(struct cliente),1,registros);
				} // fim do for de registro
				
				fflush(stdin);
				printf("Você deseja realizar mais um cadastro?");
				scanf(" %c",&resposta);
			} while (resposta == 's' or resposta == 'S');
				if(resposta != 115 or resposta != 83){
					printf("\nOperação encerrada");
				} 
					printf("\nCadastro(s) realizado(s) com sucesso!\n");
						if(!fclose(registros)){
								system("color F2");
								printf("\nFECHAR:Arquivo fechado com sucesso");
							} else{
								printf("\nErro ao fechar o arquivo\n");
							}
							printf("\nDeseja voltar ao MENU PRINCIPAL?");
							scanf(" %c",&r);
								if(r == 's' or r == 'S'){
									printf("Você será redirecionado para o MENU PRINCIPAL \n");
									menu();
								} else{
									exit(0);
								}
					
	}
	} 
	void organizarPorIdade(struct cliente cliente[], int numeroClientes){
	int i,j;
	struct cliente temporario;
		for(i = 0; i<numeroClientes - 1; i++){
			for(j = i+1; j<numeroClientes; j++){
				if(cliente[i].idade> cliente[j].idade){
					temporario = cliente[i];
					cliente[i] = cliente[j];
					cliente[j] = temporario;
				}
			}
		}
}	
//Funcao para listar clientes
void listarClientes(){
	int resp;
	char r;
	int i,j;
	char temp[10];
	cliente pessoa[MAX];
	FILE*registros;
	registros = fopen("registros2.txt","rb");
		if(registros == NULL){
			system("color F4");
			printf("ERRO. O arquivo não pode ser aberto.\n");
			exit(1);
		} else{		printf("\t========= CLIENTES REGISTRADOS =========\n");
					printf("\tVocê quer a listagem por \n\t1.Ordem Alfabética \n\t2.Ordem crescente de idade\n");
					scanf(" %d",&resp);
					fflush(stdin);
				while(fread(&pessoa,sizeof(struct cliente),1, registros)==1){
				
					switch(resp){
						case 1: printf("\nOoops... a página que voce procurou nao foi encontrada");
						 /* A ideia aqui era a de utilizar um algoritmo de Bubble sort, mas não consegui implementar*/
						break;
						case 2: organizarPorIdade(pessoa,MAX);
						for(i = 0; i<MAX; i++){
							printf("\nA idade de %s é %d anos",pessoa[i].nome, pessoa[i].idade);
						} 
							break;
						default: system("color F1"); printf("ERRO.Opção não encontrada.");	
						    exit(1);;	
					}//fim do switch	
				} //fim do while
		} // fim do else
		printf("\nDeseja voltar ao MENU PRINCIPAL?");
							scanf(" %c",&r);
								if(r == 's' or r == 'S'){
									printf("Você será redirecionado para o MENU PRINCIPAL \n");
									menu();
								} else{
									exit(0);
								}
}
void categorizarClientes(){
	Cliente;
	int crianca = 0,adol = 0, adulto = 0, idoso =0;
	char r;
	FILE*registros;
	registros = fopen("registros2.txt","rb");
		if(registros == NULL){
			system("color F1");
			printf("ERRO. O arquivo não pode ser aberto\n");
			exit(1);
		} else{
			printf("\nAqui,você pode ter uma estimativa da faixa etária de nossos clientes.\n");
			for(int i = 0; i< 50; i++){
					while(fread(&Cliente,sizeof(struct cliente),1,registros)==1){
				if(Cliente.idade <= 12 and Cliente.idade>=0){
					printf("\n\tCliente %d: Criança",i++);
					crianca++;
				} if(Cliente.idade >=13 and Cliente.idade<=19){
					printf("\n\tCliente %d: Adolescente",i++);
					adol++;
				} if (Cliente.idade>=20 and Cliente.idade<=65){
					printf("\n\tCliente %d: Adulto",i++);
					adulto++;
				} if(Cliente.idade >= 65){
					printf("\n\tCliente %d: Idoso",i++);
					idoso++;
				}
			}
		}//fim do for
				printf("\n\tA quantidade de crianças é: %d",crianca);
				printf("\n\tA quantidade de adolescentes é: %d",adol);
				printf("\n\tA quantidade de adultos é: %d",adulto);
				printf("\n\tA quantidade de idosos é: %d",idoso);
			
				if(crianca> adol and crianca>adulto and crianca>idoso){
					printf("\n\tA faixa etária com maior quantidade de clientes é: CRIANÇAS" );
				} if(adol>crianca and adol>adulto and adol>idoso){
					printf("\n\tA faixa etária com maior quantidade de clientes é: ADOLESCENTES" );
				} if(adulto>crianca and adulto>adol and adulto>idoso){
						printf("\n\tA faixa etária com maior quantidade de clientes é: ADULTOS" );
				} if( idoso>crianca and idoso>adulto and idoso> adol){
					printf("\n\tA faixa etária com maior quantidade de clientes é: IDOSOS" );
				} 
				
			}	//fim do else	
		if(fclose(registros)!=0){ //fechar arquivo
								system("color F1");
								printf("\n\nFECHAR:Erro ao fechar o arquivo");
							} else{
								printf("\nFECHAR: Arquivo fechado com sucesso\n");
							}
							printf("\nDeseja voltar ao MENU PRINCIPAL?");
							scanf(" %c",&r);
								if(r == 's' or r == 'S'){
									printf("Você será redirecionado para o MENU PRINCIPAL \n");
									menu();
								} else{
									exit(0);
								}
		
} //fim da funcao
void menu(){
int opcao;

printf("\tATENÇÃO: Para acessar as opções 2 e 3, é necessário cadastrar os clientes na base.\n\n");
printf("\t1 - Cadastro\n");
printf("\t2 - Listar Cadastros\n");
printf("\t3 - Organizar Cadastros (por idade)\n");
printf("\t4 - Sair\n\n");
scanf(" %d",&opcao);
	switch(opcao){
		case 1: system("cls");
				cadastroClientes();
			break;
		case 2: system("cls");
				listarClientes();
			break;
		case 3: system("cls");
				categorizarClientes();	
			break;	
		case 4: system("color F4");
				printf("Você escolheu sair.");
				exit(0);	
		default: printf("Opção inválida");
}
}

 main(){
	setlocale(LC_ALL,"Portuguese");
	system("color F1");
	printf("\t========= Bem-vindo/a Á Livraria Travessa! =========\n\n");
	printf("\tQual operação você deseja realizar?\n");
	menu();
}
