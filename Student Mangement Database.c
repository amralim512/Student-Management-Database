/*Student Mangemnet Database
 * Author: Amr Adel
 * */

#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int id;
	char name[50];
	int age;
	float gpa;
} student;

struct node{
	student data;
	struct node* next;
};
struct node* head=NULL;

void addstudent(const student*constptr){
	struct node* current=NULL;
	struct node*linker= (struct node*)malloc(sizeof(struct node));
	linker->data= *constptr;
	linker->next=NULL;
	if(head==NULL)
	{
		head = linker;
		return;
	}
	current = head;
	if(constptr->id==current->data.id){
		printf("Student already exist\n");
		return;
	}
	while(current->next != NULL)
	{
		current = current->next;
	}
	current->next = linker;
}

void displaystudents(void){

	struct node *temp = head;
	if (head==NULL){
		printf("Our database is empty now -_- \n\n");
	}
	while(temp != NULL)
	{
		printf("******************************* \n");
		printf(" ID:%d \t",temp->data.id);
		printf(" Name:%s \t",temp->data.name);
		printf(" Age:%d \t",temp->data.age);
		printf(" GPA:%.2f \t\n",temp->data.gpa);
		printf("******************************* \n");
		temp = temp->next;
	}
}

void searchbyid(int ID){
	struct node*current=NULL;
	if(head==NULL) printf("Database is Empty -_-\n");
	current=head;
	while(current!=NULL){
		if(current->data.id==ID){
			printf("ID is available :D\n");
			printf("Student details:[ID: %d , Name: %s , Age: %d ,GPA: %.2f] \n\n",current->data.id,current->data.name,current->data.age,current->data.gpa);
			return;
		}
		current=current->next;
	}
	printf("ID Not found in our database :'(\n ");

}

void updateinfo(int ID){
	struct node*exist=NULL;
	if(head==NULL) printf("Database is Empty -_-\n");
	exist=head;
	while(exist!=NULL){
		if(exist->data.id==ID){
			printf("Let's Update info for ID:%d\n",ID);
			printf("New Name:");
			scanf("%s",exist->data.name);
			printf("New Age:");
			scanf("%d",&exist->data.age);
			printf("New GPA:");
			scanf("%f",&exist->data.gpa);
			printf("Information updated Successfully :D\n");
			return;
		}
		exist=exist->next;
	}
	printf("ID Not found in our database :'(\n ");
	return;
}
void deletestudent(int id){
	struct node*current=NULL;
	struct node* dele=NULL;
	struct node* prev=NULL;
	if(head==NULL) {printf("Database is Empty -_-\n");return;}
	if (head->data.id==id){
		dele=head;
		printf("ID data Deleted\n");
		free(dele);
		head=head->next;
		return;
	}
	current=head->next;
	prev=head;
	while(current!=NULL){
		if(current->data.id==id){
			dele=current;
			free(dele);
			prev->next=current->next;
			printf("ID data Deleted\n");
			return;
		}
		prev=current;
		current=current->next;
	}
}
float avggpa(void){
	struct node* current=NULL;
	if(head==NULL) {printf("Database is empty\n"); return 0.0;}
	float avg=0.0;
	int size=0;
	current=head;
	while(current!=NULL){
		avg+= current->data.gpa;
		size++;
		current=current->next;
	}
	return avg/size;
}

void highgpa(void){
	struct node* current=NULL;
	struct node* best;
	if(head==NULL) {printf("Database is empty\n"); return;}
	current=head;
	best=head;
	while(current!=NULL){
		if(current->data.gpa>best->data.gpa){

			current->data=best->data;
		}
		current=current->next;

	}
	printf("Highest GPA Student details:[ID: %d , Name: %s , Age: %d ,GPA: %.2f] \n\n",best->data.id,best->data.name,best->data.age,best->data.gpa);



	return;
}

int main(void){
	setvbuf(stdout, NULL,_IONBF,0 );
	setvbuf(stderr, NULL,_IONBF,0);
	int in;
	printf("Welcome To Students Database :) \n\n");
	printf("Please choose from the following option by the number : \n\n");
	printf("1:Add Student\n");
	printf("******************************* \n");
	printf("2:Display all students\n");
	printf("******************************* \n");
	printf("3:Search Student by ID\n");
	printf("******************************* \n");
	printf("4:Update Student Info\n");
	printf("******************************* \n");
	printf("5:Delete Student\n");
	printf("******************************* \n");
	printf("6:Calculate Average GPA\n");
	printf("******************************* \n");
	printf("7:Find Highest GPA Student\n");
	printf("******************************* \n");
	printf("8:Exit\n");
	scanf(" %d", &in);

	switch(in){
	case 1:
		student adder;
		printf("Enter Student Details:\n");
		printf("ID:\n");
		scanf("%d",&adder.id);
		printf("Name:\n");
		scanf("%s",adder.name);
		printf("Age:\n");
		scanf("%d",&adder.age);
		printf("GPA:\n");
		scanf("%f",&adder.gpa);
		addstudent(&adder);
		return main();
		break;
	case 2:
		displaystudents();
		return main();
		break;
	case 3:
		printf("Lets's Find your inquiry:\n");
		printf("Enter The Id you're looking for:\n");
		int INQ;
		scanf(" %d", &INQ);
		searchbyid(INQ);
		return main();
		break;
	case 4:
		printf("Let's update needed information\n");
		printf("Enter Student ID:\n");
		int upd;
		scanf(" %d",&upd);
		updateinfo(upd);
		return main();
		break;
	case 5:
		printf("Enter ID to delete it's Data from the database:\n");
		printf("ID:");
		int del;
		scanf("%d",&del);
		deletestudent(del);
		return main();
		break;
	case 6:
		printf("Average GPA=%0.2f\n",avggpa());
		return main();
		break;
	case 7:
		highgpa();
		return main();
		break;
	case 8:
		break;
	default:printf("Enter a valid Choice :(\n");
	break;
	}
	return 0;
}
