//
//  cal_healthdata.c
//  Diets for Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h" 

/*
    description : enter the exercise and diet history in "health_data.txt" 
    input parameters : health_data - data object in which the selected exercise and diet is stored
    return value : No
    
    operation : 1. save the chosen exercise and total calories burned
    			2. save the chosen diet and total calories intake 
    			3. save the total remaining calrories
*/


//전역 변수로 남은 칼로리 변수 선언. 
int remaining_calories;


void saveData(const char* HEALTHFILEPATH, const HealthData* health_data) {
	int i;
    FILE* file = fopen(HEALTHFILEPATH, "w");
    if (file == NULL) {
        printf("There is no file for health data.\n");
        return;
    }

    // ToCode: to save the chosen exercise and total calories burned 
    fprintf(file, "[Exercises] \n");
    //운동 기록 저장 
    for(i=0; i<health_data->exercise_count; i++)
    	fprintf(file, "%s - %d kcal\n", health_data->exercises[i].exercise_name, health_data->exercises[i].calories_burned_per_minute);
    //총 운동 칼로리 소모량
	fprintf(file, "Total calories burned: %d kcal\n", health_data->total_calories_burned); 
    
    // ToCode: to save the chosen diet and total calories intake 
    
    fprintf(file, "\n[Diets] \n");
    //식단 기록 저장 
    for(i=0; i< health_data->diet_count; i++)
    	fprintf(file, "%s - %d kcal\n", health_data->diet[i].food_name, health_data->diet[i].calories_intake); 
	
	//총 식단 칼로리 소비량 
	fprintf(file, "Total calories intake: %d kcal\n", health_data->total_calories_intake);  
	
    // ToCode: to save the total remaining calrories
    fprintf(file, "\n[Total] \n");
    
    //총 칼로리 정보 저장 
	remaining_calories = (health_data->total_calories_intake) - BASAL_METABOLIC_RATE - (health_data->total_calories_burned);
    
    fprintf(file, "Basal metabolic rate - %d kcal\n", BASAL_METABOLIC_RATE);
    fprintf(file, "The remaining calories - %d kcal\n", remaining_calories);
    
    fclose(file);
}

/*
    description : print the history of exercised and diets
    input parameters : health_data - data object in which the history of the exercise and diet is to be printed
    return value : No
    
    operation : 1. print out the saved history of exercises
    			2. print out the saved history of diets
    			3. print out the saved history of calories
*/

void printHealthData(const HealthData* health_data) {
	int i;
	
	// ToCode: to print out the saved history of exercises
	printf("=========================== History of Exercise =======================\n");
	//Exercise: 운동 이름, Calories burned : 칼로리 kcal 
	for(i=0; i< health_data->exercise_count; i++)
		printf("Exercise: %s, Calories burned : %d kcal\n", health_data->exercises[i].exercise_name, health_data->exercises[i].calories_burned_per_minute );
  
    printf("=======================================================================\n");

    // ToCode: to print out the saved history of diets
    printf("============================= History of Diet =========================\n");
    for(i=0; i < health_data->diet_count; i++)
    	printf("Food: %s, Calories intake: %d kcal\n", health_data->diet[i].food_name, health_data->diet[i].calories_intake);
    	
    	
    printf("=======================================================================\n");


	// ToCode: to print out the saved history of calories including basal metabolic rate, 
	// total calories burned, total calories intake, and the remaining calories
	printf("============================== Total Calories =========================\n");
	printf("Basal Metabolic Rate: %d kcal\n", BASAL_METABOLIC_RATE);
	printf("Total calories burned: %d kcal\n", health_data->total_calories_burned);
	printf("Total calories intake: %d kcal\n", health_data->total_calories_intake);
	
	remaining_calories = (health_data->total_calories_intake) - BASAL_METABOLIC_RATE - (health_data->total_calories_burned);
	printf("The remaining calories: %d kcal\n", remaining_calories);
 
    printf("=======================================================================\n \n");
    
	
	// ToCode: to print out the recommendtaion depending on the current total calories burned and intake    
    
    if(remaining_calories == 0) //남은 칼로리가 0인 경우 
    {
     	printf("You have consumed all your calories for today!\n"); 
     	//시스템 종료
	}
    else if(remaining_calories<0) //남은 칼로리가 <0인 경우 
    {
    	printf("[Warning] Too few calories!\n");
    	
		if (health_data->total_calories_intake >= DAILY_CALORIE_GOAL) //섭취 칼로리가 일일 권장 칼로리에 도달한 경우 
			printf("Your total calorie intake for today has reached your goal!\n");
		else //섭취 칼로리가 일일 권장 칼로리보다 적은 경우 
			printf("Your total calorie intake for today has not reached your goal, remember to eat more!!\n");
		
		////섭취 칼로리가 일일 권장 칼로리보다 많은 경우
		if (health_data->total_calories_intake > DAILY_CALORIE_GOAL) 	////섭취 칼로리가 일일 권장 칼로리보다 많은 경우
			printf("You have eaten more calories than planned today, but have exercised too much!\n");
		
	}
	else//남은 칼로리가 >0인 경우 
	{
		printf("Please exercise for your health!\n");
		if(health_data->total_calories_intake >= DAILY_CALORIE_GOAL) //섭취 칼로리가 일일 권장 칼로리에 도달한 경우 
			printf("Your total calorie intake for today has reached your goal!\n");
		else //섭취 칼로리가 일일 권장 칼로리보다 적은 경우 (= 섭취 칼로리가 일일 권잘 칼로리에 도달하지 못했을 경우)
			printf("Your total calorie intake for today has not reached your goal, remember to eat more!!\n");
	}
    
	 printf("=======================================================================\n");
}
