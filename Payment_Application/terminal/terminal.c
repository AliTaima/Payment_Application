#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\card\card.h"           
#include "terminal.h"
//int main()
//{
//    //test cases
//    /*
//        //success test case
//        0/25
//        12/10/2022
//        5000
//        3000
//        //wrong test case date
//        12/22
//        12/10/2025
//        //wrong test case transaction amount 
//        15/25
//        12/10/2022
//        3000
//        5000
//    */
//                      
//    ST_terminalData_t termData;
//    ST_cardData_t cardData;         
//    // getting card expiry date 
//    if(getCardExpiryDate(&cardData) == WRONG_EXP_DATE)                      
//        printf("error! Card expiry date is 5 characters string in the format \"MM/YY\", e.g \"05/25\"\n");    
//    else
//    {
//        // getting transaction date
//        if(getTransactionDate(&termData) == WRONG_DATE)
//            printf("error! Transaction date is 10 characters string in the format DD/MM/YYYY, e.g 25/06/2022\n");
//        else
//        {   // checking if the card is expired or not
//            if (isCardExpired(&cardData, &termData) == EXPIRED_CARD)
//                printf("error! Expired card\n");
//            else
//            {   // getting max amount
//                if (setMaxAmount(&termData) == INVALID_MAX_AMOUNT)
//                    printf("error! Invalide max amount\n");
//                else
//                {   // getting the transaction amount 
//                    if(getTransactionAmount(& termData) == INVALID_AMOUNT)
//                        printf("error! Invalid amount\n");
//                    else
//                    {   // checking if the transaction that entered is less that max amount or not
//                        if (isBelowMaxAmount(&termData) == EXCEED_MAX_AMOUNT)
//                            printf("error! Exceed max amount\n");
//                    }
//                }
//            }
//        }
//        
//
//    }
//
//    printf("-----------------You entered these data---------------------\n");
//    printf("The card expiry date = %s\n", cardData.cardExpirationDate);
//    printf("The transaction date = %s\n", termData.transactionDate);
//    printf("The max transaction amount = %.1f\n", termData.maxTransAmount);
//    printf("The transaction amount = %.1f\n", termData.transAmount);
//
//
//    return 0;
//}
EN_terminalError_t getTransactionDate(ST_terminalData_t *termData)
{
    /*
        This function will ask for the transaction data and store it in terminal data.
        Transaction date is 10 characters string in the format DD/MM/YYYY, e.g 25/06/2022.
        If the transaction date is NULL, less than 10 characters or wrong format will return WRONG_DATE error, else return TERMINAL_OK.
    */
    printf("Enter the transaction date int this forrmate DD/MM/YYYY: ");
    gets(termData->transactionDate);
    if(strlen(termData->transactionDate) < 10 || strlen(termData->transactionDate) > 10)
        return WRONG_DATE;
    else
        return TERMINAL_OK;
}
EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData)
{
    /*
        This function compares the card expiry date with the transaction date.
        If the card expiration date is before the transaction date will return EXPIRED_CARD, else return TERMINAL_OK.
    */

    //cardExpirationDate -->MM/YY, transactionDate--> DD/MM/YYYY
    
    //comparing the 1st  digit of the year number, for example 2025, 17 --> comparing 1, 2
    if ((int)cardData->cardExpirationDate[3] < (int)termData->transactionDate[8])
        return EXPIRED_CARD;
    //comparing the 1st and 2nd digits of the year number, for example 2025, 23 --> comparing 25 
    else if ((int)cardData->cardExpirationDate[3] == (int)termData->transactionDate[8] && (int)cardData->cardExpirationDate[4] < (int)termData->transactionDate[9])
        return EXPIRED_CARD;
    // comparing month in case of years are equals, for example 12/2025, 07/25 -->  25 == 25
    else if ((int)cardData->cardExpirationDate[3] == (int)termData->transactionDate[8] && (int)cardData->cardExpirationDate[4] == (int)termData->transactionDate[9])
    {
        // checking 1st digit in month, in previous example comparing 12, 07 --> 0<1
        if ((int)cardData->cardExpirationDate[0] < (int)termData->transactionDate[3])
            return EXPIRED_CARD;
        // checking 2nd digit in case of digits 1 are equals, 12,11 --> 1<2
        else if((int)cardData->cardExpirationDate[0] == (int)termData->transactionDate[3] && (int)cardData->cardExpirationDate[1] < (int)termData->transactionDate[4])
            return EXPIRED_CARD;
        // checking if two digits are equal, 
        else if ((int)cardData->cardExpirationDate[0] == (int)termData->transactionDate[3] && (int)cardData->cardExpirationDate[1] == (int)termData->transactionDate[4])
            return EXPIRED_CARD;
    }
    // if previsous condistions not satisfied, so there is no prolbem 
    else
        return TERMINAL_OK;
}

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData)
{
    /*
        This function sets the maximum allowed amount into terminal data.
        Transaction max amount is a float number.
        If transaction max amount less than or equal to 0 will return INVALID_MAX_AMOUNT error, else return TERMINAL_OK.
    */
    printf("Enter the maximum transaction amount: ");
    scanf_s("%f", &(termData->maxTransAmount));
    if (termData->maxTransAmount <= 0)
        return INVALID_MAX_AMOUNT;
    else
        return TERMINAL_OK;
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
    /*
        This function asks for the transaction amount and saves it into terminal data.
        If the transaction amount is less than or equal to 0 will return INVALID_AMOUNT, else return OK.
        You should deliver a maximum 2min video to discuss your implementation and run different test cases 
        on this function
    */
    printf("Enter the transaction amount: ");
    scanf_s("%f", &(termData->transAmount));

    if (termData->transAmount <= 0)
        return INVALID_AMOUNT;
    else
        return TERMINAL_OK;
}
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
    /*
        This function compares the transaction amount with the terminal max amount.
        If the transaction amount is larger than the terminal max amount will return EXCEED_MAX_AMOUNT,
        else return TERMINAL_OK.
    */
    if (termData->transAmount > termData->maxTransAmount)
        return EXCEED_MAX_AMOUNT;
    else
        return TERMINAL_OK;

}