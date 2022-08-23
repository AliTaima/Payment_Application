#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\card\card.h"           //---------------delete this -----
#include "terminal.h"
//int main()
//{
//    ST_terminalData_t termData;
//    ST_cardData_t cardData;         //---------------delete this  -----
//
//
//    if(getTransactionDate(&termData) == WRONG_DATE)
//        printf("error! Transaction date is 10 characters string in the format DD/MM/YYYY, e.g 25/06/2022\n");
//    else
//    {   // checking card expiry date specifications
//        if(getCardExpiryDate(&cardData) == WRONG_EXP_DATE)                      //--------------- delete this ---------------
//            printf("error! Card expiry date is 5 characters string in the format \"MM/YY\", e.g \"05/25\"");    //--------------- delete this ----------
//        else
//        {
//            if (isCardExpired(&cardData, &termData) == EXPIRED_CARD)
//                printf("error! Expired card");
//            else
//            {
//                if (setMaxAmount(&termData) == INVALID_MAX_AMOUNT)
//                    printf("error! Invalide max amount");
//                else
//                {
//                    if(getTransactionAmount(& termData) == INVALID_AMOUNT)
//                        printf("error! Invalid amount");
//                    else
//                    {
//                        if (isBelowMaxAmount(&termData) == EXCEED_MAX_AMOUNT)
//                            printf("Exceed max amount");
//                    }
//                    
//                    
//                }
//            }
//        }
//        
//
//    }
//
//    printf("-----------------You entered these data---------------------\n");
//    printf("The transaction date = %s\n", termData.transactionDate);
//    printf("The card expiration = %s\n", cardData.cardExpirationDate);
//    printf("The transaction amount = %.1f\n", termData.transAmount);
//    printf("The max transaction amount = %.1f\n", termData.maxTransAmount);
//
//
//    return 0;
//}
EN_terminalError_t getTransactionDate(ST_terminalData_t *termData)
{
    printf("Enter the transaction date: ");
    gets(termData->transactionDate);
    if(strlen(termData->transactionDate) < 10 || strlen(termData->transactionDate) > 10 || termData->transactionDate[2] != '/' || termData->transactionDate[5] != '/')
        return WRONG_DATE;
    else
        return TERMINAL_OK;
}
EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData)
{
    //cardExpirationDate -->MM/YY, transactionDate--> DD/MM/YYYY
    //comparing the 1st and 2nd digits of the year number, for example 2025 --> comparing 25 
    if ((int)cardData->cardExpirationDate[3] < (int)termData->transactionDate[8] || (int)cardData->cardExpirationDate[4] < (int)termData->transactionDate[9])
        return EXPIRED_CARD;

    //comparing the month
    else if((int)cardData->cardExpirationDate[0] < (int)termData->transactionDate[3] || (int)cardData->cardExpirationDate[1] < (int)termData->transactionDate[4])
        return EXPIRED_CARD;
    else
        return TERMINAL_OK;
}
EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
    printf("Enter the transaction amount: ");
    scanf_s("%f", &(termData->transAmount));

    if (termData->transAmount <= 0)
        return INVALID_AMOUNT;
    else
        return TERMINAL_OK;
}
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
    if (termData->transAmount < termData->maxTransAmount)
        return EXCEED_MAX_AMOUNT;
    else
        return TERMINAL_OK;

}
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData)
{
    printf("Enter the maximum transaction amount: ");
    scanf_s("%f", &(termData->maxTransAmount));
    if (termData->maxTransAmount <= 0)
        return INVALID_MAX_AMOUNT;
    else
        return TERMINAL_OK;
}