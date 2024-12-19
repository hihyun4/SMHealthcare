//
//  main.c
//  Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define EXERCISEFILEPATH "exercises.txt"
#define DIETFILEPATH "diets.txt"
#define HEALTHFILEPATH "health_data.txt"

static int choice;

int main() {
	// To initialize the health data object
    HealthData health_data = {0};
    
    // Tocode: to read the list of the exercises and diets
    loadExercises(EXERCISEFILEPATH);
    loadDiets(DIETFILEPATH);
    
    int remaining_calories; ////남은 칼로리 변수 선언
    

    // ToCode: to run the "Healthcare Management Systems" until all calories are used up or the user wants to exit the system
    do {
    	
    	remaining_calories = (health_data.total_calories_intake) - BASAL_METABOLIC_RATE - (health_data.total_calories_burned); //남은 칼로리 계산 
    	if (remaining_calories == 0){
            printf("You have consumed all your calories for today!\n");
            break; 
		} 
		else{
			printf("\n=======================================================================\n");
        	printf("[Healthcare Management Systems] \n");
        	printf("1. Exercise \n");
        	printf("2. Diet \n");
        	printf("3. Show logged information \n");
        	printf("4. Exit \n");
        	printf("Select the desired number: ");
        	scanf("%d", &choice);
        	printf("=======================================================================\n");
        }
        
		// ToCode: to run the sysmtem based on the user's choice
        switch (choice) {
            case 1:
            	//운동
				inputExercise(&health_data);
                break;
                
            case 2:
            	//식단
				inputDiet(&health_data); 
                break;
                
            case 3:
            	//기록된 거 출력
				printHealthData(&health_data);
                break;
                
            case 4:
            	//저장 후 종료
				saveData(HEALTHFILEPATH, &health_data);
    			printf("Exit the system.\n");
    			printf("=======================================================================\n");
                break;
                
            default:
                printf("[Error] Invalid option. \n");
                printf("Please try again! \n");
        }
    } while (choice != 4);

    return 0;
}

