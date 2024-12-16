//
//  cal_diets.c
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

#define MAX_DIETS 100      			// Maximum number of diets
#define MAX_FOOD_NAME_LEN 50		// Maximum length of the name of food

//loadDiets, inputDiet 함수 

//MAX_EXERCISES 100 / 최대 운동 횟수
//MAX_EXERCISE_NAME_LEN 50 / 운동 이름 길이
//MAX_DIETS 100 / 최대 다이어트 횟수
//MAX_FOOD_NAME_LEN 50 / 음식 이름 길이
//DAILY_CALORIE_GOAL 2000 / 성인 여성 일일 권장 칼로리 섭취량
//BASAL_METABOLIC_RATE 1300 / 성인 여성 기초대사량

//EXERCISEFILEPATH "exercises.txt"
//DIETFILEPATH "diets.txt"
//HEALTHFILEPATH "health_data.txt"


// list of diets 
static Diet diet_list[MAX_DIETS];
static int diet_list_size = 0;


/*
    description : read the information in "diets.txt" 식단 정보 읽어오는 코딩 
*/

void loadDiets(const char* DIETFILEPATH) {
	
    FILE *file = fopen(DIETFILEPATH, "r");
    
    if (file == NULL) {
        printf("There is no file for diets! \n");
        return;
    }

     // ToCode: to read a list of the diets from the given file
     //파일에서 식단 정보 읽기
	  
    while (1) 
	{
    	
    	//다 읽었으면 루프 탈출. 
    	//MAX_FOOD_NAME_LEN에 null문자 포함해서 49까지 읽을 수 있게 설정. 
    	if(fscanf(file, "%49s %d", diet_list[diet_list_size].food_name, &diet_list[diet_list_size].calories_intake) != 2)
    		break;
    	
        if (diet_list_size >= MAX_DIETS)
		{
        	break;
		}
		diet_list_size ++;
    }
    fclose(file);
}

/*
    description : to enter the selected diet and the total calories intake in the health data
    input parameters : health_data - data object to which the selected diet and its calories are added 
    return value : No
    
    operation : 1. provide the options for the diets to be selected //옵션 제공 
    			2. enter the selected diet and the total calories intake in the health data //후 출력 받기 
*/

void inputDiet(HealthData* health_data) {
    int choice, i;
    
    // ToCode: to provide the options for the diets to be selected
    printf("The list of diets:\n");
    
    
	// ToCode: to enter the diet to be chosen with exit option
    

    // ToCode: to enter the selected diet in the health data
    

    // ToCode: to enter the total calories intake in the health data


}

