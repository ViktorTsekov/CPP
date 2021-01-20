#include "StudentGrade.h"

int main() {
    StudentGrade studentA("Viktor", "Ivaylov", "Tsekov", "28001040", 100, 120);
    StudentGrade studentB("Denis", "", "Stoynov", "28008042", 60);
    
    studentA.assignGrade();
    studentA.displayData();

    studentB.assignGrade();
    studentB.displayData();
}