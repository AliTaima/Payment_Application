#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\card\card.h"           
#include "..\terminal\terminal.h"	
#include "..\Server\server.h"
#include "app.h"

int main()
{
	printf("------------Welcome to the Payment application--------------\n");
	appStart();

	return 0;
}

void appStart(void)
{
	//Declaring card, terminal and transaction data 
	ST_cardData_t cardData;
	ST_terminalData_t termData;
	ST_transaction_t transData;
	char module = 10;
	// -----------------------------------Card module -----------------------------------------------
	if (getCardHolderName(&cardData) == WRONG_NAME)
		printf("error! Card holder name is 24 alphabetic characters string max and 20 min\n");
	else
	{
		// checking car expiry date specifications
		if (getCardExpiryDate(&cardData) == WRONG_EXP_DATE)
			printf("error! Card expiry date is 5 characters string in the format MM/YY, e.g 05/25 \n");
		else
		{
			//checking card pan specifications
			if (getCardPAN(&cardData) == WRONG_PAN)
				printf("error! PAN is 20 numeric characters string, 19 character max, and 16 character min\n");
			else
				module = FINISH_CARD;
		}
	}
	//---------------------------------Terminal module--------------------------------------------------
	// checking card module finish successfully or not
	if (module == FINISH_CARD)
	{
		// getting transaction date
		if (getTransactionDate(&termData) == WRONG_DATE)
			printf("error! Transaction date is 10 characters string in the format DD/MM/YYYY, e.g 25/06/2022\n");
		else
		{
			// checking if the card is expired or not
			if (isCardExpired(&cardData, &termData) == EXPIRED_CARD)
				printf("error! Expired card\n");
			else
			{   // getting max amount
				if (setMaxAmount(&termData) == INVALID_MAX_AMOUNT)
					printf("error! Invalide max amount\n");
				else
				{   // getting the transaction amount 
					if (getTransactionAmount(&termData) == INVALID_AMOUNT)
						printf("error! Invalid amount\n");
					else
					{   // checking if the transaction that entered is less that max amount or not
						if (isBelowMaxAmount(&termData) == EXCEED_MAX_AMOUNT)
							printf("error! Exceed max amount\n");
						else
							module = FINISH_TERMINAL;
					}
				}
			}
		}
	}
	//--------------------------------------------Server Module--------------------------------------------------
	// checking terminal module finish successfully or not
	if (module == FINISH_TERMINAL)
	{
		// Assigning card and terminal data to the trasdata
		transData.cardHolderData = cardData;
		transData.terminalData = termData;

		if (recieveTransactionData(&transData) == FRAUD_CARD)
			printf("error! Fraud card\n");
		else
		{
			if (recieveTransactionData(&transData) == DECLINED_STOLEN_CARD)
				printf("error! Declined stolen card\n");
			else
			{
				if (recieveTransactionData(&transData) == DECLINED_INSUFFECIENT_FUND)
					printf("error! Declined insuffecient fund\n");
				else
				{
					if (recieveTransactionData(&transData) == APPROVED)
						printf("-----------------Successfull process-----------------\n");
				}
			}
		}
	}
}
