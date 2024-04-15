#include <iostream>
#include <cstdlib>

bool IsLeapYear(int year);
int DifferenceInDays(int y1, int m1, int d1, int y2, int m2, int d2);
double Average(int arr[]);
int PosNegZero(int arr[]);
void MatrixInit(int arr[4][4]);
void MatrixInit(double arr[4][4]);
void MatrixInit(char arr[4][4]);
void MatrixOutput(int arr[4][4]);
void MatrixOutput(double arr[4][4]);
void MatrixOutput(char arr[4][4]);
int MatrixMax(int arr[4][4]);
double MatrixMax(double arr[4][4]);
char MatrixMax(char arr[4][4]);
int MatrixMin(int arr[4][4]);
double MatrixMin(double arr[4][4]);
char MatrixMin(char arr[4][4]);
void MatrixSort(int arr[4][4]);
void MatrixSort(double arr[4][4]);
void MatrixSort(char arr[4][4]);
int GCD(int n1, int n2);
void BullsAndCows();




int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	int day_1, month_1, year_1, day_2, month_2, year_2;

	do
	{
		std::cout << "Введите 2 даты в формате: \nдд\nмм\nгггг\n\n1-ая:\n";
		std::cin >> day_1 >> month_1 >> year_1;
		std::cout << "\n2-ая:\n";
		std::cin >> day_2 >> month_2 >> year_2;
	} while (day_1 > 31 || day_2 > 31 || month_1 > 12 || month_2 > 12);

	std::cout << "\nРазница между этими датами в днях: " 
		<< DifferenceInDays(day_1, month_1, year_1, day_2, month_2, year_2);






	std::cout << "\n\n=========================================================\n\n";





	int arrAverage[15]{};
	std::cout << "Введите массив из 15 целых чисел:\n";

	int number = 1;
	for (int i = 0; i < 15; i++)
	{
		std::cout << "  " << number << ": ";
		std::cin >> arrAverage[i];
		number++;
	}

	std::cout << "Среднее арифметическое: " << Average(arrAverage);





	std::cout << "\n\n=========================================================\n\n";





	int arrPosNegZero[10]{};
	std::cout << "Введите массив из 10 целых чисел:\n";

	number = 1;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "  " << number << ": ";
		std::cin >> arrPosNegZero[i];
		number++;
	}

	std::cout << PosNegZero(arrPosNegZero);





	std::cout << "\n\n=========================================================\n\n";




	int matrix[4][4]{};
	std::cout << "init: ";
	MatrixInit(matrix);

	std::cout << "\noutput: ";
	MatrixOutput(matrix);
	std::cout << "\n\nmax: " << MatrixMax(matrix) << "\nmin: " << MatrixMin(matrix);
	std::cout << "\n\nsorted: ";
	MatrixSort(matrix);
	


	std::cout << "\n\n=========================================================\n\n";




	int n1, n2;
	std::cout << "\n\nenter number one: ";
	std::cin >> n1;
	std::cout << "number two: ";
	std::cin >> n2;

	std::cout << "the greatest common devisor: " << GCD(n1, n2);


	BullsAndCows();

	return 0;
}





bool IsLeapYear(int year)
{
	if (year % 400 == 0)
	{
		return true;
	}
	else
	{
		if (year % 100 == 0)
		{
			return false;
		}
		else
		{
			if (year % 4 == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

int DifferenceInDays(int d1, int m1, int y1, int d2, int m2, int y2 )
{
	//YEARS 2

	long DAYS_IN_ALL_2 = (y2 + 1) * 365; 

	int amountOfLeapYears_2 = 0;
	for (int year = y2; year >= 0; year--)
	{
		if (IsLeapYear(year))
		{
			amountOfLeapYears_2++;
		}
	}
	DAYS_IN_ALL_2 += amountOfLeapYears_2;

	//MONTHS 2

	for (int month = m2; month > 0; month--)
	{
		if (month != 2)
		{
			if (month % 2 == 0)
			{
				DAYS_IN_ALL_2 += 30;
			}
			else
			{
				DAYS_IN_ALL_2 += 31;
			}
		}
		else
		{
			if (IsLeapYear(y2))
			{
				DAYS_IN_ALL_2 += 29;
			}
			else
			{
				DAYS_IN_ALL_2 += 28;
			}
		}
	}

	//DAYS 2

	DAYS_IN_ALL_2 += d2;


	//YEARS 1

	long DAYS_IN_ALL_1 = (y1 + 1) * 365;

	int amountOfLeapYears_1 = 0;
	for (int year = y1; year >= 0; year--)
	{
		if (IsLeapYear(year))
		{
			amountOfLeapYears_1++;
		}
	}
	DAYS_IN_ALL_1 += amountOfLeapYears_1;

	//MONTHS 1

	for (int month = m1; month > 0; month--)
	{
		if (month != 2)
		{
			if (month % 2 == 0)
			{
				DAYS_IN_ALL_1 += 30;
			}
			else
			{
				DAYS_IN_ALL_1 += 31;
			}
		}
		else
		{
			if (IsLeapYear(y1))
			{
				DAYS_IN_ALL_1 += 29;
			}
			else
			{
				DAYS_IN_ALL_1 += 28;
			}
		}
	}

	//DAYS 1

	DAYS_IN_ALL_1 += d1;

	return DAYS_IN_ALL_2 - DAYS_IN_ALL_1;
} 

double Average(int arr[])
{
	int size = 15;
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum / size;
}

int PosNegZero(int arr[])
{
	int positive = 0, negative = 0, zero = 0;

	int size = 10;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > 0)
		{
			positive++;
		}
		else if (arr[i] < 0)
		{
			negative++;
		}
		else if (arr[i] == 0)
		{
			zero++;
		}
	}
	
	std::cout << "positive: " << positive << "\nnegative: " << negative << "\nzero: " << zero << "\n";
	return 0;
}

void MatrixInit(int arr[4][4])
{
	std::cout << "\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << i + 1 << "." << j + 1 << ": ";
			std::cin >> arr[i][j];
		}
	}
}
void MatrixInit(double arr[4][4])
{
	std::cout << "\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << i + 1 << "." << j + 1 << ": ";
			std::cin >> arr[i][j];
		}
	}
}
void MatrixInit(char arr[4][4])
{
	std::cout << "\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << i + 1 << "." << j + 1 << ": ";
			std::cin >> arr[i][j];
		}
	}
}

void MatrixOutput(int arr[4][4])
{
	std::cout << "\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0;  j < 4;  j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << "\n";
	}
}
void MatrixOutput(double arr[4][4])
{
	std::cout << "\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << "\n";
	}
}
void MatrixOutput(char arr[4][4])
{
	std::cout << "\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << "\n";
	}
}


int MatrixMax(int arr[4][4])
{
	int max = arr[0][0];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i = j)
			{
				if (arr[i][j] > max)
				{
					max = arr[i][j];
				}
			}
		}
	}
	return max;
}
double MatrixMax(double arr[4][4])
{
	int max = arr[0][0];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i = j)
			{
				if (arr[i][j] > max)
				{
					max = arr[i][j];
				}
			}
		}
	}
	return max;
}
char MatrixMax(char arr[4][4])
{
	int max = arr[0][0];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i = j)
			{
				if (arr[i][j] > max)
				{
					max = arr[i][j];
				}
			}
		}
	}
	return max;
}

int MatrixMin(int arr[4][4])
{
	int min = arr[0][0];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i = j)
			{
				if (arr[i][j] < min)
				{
					min = arr[i][j];
				}
			}
		}
	}
	return min;
}
double MatrixMin(double arr[4][4])
{
	int min = arr[0][0];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i = j)
			{
				if (arr[i][j] < min)
				{
					min = arr[i][j];
				}
			}
		}
	}
	return min;
}
char MatrixMin(char arr[4][4])
{
	int min = arr[0][0];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i = j)
			{
				if (arr[i][j] < min)
				{
					min = arr[i][j];
				}
			}
		}
	}
	return min;
}


void MatrixSort(int arr[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int h = 0; h < 4; h++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (arr[i][j] > arr[i][j + 1])
				{
					int temp = arr[i][j];
					arr[i][j] = arr[i][j + 1];
					arr[i][j + 1] = temp;
				}
			}
		}
		
	}
	MatrixOutput(arr);
}
void MatrixSort(double arr[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int h = 0; h < 4; h++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (arr[i][j] > arr[i][j + 1])
				{
					double temp = arr[i][j];
					arr[i][j] = arr[i][j + 1];
					arr[i][j + 1] = temp;
				}
			}
		}

	}
	MatrixOutput(arr);
}
void MatrixSort(char arr[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int h = 0; h < 4; h++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (arr[i][j] > arr[i][j + 1])
				{
					char temp = arr[i][j];
					arr[i][j] = arr[i][j + 1];
					arr[i][j + 1] = temp;
				}
			}
		}

	}
	MatrixOutput(arr);
}

int GCD(int n1, int n2)
{
	int div;
	if (n1 == n2) 
	{
		return n1;
	}

	int d = n1 - n2; 

	if (d < 0) 
	{
		d = -d; 
		div = GCD(n1, d); 
	}
	else 
	{
		div = GCD(n2, d); 
	}
	return div;
}


void BullsAndCows()
{

	int attempts = 0;
	int mainNumber = rand() % 8999 + 1000;
	int inputNumber;

	std::cout << "\nWelcome to 'Bulls & Cows' game!\n(you need to guess the number that i've made up)\n\nEnter a 4-digit number: ";
	
	do
	{
		int bulls = 0, cows = 0;
		
		std::cout << "\n";
		std::cin >> inputNumber;

		int input[4]{};
		int main[4]{};

		input[0] = inputNumber % 10000 / 1000;
		input[1] = inputNumber % 1000 / 100;
		input[2] = inputNumber % 100 / 10;
		input[3] = inputNumber % 10;

		main[0] = mainNumber % 10000 / 1000;
		main[1] = mainNumber % 1000 / 100;
		main[2] = mainNumber % 100 / 10;
		main[3] = mainNumber % 10;

		for (int i = 0; i < 4; i++)
		{
			if (input[i] == main[i])
			{
				cows++;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (j != i && input[i] == main[j])
				{
					bulls++;
				}
			}
		}
		std::cout << "\nBulls: " << bulls << "\nCows: " << cows << "\n";
	
		attempts++;

	} while (inputNumber != mainNumber);

	std::cout << "\nHooray! You've guessed the number!\n\n";
	std::cout << "Attempts: " << attempts << "\n\n";
}
