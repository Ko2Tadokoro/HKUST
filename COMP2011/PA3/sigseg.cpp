#include <iostream>
#include <cstring>

using namespace std;

const int MAX_CODE = 10; // at most 10 characters (including the NULL character)
const int MAX_TITLE = 100; // at most 100 characters (including the NULL character)


struct Course {
    char code[MAX_CODE];        // course code
    char title[MAX_TITLE];      // course title
    int credit;                 // course credit
    Course* next;               // a pointer pointing to the next Course
    //CourseItem* exclusions;     // a sorted linked list of CourseItem
    //CourseItem* prerequisites;  // a sorted linked list of CourseItem
};


Course* ll_createCourse(const char c[MAX_CODE], const char t[MAX_TITLE], int cred, Course* nextcourse)
{
    Course* new_course = new Course;

    strcpy(new_course->code, c);
    strcpy(new_course->title, t);
    new_course->credit = cred;
    new_course->next = nextcourse;
    //new_course->exclusions = exclusionss;
    //new_course->prerequisites = prerequisitess;

    return new_course;
}


Course* head = nullptr;

int main()
{   
    Course* new_course = nullptr;

    char c[MAX_CODE] = {"sup"};


    //cout << strcmp(new_course->code, c);//segmentation fault because of new_course->code which is non-existent



    Course* course_1 = ll_createCourse("yes", "yes", 3, nullptr);
    Course* course_2 = ll_createCourse("no", "no", 3, nullptr);

    head = course_1;
    course_1->next = course_2;


    
    Course* course_ptr = head;    
/*     for (; (course_ptr != nullptr)  && (strcmp(course_ptr->code, c) != 0) ;)//no sigseg
  {
         if (strcmp(course_ptr->code, c) == 0)
            break; 
            
        course_ptr = course_ptr->next;
    }

    if (course_ptr == nullptr)//NO same code in list, nullptr == empty list or end of list
        return false;
    else
        return true; */ 


/*     while((course_ptr != nullptr)  && (strcmp(course_ptr->code, c) != 0))//no sigseg
    {
         if (strcmp(course_ptr->code, c) == 0)
            break; 
            
        course_ptr = course_ptr->next;
    } */
    

    while((strcmp(course_ptr->code, c) != 0) && (course_ptr != nullptr))//sigseg
    {
/*         if (strcmp(course_ptr->code, c) == 0)
            break; */
            
        course_ptr = course_ptr->next;
    }

    while( (course_ptr != nullptr) && (strcmp(course_ptr->code, c) != 0) )//no sigseg
    {
/*         if (strcmp(course_ptr->code, c) == 0)
            break; */
            
        course_ptr = course_ptr->next;
    }

    

    return 0;
}