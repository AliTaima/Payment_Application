# Payment Application
---
This is the 1st project in the Embedded Systems - FWD T2 Professional track.
---
![payment-flowchart](https://user-images.githubusercontent.com/87614712/186474556-7efa05a9-1053-4070-8a02-de586c1c6826.jpeg)
## Project Requirements
---
- Development environment preparation
- Implement the card module
- Implement the terminal module
- Implement the server module
- Implement the application
- Testing the application

### Development environment preparation
---
- We should organize our project by creating new folder for each module in our project, .c and .h files for each module with header file guard for each .h file

  - This [README_file](https://github.com/AliTaima/Payment_Application/blob/main/Development_environment_preparation/README.md) contains screenshots for the folder structure, files in each folder and header file guard
### The card module
---
It's required to create these three functions to implement this module 
- EN_cardError_t getCardHolderName(ST_cardData_t *cardData)
- EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData)
- EN_cardError_t getCardPAN(ST_cardData_t *cardData)
  - This [README_file](https://github.com/AliTaima/Payment_Application/blob/main/Payment_Application/card/README.md) contains screenshot for card.h file and videos to explain each function
### The terminal module
---
It's required to create these five functions to implement this module 
- EN_terminalError_t getTransactionDate(ST_terminalData_t *termData)
- EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData)
- EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData)
- EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData)
- EN_terminalError_t setMaxAmount(ST_terminalData_t *termData)
  - This [README_file](https://github.com/AliTaima/Payment_Application/tree/main/Payment_Application/terminal) contains screenshot for termnal.h file and videos to explain each function
### The server module
---
It's required to create these four functions to implement this module
- EN_transState_t recieveTransactionData(ST_transaction_t* transData)
- EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_accountsDB_t* accountRefrence)
- EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence)
- EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_accountsDB_t* accountRefrence)
  - This [README_file](https://github.com/AliTaima/Payment_Application/tree/main/Payment_Application/Server) contains screenshot for server.h file,  server-side accounts' database array, server-side transactions' database and videos to explain each function
### The app module
---
It's required to create this function to implement this module
- void appStart(void)
  - This [README_file](https://github.com/AliTaima/Payment_Application/blob/main/Payment_Application/Application/README.md) contains screenshot for app.h file and videos to explain this function try required five test cases
---
This [Google_Drive](https://drive.google.com/drive/folders/1ScxEBqYrTMixtPx3kUz-g8_QdayxkaS3?usp=sharing) contains all videos we need in this project
---


