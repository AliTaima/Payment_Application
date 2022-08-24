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
//	//test cases
//	/*
//		// Printing Successful process
//		8989374615436851
//		1000
//		// printing error! Declined insuffecient fund(transactio amount > balance)
//		8989374615436851
//		3000
//		// Printing error! Declined stolen card(BLOCKED)
//		6317671354844040
//		2000
//		//Printing error! Fraud card (account not found in database)
//		8989374615436850
//		1000
//	*/
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
	/*
		This function will take all transaction data and validate its data.
		It checks the account details and amount availability.
		If the account does not exist return FRAUD_CARD, 
		if the amount is not available will return DECLINED_INSUFFECIENT_FUND, 
		if the account is blocked will return DECLINED_STOLEN_CARD, 
		else returns APPROVED.
	*/
	ST_accountsDB_t accountRefrence;

	if (isValidAccount(&transData->cardHolderData, &accountRefrence) == ACCOUNT_NOT_FOUND)
		return FRAUD_CARD;
	else
	{
		
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
	/*
		This function will take card data and validate if the account related to this card exists or not.
		It checks if the PAN exists or not in the server's database (searches for the card PAN in the DB).
		If the PAN doesn't exist will return ACCOUNT_NOT_FOUND, 
		else will return SERVER_OK and return a reference to this account in the DB.
	*/
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
	/*
		This function will take a reference to an existing account in the database.
		It checks if the account is blocked or not.
		If the account is blocked, will return BLOCKED_ACCOUNT, else will return SERVER_OK.
	*/
	 
	if (accountRefrence->state == BLOCKED)
		return BLOCKED_ACCOUNT;
	else
		return SERVER_OK;
		
}
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_accountsDB_t* accountRefrence)
{
	/*
		This function will take terminal data and validate these data.
		It checks if the transaction's amount is available or not.
		If the transaction amount is greater than the balance in the database will return LOW_BALANCE, else will return SERVER_OK
	*/
	// in this function I add additional pointer of ST_accountsDB_t* accountRefrence to use its data in the comparison tha I make
	if (termData->transAmount > accountRefrence->balance)
		return LOW_BALANCE;
	else
		return SERVER_OK;
}