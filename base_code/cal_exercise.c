//
//  cal_exercise.c
//  Excercise for Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define MAX_EXERCISES 100  			// Maximum number of exercises
#define MAX_EXERCISE_NAME_LEN 50	// Maximum length of the name of exercise


// To declare the structure of the exercises
static Exercise exercise_list[MAX_EXERCISES];
int exercise_list_size = 0;


/*
    description : read the information in "excercises.txt"
*/

void loadExercises(const char* EXERCISEFILEPATH) {
    FILE *file = fopen(EXERCISEFILEPATH, "r");
    if (file == NULL) {
        printf("There is no file for exercises! \n");
        return;
    }

    // ToCode: to read a list of the exercises from the given file
    while (1 ) {
    	
    	//loadDiets랑 동일 
    	if (fscanf(file, "%49s %d", exercise_list[exercise_list_size].exercise_name, &exercise_list[exercise_list_size].calories_burned_per_minute) !=2 )
    		break;
    		
        if (exercise_list_size >= MAX_EXERCISES){
        	break;
		}
		
		exercise_list_size++;
    }

    fclose(file);
}


/*
    description : to enter the selected exercise and the total calories burned in the health data
    input parameters : health_data - data object to which the selected exercise and its calories are added 
    return value : No
    
    operation : 1. provide the options for the exercises to be selected
    			2. enter the duration of the exercise
    			3. enter the selected exercise and the total calories burned in the health data
*/

void inputExercise(HealthData* health_data) {
    int choice, duration, i;
    
    // ToCode: to provide the options for the exercises to be selected
    printf("The list of exercises: \n");
    
    //운동 옵션 출력
	for(i=0; i<exercise_list_size; i++)
		printf("%d: %s, %d kcal/min\n", i+1, exercise_list[i].exercise_name, exercise_list[i].calories_burned_per_minute);

	choice = -1; //초기값 -1로 설정. 
	while(choice != 0)
	{
		// ToCode: to enter the exercise to be chosen with exit option
		//사용자 운동 입력
		printf("Select exercise (0 to exit): ");
		scanf("%d", &choice);
		
		//선택 범위 맞는지 확인 후 운동시간 입력받기 
		if(choice > exercise_list_size || choice <0)
		{
			printf("Wrong choice. Try again.\n");
			continue;
		}

		else if (choice>0)
		{
			// To enter the duration of the exercise
    		printf("Enter the duration of the exercise (in min.): ");
			scanf("%d", &duration); 
			
			// ToCode: to enter the selected exercise and total calcories burned in the health data
			
			int j;
			for (j = 0 ; exercise_list[choice - 1].exercise_name[j] != '\0' ; j++) 
			{
				//문자열 끝에 도달할 때까지 복사 
				health_data->exercises[health_data->exercise_count].exercise_name[j] = exercise_list[choice-1].exercise_name[j];
			}
			//문자열 끝에 null문자 붙여주기 
			health_data->exercises[health_data->exercise_count].exercise_name[strlen(exercise_list[choice-1].exercise_name)] = '\0'; 
				
			// 선택한 운동의 칼로리 소모량 기록 
			health_data->exercises[health_data->exercise_count].calories_burned_per_minute = exercise_list[choice-1].calories_burned_per_minute; 
			health_data->exercise_count++; //운동 개수 증가 
			
			//총 소모 칼로리 추가( 총 칼로리 소모량 = 분당 칼로리 소모량 X 운동 시간) 
			health_data->total_calories_burned += exercise_list[choice -1].calories_burned_per_minute*duration;
		}
	}


    printf("Exiting the exercise selection.\n");
}
