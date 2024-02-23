#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;
struct Rating
{
	int rating;
};

struct Student
{
	char str_student[30];
	char group[20];
	Rating rating_student[5];
};

void Show_Rating(Student students[], int index)
{
	for (int i = 0; i < 5; i++)
	{
		cout << students[index].rating_student[i].rating << ' ';
	}
}

void Show_Students(Student students[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << students[i].str_student << endl;
		cout << students[i].group << endl;
		Show_Rating(students, i);
		cout << endl;
	}
	cout << endl;
}

void Fill_Student_Rating(Student students[], int index)
{
	for (int i = 0; i < 5; i++)
	{
		students[index].rating_student[i].rating = rand() % 12 + 1;
	}
}

void Fill_Students_Rating(Student students[], int size)
{
	for (int i = 0; i < size; i++)
	{
		Fill_Student_Rating(students, i);
	}
}

Student* Change_Size_Arr_Students(Student students[], char* str_student, char* group, int size)
{
	Student* p_student = new Student[size + 1];

	for (int i = 0; i < size; i++)
	{
		p_student[i] = students[i];
	}

	strcpy(p_student[size].str_student, str_student);
	strcpy(p_student[size].group, group);
	Fill_Student_Rating(p_student, size);

	return p_student;
}

int Counter_Excellent_Students(Student students[], int size)
{
	double GPA;
	int counter_1 = 0;
	int counter_2 = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			counter_1 += students[i].rating_student[j].rating;
		}
		GPA = counter_1 / 1.0 / 5;
		if (GPA >= 9)
		{
			counter_2++;
		}
		counter_1 = 0;
	}

	return counter_2;
}

Student* Excellent_Students(Student students[], int size)
{
	int counter_array = Counter_Excellent_Students(students, size);

	Student* p_excellent_students = new Student[counter_array];

	double GPA;
	int counter_1 = 0;
	int counter_2 = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			counter_1 += students[i].rating_student[j].rating;
		}
		GPA = counter_1 / 1.0 / 5;
		if (GPA >= 9)
		{
			p_excellent_students[counter_2] = students[i];
			counter_2++;
		}
		counter_1 = 0;
	}

	return p_excellent_students;
}

int Counter_Students_Study_not_Well(Student students[], int size)
{
	int counter_1 = 0;
	int counter_2 = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (students[i].rating_student[j].rating <= 3)
			{
				counter_1++;
			}
		}
		if (counter_1 >= 3)
		{
			counter_2++;
		}
		counter_1 = 0;
	}

	return counter_2;
}

Student* Students_Study_not_Well(Student students[], int size)
{
	int counter_array = Counter_Students_Study_not_Well(students, size);

	Student* p_students_study_well = new Student[counter_array];

	int counter_1 = 0;
	int counter_2 = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (students[i].rating_student[j].rating <= 3)
			{
				counter_1++;
			}
		}
		if (counter_1 >= 3)
		{
			p_students_study_well[counter_2] = students[i];
			counter_2++;
		}
		counter_1 = 0;
	}

	return p_students_study_well;
}

int main()
{
	srand(static_cast<unsigned>(time(nullptr)));

	// Завдання 1

	int size = 2;
	Student* p_students_1 = new Student[2];

	strcpy(p_students_1[0].str_student, "Kola");
	strcpy(p_students_1[0].group, "Joja");

	strcpy(p_students_1[1].str_student, "Jija");
	strcpy(p_students_1[1].group, "Agt");

	Fill_Students_Rating(p_students_1, 2);

	char str_name[30];
	char str_group[30];
	int counter;
	Student* p_excellent_students;
	Student* p_students_study_not_well;
	Student* p_students;
	int user_input;
	do
	{
		cout << "What do you want to know?\n1 - Change size array students\n2 - Excellent students\n3 - Students do not study well\n-1 to stop\n";
		do
		{
			cin >> user_input;
		} while (user_input < -1 || user_input>3);
		if (user_input == -1)
		{
			break;
		}
		switch (user_input)
		{
		case 1:
			cin.ignore();
			cout << "Enter name student:\n";
			cin.getline(str_name, 30);
			cout << "Enter group student:\n";
			cin.getline(str_group, 20);
			p_students = Change_Size_Arr_Students(p_students_1, str_name, str_group, size);
			size++;
			delete[] p_students_1;
			p_students_1 = p_students;
			Show_Students(p_students_1, size);
			break;
		case 2:
			counter = Counter_Excellent_Students(p_students_1, size);
			p_excellent_students = Excellent_Students(p_students_1, size);
			Show_Students(p_excellent_students, counter);
			delete[] p_excellent_students;
			break;
		case 3:
			counter = Counter_Students_Study_not_Well(p_students_1, size);
			p_students_study_not_well = Students_Study_not_Well(p_students_1, size);
			Show_Students(p_students_study_not_well, counter);
			delete[] p_students_study_not_well;
			break;
		default:
			break;
		}
	} while (user_input != -1);

	return 0;
}