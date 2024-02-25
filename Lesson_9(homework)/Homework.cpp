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

struct Man
{
	char last_name[50];
	char first_name[50];
	int age;
	int day;
	int month;
	int year;
};

void Show_People(const Man people[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << people[i].last_name << endl;
		cout << people[i].first_name << endl;
		cout << "Age: " << people[i].age << endl;
		cout << people[i].day << "." << people[i].month << "." << people[i].year << endl;
	}
	cout << endl;
}

void Sort_by_Last_or_First_Name(Man people[], int size, bool way = true)
{
	if (way)
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (strcmp(people[i].last_name, people[j].last_name) == 1)
				{
					swap(people[i], people[j]);
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (strcmp(people[i].first_name, people[j].first_name) == 1)
				{
					swap(people[i], people[j]);
				}
			}
		}
	}
}

int Counter_Birthday_People(const Man people[], int size, int month)
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (people[i].month == month)
		{
			counter++;
		}
	}

	return counter;
}

Man* Search_Birtday_People(Man people[], int size, int month)
{
	int counter_1 = Counter_Birthday_People(people, size, month);
	if (counter_1 == 0)
	{
		cout << "No birtday people this month!\n";
		return nullptr;
	}

	int counter_2 = 0;
	Man* birtday_people = new Man[counter_1];

	for (int i = 0; i < size; i++)
	{
		if (people[i].month == month)
		{
			birtday_people[counter_2] = people[i];
			counter_2++;
		}
	}

	return birtday_people;
}

int Counter_LastName_and_Name(Man people[], char* str_name, char* str_last_name, int size)
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(_strlwr(people[i].first_name), _strlwr(str_name)) == 0 && strcmp(_strlwr(people[i].last_name), _strlwr(str_last_name)) == 0)
		{
			counter++;
		}
	}

	return counter;
}

Man* Search_LastName_and_Name(Man people[], char* str_name, char* str_last_name, int size)
{
	int counter_1 = Counter_LastName_and_Name(people, str_name, str_last_name, size);
	Man* search_last_name_and_name = new Man[counter_1];
	int counter_2 = 0;

	for (int i = 0; i < size; i++)
	{
		if (strcmp(_strlwr(people[i].first_name), _strlwr(str_name)) == 0 && strcmp(_strlwr(people[i].last_name), _strlwr(str_last_name)) == 0)
		{
			search_last_name_and_name[counter_2] = people[i];
			search_last_name_and_name[counter_2].first_name[0] -= ' ';
			search_last_name_and_name[counter_2].last_name[0] -= ' ';
			counter_2++;
		}
		people[i].last_name[0] -= ' ';
		people[i].first_name[0] -= ' ';
	}

	return search_last_name_and_name;
}

void Edit_Last_Name(Man people[], char* last_name, int index)
{
	strcpy(people[index].last_name, last_name);
}

void Edit_First_Name(Man people[], char* str_name, int index)
{
	strcpy(people[index].first_name, str_name);
}

void Edit_Age(Man people[], int new_age, int index)
{
	people[index].age = new_age;
}

void Edit_Day(Man people[], int new_day, int index)
{
	people[index].day = new_day;
}

void Edit_Month(Man people[], int new_month, int index)
{
	people[index].month = new_month;
}

void Edit_Year(Man people[], int new_year, int index)
{
	people[index].year = new_year;
}

Man* Add_or_Delete_Person(Man people[], int& size, bool add_or_delete = 1)
{
	Man* p_new_size;
	if (add_or_delete)
	{
		p_new_size = new Man[++size];
		for (int i = 0; i < size - 1; i++)
		{
			p_new_size[i] = people[i];
		}

		char str_last_name[50];
		cin.ignore();
		cout << "Enter last name:\n";
		cin.getline(str_last_name, 50);
		strcpy(p_new_size[size - 1].last_name, str_last_name);

		char str_name[50];
		cin.ignore();
		cout << "Enter name:\n";
		cin.getline(str_name, 50);
		strcpy(p_new_size[size - 1].first_name, str_name);

		int new_age;
		cout << "Enter age:\n";
		cin >> new_age;
		p_new_size[size - 1].age = new_age;

		int new_day;
		cout << "Enter day:\n";
		cin >> new_day;
		p_new_size[size - 1].day = new_day;

		int new_month;
		cout << "Enter month:\n";
		cin >> new_month;
		p_new_size[size - 1].month = new_month;

		int new_year;
		cout << "Enter year:\n";
		cin >> new_year;
		p_new_size[size - 1].year = new_year;
	}
	else
	{
		int index_to_delete;
		cout << "Enter index(from 1 to size arr)\n";
		do
		{
			cin >> index_to_delete;
			if (index_to_delete < 1 || index_to_delete >= size)
			{
				cout << "Error!\nTry again!\n";
			}
		} while (index_to_delete < 1 || index_to_delete >= size);

		p_new_size = new Man[--size];
		index_to_delete--;
		for (int i = 0; i < index_to_delete; i++)
		{
			p_new_size[i] = people[i];
		}
		for (int i = index_to_delete + 1; i < size + 1; i++)
		{
			p_new_size[i - 1] = people[i];

		}
	}

	delete[] people;

	return p_new_size;
}

int main()
{
	srand(static_cast<unsigned>(time(nullptr)));

	// Завдання 1

	/*int size = 2;
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
	} while (user_input != -1);*/

	// Завдання 2

	int size = 3;
	Man* p_man = new Man[size];

	strcpy(p_man[0].last_name, "Hopak");
	strcpy(p_man[0].first_name, "Ukr");
	p_man[0].age = 324;
	p_man[0].day = 21;
	p_man[0].month = 12;
	p_man[0].year = 1700;

	strcpy(p_man[1].last_name, "Dodaluk");
	strcpy(p_man[1].first_name, "Jaja");
	p_man[1].age = 24;
	p_man[1].day = 4;
	p_man[1].month = 11;
	p_man[1].year = 2000;

	strcpy(p_man[2].last_name, "Rotahef");
	strcpy(p_man[2].first_name, "Shet");
	p_man[2].age = 30;
	p_man[2].day = 6;
	p_man[2].month = 7;
	p_man[2].year = 1994;

	int user_input;
	int user_choice_1;
	int counter;
	Man* p_temp;
	int user_input_month;
	char str_last_name[50];
	char str_first_name[50];
	int user_input_choice;
	int user_input_age;
	int user_input_day;
	int user_input_year;
	do
	{
		cout << "What do you want to know:\n1 - Sort by last name or first name\n2 - Search Birtday people\n3 - Add person\n4 - Delete person\n5 - Search by last name and first name\n6 - Edit\nOr -1 to stop\n";
		do
		{
			cin >> user_input;
		} while (user_input < -1 || user_input>6);

		if (user_input == -1)
		{
			break;
		}
		switch (user_input)
		{
		case 1:
			do
			{
				cout << "1 - Sort by last name\n2 - Sort by first name\n";
				cin >> user_choice_1;
			} while (user_choice_1 < 1 || user_choice_1 > 2);
			switch (user_choice_1)
			{
			case 1:
				Sort_by_Last_or_First_Name(p_man, size);
				break;
			case 2:
				Sort_by_Last_or_First_Name(p_man, size, 0);
				break;
			default:
				break;
			}
			break;
		case 2:
			cout << "Enter month:\n";
			cin >> user_input_month;

			counter = Counter_Birthday_People(p_man, size, user_input_month);
			p_temp = Search_Birtday_People(p_man, size, user_input_month);
			Show_People(p_temp, counter);
			delete[] p_temp;
			break;
		case 3:
			p_man = Add_or_Delete_Person(p_man, size);
			Show_People(p_man, size);
			break;
		case 4:
			p_man = Add_or_Delete_Person(p_man, size, 0);
			Show_People(p_man, size);
			break;
		case 5:
			cin.ignore();
			cout << "Enter last name:\n";
			cin.getline(str_last_name, 50);

			cin.ignore();
			cout << "Enter first name:\n";
			cin.getline(str_first_name, 50);

			counter = Counter_LastName_and_Name(p_man, str_first_name, str_last_name, size);
			p_temp = Search_LastName_and_Name(p_man, str_first_name, str_last_name, size);
			Show_People(p_temp, counter);
			delete[] p_temp;
			break;
		case 6:
			do
			{
				cout << "Enter index(from 1 to size):\n";
				cin >> user_choice_1;
			} while (user_choice_1<1 || user_choice_1>size);

			do
			{
				cout << "Enter what:\n1 - Edit last name\n2 - Edit first name\n3 - Edit age\n4 - Edit day\n5 - Edit month\n6 - Edit year\n";
				cin >> user_input_choice;
			} while (user_input_choice < 1 || user_input_choice>6);

			switch (user_input_choice)
			{
			case 1:
				cin.ignore();
				cout << "Enter last name:\n";
				cin.getline(str_last_name, 50);

				Edit_Last_Name(p_man, str_last_name, user_choice_1 - 1);
				break;
			case 2:
				cin.ignore();
				cout << "Enter first name:\n";
				cin.getline(str_first_name, 50);

				Edit_First_Name(p_man, str_first_name, user_choice_1 - 1);
				break;
			case 3:
				cout << "Enter age:\n";
				cin >> user_input_age;

				Edit_Age(p_man, user_input_age, user_choice_1 - 1);
				break;
			case 4:
				cout << "Enter day:\n";
				cin >> user_input_day;

				Edit_Day(p_man, user_input_day, user_choice_1 - 1);
				break;
			case 5:
				cout << "Enter month:\n";
				cin >> user_input_month;

				Edit_Month(p_man, user_input_month, user_choice_1 - 1);
				break;
			case 6:
				cout << "Enter year:\n";
				cin >> user_input_year;

				Edit_Year(p_man, user_input_year, user_choice_1 - 1);
				break;
			default:
				break;
			}
		default:
			break;
		}
	} while (user_input != -1);

	return 0;
}