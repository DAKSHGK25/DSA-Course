#include <stdio.h>
#include <string.h>

struct Student{
    char usn[50];
    char name[50];
    int m1, m2, m3;
    float attendance;
};

int main(){
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct Student S[n];
    int i=0;
    while(i<n){
        printf("\nEnter the details of student %d\n", i+1);
        printf("Enter USN: ");
        scanf("%s", &S[i].usn);
        printf("Enter Name: ");
        scanf(" %[^\n]s", &S[i].name);
        printf("Enter marks in 3 subjects: ");
        scanf("%d %d %d", &S[i].m1, &S[i].m2, &S[i].m3);
        printf("Enter attendance percentage: ");
        scanf("%f", &S[i].attendance);
        i++;
    }

    int j=0;
    printf("===== Student Details =====\n");
    int total, pass = 0, fail = 0, fail_att = 0, p, e;
    char tusn[50], tname[50]; float tavg, tattendance, max = 0.0;
    while(j<n){
        int total = 0, p = 0, e = 0;
        printf("\nStudent %d\n", j+1);
        printf("USN: %s\n", S[j].usn);
        printf("Name: %s\n", S[j].name);
        printf("Marks: %d, %d, %d\n", S[j].m1, S[j].m2, S[j].m3);
        total = S[j].m1 + S[j].m2 + S[j].m3;
        printf("Attendance: %.2f%%\n", S[j].attendance);
        printf("Total: %d\n", total);
        float avg = (float)total/3;
        printf("Average: %.2f\n", avg);
        if(avg>max){
            tavg = avg;
            max = avg;
            strcpy(tusn, S[j].usn);
            strcpy(tname, S[j].name);
            tattendance = S[j].attendance;
        }
        if(S[j].m1 < 35 || S[j].m2 < 35 || S[j].m3 < 35){
            printf("Result: Fail\n");
            fail++;}
        else{
            printf("Result: Pass\n");
            p = 1;
            pass++;}
        if(p != 1){
            printf("Grade: -\n");}
        else{
            if(avg >= 85){
            printf("Grade: A\n");}
            else if(avg >= 70 && avg < 85){
                printf("Grade: B\n");}
            else if(avg >= 50 && avg < 70){
                printf("Grade: C\n");}
            else{
                printf("Grade: D\n");}
        }
        if(S[j].attendance < 75.0){
            printf("Eligibility: Not Eligible\n");
            fail_att++;}
        else{
            printf("Eligibility: Eligible\n");
            e = 1;}
        float scholarship = 0.0;
        if(p == 1 && e == 1){
            if(avg >= 90 && S[j].attendance >= 90){
                scholarship = 10000.0;}
            else if(avg >= 80 && S[j].attendance >= 85){
                scholarship = 5000.0;}
            else{
                scholarship = 0.0;
            }
        }
        else{scholarship = 0.0;}
        printf("Scholarship: Rs.%.2f\n", scholarship);
        j++;
    }

    printf("\n===== Summary =====\n");
    printf("Passed Students: %d\n", pass);
    printf("Failed Students: %d\n", fail);
    printf("Students Not Eligible by Attendance: %d\n", fail_att);
    printf("\n===== Top Eligible Student =====\n");
    printf("USN: %s\n", tusn);
    printf("Name: %s\n", tname);
    printf("Average: %.2f\n", tavg);
    printf("Attendance: %.2f%%\n", tattendance);
    return 0;
}