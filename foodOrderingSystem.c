#include <stdio.h>
#include <string.h>
#include <conio.h>

struct order
{
    char name[100];
    int order_number;
    int number_of_food;
    int cost;
} p[100];
int order_count = 0, served_count = 0, waiting_now = 0, cost_count=0;

int order ()
{
    int n, in, qu;
    printf ("Please enter your name: ");
    gets (p[order_count].name);
    p[order_count].order_number = 1+order_count;
    items();
    p[order_count].number_of_food = n;
    p[order_count].cost = 0;
    p[order_count].number_of_food = 0;

level:
    printf ("Number of items to be ordered: ");
    scanf ("%d", &n);
    getchar ();
    while (n--)
    {
        printf ("\nEnter chosen item code: ");
        scanf ("%d", &in);
        getchar();
        switch(in)
        {
        case 1 :
        {
            printf ("Choose from the option:\n1. BBQ Beef\n2. BBQ Chicken\n3. Naga Spicy\n");
            int i;
            printf ("-> ");
            scanf ("%d", &i);
            getchar();
            printf ("Please enter the quantity: ");
            scanf ("%d", &qu);
            getchar();
            p[order_count].number_of_food +=qu;

            if (i==1) p[order_count].cost += (190*qu);
            else if (i==2)p[order_count].cost += (160*qu);
            else  p[order_count].cost += (180*qu);
            break;
        }

        case 2 :
        {
            printf ("Choose from the option:\n1. 12 inch \n2. 14inch\n");
            int i;
            printf ("-> ");
            scanf ("%d", &i);
            getchar();
            printf ("Please enter the quantity: ");
            scanf ("%d", &qu);
            getchar();
            p[order_count].number_of_food +=qu;

            if (i==1) p[order_count].cost += (700*qu);
            else p[order_count].cost += (900*qu);
            break;
        }

        case 3 :
        {
            printf ("Choose from the option:\n1. Quarter\n2. Half\n3. Full\n");
            int i;
            printf ("-> ");
            scanf ("%d", &i);
            getchar();
            printf ("Please enter the quantity: ");
            scanf ("%d", &qu);
            getchar();

            p[order_count].number_of_food +=qu;

            if (i==1) p[order_count].cost += (80*qu);
            else if (i==2)p[order_count].cost += (160*qu);
            else p[order_count].cost += (300*qu);
            break;
        }

        case 4 :
        {
            printf ("Choose from the option:\n1. Regular\n2. BBQ\n");
            int i;
            printf ("-> ");
            scanf ("%d", &i);
            getchar();
            printf ("Please enter the quantity:-> ");
            scanf ("%d", &qu);
            getchar();
            p[order_count].number_of_food +=qu;

            if (i==1) p[order_count].cost += (150*qu);
            else p[order_count].cost += (180*qu);
            break;
        }

        case 5 :
        {
            printf ("Choose from the option:\n1. Mutton\n2. Chicken\n");
            int i;
            printf ("-> ");
            scanf ("%d", &i);
            getchar();

            printf ("Please enter the quantity:-> ");
            scanf ("%d", &qu);
            getchar();
            p[order_count].number_of_food +=qu;

            if (i==1) p[order_count].cost += (220*qu);
            else p[order_count].cost += (170*qu);
            break;
        }

        case 6 :
        {
            printf ("Choose from the option:\n1. Normal\n2. Cold\n3. Special Cappucino\n");
            int i;
            printf ("-> ");
            scanf ("%d", &i);
            getchar();
            printf ("Please enter the quantity:-> ");
            scanf ("%d", &qu);
            getchar();
            p[order_count].number_of_food +=qu;

            if (i==1)p[order_count].cost += (50*qu);
            else if (i==2)p[order_count].cost += (80*qu);
            else p[order_count].cost += (150*qu);
            break;
        }

        case 7 :
        {
            printf ("Choose from the option:\n1. Coca Cola\n2. Sprite\n3. Mountain Dew\n");
            int i;
            printf ("-> ");
            scanf ("%d", &i);
            getchar();
            printf ("Please enter the quantity:-> ");
            scanf ("%d", &qu);
            getchar();
            p[order_count].number_of_food +=qu;

            if (i==1) p[order_count].cost += (25*qu);
            else if (i==1) p[order_count].cost += (25*qu);
            else p[order_count].cost += (30*qu);
            break;
        }
        default :
        {
            printf ("\t*Invalid selection try again*\n");
            n++;
        }
        }
    }
    char temp;
    printf ("Do you want to order anything more? -> 'Y' for Yes and 'N' for No. (Y/N)\n ");
    printf ("-> ");
    scanf("%c", &temp);
    if (temp == 'y' || temp == 'Y')
        goto level;
    printf ("\n\tNumber of food ordered %d.\n", p[order_count].number_of_food);
    printf ("\tThank you %s for your order.\n\tYour bill= %d BDT.\n\n", p[order_count].name, p[order_count].cost);
    order_count ++;
}
int receive ()
{
    if (order_count==0)
    {
        printf ("Please Order First!\n");
        return;
    }

    else if (served_count == order_count)
    {
        printf ("All order served!\n");
        return;
    }
    printf ("\tOrder no: %d by %s is ready.\n", p[served_count].order_number, p[served_count].name);
    printf ("\tEnjoy your meal!\n\n");
    served_count++;
}
int display ()
{
    printf ("\t\tTotal order taken:            %d\n", (order_count));
    printf ("\t\tTotal number of order served: %d\n", served_count);
}
void items ()
{
    printf("========================================MENU==================================\n");
    printf("Item Code    Food Item                   Varieties                            Price(BDT)\n");

    printf("   [1]         Burger             BBQ Chicken/Beef/Naga Spicy                 190/160/180\n");
    printf("   [2]      Chicken Pizza              12 inch/14 inch                            700/900\n");
    printf("   [3]     Grilled Chicken          Quarter/Half/Full                          80/160/300\n");
    printf("   [4]         Nachos                   Regular/BBQ                               150/180\n");
    printf("   [5]         Biryani                 Mutton/Chicken                             220/170\n");
    printf("   [6]        Coffee             Normal/Cold/Special Cappuccino                 50/80/150\n");
    printf("   [7]      Soft Drinks          Coca Cola/Sprite/Mountain Dew                   25/25/30\n\n");

}
int main ()
{

    printf("                                 ==============================================================================\n");
    printf("                                                     WELCOME TO OUR FOOD ORDERING SYSTEM\n");
    printf("                                 ==============================================================================\n\n\n");
    while (1)
    {
        printf ("1. Order\n2. Serve\n3. Display\n4. Exit the program\n\n");
        int in;
        printf ("Enter Your Choice: ");
        scanf ("%d", &in);
        printf("\n");
        getchar ();

        switch (in)
        {
        case 1 :
        {
            order ();
            break;
        }
        case 2 :
        {
            receive();
            break;
        }
        case 3 :
        {
            display();
            break;
        }
        case 4 :
        {
            system("COLOR 3");
            printf("\n========*THANK YOU*=======\n\n");
            printf("\n========*Come Again*======\n\n");
            printf("\n========Credits=========\n\n\n");
            printf("\n   Hafiz Al Fahim 202-15-3781\n");
            return 0;
        }
        }
    }
}
