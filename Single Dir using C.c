#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct
{
	char dname[40],fname[40][40];
	int fcnt;
}dir[20];

void main()
{
	int i,ch,dcnt=0,k;
	char f[40], d[40], tdname[40], tfname[40];
	while(1){
		printf("\n\n1.Create Directory\t2.Delete Directory\t3.Create File\t4.Delete File");
		printf("\t5.Search File\t6.Display\t7.Exit\nEnter your choice:\t");
		scanf("%d",&ch);
		switch(ch){
			case 1:	printf("\nEnter name of directory:\t");
					scanf("%s", tdname);
					for(i=0;i<dcnt;i++){
						if(!strcmp(tdname,dir[i].dname))
						break;
					}	
					if(i==dcnt){
						strcpy(dir[i].dname,tdname);
						dir[dcnt].fcnt=0;
						dcnt++;
						printf("Directory created!");
						break;
					}
					else{
						printf("%s already exists!\n",tdname);
						break;
					}
					break;
								
			case 3: printf("\nEnter name of the Directory:\t");
					scanf("%s",d);
					for(i=0;i<dcnt;i++)			// i will be incremented to dcnt but won't enter loop
					 
											/* i = 0 first and increments till i < dcnt and enter loop that many times 
											and when it increments to i = dcnt it won't enter loop */
						if(strcmp(d,dir[i].dname)==0)
						{							
							printf("Enter File name:\t");
							scanf("%s", tfname);
							for(k=0;k<dir[i].fcnt;k++){
								if(!strcmp(tfname,dir[i].fname[k]))
								break;
							}	
							if(k==dir[i].fcnt){
								strcpy(dir[i].fname[k],tfname);
								dir[i].fcnt++;
								printf("File created!");
								break;
							}
							else{
								printf("%s already exists!\n",tfname);
								break;
							}
							break;	
						}
					if(i==dcnt)			// since i is now equal to dcnt if the 'if' statement inside the above loop isn't satisfied
						printf("Directory %s doesn't Exist!'",d);
						break;
			case 4: printf("\nEnter name of the directory:\t");
					scanf("%s",d);
					for(i=0;i<dcnt;i++)
					{
						if(strcmp(d,dir[i].dname)==0)
						{
							printf("Enter name of the file:\t");
							scanf("%s",f);
							for(k=0;k<dir[i].fcnt;k++)
							{
								if(strcmp(f, dir[i].fname[k])==0)
								{
									printf("File %s is deleted!",f);
									dir[i].fcnt--;
									strcpy(dir[i].fname[k],dir[i].fname[dir[i].fcnt]);
									goto jmp;
								}
							}
							printf("File %s doesn't Exist'!",f);
							goto jmp;
						}
					}
					printf("Directory %s doesn't Exist!'",d);
					jmp : break;							// goes to this break statement otherwise it will loop
			case 2: printf("\nEnter name of the directory:\t");
					scanf("%s",d);
					for(i=0;i<dcnt;i++)
					{
						if(strcmp(d,dir[i].dname)==0)
						{
							printf("Directory %s is deleted!",d);
							dcnt--;
							dir[i]=dir[i+1];
							goto jmp1;
						}
					}
					printf("Directory %s not found!",d);
					jmp1 : break;
			case 5: printf("\nEnter name of the directory:\t");
					scanf("%s",d);
					for(i=0;i<dcnt;i++)
					{
					
						if(strcmp(d,dir[i].dname)==0)
						{
							printf("Enter the name of the file:\t");
							scanf("%s",f);
							for(k=0;k<dir[i].fcnt;k++)
							{
								if(strcmp(f, dir[i].fname[k])==0)
								{
									printf("File %s Exists!",f);
									goto jmp2;
								}
							}
							printf("File %s Doesn't Exist!",f);
							goto jmp2;
						}
					}
					printf("Directory %s not found!",d);
					jmp2: break;
			case 6: if(dcnt==0)
					printf("\nEMPTY : Please add new Directories!");
					else
					{
							printf("\nDirectory \tFiles\n");
						for(i=0;i<dcnt;i++)
						{
							printf("\n%s\t",dir[i].dname);
							for(k=0;k<dir[i].fcnt;k++)
								printf("\t%s",dir[i].fname[k]);
						}
					}
					break;
			default:exit(0);
		}
	}
}
