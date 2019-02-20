//welcome
//hellloooooo
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define N 3
#define M 3
struct restaurant
{
    char name[30];
    char add[100];
    struct food
    {
        char common[3][20];
        int common_price[3];
        char special[3][20];
        int special_price[3];
        char special_day[20];
        int special_day_price;
    } f;
};
struct order
{
    int order_time;	//takes time in 24 hour clock, ex- 1908
    char user_name[30];
    char user_phone[10];
    char add[100];
    char food_item[20];
    int qty;
    int del_time;	//same as del_time
};
struct restaurant a[N];
struct order b[M];
int k=0;
void sorting(char a[][20], int n)
{
    int i,j;
    char temp[20];
    for (j=0; j<n-1; j++)
    {
        for (i=j+1; i<n; i++)
        {
            if (strcmp(a[j], a[i]) > 0)
            {
                strcpy(temp, a[j]);
                strcpy(a[j], a[i]);
                strcpy(a[i], temp);
            }
        }
    }
}
void getSpecialItemListinSortedOrder()
{
    int i,j;
    char rest[20];
    scanf("%s",rest);
    for(i=0; i<N; i++)
    {
        if(strcmp(rest,a[i].name)==0)
        {
            sorting(a[i].f.special, 3);
            for(j=0; j<3; j++)
            {
                printf("%s\n",a[i].f.special[j][20]);
            }
        }
    }
}
void getAllSpecialItemListinSortedOrder()
{
    int i,n,j;
    char name[N][20];
    printf("Enter the number of restaurants you want in the list\n");
    scanf("%d",&n);
    printf("Enter the restaurants\n");
    for(i=0; i<n; i++)
    {
        scanf("%s",name[i]);
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<N; j++)
        {
            if(strcmp(name[i][20],a[j].name)==0)
            {
                sorting(a[i].f.special, 3);
                printf("%s\n",a[j].name);
                for(j=0; j<3; j++)
                {
                    printf("%s\n",a[i].f.special[j][20]);
                }
            }
        }
    }
}
void getItemListInAreaSortedOrder()
{
    char area[20];
    scanf("%s",area);
    int i,j;
    for(i=0; i<N; i++)
    {
        if(strcmp(area,a[i].add)==0)
        {
            sorting(a[i].f.common, 3);
            for(j=0; j<3; j++)
            {
                printf("%s\n",a[i].f.common[j][20]);
            }
        }
    }
}
void getItemListInSortedOrder()
{
    int i,j;
    char rest[20];
    scanf("%s",rest);
    for(i=0; i<N; i++)
    {
        if(strcmp(rest,a[i].name)==0)
        {
            sorting(a[i].f.common, 3);
            for(j=0; j<3; j++)
            {
                printf("%s\n",a[i].f.common[j][20]);
            }
        }
    }
}
void addRestaurant(int i)                   //adds restaurant using iniRestaurant() function
{
    iniRestaurant(i);
    printf("restaurant added");
}

void deleteRestaurant()                 //Deletes restaurant details
{
    int i,j;
    char n[30],ar[100];
    gets(n);
    gets(ar);
    for(i=0; i<N; i++)
    {
        if((strcmp(n,a[i].name)==0)&&(strcmp(ar,a[i].add)==0))
        {
            for(j=i; j<N-1; j++)
            {
                strcpy(a[j].name,a[j+1].name);
                strcpy(a[j].add,a[j+1].add);
                a[j].f=a[j+1].f;
            }
        }
    }
    printf("SUCCESS\n");
}
void iniRestaurant(int i)               //initialise the details of restaurant
{
    int j;
    printf("Enter the %d Restaurants\n",N);
    printf("Enter name of restaurant number %d\n",i);
    scanf("%s",a[i].name);
    printf("Enter address\n");
    scanf("%s",a[i].add);
    printf("Enter the 3 common food items\n");
    for(j=0; j<3; j++)
    {
        scanf("%s",a[i].f.common[j]);
    }
    printf("Enter the 3 common food prices\n");
    for(j=0; j<3; j++)
    {
        scanf("%d",&a[i].f.common_price[j]);
    }
    printf("Enter the 3 special items\n");
    for(j=0; j<3; j++)
    {
        scanf("%s",a[i].f.special[j]);
    }
    printf("Enter the 3 special items prices\n");
    for(j=0; j<3; j++)
    {
        scanf("%d",&a[i].f.special_price[j]);
    }
    printf("Enter special item of the day among special items\n");
    scanf("%s",a[i].f.special_day);
    printf("Enter the price\n");
    scanf("%d",&a[i].f.special_day_price);
}
int placeOrder(int i)
{
    //places order
    printf("Enter order time\n");
    scanf("%d",&b[i].order_time);
    printf("Enter customer name\n");
    scanf("%s",b[i].user_name);
    printf("Enter phone number\n");
    scanf("%s",b[i].user_phone);
    printf("Enter address\n");
    scanf("%s",b[i].add);
    printf("Enter food item\n");
    scanf("%s",b[i].food_item);
    printf("Enter quantity\n");
    scanf("%d",&b[i].qty);
    b[i].del_time=b[i].order_time+(rand()%100);
    return k;
}
int  trackOrder(int i)                  //tracks order gives time of delivery
{
    int k=b[i].del_time;
    if(k!=0)
    {
    }
    else
    {
        printf("This order has been completed\n");
        k=-1;
    }
    return k;
}
int closeOrder(int i)                       //closes order by assigning delivery time value 0
{
    b[i].del_time=0;
    return i;
}
int getTime(int i)
{
    return b[i].del_time; //gives back delivery time
}
int  getMinTime(int i)              //gives minimum time by subtracting 10 minutes from delivery time
{
    int j=b[i].del_time-10;
    return j;
}
void getItemAvailability()              //checks if item is available by running loops
{
    int i,j;
    char food[20];
    scanf("%s",food);
    printf("Item is available in following restaurants\n");
    for(i=0; i<N; i++)
    {
        for(j=0; j<3; j++)
        {
            if(strcmp(a[i].f.common[j],food)==0)
            {
                printf("%s has this item @ %d\n",a[i].name,a[i].f.common_price[j]);
            }
        }
        for(j=0; j<3; j++)
        {
            if(strcmp(a[i].f.special[j],food)==0)
            {
                printf("%s has this item @ %d\n",a[i].name,a[i].f.special_price[j]);
            }
        }
    }
}
void getRestaurantInArea()                  //runs loops and checks restaurants in an area
{
    int i;
    char area[100];
    scanf("%s",area);
    printf("List of Restaurants in area\n");
    for(i=0; i<N; i++)
    {
        if(strcmp(area,a[i].add)==0)
        {
            printf("%s\n",a[i].name);
        }
    }
}
void addItem()              //adds item replaces in reality cant add extra item
{
    int j,i;
    char rest[30],add[100];
    scanf("%s\n",rest);
    scanf("%s",add);
    for(j=0; j<N; j++)
    {
        if((strcmp(rest,a[j].name)==0)&&(strcmp(add,a[j].add)==0))
        {
            printf("Enter the item number\n");
            scanf("%d",&i);
            printf("Enter the name of new item\n");
            gets(a[j].f.common[i]);
            printf("Enter the price of new item\n");
            scanf("%d",&a[j].f.common_price[i]);
        }
    }
    printf("Item added\n");
}
void deleteItem()               //deletes item by assigning its price as 0
{
    int j,i;
    char rest[30],add[100],del[]="delete";
    scanf("%s\n",rest);
    scanf("%s",add);
    for(j=0; j<N; j++)
    {
        if((strcmp(rest,a[j].name)==0)&&(strcmp(add,a[j].add)==0))
        {
            printf("Enter the item number\n");
            scanf("%d",&i);
            strcpy(a[j].f.common[i],del);
            a[j].f.common_price[i]=0;
        }
    }
    printf("Item deleted\n");
}
void updateItem()               //same as addItem function but checks if item exists or not
{
    int j,i;
    char rest[30],add[100];
    scanf("%s",rest);
    scanf("%s",add);
    for(j=0; j<N; j++)
    {
        if((strcmp(rest,a[j].name)==0)&&(strcmp(add,a[j].add)==0))
        {
            printf("Enter the item number\n");
            scanf("%d",&i);
            if(a[j].f.common_price[i]!=0)
            {
                printf("Enter the name to update\n");
                scanf("%s",a[j].f.common[i]);
                printf("Enter the price to update\n");
                scanf("%d",&a[j].f.common_price[i]);
                printf("Item updated\n");
            }
            else
            {
                printf("Cant update, the item doesn't exist\n");
            }
        }
    }
    printf("Item updated\n");
}
void main()
{
    int flag=1,x,i,j,o;
    printf("Enter Restaurants details. Max Restaurants are 5.\n");
    for(i=0; i<N; i++)
    {
        iniRestaurant(i);
    }
    while(flag==1)
    {
        printf("Enter the choice :\n1. Add Restaurant\n2. Delete Restaurant\n3. Add Item\n4. Delete Item\n5. Update Item\n6. Get Restaurant in Area\n7. Get Time\n8. Get minimum time\n9. Get item  availability\n10. Place order\n11. Track order\n12. Close order\n13. Get item list sorted\n14. Get item list in area sorted\n15. Get special item list sorted\n16. Get all special item list sorted\n17. Get item of the day list sorted\n18. Get common item\n19. Get common special item\n20. Get all unique item\n21. Find order assignment\n22. Quit\n");
        scanf("%d",&x);
        switch (x)
        {
        case 1:
            printf("Enter restaurant number\n");
            scanf("%d",&i);
            addRestaurant(i);
            break;
        case 2:
            printf("Enter restaurant name and address to delete\n");
            deleteRestaurant();
            break;
        case 3:
            printf("Enter restaurant name and address\n");
            addItem();
            break;
        case 4:
            printf("Enter restaurant name and address\n");
            deleteItem();
            break;
        case 5:
            printf("Enter restaurant name and address\n");
            updateItem();
            break;
        case 6:
            printf("Enter the address\n");
            getRestaurantInArea();
            break;
        case 7:
            printf("Enter the order ID");
            scanf("%d",&i);
            printf("At %d the order will reach",getTime(i));
            break;
        case 8:
            printf("Enter the order ID");
            scanf("%d",&i);
            printf("At %d the order will reach",getMinTime(i));
            break;
        case 9:
            printf("Enter the name of food item\n");
            getItemAvailability();
            break;
        case 10:
            printf("How many orders? Max orders are 3");
            scanf("%d",&o);
            for(i=0; i<o; i++)
            {
                printf("ID=%d\n Order is placed\n",placeOrder(i));
            }
            break;
        case 11:
            printf("Enter order ID\n");
            scanf("%d",&o);
            printf("Order will reach at %d",trackOrder(o));
            break;
        case 12:
            printf("Enter order ID\n");
            scanf("%d",&o);
            printf("Order number %d is done",closeOrder(o));
            break;
        case 13:
            printf("Enter the restaurant name\n");
            getItemListInSortedOrder();
            break;
        case 14:
            printf("Enter the restaurant area\n");
            getItemListInAreaSortedOrder();
            break;
        case 15:
            printf("Enter the restaurant name\n");
            getSpecialItemListinSortedOrder();
            break;
        case 16:
            getAllSpecialItemListinSortedOrder();
            break;
       /* case 17:
            printf("Enter the restaurant area\n");
            getItemofDayListinSortedOrder();
            break;
        case 18:
            getCommonItem();                                //Yet to be written
            break;
        case 19:
            getCommonSpecialItem();
            break;
        case 20:
            getAllUniqueItem();
            break;
        case 21:
            FindOrderAssignment();
            break;
        case 22:
            flag=0;
            break; */
        default:
            printf("No option matched\n");
        }
    }
}

