#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <string.h>




typedef struct Pessoa{
        char question[128];
        char answers[4][64];
		enum {Books = 1 , Film , General, Music, Theatres, Television, Video, Board, Nature, Computers, Mathematics, Mythology, Sports, Geography, History, Politics, Art, Celebrities, Animals, Vehicles,Comics, Gadgets, Japanese, Cartoon}category;
		enum {easy = 1, medium=2  , hard=3 } difficulty ;
        struct Pessoa *next;
		struct Pessoa *prev;
 
}PESSOA;

PESSOA *Ler(char* ficheiro);
void Showlist(PESSOA *L);

void print_menu(void);
void showstats(char name[], int lvl, bool j50, bool j25);
void randomize(int arr[], int n);
void swap(int *a, int *b);
void printCredits(void);
void jogo(int seed,char nome[], PESSOA *L);
char* ShowQuestion(PESSOA *L, unsigned difficulty,char* seed,int* r,char* dest,bool ch);

int main(int argc, char **argv)
{
	char joker[2];
	char str[64] = {'\0'};
	int show = 0;
	int errar = 0;
	int r = 0;
	char ans[64];
	char seed[10] = "-2000";
	char c;
	char name[35];
	int lvl = 0;
	bool j50 = true;
	bool j25 = true;
	PESSOA *L=NULL;


	if (argc <= 2){
		
	}else{
	
		if (argc == 3)
		{
			if (strcmp(argv[1], "-s") == 0)
			{
				
				strcpy(seed,argv[2]);
				
				
			}else if (strcmp(argv[1] ,"-f") == 0)
			{
				
				L=Ler(argv[2]);
				
			}else
			{
				
			}
		}
		if (argc == 5)
		{
		
			if (strcmp(argv[1], "-s") == 0)
			{
				strcpy(seed,argv[2]);
			}else if (strcmp(argv[1] ,"-f") == 0)
			{
				
				
				L=Ler(argv[2]);
				
				
			}else
			{
				
			}
			if (strcmp(argv[3], "-s") == 0)
			{
				strcpy(seed,argv[2]);
			}else if (strcmp(argv[3] ,"-f") == 0)
			{
			
				
				L=Ler(argv[4]);
				
			}
		}else
		{
			
		}
		
	}

	print_menu();
			
	bool check = false;
	while (c != 'q')
	{
		scanf("%c", &c);
		if (check == true && c != 'q' && c!= 'r' && c!='h' && c!='c' && c!='j' && c!='s' && c!='\n' )
		{
			if (r == 0){
				if (c=='A' )
				{
					
					printf(">*** Hooray!\n");
					lvl++;
					errar = 0;
					show = 0;
					showstats(name,lvl,j50,j25);
					if (lvl==8)
					{
						break;
					}
					
				}else if(c=='B'||c=='C'||c=='D'){
					

					if (lvl != 0){
					lvl--;
					
					}
					errar++;
				
					show = 0;
					printf(">*** Woops... That's not correct.\n");
					printf("*** The correct answer was A: %s\n",ans);
					if(errar==2){
						break;
					}
				}
			}
			if (r == 1){
				if (c=='B')
				{
					
					printf(">*** Hooray!\n");
					lvl++;
					errar = 0;
					show = 0;
					showstats(name,lvl,j50,j25);
					if (lvl==8)
					{
						break;
					}
				}else if(c=='A'||c=='C'||c=='D'){
					
					if (lvl != 0){
					lvl--;				
					}
					errar++;
				
					show = 0;
					printf(">*** Woops... That's not correct.\n");
					printf("*** The correct answer was B: %s\n",ans);
					if(errar==2){
						break;
					}
					showstats(name,lvl,j50,j25);
					
				}	
			}
			if (r == 2){
				
				if (c=='C')
				{
					
					printf(">*** Hooray!\n");
					lvl++;
					errar = 0;
					show = 0;
					showstats(name,lvl,j50,j25);
					if (lvl==8)
					{
						break;
					}
				}else if(c=='A'||c=='B'||c=='D'){
					
					if (lvl != 0){
					lvl--;
					
					}
					errar++;
					
					show = 0;
					printf(">*** Woops... That's not correct.\n");
					printf("*** The correct answer was C: %s\n",ans);
					if(errar==2){
						break;
					}
					showstats(name,lvl,j50,j25);
					
				}
			}
			if (r == 3){
				if (c=='D')
				{
					
					printf(">*** Hooray!\n");
					lvl++;
					errar = 0;
					show = 0;
					showstats(name,lvl,j50,j25);
					if (lvl==8)
					{
						break;
					}
				}else if(c=='B'||c=='C'||c=='A'){
					
					if (lvl != 0){
					lvl--;
					}
					errar++;
					
					show = 0;
					printf(">*** Woops... That's not correct.\n");
					printf("*** The correct answer was D: %s\n",ans);
					if(errar==2){
						break;
					}
					showstats(name,lvl,j50,j25);
					
				}

			}
			
			if (show == 0){
			if (errar<2)
			{
			if(lvl>=0 && lvl<4){
			strcpy(ans,ShowQuestion(L,1,seed,&r,str,true));
			}else if(lvl>3 && lvl<6){
			strcpy(ans,ShowQuestion(L,2,seed,&r,str,true));
			}else if(lvl>5 && lvl<9){
			strcpy(ans,ShowQuestion(L,3,seed,&r,str,true));
			}
			}else
			{
				break;
			}
			}
		}	
			
		if (c=='n')
		{
			
			fgets(name,35,stdin);
			
			name[strcspn(name, "\n")] = 0;
			
			if(name[0]=='\0')
			{
				strcpy(name,"Newbie");
			}
			printf(">*** Hi %s, let's get started!\n",name);
			showstats(name,lvl,j50,j25);
			strcpy(ans,ShowQuestion(L,1,seed,&r,str,false));
			show = 1;
			check = true;
			

			
			
		}else if (c=='q')
		{
			printf(">*** Sad to see you go...\n");
		}else if (c=='h')
		{
			printf(">");
			print_menu();
		}else if (c=='r')
		{
			if (check == true)
			{
				printf("Illegal move\n");
			}
				
		}else if (c=='s')
		{
			
			
		}else if (c=='j')
		{
			scanf("%s",joker);
			if (strcmp(joker,"50")==0)
			{
				
			}else if(strcmp(joker,"50")){

			}
			while(getchar() != '\n');
		}else if (c=='c'){
			printCredits();
		}
		
		

	}
			
	if (errar==2)
	{		
	printf("*** Sorry, you have lost the game. Bye!");	
	}
	if (lvl==8)
	{
		printf("*** This is incredible! You have won!\n");
		printf("*** Congratulations Henry!\n");

	}
	
	
}





PESSOA *Ler(char* ficheiro){
 
    char line[512];
   PESSOA * head = NULL;
   PESSOA * tail = NULL;
   PESSOA * new;
   
   FILE *in_file;
   
  
   in_file = fopen(ficheiro, "r");
   
   if (in_file == NULL)
   {
      puts("*** Error opening file");
      exit(0);
   }
   while(fgets(line, 512, in_file) != NULL)
   {
      if (line[0] == ';')
         continue;

      new = (PESSOA *) malloc(sizeof(PESSOA));
      new->next = NULL;

      strcpy(new->question, &line[9]);

      fgets(line, 512, in_file); 
      strcpy(new->answers[0], &line[8]);

      fgets(line, 512, in_file); 
      strcpy(new->answers[1], &line[8]);

      fgets(line, 512, in_file); 
      strcpy(new->answers[2], &line[8]);

      fgets(line, 512, in_file); 
      strcpy(new->answers[3], &line[8]);

      fgets(line, 512, in_file); 
      
      fgets(line, 512, in_file); 
      if (strcmp(line, "DIFFICULTY=easy\n") == 0)
         new->difficulty = easy;
      else if(strcmp(line, "DIFFICULTY=medium\n") == 0)
         new->difficulty = medium;
      else
        new->difficulty = hard;
		

      if (head == NULL)
      {
         head = new;
      }

      if (tail != NULL)
      {
         tail->next = new;
      }
      tail = new;

   }
   fclose(in_file);
   return head;
}

void Showlist(PESSOA *L){
 
        if(L==NULL){
 
                printf("A Lista esta' vazia!\n");
                return;
        }
        else {
                while(L!=NULL){
                        printf("%s\n%s\n%s\n%s\n%s\n%d\n%d\n",L->question,L->answers[0], L->answers[1], L->answers[2], L->answers[3],L->category, L->difficulty);
						L=L->next;             
                }
        }
 
        return;
}

char* ShowQuestion(PESSOA *L, unsigned difficulty,char* seed,int* r, char* dest,bool ch){
	 PESSOA *prev = NULL;
	 if(ch == false){
	 if(strcmp(seed,"-2000")==0){
		 srand(time(NULL));
	 }else
	 {
	 srand((atoi(seed)));
	 }
	 }
	 int random = rand() % 4;
	 *r=random;
	 int count = 0;
	 while (L!=NULL)
	 {
		 
		if (L->difficulty==difficulty)
		{
			
			break;
		}
		count++;
		prev = L;
		L = L->next;   
	 }
	 
	 
			
	 
	 if(L==NULL){
 
            printf("A Lista esta' vazia!\n");
            return 0;

        }else {
			printf("*** Question: %s",L->question);
			if (random == 0)
			{

				printf("*** A: %s",L->answers[0]);
				printf("*** B: %s",L->answers[1]);
				printf("*** C: %s",L->answers[2]);
				printf("*** D: %s",L->answers[3]);
				printf("Rola");
			}else if(random == 1){

				printf("*** A: %s",L->answers[1]);
				printf("*** B: %s",L->answers[0]);
				printf("*** C: %s",L->answers[2]);
				printf("*** D: %s",L->answers[3]);
				printf("Rola");
			}else if(random == 2){

				printf("*** A: %s",L->answers[1]);
				printf("*** B: %s",L->answers[2]);
				printf("*** C: %s",L->answers[0]);
				printf("*** D: %s",L->answers[3]);
				printf("Rola");
			}else if (random == 3){

				printf("*** A: %s",L->answers[1]);
				printf("*** B: %s",L->answers[2]);
				printf("*** C: %s",L->answers[3]);
				printf("*** D: %s",L->answers[0]);

				
			}

		}

	strcpy(dest,L->answers[0]);
	prev->next = L->next;
	dest[strlen(dest)-1]='\0';
	free(L);
	return dest;
}


void print_menu(void){
	puts("********************************************");
	puts("***            CILLIONAIRE                 *");
	puts("********************************************");
	puts("*** n <name>     - new game                *");
	puts("*** q            - quit                    *");
	puts("*** h            - show this menu          *");
	puts("*** r <filename> - resume game             *");
	puts("*** s <filename> - save progress and quit  *");
	puts("*** j 50         - play 50:50 joker        *");
	puts("*** j 25         - play 25:75 joker        *");
	puts("*** c            - show credits            *");
	puts("********************************************");
}

void showstats(char name[], int lvl, bool j50, bool j25){
	if (lvl==0){
		lvl = 0;
	}else if (lvl==1){
		lvl = 500;
	}else if (lvl==2){
		lvl = 1000;
	}else if (lvl==3){
		lvl = 2000;
	}else if (lvl==4){
		lvl = 5000;
	}else if (lvl==5){
		lvl = 10000;
	}else if (lvl==6){
		lvl = 20000;
	}else if (lvl==7){
		lvl = 50000;
	}else if (lvl==8){
		lvl = 100000;
	}
	
	
	size_t i=0;
	char linename[50]="*** Name:                                  *";
	char str[10];
	char linej50[50]="*** j50:                                   *";
	char linej25[50]="*** j25:                                   *";
	puts("********************************************");
	while (i<strlen(name))
	{
		linename[11+i] = name[i];
		i++;
	}
	printf("%s\n", linename);
	sprintf(str, "%d", lvl);
	i = 0;
		printf("*** Level: %d                               *\n",lvl);
	
	if (j50==true)
	{
		linej50[11]='Y';
		linej50[12]='E';
		linej50[13]='S';
	}else
	{
		linej50[11]='N';
		linej50[12]='O';
	}

	printf("%s\n", linej50);
	i = 0;
	if (j25==true)
	{
		linej25[11]='Y';
		linej25[12]='E';
		linej25[13]='S';
	}else
	{
		linej25[11]='N';
		linej25[12]='O';
	}
	
	printf("%s\n", linej25);
	puts("********************************************");
	
	
	

}

void printCredits(void)
{
   puts("*********************");
	puts("*** GAME CREATORS ***");
   puts("***   Francisco Costa   ***");
   puts("***  Daniela Gameiro  ***");
   puts("***    Luís Martins    ***");
   puts("*********************");
}

