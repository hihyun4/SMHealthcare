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

//loadDiets, inputDiet �Լ� 

//MAX_EXERCISES 100 / �ִ� � Ƚ��
//MAX_EXERCISE_NAME_LEN 50 / � �̸� ����
//MAX_DIETS 100 / �ִ� ���̾�Ʈ Ƚ��
//MAX_FOOD_NAME_LEN 50 / ���� �̸� ����
//DAILY_CALORIE_GOAL 2000 / ���� ���� ���� ���� Į�θ� ���뷮
//BASAL_METABOLIC_RATE 1300 / ���� ���� ���ʴ�緮

//EXERCISEFILEPATH "exercises.txt"
//DIETFILEPATH "diets.txt"
//HEALTHFILEPATH "health_data.txt"


// list of diets 
static Diet diet_list[MAX_DIETS];
static int diet_list_size = 0;


/*
    description : read the information in "diets.txt" �Ĵ� ���� �о���� �ڵ� 
*/

void loadDiets(const char* DIETFILEPATH) {
	
    FILE *file = fopen(DIETFILEPATH, "r");
    
    if (file == NULL) {
        printf("There is no file for diets! \n");
        return;
    }

     // ToCode: to read a list of the diets from the given file
     //���Ͽ��� �Ĵ� ���� �б�
	  
    while (1) 
	{
    	
    	//�� �о����� ���� Ż��. 
    	//MAX_FOOD_NAME_LEN�� null���� �����ؼ� 49���� ���� �� �ְ� ����. 
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
    
    operation : 1. provide the options for the diets to be selected //�ɼ� ���� 
    			2. enter the selected diet and the total calories intake in the health data //�� ��� �ޱ� 
*/

void inputDiet(HealthData* health_data) {
    int choice, i;
    
    // ToCode: to provide the options for the diets to be selected 
    printf("The list of diets:\n");
    
    //�Ĵ� �ɼ� ���
	for (i=0; i< diet_list_size; i++)
	{
		printf("%d: %s, %d kcal\n", i+1, diet_list[i].food_name, diet_list[i].calories_intake);
	}
    
    choice = -1; //�Է¹ޱ� �� �ʱⰪ -1�� ���� 
    //choice�� 0�� �ƴ� ������ �ݺ� 
    while(choice != 0)
    {
    	
    	// ToCode: to enter the diet to be chosen with exit option 
		//������ �Ĵ� �Է�
		printf("Select diet (0 to exit): ");
		scanf("%d", &choice); //choice�� ������ �Ĵ� ��ȣ �ֱ� 
	
	
		// ToCode: to enter the selected diet in the health data
		//�Ĵ� ���, choice�� ������ �߸������� �ٽ� �õ�. 
		if(choice> diet_list_size || choice < 0)
			printf("Wrong choice. Try again.\n");
		else if(choice>0) 
		{
			//�Ĵ��� health_data �� ����ؾ���.
			
			// ToCode: to enter the total calories intake in the health data
    		//Į�θ� ���  
		}
	}
    
    printf("Exiting the diet selection.\n");	
	}


