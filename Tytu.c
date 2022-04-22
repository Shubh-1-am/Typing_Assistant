#include<stdio.h>
#include <time.h>
//functions
void choiceCheck(int choice);
void userInfo();
int write(FILE *fp);
void fileCh();
void loadFile( int level);

int level;
char name[50];
int age, mistakes, nchar;
FILE *fp;
int main(){
  printf("\n\r%26s%c T Y P I N G  A S S I S T A N T %c","",16,17);
  printf("\nTyping Assistant is an easy-to-use, quick and customizable C lanuage-based typing test that you can use for all your business recruitment,training purposes and typing skill development.Take the easy way to assess your performance based on your typing speed, accuracy and score.");
  printf("\n\n\r \xaf Welcome to the Game! \
  \n\r \xaf MAIN MENU \n\n\r (1) Select User\n (2) About\n (3) Quit \n \n\r \xaf Enter your choice: ");
  int choice;
  scanf("%d",&choice);
  choiceCheck(choice);
  printf("\n\n");
  return 0;
}

void choiceCheck(int choice){
  if(choice==1){
    printf("Ready to play!\n"); 
    userInfo();
    fileCh();
    printf("\n");
    loadFile(level);
  
  }
  else if(choice==2){
    printf("\n\n\r\t\t\t\t[[[[ABOUT US]]]]\n\n\n");
     printf("\n\r%26s%c T Y P I N G  T E S T E R %c\n\n\n","",16,17);
       printf("\t\t\t||Developed on: 20th March 2021||\t\t\t\n ");
       printf("\t\t\t||      ***Developers****      || \n\t\t\t\xaf SHUBHAM SINGH (2021BCSE028) \n\t\t\t\xaf TANISHKA KUMARI (2021BCSE060)\n");

  }
  else if(choice==3){
    printf("Thank you!");
     exit(0);
  }
  else{
      printf("Please Enter the valid choice:");
      scanf("%d",&choice);
      choiceCheck(choice);
  }
}
void userInfo(){
    
  printf("Enter Your Name:");
  scanf("%s",name);
  printf("Enter Your Age:");
  scanf("%d",&age);
  //printf("%s %d",name,age);
}
void fileCh(){
  printf("\n\r \xaf LEVELS \n\n\r (1) Beginner\n (2) Intermediate\n (3) Advance\n");
  printf("Select the your Level:\n ");
  scanf("%d",&level);
 
}
void loadFile( int level){
  if(level==1){
   
    fp=fopen("level1.txt","r");
    write(fp);
  }
  else if(level==2){
    fp=fopen("level2.txt","r");
    write(fp);
  }
  else if(level==3){
    fp=fopen("level3.txt","r");
    write(fp);
  }
  else{
    printf("Cannot open the file!");
  }
}
int write(FILE *fp) 
{
  int wpm; float accuracy;
  fseek(fp,0,SEEK_END);
  int length=ftell(fp);
  fseek(fp,0,SEEK_SET);
  char arr[length];
  fread(arr,1,length,fp);
  printf("%s",arr);
  printf("\n\nSTART TYPING:\n\n");
  time_t start=time(NULL);
  for(int i=0;i<length && arr[i]!='\n';){
    char c=getch();
    if(c==arr[i]){
        putc(c,stdout);
        i++;
      }
    else
    {
      mistakes++;
    }
    nchar++;
    }
    
  time_t end=time(NULL);
  
  double diff= difftime(end,start);
  if(diff!=0){
	  wpm = (length*60)/diff;	
  }
	else{
      wpm=0;
    }
  if(length!=0)
		accuracy=(float)100*(nchar-mistakes)/nchar;
  else accuracy=0.0;

	printf("\n\n\n\r\t\t\t\t    [[[[[ R E S U L T ]]]]]");
  printf("\n\r\t\t\t\t|*  Name: %s                ",name);
  printf("\n\r\t\t\t\t|*  Level: %d                ",level);
	printf("\n\r\t\t\t\t|*  Duration: %.2f seconds  ",diff);
  printf("\n\r\t\t\t\t|*  Errors: %d               ", mistakes);
  printf("\n\r\t\t\t\t|*  Gross Speed : %d WPM   ",wpm);
  printf("\n\r\t\t\t\t|*  Accuracy : %.0f%%         ",accuracy);
  printf("\n\r\t\t\t\t|*  Score: %.0f            ",accuracy*wpm);
      if(accuracy*wpm>=800){
        if(level<3){
        printf("\n\n[[[[CONGRATULATIONS!!!!]]]]\n");
       printf("You have successfully completed Level %d\n",level);
          printf("Do you want to continue?\n");
        printf("\t\t\r 1. Yes, take me to the next level.\n 2. Quit\n");
          char input=getch();
           if(input=='1' || input=='2'){
             if(input=='1'){
               loadFile(++level);
             }
             else{
               printf("Thank you!");
               exit(1);
             }
           }
         } else{
           printf("\n\n\rCongratulations!!! You have Successfully completed all the levels.\n");
           printf("Thank You! Welcome Back!!!");
         }
      }
      else{
        printf("\nYou have not cleared this level!\n");
        printf("Do you you want to try again?\n");
         printf(" press (1) to try this level again\n press (2) to Exit\n");
          char input=getch();
         if(input=='1' || input=='2'){
             if(input=='1'){
               loadFile(level);
             }
             else{
                printf("Thank you!");
               exit(1);
             }
           }
      }
  return 0; 
}