#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 2
typedef struct NODE
{
	int reg_no;
	int age;
	char name[20];
	struct NODE *next;
} node;
node* deq();
int create();
int reserve(node*);
int cancel(int);
void enq(node*);
void display();


node *start;
node *front;
node *rear;
int count=0;
int num=0;


int create( )
{
	node *new;
	new=(node *)malloc(sizeof(node));
	new->reg_no=1;
	printf("Name: ");
	scanf("%s", new->name);
	printf("Age : ");
	scanf("%d", &new->age);
    if(new->age>=90 || new->age<=10) {
        free(new);
        return -1;
    }
	start=new;
	new->next=NULL;
	num++;
    return 1;
}
int reserve(node *start)
{
	int temp;
	if(start==NULL)
	{
   		temp = create(start);
		return temp;
	}
	else
	{

	node *temp, *new_node;
	temp=start;
	while(temp->next!=NULL)
	{
	  temp=temp->next;
	}

	new_node=(node *)malloc(sizeof(node));

	printf("Name: ");
	scanf("%s", new_node->name);
	printf("Age: ");
	scanf("%d", &new_node->age);
    if(new_node->age >=90 || new_node->age<=10) {
        return -1;
    }
	new_node->next=NULL;
	if(num<=size)
	{
		num++;
		new_node->reg_no=num;
		temp->next=new_node;

		return 1;
	}
	else
	{
		enq(new_node);
		return 0;
	}
}
}


int cancel(int reg)
{
	node *ptr, *preptr, *new;
	ptr=start;
	preptr=NULL;
	if(start==NULL)
	return -1;
	if(ptr->next==NULL && ptr->reg_no==reg)
		{
		start=NULL;
		num--;
		free(ptr);
		return 1;

		}

	else{
	while(ptr->reg_no!=reg && ptr->next!=NULL)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		if(ptr==NULL && ptr->reg_no!=reg)
			return -1;
		else
			preptr->next=ptr->next;
		free(ptr);
		new=deq();
		while(preptr->next!=NULL)
			preptr=preptr->next;
		preptr->next=new;
		num--;
		return 1;

	}
}

void enq(node *new_node)
{
	if(rear==NULL)
	{
		rear=new_node;
		rear->next=NULL;
		front=rear;
	}
	else
	{
		node *temp;
		temp=new_node;
		rear->next=temp;
		temp->next=NULL;
		rear=temp;
	}
	count++;
}

node* deq()
{
	node *front1;
	front1=front;
	if(front==NULL)
		return NULL;
	else
	{
	    count-- ;
		if(front->next!=NULL)
		{
			front=front->next;
			front1->next=NULL;
			return front1;
		}
		else
		{
			front=NULL;
			rear=NULL;
			return front1;
		}
	}
}

void display()
{
	node *temp;
	temp=start;
	while(temp!=NULL)
	{
		printf("\nRegistration Number: %d\n", temp->reg_no);
		printf("Name : %s\n\n", temp->name);
		temp=temp->next;
    }
}

void file(char cf)
{
	if(cf == 'y' || cf == 'Y')
				{
					printf("Thank you\n");
				}
				else if(cf == 'n' || cf == 'N')
				{
					FILE *fp;
					char feed[500];
					fp = fopen("feedback.txt", "w");
					printf("Please tell how can we improve\nTo stop press ctrl + Z\n");
					while((scanf("%s", feed)) != EOF)
					{
						fprintf(fp, "%s", feed);
					}
					fclose(fp);
				}
				printf("Thanks for your valuable feedback\n");
				exit(0);
}

int main()
{
  char station[52][20], cf;
  int train[52][100];
  char choice[20];
  int i,j,k;
  char opt[10];

    strcpy(station[0],"chennai_beach");
    strcpy(station[1],"chennai_central_railway_station");
    strcpy(station[2],"anna_nagar");
    strcpy(station[3],"royapuram");
    strcpy(station[4],"basin_bridge");
    strcpy(station[5],"washermanpet");
    strcpy(station[6],"chennai_fort");
    strcpy(station[7],"chennai_park");
    strcpy(station[8],"chennai_egmore");
    strcpy(station[9],"korukkupet");
    strcpy(station[10],"tondiarpet");
    strcpy(station[11],"tiruvottiyur");
    strcpy(station[12],"adambakkam");
    strcpy(station[13],"kathivakkam");
    strcpy(station[14],"santragachi");
    strcpy(station[15],"ennore");
    strcpy(station[16],"athipattu_pudhunagar");
    strcpy(station[17],"athipattu");
    strcpy(station[18],"nandiambakkam");
    strcpy(station[19],"minjur");
    strcpy(station[20],"puzhuthivakkam");
    strcpy(station[21],"perambur");
    strcpy(station[22],"kotturpuram");
    strcpy(station[23],"kasturba_nagar");
    strcpy(station[24],"villivakkam");
    strcpy(station[25],"korattur");
    strcpy(station[26],"pattaravakkam");
    strcpy(station[27],"ambattur");
    strcpy(station[28],"thirumullaivoyal");
    strcpy(station[29],"annanur");
    strcpy(station[30],"velachery");
    strcpy(station[31],"pattabiram");
    strcpy(station[32],"nemilichery");
    strcpy(station[33],"thirunindravur");
    strcpy(station[34],"chetput");
    strcpy(station[35],"nungambakkam");
    strcpy(station[36],"kodambakkam");
    strcpy(station[37],"mambalam");
    strcpy(station[38],"padi");
    strcpy(station[39],"guindy");
    strcpy(station[40],"pazhavanthangal");
    strcpy(station[41],"meenambakkam");
    strcpy(station[42],"tirusulam");
    strcpy(station[43],"pallavaram");
    strcpy(station[44],"chromepet");
    strcpy(station[45],"tambaram");
    strcpy(station[46],"perungalathur");
    strcpy(station[47],"vandalur");
    strcpy(station[48],"chintadripet");
    strcpy(station[49],"chepauk");
    strcpy(station[50],"thiruvallikeni");
    strcpy(station[51],"mandaveli");
    strcpy(station[52],"kotturpuram");

    train[0][0]=1200;
    train[0][1]=-1;
    train[1][0]=1201;
    train[1][1]=1301;
    train[1][2]=1401;
    train[1][3]=1501;
    train[1][4]=1601;
    train[1][5]=1701;
    train[1][6]=1801;
    train[1][7]=1901;
    train[1][8]=2001;
    train[1][9]=2101;
    train[1][10]=2201;
    train[1][11]=2301;
    train[1][12]=2401;
    train[1][13]=2501;
    train[1][14]=2601;
    train[1][15]=2701;
    train[1][16]=2801;
    train[1][17]=2901;
    train[1][18]=3001;
    train[1][19]=3101;
    train[1][20]=3201;
    train[1][21]=3301;
    train[1][22]=3401;
    train[1][23]=3501;
    train[1][24]=3601;
    train[1][25]=-1;
    train[2][0]=1202;
    train[2][1]=-1;
    train[3][0]=1203;
    train[3][1]=1303;
    train[3][2]=-1;
    train[4][0]=1204;
    train[4][1]=1304;
    train[4][2]=-1;
    train[5][0]=1205;
    train[5][1]=1305;
    train[5][2]=1405;
    train[5][3]=1505;
    train[5][4]=1605;
    train[5][5]=1705;
    train[5][6]=1805;
    train[5][7]=-1;
    train[6][0]=1206;
    train[6][1]=1306;
    train[6][2]=1406;
    train[6][3]=1506;
    train[6][4]=-1;
    train[7][0]=1207;
    train[7][1]=1307;
    train[7][2]=1407;
    train[7][3]=-1;
    train[8][0]=1208;
    train[8][1]=1308;
    train[8][2]=1408;
    train[8][3]=1508;
    train[8][4]=1608;
    train[8][5]=1708;
    train[8][6]=1808;
    train[8][7]=-1;
    train[9][0]=1209;
    train[9][1]=1309;
    train[9][2]=1409;
    train[9][3]=1509;
    train[9][4]=1609;
    train[9][5]=1709;
    train[9][6]=-1;
    train[10][0]=1210;
    train[10][1]=-1;
    train[11][0]=1211;
    train[11][1]=1311;
    train[11][2]=-1;
    train[12][0]=1212;
    train[12][1]=1312;
    train[12][2]=-1;
    train[13][0]=1213;
    train[13][1]=1313;
    train[13][2]=1413;
    train[13][3]=1513;
    train[13][4]=1613;
    train[13][5]=1713;
    train[13][6]=-1;
    train[14][0]=1214;
    train[14][1]=1314;
    train[14][2]=1414;
    train[14][3]=1514;
    train[14][4]=1614;
    train[14][5]=1714;
    train[14][6]=-1;
    train[15][0]=1215;
    train[15][1]=-1;
    train[16][0]=1216;
    train[16][1]=1316;
    train[16][2]=-1;
    train[17][0]=1217;
    train[17][1]=-1;
    train[18][0]=1218;
    train[18][1]=-1;
    train[19][0]=1219;
    train[19][1]=1319;
    train[19][2]=-1;
    train[20][0]=1220;
    train[20][1]=-1;
    train[21][0]=1221;
    train[21][1]=1321;
    train[21][2]=1421;
    train[21][3]=-1;
    train[22][0]=1222;
    train[22][1]=-1;
    train[23][0]=1223;
    train[23][1]=-1;
    train[24][0]=1224;
    train[24][1]=1324;
    train[24][2]=1424;
    train[24][3]=-1;
    train[25][0]=1225;
    train[25][1]=-1;
    train[26][0]=1226;
    train[26][1]=-1;
    train[27][0]=1227;
    train[27][1]=1327;
    train[27][2]=1328;
    train[27][3]=-1;
    train[28][0]=1228;
    train[28][1]=1328;
    train[28][2]=-1;
    train[29][0]=1229;
    train[29][1]=-1;
    train[30][0]=1330;
    train[30][1]=1430;
    train[30][2]=-1;
    train[31][0]=1231;
    train[31][1]=-1;
    train[32][0]=1232;
    train[32][1]=-1;
    train[33][0]=1233;
    train[33][1]=-1;
    train[34][0]=1234;
    train[34][1]=-1;
    train[35][0]=1235;
    train[35][1]=1335;
    train[35][2]=-1;
    train[36][0]=1236;
    train[36][1]=1336;
    train[36][2]=-1;
    train[37][0]=1237;
    train[37][1]=-1;
    train[38][0]=1238;
    train[38][1]=-1;
    train[39][0]=1239;
    train[39][1]=-1;
    train[40][0]=1240;
    train[40][1]=-1;
    train[41][0]=1241;
    train[41][1]=-1;
    train[42][0]=1242;
    train[42][1]=1342;
    train[42][2]=1442;
    train[42][3]=-1;
    train[43][0]=1243;
    train[43][1]=1343;
    train[43][2]=-1;
    train[44][0]=1244;
    train[44][1]=-1;
    train[45][0]=1245;
    train[45][1]=-1;
    train[46][0]=1246;
    train[46][1]=-1;
    train[47][0]=1247;
    train[47][1]=-1;
    train[48][0]=1248;
    train[48][1]=-1;
    train[49][0]=1249;
    train[49][1]=1349;
    train[49][2]=-1;
    train[50][0]=1250;
    train[50][1]=-1;
    train[51][0]=1251;
    train[51][1]=-1;
    retry:
      printf("*********Local Train Reservation*********\n**************From Potheri**************\n\nThe program will show the train number of all the trains going from Potheri to another local station in Chennai\nStation Name entered must be in lowercase letters\nIn case of spaces please use ''_'' (underscore)\n");
      printf("Enter station to travel to:\n");
    scanf("%s",choice);
    printf("These train number  will go to the %s station\n",choice);
    for(i=0;i<52;i++){
        if(strcmp(station[i],choice)==0)
             {
               break;
             }
    }
       if(strcmp(station[i],choice)!=0)
            {
               printf("No trains available\n");
               goto retry;
            }
    for(j=0;train[i][j]!=-1;j++)
     {
       k=train[i][j];
       if((k/10000)!=0)
         printf("%d\n",train[i][j]);
       else
         printf("%d%d\n",0,train[i][j]);
      }
     printf("Do you wish to search for another city?(yes/no)\n");
     scanf("%s",opt);
     if(strcmp(opt,"yes")==0)
        goto retry;
     else
    printf("Thank you");
    int choose, status=0,canc=0, reg=0;
	start=NULL;
	rear=NULL;
	front=NULL;
	printf("\t\t\t*RAILWAY RESERVATION*\t\t\t\t\n");
	int ch =0;
	while(ch!=4)
	{
	printf("\n\nDo you want to - \n 1. Book a ticket \n 2. Cancel Booking \n 3. Display passenger details \n 4.Provide feedback\n 5. exit\n\n");
	scanf("%d", &choose);
	switch(choose)
	{
		case 1 :  status=reserve(start);
	              if(status==0)
	                printf("\nBooking Full!! \nYou are added to waiting list. Waiting list number %d", count);
	              else if(status == -1) {
                      printf("\n age not eligible");
                  }
                  else
	                printf(" \nBooking Successful!!! Enjoy your journey! Your Reg No is %d\n\n", num);
	              break;
	    case 2:   printf(" \n Give the Registration Number to be cancelled\n");
	              scanf(" %d", &reg);
	              if(reg>num)
	              printf("Invalid!!");
	              else
	              {
	              canc=cancel(reg);
	              if(canc==-1)
	              	printf("\nRegistration Number Invalid!!\n");
	              else
	              	printf("\nRegistration cancelled successfully\n");
	              	}
	              break;
	    case 3: display();
	    break;
	    case 4:
				printf("Enter Y for positive feedback\nEnter N for negative feedback\n");
				scanf(" %c", &cf);
				file(cf);
				    		break;
	    case 5: exit(0);
	    break;
	    default: printf("\nWrong choice!\n");
  }


	}
return 0;
}
