# Payment_Application
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
It's required to create three functions to implement this module 
- EN_cardError_t getCardHolderName(ST_cardData_t *cardData)
- EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData)
- EN_cardError_t getCardPAN(ST_cardData_t *cardData)
  - This [README_file](https://github.com/AliTaima/Payment_Application/blob/main/Payment_Application/card/README.md) contains screenshot for card.h file and video to explain each function




