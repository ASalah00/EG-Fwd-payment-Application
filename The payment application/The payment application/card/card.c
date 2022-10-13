#include "card.h"
#include <stdio.h>
#include <string.h>

EN_cardError_t getCardHolderName(ST_cardData_t* cardData) {
	printf("Please enter your card holder name:\n");
	gets(cardData->cardHolderName);
	
	if (strlen(cardData->cardHolderName) > 24 || strlen(cardData->cardHolderName) < 20 || cardData->cardHolderName == NULL)
		return WRONG_NAME;
	return CARD_OK;

}
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData) {
	printf("Please enter your card expiry date:MM/YY\n");
	gets(cardData->cardExpirationDate);
	//after modification
	//getting month as a whole number
	uint8_t monthFirstDigit = cardData->cardExpirationDate[0] - '0';
	uint8_t monthSecondDigit = cardData->cardExpirationDate[1] - '0';
	uint8_t monthNumber = monthFirstDigit * 10 + monthSecondDigit;
	
	//checking if the month number is between 1 and 12 inclusive
	//what we want is (monthNumber >= 1 && monthNumber <= 12)
	 
	if (strlen(cardData->cardExpirationDate) > 5 ||cardData->cardExpirationDate[2]!='/' || cardData->cardExpirationDate == NULL
		||!(monthNumber >= 1 && monthNumber <= 12))
		return WRONG_EXP_DATE;
	return CARD_OK;

}
EN_cardError_t getCardPAN(ST_cardData_t* cardData) {
	printf("Please enter your Primary Account Number\n");
	gets(cardData->primaryAccountNumber);
	
	if (strlen(cardData->primaryAccountNumber) > 19 || strlen(cardData->primaryAccountNumber) < 16 || cardData->primaryAccountNumber == NULL)
		return WRONG_PAN;
	return CARD_OK;
}