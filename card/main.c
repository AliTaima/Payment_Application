#include <stdio.h>
#include <string.h>
#include "card.h"

int main()
{
    ST_cardData_t cardData;
    // checking card hoder name specifications
    if(getCardHolderName(&cardData) == WRONG_NAME)
        printf("error! Card holder name is 24 alphabetic characters string max and 20 min");
    else
    {
        // checking car expiry date specifications
        if(getCardExpiryDate(&cardData) == WRONG_EXP_DATE)
            printf("error! Card expiry date is 5 characters string in the format \"MM/YY\", e.g \"05/25\"");
        else
        {
            //checking car pan specifications
            if(getCardPAN(&cardData) == WRONG_PAN)
                printf("error! PAN is 20 numeric characters string, 19 character max, and 16 character min");

        }
    }
    printf("-----------------You entered these data---------------------\n");
    printf("%s\n", cardData.cardHolderName);
    printf("%s\n", cardData.cardExpirationDate);
    printf("%s\n", cardData.primaryAccountNumber);


    return 0;
}

EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
    printf("Enter the cardholder's name: ");
    gets(cardData->cardHolderName);
    if(strlen(cardData->cardHolderName) == 0 || strlen(cardData->cardHolderName) < 20 || strlen(cardData->cardHolderName) > 24)
        return WRONG_NAME;
    else
        return CARD_OK;

}
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
    printf("Enter the card expiry date (e.g 05/25): ");
    gets(cardData->cardExpirationDate);
    if(strlen(cardData->cardExpirationDate) == 0 || strlen(cardData->cardExpirationDate) < 5 || strlen(cardData->cardExpirationDate) > 5)
        return WRONG_EXP_DATE;
    else
        return CARD_OK;

}
EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
    printf("Enter the card's Primary Account Number: ");
    gets(cardData->primaryAccountNumber);
    if(strlen(cardData->primaryAccountNumber) == 0 || strlen(cardData->primaryAccountNumber) < 16 || strlen(cardData->primaryAccountNumber) > 19)
        return WRONG_PAN;
    else
        return CARD_OK;
}
