#include <stdio.h>
#include <string.h>
#include "card.h"
EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	printf("Enter the cardholder's name: ");
	fgets(cardData->primaryAccountNumber, 24, stdin);

}

int main()
{
	ST_cardData_t cardData;
	getCardHolderName(&cardData);
	return 0;
}