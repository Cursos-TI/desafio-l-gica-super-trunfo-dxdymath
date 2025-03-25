#include <stdio.h>

//Utilizado struct como estrutura de dados para armazenar os dados das cartass
struct Carta {
    int idCarta;
    char estadoCarta[2];
    char codigoCarta[4];
    char nomeCidade[100];
    int numeroTotalPopulacao;
    float areaCidade;
    float pibCidade;
    int numeroPontoTuristico;
};


void ler_dados_carta(int idCarta, struct Carta *carta); //Definido função para ler dados da carta
void exibir_carta(struct Carta carta); //Definido função exibir dados da carta
float calcula_densidade_populacional(struct Carta carta); //Definido função para calcular a densidade populacional
float calcula_pib_per_capita(struct Carta carta); //Definido função para calcular pib per capita

int main() {
    
    struct Carta carta1; //Criado variável para armazenar dados da carta1
    struct Carta carta2; //Criado variável para armazenar dados da carta2
    ler_dados_carta(1, &carta1); //Realizado leitura e armazenado os valores na carta1
    ler_dados_carta(2, &carta2); //Realizado leitura e armazenado os valores na carta2

    float densidadePopulacionalCarta1 = calcula_densidade_populacional(carta1); //Calculado densidade populacional para carta1
    float pibPerCapitaCarta1 = calcula_pib_per_capita(carta1); //Calculado pib per capita para carta1
    float densidadePopulacionalCarta2 = calcula_densidade_populacional(carta2); //Calculado densidade populacional para carta2
    float pibperCapitaCarta2 = calcula_pib_per_capita(carta2); //Calculado pib per capita para carta2

    exibir_carta(carta1); //Exibido dados da carta1
    exibir_carta(carta2); //Exibido dados da carta2

    if (densidadePopulacionalCarta1 < densidadePopulacionalCarta2) { //Condição para verificar se densidade da carta1 é menor que a carta2
        printf("Resultado: Carta 1 (%s) venceu\n", carta1.nomeCidade);
    }
    else if (densidadePopulacionalCarta2 < densidadePopulacionalCarta1) { //Condição para verificar se densidade da carta2 é menor que a carta1
        printf("Resultado: Carta 2 (%s) venceu\n", carta2.nomeCidade);
    }

    return 0;
}

void ler_dados_carta(int idCarta, struct Carta *carta) {

    carta->idCarta = idCarta; //Atribuído id a estrutura de dados
    
    /*
    Exibido mensagens para facilitar entrada dos usuários e armazenado valores nas variáveis
    */
    printf("Digite o estado [A-H]: ");
    scanf("%s", carta->estadoCarta);
    printf("Digita o código da carta: ");
    scanf("%s", carta->codigoCarta);
    printf("Digite o nome da cidade: ");
    scanf("%s", carta->nomeCidade);
    printf("Digite o número de habitantes: ");
    scanf("%d", &carta->numeroTotalPopulacao);
    printf("Digite a área da cidade em metros quadrados: ");
    scanf("%f", &carta->areaCidade);
    printf("Digite o PIB da cidade: ");
    scanf("%f", &carta->pibCidade);
    printf("Digite o número total de pontos turísticos da cidade: ");
    scanf("%d", &carta->numeroPontoTuristico);

    printf("\n");
};

void exibir_carta(struct Carta carta) {

    /*
    Exibido dados na tela
    */
    printf("Carta %d\n", carta.idCarta);
    printf("Estado: %s\n", carta.estadoCarta);
    printf("Código: %s\n", carta.codigoCarta);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("Área:  %.2f\n", carta.areaCidade);
    printf("PIB: %.2f\n", carta.pibCidade);
    printf("Número de Pontos Turísticos: %d\n", carta.numeroPontoTuristico);
    printf("\n");
};

/*
Calculo da densidade populacional
*/
float calcula_densidade_populacional(struct Carta carta) {

    float densidadePopulacional = carta.numeroTotalPopulacao / carta.areaCidade;
    return densidadePopulacional;
}

/*
Calculo do PIB per capita
*/
float calcula_pib_per_capita(struct Carta carta) {

    float pibPerCapita = carta.pibCidade / carta.numeroTotalPopulacao;
    return pibPerCapita;
}
