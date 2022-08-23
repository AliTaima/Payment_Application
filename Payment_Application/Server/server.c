#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\card\card.h"           
#include "..\terminal\terminal.h"	
#include "server.h"
// define thee number of acounts I make in the database
#define database_num 10
//the valid accounts database
ST_accountsDB_t database[255] = {	2000.0, RUNNING, "8989374615436851",
									3000.0, BLOCKED, "6317671354844040",
									4000.0, RUNNING, "7302230192665200",
									5000.0, BLOCKED, "7499520760027320",
									6000.0, RUNNING, "6994230236969710",
									7000.0, BLOCKED, "6430918395350910",
									8000.0, RUNNING, "8593572954922380",
									9000.0, BLOCKED, "6797043202807190",
									10000.0, RUNNING, "6173128629492300",
									11000.0, BLOCKED, "5807007076043875"
};
// intialize global array of ST_transaction_t with zeros
ST_transaction_t transaction_data[255] = { 0, 0, 0, 0 };

//int main()
//{
//	ST_terminalData_t termData;
//	ST_cardData_t cardData;
//	ST_transaction_t transData;
//	
//	// Getting card pan 
//    if(getCardPAN(&cardData) == WRONG_PAN)
//        printf("error! PAN is 20 numeric characters string, 19 character max, and 16 character min");
//	else
//	{	// Getting transaction amount
//		if (getTransactionAmount(&termData) == INVALID_AMOUNT)
//			printf("error! Invalid amount");
//		else
//		{	
//			//printf("The transaction amount from getTransactionAmount function = %f\n", termData.transAmount);
//			
//			// Assigning card and terminal data to the trasdata
//			transData.cardHolderData = cardData;
//			transData.terminalData = termData;
//			if (recieveTransactionData(&transData) == FRAUD_CARD)
//				printf("error! Fraud card");
//			else
//			{
//				if (recieveTransactionData(&transData) == DECLINED_STOLEN_CARD)
//					printf("error! Declined stolen card");
//				else
//				{
//					if (recieveTransactionData(&transData) == DECLINED_INSUFFECIENT_FUND)
//						printf("error! Declined insuffecient fund");
//					else
//					{
//						if (recieveTransactionData(&transData) == APPROVED)
//							printf("-----------------Successful process-----------------");
//					}
//				}
//			}
//		}
//	}
//
//	return 0;
//}
EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{
	ST_accountsDB_t accountRefrence;

	if (isValidAccount(&transData->cardHolderData, &accountRefrence) == ACCOUNT_NOT_FOUND)
		return FRAUD_CARD;
	else
	{
		/*printf("The balance of this account = %f\n", accountRefrence.balance);
		printf("The account number = %s\n", accountRefrence.primaryAccountNumber);*/
		if (isBlockedAccount(&accountRefrence) == BLOCKED_ACCOUNT)
			return DECLINED_STOLEN_CARD;
		else
		{
			if (isAmountAvailable(&transData->terminalData, &accountRefrence) == LOW_BALANCE)
				return DECLINED_INSUFFECIENT_FUND;
			else
			{	
				// I will call the serverTransaction function here after implement it
				return APPROVED;
			}
		}
	}
}
EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_accountsDB_t* accountRefrence)
{
	int a;
	for (a = 0; a < database_num; a++)
	{
		/* strcmp function return 0 if the two strings are identical so I put not before it to be true only 
		 if the return value of strcmp is 0*/
		if (!strcmp(database[a].primaryAccountNumber, cardData->primaryAccountNumber))
		{
			// assigning the data of account to account reference pointer
			*accountRefrence = database[a];
			return SERVER_OK;
		}
	}
	return ACCOUNT_NOT_FOUND;
}
EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence)
{
	 
	if (accountRefrence->state == BLOCKED)
		return BLOCKED_ACCOUNT;
	else
		return SERVER_OK;
		
}
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_accountsDB_t* accountRefrence)
{
	// in this function I add additional pointer of ST_accountsDB_t* accountRefrence to use its data in the comparison tha I make
	if (termData->transAmount > accountRefrence->balance)
		return LOW_BALANCE;
	else
		return SERVER_OK;
}