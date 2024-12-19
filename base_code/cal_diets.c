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
	{	//파일을 읽어와서 저장 
		//앞쪽은 이름, null문자 포함해서 49까지 읽은 후 diet_list의 food_name속 저장
		//뒤쪽은 칼로리, 숫자로 읽은 후 diet_list의 calories_intake 속 저장

    	if(fscanf(file, "%49s %d", diet_list[diet_list_size].food_name, &diet_list[diet_list_size].calories_intake) != 2)
    		break; //파일 끝에 도달 or 오류 발생 시 루프 탈출
    	
    	//최대 식단 개수에 도달하면 탈출
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
    
    //식단 옵션 출력
	for (i=0; i< diet_list_size; i++)
	{
		printf("%d: %s, %d kcal\n", i+1, diet_list[i].food_name, diet_list[i].calories_intake);
	}
    
    choice = -1; //입력받기 전 초기값 -1로 설정 
    //choice가 0이 아닐 때까지 반복 
    while(choice != 0)
    {
    	
    	// ToCode: to enter the diet to be chosen with exit option 
		//선택할 식단 입력
		printf("Select diet (0 to exit): ");
		scanf("%d", &choice); //choice에 선택한 식단 번호 넣기 
	
	
		// ToCode: to enter the selected diet in the health data
		//식단 기록, choice의 범위가 잘못됐으면 다시 시도
		if(choice> diet_list_size || choice < 0)
		{
			printf("Wrong choice. Try again.\n");
			continue;
		}

		else if(choice>0) 
		{
			// ToCode: to enter the total calories intake in the health data
			//식단 이름 끝(null)에 도달할 때까지 식단 이름 복사 
			int j; 
			////0부터 문자열의 현재 위치에 있는 문자가 끝에 있는 null문자가 아닐 동안 실행하여 한 문자씩 복사하기
			for(j=0; diet_list[choice-1].food_name[j] != '\0'; j++) 
			{
				//현재 복사할 위치에 있는 식단 이름을 복사하기. 
				health_data->diet[health_data->diet_count].food_name[j] = diet_list[choice-1].food_name[j];
			}
			//복사한 문자열 끝에 null문자 붙여서 문자열의 끝 표시하기 
			health_data->diet[health_data->diet_count].food_name[strlen(diet_list[choice-1].food_name)] = '\0';
			//선택한 식단의 칼로리도  기록. 
			health_data->diet[health_data->diet_count].calories_intake = diet_list[choice - 1].calories_intake;
			//식단 개수 증가
			health_data->diet_count++;
			//총 칼로리 섭취량에도 추가하기. 
			health_data->total_calories_intake += diet_list[choice - 1].calories_intake;
		}
	}
    
    printf("Exiting the diet selection.\n");
}


