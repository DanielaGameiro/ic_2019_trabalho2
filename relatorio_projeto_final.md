# __Relatório do Projeto Final da UC Introdução à Computação__

__Autores:__ Daniela Gameiro nº21901681, Francisco Costa nº21903228 e Luís Martins nº21903145

__Grupo Pandora:__ outra_coisa

__*Link GitHub*:__ <https://github.com/DanielaGameiro/ic_2019_trabalho2>

## __Descrição da Solução__
>Criámos a estrutura das perguntas (Pessoa) e de seguida a função Ler. A mesma irá ler o ficheiro preveniente do docente e passá-lo para dentro da estrutura Pessoa, em forma de lista ligada. 
>
>A função ShowQuestion(); vai receber a seed resultante do professor e irá procurar na lista ligada uma pergunta adequada ao nível de dificuldade que o utilizador se encontra. De seguida, se existir uma pergunta irá mostrar a mesma e as opções no ecrã de forma randomizada. Vai também guardar a resposta correta à pergunta feita e depois vai apagar da lista ligada a pergunta feita ao utilizador e juntá-la ao resto da lista. 

## __Estrutura do *Software*__
>A função *main()* recebe os argumentos da *command line*; e executa as restantes funções de modo a correr o programa.
>
>Em seguida, começa por chamar a função *Ler();* para ler o ficheiro. Depois mostra ao utilizar o menu com o *printMenu();*, aceita o input do utilizador sobre o que é que o utilizador quer fazer no menu, e em caso de ele querer começar o jogo, irá pedir o nome, mostrar os *status* iniciais e finalmente a primeira pergunta no ecrã. De seguida, o utilizador irá meter a sua resposta ou o que quer fazer no menu e o programa irá verificar se a sua resposta está correta. Perante a resposta irá passar ou não para o próximo patamar, se não tiver perdido o jogo irá constantemente mostrar as perguntas novas até o utilizador ganhar ou perder. Caso o utilizador errar duas vezes seguidas, o programa fecha e mostra a mensagem *“Sorry, you have lost the game. Bye!”*
>
>O *printCredits();* faz print dos créditos e o *showstatus();* faz print dos status. 

## __Conclusões Finais__
> Com este projeto conseguimos assimilar melhor a matéria dada nas aulas de IC e pôr em prática o conteúdo ensinado. Possibilitou a aprendizagem dos conteúdos sobre ficheiros, apontadores e memória dinâmica de uma forma prática e precentível.
> 
> O procedimento de debugging foi um desenvolvimento complicado e demorado, porém muito bom
para o aumento dos nossos conhecimentos em C.

## __Referências__
As bibliotecas que utilizámos foram as seguintes:
- stdio.h
- stdlib.h
- stdbool.h
- math.h
- time.h
- string.h

> O nosso colega Pedro Dias Marques da Universidade Lusófona deu-nos algumas dicas de como ler o ficheiro.