#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using std::cout;

/*
	Jordan Mohler
	Lab 5
	COMP 2355
	23 January 2017
*/

struct Student {
	int studentId;
	int assignmentGrades[4];
};

void reWrite(FILE *f) {
	for (int i = 0; i < 5; i++) {
		int x = fseek(f, (4-i)* sizeof(Student), SEEK_SET);
		cout << "FSeek return: " << x << "\n";
		Student arr;
		int y = fread(&arr, sizeof(Student), 1, f);
		cout << "FRead return: " << y << "\n";

		cout << "Student ID: " << arr.studentId << " Student Grades: ";
		for (int k = 0; k < 4; k++) { cout << arr.assignmentGrades[k] << " "; }
		cout << "\n";

		int answer[4];
		cout << "What are the students new grades?\n";
		for (int j = 0; j < 4; j++) {
			cout << "Grade " << j + 1 << ":\n";
			std::cin >> arr.assignmentGrades[j];
			int k = fseek(f, (4 - i) * sizeof(Student), SEEK_SET);
			cout << "FSeek return: " << k << "\n";
			int r = fwrite(&arr, sizeof(arr), 1, f);
			cout << "FWrite return: " << r << "\n";
		}
	}
}

int main(int argc, char* argv[]) {

	//Step 1
	FILE *f = fopen("Lab5", "wb+");
	if (f == 0) {
		cout << "Cannot open file.\n";
		return 0;
	}

	//Step 2
	Student arr;
	for (int j = 0; j < 5; j++) {
		cout << "What are the students grades?\n";
		for (int i = 0; i < 4; i++) {
			cout << "Grade " << i + 1 << ":\n";
			std::cin >> arr.assignmentGrades[i];
		}
		arr.studentId = j;
		int x = fwrite(&arr, sizeof(arr), 1, f);
		cout << "\nFWrite return: " << x << "\n";
	}

	//Step 3
	cout << "\nRewrite 1:\n";
	reWrite(f);
	
	//Step 4
	cout << "\nRewrite 2:\n";
	reWrite(f);

	//Step 5
	fclose(f);

	return 0;
}