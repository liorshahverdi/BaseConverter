#include <string.h>
int main ()
{
char inbase = '0';
char bout;
int num;
int cont = 1;
char response;
char bin[32];

while (cont != 0)
   {	
	if (inbase != '0') scanf("%c", &inbase);
	printf("\nBase of input integer: Enter b for binary, d for decimal, h for hexadecimal or o for octal: ");
	scanf("%c", &inbase);
	
	if (inbase == 'b')
	{
		scanf("%c", &bout);
		printf("\nEnter the base of the output (b, d, h or o): "); 
		scanf("%c", &bout);
		
		printf("\nEnter the number: ");
		scanf("%s", bin);

		if (bout == 'b') printf("\nThe integer %s in binary is %s in binary.", bin, bin);
		else if (bout == 'd') 
		{	
			if ((bin[0] == '1') || (bin[0] == '0'))
			{
				/*binary to decimal*/
				int base = 2;
				int prod = base;
				int power = strlen(bin) - 1;
				int i = 0;    	/* lcv for binary number string */
				int temp = 0;
				int sum = 0;
				while (bin[i] != '\0')
				{	
					if (bin[i] == '1')
					{
						if (power > 1)
						{
							int j= 0;
							prod = base;
							for (j=0;j<(power-1);j++)
							{
								temp = 2 * prod;
								prod = temp;
							}	
						}
						else if (power == 1)	temp = 2;
						else if (power == 0)	temp = 1;
					}
					power--;
					sum = sum + temp;
					temp = 0;
					i++;
				}
				printf("\nThe integer %s in binary is %d in decimal.", bin, sum);
			}
		}
		else if (bout == 'h')
		{
			if ((bin[0] == '1') || (bin[0] == '0'))
			{
				int power = 3;
				int origlen = strlen(bin);
				int numhxdig = (origlen / 4) + 1;
				int leftover = origlen % 4;
				int numzeros;
				if (leftover == 0)	numzeros = 0;
				else	numzeros = 4 - leftover;
				int s = numzeros + origlen;
				char bindec[s+1];
				bindec[s] = '\0';
				int hexnum[numhxdig];
				int i = 0;
				
				while (i<numzeros)
				{
					bindec[i] = '0';
					i++;
				}
				int k = 0;
				while (i<s)
				{
					bindec[i] = bin[k];
					k++;
					i++;
				}
				i = 0;
				int nextpo = power;
				int count = 0;
				int temp = 0;
				int sum = 0;
				while (i<s)
				{
					power = nextpo;
					if (bindec[i] == '1')
					{	
						if (power == 3) temp = 8;
						else if (power == 2) temp = 4;
						else if (power == 1) temp = 2;
						else if (power == 0) temp = 1; 
						sum = sum + temp;
					}
					temp = 0;
					nextpo--;
					if (power == 0)
					{
						nextpo = 3;
						hexnum[count] = sum;
						sum = 0;
						count++;
					}
					i++;
				}
				i = 0;
				printf("\nThe integer %s in binary is ", bin);
				while (i<count)
				{
					printf("%x", hexnum[i]);
					i++;
				}
				printf(" in hexadecimal.");
			}
			}
		else if (bout == 'o')
		{
			if ((bin[0] == '1') || (bin[0] == '0'))
			{
				int power = 2;
				int origlen = strlen(bin);
				int numocdig = (origlen / 3) + 1;
				int leftover = origlen % 3;
				int numzeros;
				if (leftover == 0)	numzeros = 0;
				else	numzeros = 3 - leftover;
				int s = numzeros + origlen;
				char bindec[s+1];
				bindec[s] = '\0';
				int octnum[numocdig];
				int i = 0;
				
				while (i<numzeros)
				{
					bindec[i] = '0';
					i++;
				}
				int k = 0;
				while (i<s)
				{
					bindec[i] = bin[k];
					k++;
					i++;
				}
				i = 0;
				int nextpo = power;
				int count = 0;
				int temp = 0;
				int sum = 0;
				while (i<s)
				{
					power = nextpo;
					if (bindec[i] == '1')
					{	
						if (power == 2) temp = 4;
						else if (power == 1) temp = 2;
						else if (power == 0) temp = 1; 
						sum = sum + temp;
					}
					temp = 0;
					nextpo--;
					if (power == 0)
					{
						nextpo = 2;
						octnum[count] = sum;
						sum = 0;
						count++;
					}
					i++;
				}
				i = 0;
				printf("\nThe integer %s in binary is ", bin);
				while (i<count)
				{
					printf("%o", octnum[i]);
					i++;
				}
				printf(" in octal.");
			}		
		}
	}
	else if (inbase == 'd')
	{
		scanf("%c", &bout);
		printf("\nEnter the base of the output (d, h or o): ");
		scanf("%c", &bout);

		printf("\nEnter the number: ");
        scanf("%d", &num);

		if (bout == 'd') printf("\nThe integer %d in decimal is %d in decimal.", num, num);
		else if (bout == 'h') printf("\nThe integer %d in decimal is %x in hexadecimal.", num, num);
		else if (bout == 'o') printf("\nThe integer %d in decimal is %o in octal.", num, num);
	}	
	else if (inbase == 'h')
	{
		scanf("%c", &bout);
        printf("\nEnter the base of the output (d, h or o): ");
        scanf("%c", &bout);

		printf("\nEnter the number: ");
		scanf("%x", &num);

		if (bout == 'd') printf("\nThe integer %x in hexadecimal is %d in decimal.", num, num);
		else if (bout == 'h') printf("\nThe integer %x in hexadecimal is %x in hexadecimal.", num, num);
		else if (bout == 'o') printf("\nThe integer %x in hexadecimal is %o in octal.", num, num); 
	}
	else if (inbase == 'o')
	{
		scanf("%c", &bout);
		printf("\nEnter the base of the output (d, h or o): ");
		scanf("%c", &bout);
		 
		printf("\nEnter the number: ");
		scanf("%o", &num);

		if (bout == 'd') printf("\nThe integer %o in octal is %d in decimal.", num, num);
		else if (bout == 'h') printf("\nThe integer %o in octal is %x in hexadecimal.", num, num);
		else if (bout == 'o') printf("\nThe integer %o in octal is %o in octal.", num, num);  
	}
	
	scanf("%c", &response);
	printf("\nDo you wish to do another? (y or n lowercase): ");
	scanf("%c", &response);
	if (response == 'y') cont = 1;
	else if (response == 'n') cont = 0; 
   }

return 0;
}
