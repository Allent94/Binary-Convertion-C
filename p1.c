#include<stdio.h>
#include<math.h>

//Allen Tran
//Aman Daddy
//TCSS 333
//10-08-2017
//Program that thats takes the user IP address and converts it into dot decimal nations by using bitwise
//operators

unsigned int iPtoDecimal(int, int, int, int);
void decimalToBinary(unsigned int);
double maskToDecimal(int);
void decimalToDotDecimal(unsigned int);
double networkPrefix(unsigned int, unsigned int);
double hostId(unsigned int, unsigned int);

//added

unsigned int num1, num2, num3, num4, num5, num6, num7, num8, conversion, y, mask, stop;
unsigned int decimal1, decimal2, decimal3, decimal4;
int findTheLastOne(unsigned int n);

//main fuction that takes the user input and calulates using the smaller fuctions below

int main() {

    printf("\n");

    char anwser;

    int choice = 0;
    int int1 = 0, int2 = 0, int3 = 0, int4 = 0, mask = 0;

    do {

    while(choice != 1 && choice != 2 && choice != 3){

    printf("What type of conversion do you want?\n");
    printf("Enter \n1 for IP-address and subnet, \n2 for the host and network prefix, \n3 for 32-bit decimal number for IP and subnet");
    scanf("%d", &choice);

    }

    if(choice == 1) {

        printf("Enter the message address: ");
        scanf("%d.%d.%d.%d/%d", &int1, &int2, &int3, &int4, &mask);
        do {
            if((int1 < 0 || int2 < 0 || int3 < 0 || int4 < 0) && (int1 > 255 || int2 > 255 ||
                int3 > 255 || int4 > 255 || mask < 0 || mask > 32)) {
	        printf("Wrong address, try again: ");
                scanf("%d.%d.%d.%d/%d", &int1, &int2, &int3, &int4, &mask);
	    }

        } while(int1 < 0 || int2 < 0 || int3 < 0 || int4 < 0 || int1 > 255 || int2 > 255 ||
               int3 > 255 || int4 > 255 || mask < 0 || mask > 32);

    unsigned int  number = iPtoDecimal(int1, int2, int3, int4);
    printf("The IP-address is %u in decimal and\n", number); //Step 1
    decimalToBinary(number);
    printf("in binary\n\n");
    double maskValue = maskToDecimal(mask); //
    printf("The subnet mask is %.0lf in decimal and\n", maskValue);
    maskValue = (unsigned int) maskValue; //
    decimalToBinary(maskValue);
    printf(" in binary\n");
    printf("The subnet mask in dot-decimal is: ");
    decimalToDotDecimal(maskValue);
    double prefixValue = networkPrefix(number, maskValue); //step
    printf("\n\nThe network prefix is: %.0lf ", prefixValue);
    printf("in decimal and\n");
    decimalToBinary(prefixValue); //Step
    printf(" in binary\n");
    printf("The network prefix in dot-decimal is "); // Last Step
    decimalToDotDecimal(prefixValue);
    double host = hostId(number, maskValue);
    printf("\n\n The host id is: %.0lf in decimal and\n", host);
    decimalToBinary(host);
    printf(" in binary\n");
    printf("The host in dot-decimal is ");
    decimalToDotDecimal(host);
    printf("\n\nEnter r to repeat, q to quit");


    }else if(choice == 2){

        printf("Enter the host: ");
        scanf("%d.%d.%d.%d", &num1, &num2, &num3, &num4);
        printf("\n");

        printf("Enter the network prefix: " );
        scanf("%d.%d.%d.%d", &num5, &num6, &num7, &num8);
        printf("\n");

        do {
            if((num1 != 0 || num2 != 0 || num3 != 0 || num4 == 0 || num1 > 0 || num2 > 0 ||
                num3 > 0 || num4 > 256) 
                & (num5 == 0 || num6 == 0 || num7 == 0 || num8 != 0 ||
                num5 > 256 || num6 > 256 || num7 > 256 || num8 > 0)) {
            printf("Wrong host, try again: ");
            scanf("%d.%d.%d.%d", &num1, &num2, &num3, &num4);
            printf("Wrong network prefix, try again : ");
        }

        } while(num1 != 0 || num2 != 0 || num3 != 0 || num4 == 0 || num1 > 0 || num2 > 0 ||
               num3 > 0 || num4 > 256);

        scanf("hello");

        decimal1 = (num1*pow(256, 3)) + (num2*pow(256, 2)) + (num3*256) + num4;
        decimal2 = (num5*pow(256, 3)) + (num6*pow(256, 2)) + (num7*256) + num8;
        decimal3 = (num5*pow(256, 3)) + (num6*pow(256, 2)) + (num7*256) + num4;

        printf("The message is: %d.%d.%d.%d/%u\n" , num5, num6, num7, num4, findTheLastOne(decimal2));
        printf("\n");

        printf("Enter r to repeat, q to quit: \n");


    }else if(choice == 3){


        printf("Enter the 32-bit of IP: \n");
        scanf("%u" , &num1);
        printf("\n");

        printf("Enter the 32-bit of Subnet: \n");
        scanf("%u" , &num2);
        printf("\n");

        do{
            if( (num1 <= 0 || num1 > 4294967295 || num2 <= 0 || num2 > 4294967295)){
                printf("Wrong 32-bit IP decimal number. try again: ");
                scanf("%u", &num1);

                printf("Wrong 32-bit Subnet number. try again: ");
                scanf("%u", &num2);
            }
        } while ((num1 <= 0 || num1 > 4294967295 || num2 <= 0 || num2 > 4294967295));

        printf("\n");
        printf("Decimal is:  \n");
        decimalToDotDecimal(num1);
        printf("/%u\n" , findTheLastOne(num2));
        printf("\n");

        printf("\n");
        printf("Bianry is: \n");
        decimalToBinary(num1);
        printf("\n");

        printf("Enter r to repeat, q to quit: \n");


    }

        scanf(" %c" , &anwser);

}

while(anwser =='r');

    return 0;

}

//This method converts the IP into decimal number.

unsigned int iPtoDecimal(int int1, int int2, int int3, int int4) {
    unsigned int result = 0 ;
    unsigned int value = 256;
    result += int1 * pow(value, 3) + int2 * pow(value, 2) +
              int3 * pow(value, 1) + int4 * pow(value, 0);
    return result;
}

//This method takes the decimal number and converts it into binary.

void decimalToBinary(unsigned int number) {
    int i, x;
    for(i = 31; i >= 0; i--) {
        x = number >> i;
        if(x & 1) {
            printf("1");
        } else {
	    printf("0");
	}
	if(!(i % 8)) {
	   putchar(' ');
	}
    }
}

//This method takes the mask number and converts it into a decimal.

double maskToDecimal(int mask) {
double i;
double total;
double count = mask;
for(i = 31; i >= 0; i--) {
    if(count > 0) {
        total = total + pow(2, i);
        count--;
    }
}
return total;
}

//This method takes decimal number and converts it into a dot decimal.

void decimalToDotDecimal(unsigned int number) {
int i = 0, x = 0, total = 0, count = 0;
for(i = 31; i >= 0; i--) {
    x = number >> i;
    if(x & 1) {
        total = total + pow(2,(i % 8));
    }
    if(count++ == 7) {
        if(i < 7) {
            printf("%u", total);
	} else {
             printf("%u.", total);
	     total = 0;
	     count = 0;
        }
    }
}
}

//This method

double networkPrefix(unsigned int1, unsigned int2) {
double result = int1 & int2;
return result;
}

//This method

double hostId(unsigned int1, unsigned int2) {
double result = int1 & (~int2);
return result;
}

// This method finds the last one in the network prefix which will locate the subnet mask.
// When we are going through the 32 bit binary with i and when 1 is found then we count = i.

int findTheLastOne(unsigned int n){

    unsigned int x = n;
    unsigned int mask = 1 << 31;
    unsigned int count = 0;

    for(int i = 0; i <= 32; i++){

            if (x & mask){

                count = i+1;

            }

            x <<= 1;

        }

        return count;

}