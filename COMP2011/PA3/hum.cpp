// === Region: Project Overview ===
// 
// Here is the skelton code of COMP2011 PA3
//
// Project TA: CHUNG, Peter (cspeter@cse.ust.hk)
// All input/output handlings are done in the skeleton code
// You do not need to cin/cout anything in your extra code!
//
// For code-level questions, please send a direct email to the above TA. 
// Asking questions with code in a discussion forum (e.g., Piazza) may cause plagiarism issues
// Usually, you will get the quickest response via a direct email.
//
// Assumptions:
// The course code is the unique key (i.e., there won't be duplicated course codes in the system). 
// This assumption is necessary for many operations (e.g., searching, insertions, and deletions, etc.)
//
// ================================= 

#include <iostream>
#include <cstring>
using namespace std;

// === Region: constants and structs ===
// The constants are structs are defined in this region
// ===================================

// constants
const int MAX_CODE = 10; // at most 10 characters (including the NULL character)
const int MAX_TITLE = 100; // at most 100 characters (including the NULL character)


struct CourseItem; // needed because Course needs to refer to CourseItem*


// A sorted linked list of Course. List items are sorted by the course code
struct Course {
    char code[MAX_CODE];        // course code
    char title[MAX_TITLE];      // course title
    int credit;                 // course credit
    Course* next;               // a pointer pointing to the next Course
    CourseItem* exclusions;     // a sorted linked list of CourseItem
    CourseItem* prerequisites;  // a sorted linked list of CourseItem
};


// A sorted linked list of CourseItem. List items are sorted by course->code
struct CourseItem {
    Course *course;             // pointing to the course
    CourseItem *next;           // a pointer pointing to the next CourseItem
};

// === Region: function declarations ===
// The function declarations. 
//
// If needed, you can add your own helper functions
//
// The implementation is done in the function definitions after the main() function
// ===================================

Course* ll_createCourse(const char c[MAX_CODE], const char t[MAX_TITLE], int cred, Course* nextcourse, CourseItem* exclusionss, CourseItem* prerequisitess)
{
    Course* new_course = new Course;

    strcpy(new_course->code, c);
    strcpy(new_course->title, t);
    new_course->credit = cred;
    new_course->next = nextcourse;
    new_course->exclusions = exclusionss;
    new_course->prerequisites = prerequisitess;

    return new_course;
}

CourseItem* ll_createItem(Course* coursee, CourseItem* nextitem)
{
    CourseItem* new_item = new CourseItem;

    new_item->course = coursee;
    new_item->next = nextitem;

    return new_item;
}

//if checkcode exists in list, return true
//if checkcode DNE in list, return false
bool ll_check_DNE(Course*& head, const char checkcode[MAX_CODE])
{
    Course* course_ptr = head;
    for (; (course_ptr != nullptr) /* && (strcmp(course_ptr->code, checkcode) != 0) */;)
    {
        if (strcmp(course_ptr->code, checkcode) == 0)
            break;
            
        course_ptr = course_ptr->next;
    }

    if (course_ptr == nullptr)//NO same code in list, nullptr == empty list or end of list
        return false;
    else
        return true;
}

/**
 * function ll_print_all prints the linked lists stored in the system
 * @param head pointing to the head of the linked list
*/
void ll_print_all(const Course* head); // given, you cannot make any changes

/**
 * function ll_insert_prerequisite inserts a pre-requisite
 * Example: if COMP2011 requires COMP1022P, the targetCode is COMP2011 and the preCode is COMP1022P
 * @param head pointing to the head of the linked list
 * @param targetCode stores the course code of the target
 * @param preCode stores the course code of the pre-requisite 
 * @return true if the insertion is complete. false otherwise
*/
bool ll_insert_prerequisite(Course* head, const char targetCode[MAX_CODE], const char preCode[MAX_CODE]);

/**
 * function ll_insert_exclusion inserts an exclusion
 * Example: if COMP2011 excludes COMP1022P, the targetCode is COMP2011 and the excludeCode is COMP1022P
 * @param head pointing to the head of the linked list
 * @param targetCode stores the course code of the target
 * @param excludeCode stores the course code to be excluded
 * @return true if the insertion is complete. false otherwise 
*/
bool ll_insert_exclusion(Course* head, const char targetCode[MAX_CODE], const char excludeCode[MAX_CODE]);

/**
 * function ll_delete_prerequisite deletes a pre-requisite
 * Example: Given the input, if there is a pre-requisite, the pre-requisite will be deleted
 * @param head pointing to the head of the linked list
 * @param targetCode stores the course code of the target
 * @param preCode stores the course code of pre-requisite
 * @return true if the deletion is complete. false otherwise
*/
bool ll_delete_prerequisite(Course* head, const char targetCode[MAX_CODE], const char preCode[MAX_CODE]);

/**
 * function ll_delete_exclusion deletes an exclusion
 * Example: Given the input, if there is an exclusion, the exclusion will be deleted
 * @param head pointing to the head of the linked list
 * @param targetCode stores the course code of the target
 * @param excludeCode stores the course code of exclusion
 * @return true if the deletion is complete. false otherwise 
*/
bool ll_delete_exclusion(Course* head, const char targetCode[MAX_CODE], const char excludeCode[MAX_CODE]);

/**
 * function ll_insert_course inserts a course
 * Note: head is passed by reference because head may be changed during the insertion
 * @param head pointing to the head of the linked list
 * @param c is the course code 
 * @param t is the course title
 * @param cred is the course credit
 * @return true if the insertion is complete. false otherwise
*/
bool ll_insert_course(Course* &head, const char c[MAX_CODE], const char t[MAX_TITLE], int cred);

/**
 * function ll_delete_course deletes an existing course
 * Note: head is passed by reference because head may be changed during the deletion
 * @param head pointing to the head of the linked list
 * @param c is the course code
 * @return true if the deletion is complete. false otherwise
*/
bool ll_delete_course(Course* &head, const char c[MAX_CODE]);

/**
 * function ll_modify_course_title modifies the course title attribute of a course
 * @param head pointing to the head of the linked list
 * @param c is the course code
 * @param t is the new course title
 * @return true if the modification is complete. false otherwise 
*/
bool ll_modify_course_title(Course* head, const char c[MAX_CODE], const char t[MAX_TITLE]);

/**
 * function ll_modify_course_credit modifies the course credit attribute of a course
 * @param head pointing to the head of the linked list
 * @param c is the course code
 * @param cred is the new credit
 * @return true if the modification is complete. false otherwise
*/
bool ll_modify_course_credit(Course* head, const char c[MAX_CODE], int cred);



/**
 * function ll_cleanup_all cleans up the linked lists used in the system. It restores the original states (i.e., empty linked lists) of the system. 
 * No memory leak should be found after the clean up
 * Note: head is passed by reference because head may be changed during the clean up
 * @param head pointing to the head of the linked list
*/
void ll_cleanup_all(Course* &head);

// === Region: The main() function ===
// The main function is given
// DO NOT MODIFY anything inside the main() function
// ===================================

/**
 * function enter_credit: A helper function to enter a valid credit
 * ensure the credit is a non-negative integer
*/
int enter_credit() {
    int credit;
    while (true) {
        cout << "Enter the credit: " ;
        cin >> credit;
        if ( credit >= 0 )
            return credit;
        cout << "Invalid credit: " << credit << endl;
    }
}

/**
 * function main - the main function
*/
int main() {
    Course *clist = nullptr;
    enum MeunOption {
        OPTION_DISPLAY_CURRENT_LIST = 0,
        OPTION_INSERT_COURSE,
        OPTION_INSERT_PRE_REQUISITE,
        OPTION_INSERT_EXCLUSION,
        OPTION_DELETE_COURSE,
        OPTION_DELETE_PRE_REQUISITE,
        OPTION_DELETE_EXCLUSION,
        OPTION_MODIFY_COURSE_TITLE,
        OPTION_MODIFY_COURSE_CREDIT,
        OPTION_EXIT_WITHOUT_CLEANUP,
        OPTION_EXIT_WITH_CLEANUP, 
        MAX_MENU_OPTIONS
    };
    const int MAX_MENU_OPTIONS_LENGTH = 50;
    char menuOptions[MAX_MENU_OPTIONS][MAX_MENU_OPTIONS_LENGTH] = {
        "Display the current list",
        "Insert a new course",
        "Insert a pre-requisite",
        "Insert an exclusion",
        "Delete an existing course",
        "Delete an existing pre-requisite",
        "Delete an existing exclusion",
        "Modify a course title",
        "Modify a course credit",
        "Exit without clean up",
        "Exit with clean up"
    };
    
    int option = 0;
    int i = 0;
    int credit = 0;
    // It is tricky to check the input character array, write assumptions that we don't need to check
    char code[MAX_CODE] = ""; 
    char title[MAX_TITLE] = "" ;
    char targetCode[MAX_CODE] = "";
   
    bool ret = false;
    
    while (true) {
        cout << "=== Menu ===" << endl;
        for (i=0; i<MAX_MENU_OPTIONS; i++) 
            cout << i+1 << ": " << menuOptions[i] << endl; // shift by +1 when display

        cout << "Enter your option: ";
        cin >> option;

        option = option - 1; // shift by -1 after entering the option

        // The invalid menu option handling
        if ( option < 0 || option >= MAX_MENU_OPTIONS ) {
            cout << "Invalid option" << endl;
            continue;
        }

        // Exit operations handling
        if (option == OPTION_EXIT_WITHOUT_CLEANUP)
            break; // break the while loop
        else if (option == OPTION_EXIT_WITH_CLEANUP) {
            cout << "=== Cleanup ===" << endl;
            ll_cleanup_all(clist);
            ll_print_all(clist);
            break; //  break the while loop
        }
        
        switch (option) {
            case OPTION_DISPLAY_CURRENT_LIST:
                ll_print_all(clist);
                break;
            case OPTION_INSERT_COURSE:
                cout << "Enter a course code: ";
                cin >> code;
                cout << "Enter a course title: ";
                cin.ignore(); // necessary when mixing cin>> and cin.getline
                cin.getline(title, MAX_TITLE);
                credit = enter_credit();
                ret = ll_insert_course(clist, code, title, credit);
                if ( ret == false ) {
                     cout << "Failed to insert " << code << endl ;
                }
                else {
                    cout << code << " is successfully inserted" << endl ;
                    ll_print_all(clist);
                }
                break;
            case OPTION_INSERT_PRE_REQUISITE:
                cout << "Enter the target course code: ";
                cin >> targetCode;
                cout << "Enter the pre-requisite course code: ";
                cin >> code;
                if ( strcmp(targetCode, code) == 0) {
                    cout << "Cannot insert a pre-requisite to the same course " << code << endl;
                } else {
                    ret = ll_insert_prerequisite(clist, targetCode, code);
                    if ( ret == false ) {
                        cout << "Failed to insert pre-requisite " << targetCode << ", " << code << endl;
                    } else {
                        cout << "Inserted a pre-requisite " << targetCode << ", " << code << endl;
                        ll_print_all(clist);
                    }
                }
                break;
            case OPTION_INSERT_EXCLUSION:
                cout << "Enter the target course code: ";
                cin >> targetCode;
                cout << "Enter the exclusion course code: ";
                cin >> code;
                if ( strcmp(targetCode, code) == 0) {
                    cout << "Cannot insert an exclusion to the same course " << code << endl;
                } else {
                    ret = ll_insert_exclusion(clist, targetCode, code);
                    if ( ret == false ) {
                        cout << "Failed to insert exclusion " << targetCode << ", " << code << endl;
                    } else {
                        cout << "Inserted an exclusion " << targetCode << ", " << code << endl;
                        ll_print_all(clist);
                    }
                }
                break;
            case OPTION_DELETE_COURSE:
                cout << "Enter the course code: ";
                cin >> code ;
                ret = ll_delete_course(clist, code);
                if ( ret == false ) {
                    cout << "Failed to delete course " << code << endl;
                } else {
                    cout << "Deleted a course " << code << endl ;
                    ll_print_all(clist);
                }
                break;
            case OPTION_DELETE_PRE_REQUISITE:
                 cout << "Enter the target course code: ";
                cin >> targetCode;
                cout << "Enter the pre-requisite course code: ";
                cin >> code;
                ret = ll_delete_prerequisite(clist, targetCode, code);
                if ( ret == false ) {
                    cout << "Failed to delete pre-requisite " << targetCode << ", " << code << endl;
                } else {
                    cout << "Deleted a pre-requisite " << targetCode << ", " << code << endl;
                    ll_print_all(clist);
                }
                break;
            case OPTION_DELETE_EXCLUSION:
                cout << "Enter the target course code: ";
                cin >> targetCode;
                cout << "Enter the pre-requisite course code: ";
                cin >> code;
                ret = ll_delete_exclusion(clist, targetCode, code);
                if ( ret == false ) {
                    cout << "Failed to delete exclusion " << targetCode << ", " << code << endl;
                } else {
                    cout << "Deleted an exclusion " << targetCode << ", " << code << endl;
                    ll_print_all(clist);
                }
                break;
            case OPTION_MODIFY_COURSE_TITLE:
                cout << "Enter the course code: ";
                cin >> code;
                cout << "Enter the new course title: " ;
                cin.ignore();
                cin.getline(title, MAX_TITLE);
                ret = ll_modify_course_title(clist, code, title);
                if ( ret == false ) {
                    cout << "Failed to modify the course title of " << code << endl ;
                } else {
                    cout << "The course title of " << code << " is modified" << endl ;
                    ll_print_all(clist);
                }
                break;
            case OPTION_MODIFY_COURSE_CREDIT:
                cout << "Enter the course code: ";
                cin >> code ;
                credit = enter_credit();
                ret = ll_modify_course_credit(clist, code, credit);
                if ( ret == false ) {
                    cout << "Failed to modify the course credit of " << code << endl;
                } else {
                    cout << "The course credit of " << code << " is modified" << endl;
                    ll_print_all(clist);
                }
                break;
                
        } // end switch

    } // end while true
    return 0;
}


// === Region: function definitions ===
// You should implement the functions below
// ====================================


// This function is given
// DO NOT MODIFY THIS FUNCTION
// Otherwise, you may not be able to pass the ZINC test cases
void ll_print_all(const Course* head) {
    const Course *p;
    const CourseItem *q;
    int count;

    cout << "=== Course List (Code[Credits]) ===" << endl;
    count = 0;
    for (p = head; p!= nullptr; p = p->next) {
        cout << p->code << "[" << p->credit << "]" ;
        if ( p->next != nullptr )
            cout << " -> ";
        count++;
    }
    if ( count == 0 ) {
        cout << "No courses in the list";
    }
    cout << endl;

    cout << "=== Course titles ===" << endl ;
    count = 0;
    for (p = head; p!= nullptr; p = p->next) {
        cout << p->code << ": " << p->title << endl ;
        count++;
    }
    if ( count == 0 ) {
        cout << "No course titles" << endl;
    }

    cout << "=== Pre-requisites ===" << endl ;
    count = 0;
    for (p = head; p!= nullptr; p = p->next) {
        q = p->prerequisites;
        if ( q != nullptr ) {
            cout << p->code << ": ";
            for ( ; q != nullptr; q = q->next ) {
                cout << q->course->code ;
                if ( q->next != nullptr )
                    cout << ", " ;
            }
            count++;
            cout << endl;
        }
    }
    if ( count == 0 ) {
        cout << "No pre-requisites" << endl;
    }

    cout << "=== Exclusions ===" << endl ;
    count = 0;
    for (p = head; p!= nullptr; p = p->next) {
        q = p->exclusions;
        if ( q != nullptr ) {
            cout << p->code << ": ";
            for ( ; q != nullptr; q = q->next ) {
                cout << q->course->code ;
                if ( q->next != nullptr )
                    cout << ", " ;
            }
            count++;
            cout << endl;
        }
    }
    if ( count == 0 ) {
        cout << "No pre-exclusions" << endl;
    }

}



bool ll_insert_prerequisite(Course* head, const char targetCode[MAX_CODE], const char preCode[MAX_CODE]) {//COMP2011: COMP1022P
    
    //inserting COMP1022P to COMP2011
    //then inserting COMP1021 to COMP2011
    //COMP1022P disappears from prereq list of COMP2011



    // TODO: Implementation of inserting a pre-requisite

    //targetCode DNE OR preCode DNE (OR preCode > targetCode)NO SUCH RESTRICTION
/*     if (strcmp(preCode, targetCode) > 0)
        return false; */

    bool target = ll_check_DNE(head, targetCode);
    bool pre = ll_check_DNE(head, preCode);

    if (strcmp(targetCode, preCode) == 0)//exclude self-prereq
        return false;

    if ((target == false) || (pre == false))
        return false;

    //targetCode AND preCode EXIST
    Course* targetCourse = head;
    Course* AddPreqCourse = head;


    while(true)//getting address of target
    {
        if (strcmp(targetCode, targetCourse->code) == 0)
            {
                break;
            }

        targetCourse = targetCourse->next; 
    }

    for(CourseItem* target_prereq = targetCourse->prerequisites; target_prereq != nullptr;)//check for duplicate prerequisite==failed
    {   
        if (strcmp(target_prereq->course->code, preCode) == 0)
            return false;


        target_prereq = target_prereq->next;
    }

    while(true)//getting address of pre-requisite
    {
        if (strcmp(preCode, AddPreqCourse->code) == 0)
            {
                break;
            }

        AddPreqCourse = AddPreqCourse->next; 
    }

    //Insertion

    CourseItem* new_prereq = ll_createItem(nullptr, nullptr);

    new_prereq->course = AddPreqCourse;

    if (targetCourse->prerequisites == nullptr)//empty prereq list
        {
            targetCourse->prerequisites = new_prereq;
            new_prereq->course = AddPreqCourse;
            new_prereq->next = nullptr;
            return true;
        }
    
    else //non-empty prereq list            has bug
        {
            //non-empty prereq list sorted by course code

            if (strcmp(preCode, targetCourse->prerequisites->course->code) < 0)//smallest
                {
                    new_prereq->next = targetCourse->prerequisites/* ->next */;//COMP1021 -> COMP1022P
                    targetCourse->prerequisites = new_prereq;//COMP2011 prereq -> COMP1021
                    return true;
                }

            CourseItem* last_prereq = targetCourse->prerequisites;
            for (; last_prereq->next != nullptr;)
                last_prereq = last_prereq->next;


            if (strcmp(preCode,last_prereq->course->code) > 0)//largest
                {
                    last_prereq->next = new_prereq;
                    new_prereq->next = nullptr;
                    return true;
                }


            for (CourseItem* course_ptr = targetCourse->prerequisites; course_ptr->next != nullptr;)
            {   // 1st < insertion < next
                if (strcmp(preCode, course_ptr->course->code) > 0 && strcmp(preCode, course_ptr->next->course->code) < 0)
                    {//strcmp(a,b) > 0 == a > b
                        new_prereq->next = course_ptr->next;
                        course_ptr->next = new_prereq;
                        break;
                    }
        
                course_ptr = course_ptr->next;
            }  

            return true;
        
        }
    






    //return true;
}

bool ll_insert_exclusion(Course* head, const char targetCode[MAX_CODE], const char excludeCode[MAX_CODE]) {//not OK seg fault
    
    // TODO: Implementation of inserting an exclusion

    //targetCode DNE OR exclCode DNE
    bool target = ll_check_DNE(head, targetCode);
    bool exc = ll_check_DNE(head, excludeCode);

    if (strcmp(targetCode, excludeCode) == 0)
        return false;

    if ((target == false) || (exc == false))
        return false;

    

    //targetCode AND exclCode EXIST
    Course* targetCourse = head;
    Course* AddExclCourse = head;
//    CourseItem* new_exclu = ll_createItem(nullptr, nullptr);

    while(true)//getting address of target
    {
        if (strcmp(targetCode, targetCourse->code) == 0)
            {
                break;
            }

        targetCourse = targetCourse->next; 
    }

    for(CourseItem* target_excl = targetCourse->exclusions; target_excl != nullptr;)//check duplicate exclusion
    {   
        if (strcmp(target_excl->course->code, excludeCode) == 0)
            return false;


        target_excl = target_excl->next;
    }

    while(true)//getting address of exclusion
    {
        if (strcmp(excludeCode, AddExclCourse->code) == 0)
            {
                break;
            }

        AddExclCourse = AddExclCourse->next; 
    }

    //Insertion

    CourseItem* new_exclu = ll_createItem(nullptr, nullptr);

    new_exclu->course = AddExclCourse;

    if (targetCourse->exclusions == nullptr)//empty exclu list
        {
            targetCourse->exclusions = new_exclu;
            new_exclu->course = AddExclCourse;
            new_exclu->next = nullptr;
            return true;
        }
    
    else //non-empty exclu list
        {
            //non-empty exclu list sorted by course code

            if (strcmp(excludeCode, targetCourse->exclusions->course->code) < 0)//smallest
                {
                    new_exclu->next = targetCourse->exclusions/* ->next */;
                    targetCourse->exclusions = new_exclu;
                    return true;
                }

            CourseItem* last_exclu = targetCourse->exclusions;
            for (; last_exclu->next != nullptr;)
                last_exclu = last_exclu->next;


            if (strcmp(excludeCode,last_exclu->course->code) > 0)//largest
                {
                    last_exclu->next = new_exclu;
                    new_exclu->next = nullptr;
                    return true;
                }


            for (CourseItem* course_ptr = targetCourse->exclusions; course_ptr->next != nullptr;)//important for course_ptr->next != nullptr;
            {   // 1st < insertion < next
                if (strcmp(excludeCode, course_ptr->course->code) > 0 && strcmp(excludeCode, course_ptr->next->course->code) < 0)
                    {//strcmp(a,b) > 0 == a > b
                        new_exclu->next = course_ptr->next;
                        course_ptr->next = new_exclu;
                        break;
                    }
        
                course_ptr = course_ptr->next;
            }  

            return true;
        
        }
    






    //return true;
}

bool ll_delete_prerequisite(Course* head, const char targetCode[MAX_CODE], const char preCode[MAX_CODE]) {//hard
    
    // TODO: Implementation of deleting a pre-requisite

    //targetCode DNE OR preCode DNE

    bool target = ll_check_DNE(head, targetCode);
    bool pre = ll_check_DNE(head, preCode);

    if (strcmp(targetCode, preCode) == 0)
        return false;

    if ((target == false) || (pre == false))//course list DNE
        return false;    


    //targetCode AND preCode EXIST

    //search for target course first
    Course* temp_ptr = nullptr;
    Course* course_ptr = head;
    while((course_ptr != nullptr) && (strcmp(course_ptr->code, targetCode) != 0))
        course_ptr = course_ptr->next;

   

    //CourseItem* tempitem_ptr = nullptr;

    //search for prerequisite now
    CourseItem* item_ptr = course_ptr->prerequisites;
    CourseItem* previous_ptr = nullptr;

    while ((item_ptr != nullptr)  && (strcmp(item_ptr->course->code, preCode) != 0))//no seg fault
    {
        /* if (strcmp(item_ptr->course->code, preCode) == 0)
            break; */
        previous_ptr = item_ptr;
        item_ptr = item_ptr->next;
    }

    if (item_ptr == nullptr)//empty list or prereq list DNE
        return false;

    if (item_ptr == course_ptr->prerequisites)//1st 
    {
        course_ptr->prerequisites = course_ptr->prerequisites->next;
        delete item_ptr;
        return true;
    }
    else if (item_ptr != course_ptr->prerequisites)//2nd,...,last
    {
        previous_ptr->next = item_ptr->next;//segmentation fault, deleting a non-existent prereq from prereq list of COMP2011, fixed
        delete item_ptr;
        return true;
    }

    

}

bool ll_delete_exclusion(Course* head, const char targetCode[MAX_CODE], const char excludeCode[MAX_CODE]) {//hard
    
    // TODO: Implementation of deleting an exclusion

    //targetCode DNE OR excluCode DNE
    bool target = ll_check_DNE(head, targetCode);
    bool exc = ll_check_DNE(head, excludeCode);

    if (strcmp(targetCode, excludeCode) == 0)
        return false;

    if ((target == false) || (exc == false))
        return false;   


    //targetCode AND excluCode EXIST

    //search for target course first
    Course* temp_ptr = nullptr;
    Course* course_ptr = head;

    while((course_ptr != nullptr)  && (strcmp(course_ptr->code, targetCode) != 0) )//seg fault?
    {
       /*  if (strcmp(course_ptr->code, targetCode) == 0)
            break; */
        course_ptr = course_ptr->next;
    }
        

   

    //CourseItem* tempitem_ptr = nullptr;

    //search for exclusion now
    CourseItem* item_ptr = course_ptr->exclusions;      //course_ptr = 1021, exclusions = 1022P
    CourseItem* previous_ptr = nullptr;                 //= nullptr

    //if exclusion = nullptr, idk
    //if exclusion at 1st, ok
    //if exclusion at last, ok
    //if exclusion at mid, ok

    while ((item_ptr != nullptr)  && (strcmp(item_ptr->course->code, excludeCode) != 0))
    //segmentation fault, 
    {//if item_ptr = nullptr, strcmp(points to non-existent code)
        /* if (strcmp(item_ptr->course->code, excludeCode) == 0)
            break; */
        previous_ptr = item_ptr;// = nullptr
        item_ptr = item_ptr->next;
    }

    if (item_ptr == nullptr)//empty list or DNE in exclu list
        return false;

    if (item_ptr == course_ptr->exclusions)//1st 
    {
        course_ptr->exclusions = item_ptr->next;
        delete item_ptr;
        return true;
    }
    else if (item_ptr != course_ptr->exclusions)//2nd,...,last 
    {
        previous_ptr->next = item_ptr->next;//seg fault fixed by item_ptr == nullptr
        delete item_ptr;
        return true;
    }



}

bool ll_insert_course(Course*& head, const char c[MAX_CODE], const char t[MAX_TITLE], int cred) {//ok? strcmp() problem in Piazza

    // TODO: Implementation of inserting a course
    //    if (new_code == course_ptr->code)// comparison does not work
    //        return false;



    //checking uniqueness of code
    for (Course* course_ptr = head; course_ptr != nullptr;)
    {
        if (strcmp(c, course_ptr->code) == 0)//same code
            return false;
    
        course_ptr = course_ptr->next;
    }

/*     Course* new_course = new Course;

    //new_course->code 
    strcpy(new_course->code, c);
     for (int i=0; i < strlen(c); i++)
    {
        new_course->code[i] = c[i];
    }

        new_course->code[strlen(c)] = '\0'; 

    //new_course->title 
    strcpy(new_course->title, t);
     for (int i=0; i < strlen(t); i++)
    {
        new_course->title[i] = t[i];
    }

        new_course->title[strlen(t)] = '\0'; 

    new_course->credit = cred;

    new_course->exclusions = nullptr;

    new_course->prerequisites = nullptr; */

    Course* new_course = ll_createCourse(c, t, cred, nullptr, nullptr, nullptr);



    //finding the right location to insert node 
    if (head == nullptr)//empty list
        {
            head = new_course;
            return true;
        }

    
    //non-empty list
    if (strcmp(c, head->code) < 0)//smallest
        {
            //Course* temp = head;
            new_course->next = head;
            head = new_course;
            return true;
        }

    Course* last_course = head;
    for (; last_course->next != nullptr;)
        last_course = last_course->next;


    if (strcmp(c,last_course->code) > 0)//largest
        {
            last_course->next = new_course;
            new_course->next = nullptr;
            return true;
        }
    
    for (Course* course_ptr = head; course_ptr->next != nullptr;)//non-empty list
    {   // 1st < insertion < next
        if (strcmp(c, course_ptr->code) > 0 && strcmp(c, course_ptr->next->code) < 0)//strcmp(a,b) > 0 == a > b
            {
                new_course->next = course_ptr->next;
                course_ptr->next = new_course;
                return true;
            }
        
        course_ptr = course_ptr->next;
    }  
               

    
    //head->next = new_course; -> segmentation fault
    //return true;
}


bool ll_delete_course(Course*& head, const char c[MAX_CODE]) {//how to deal with exclusion and prerequisite?

    // TODO: Implementation of deleting a course

    bool del = ll_check_DNE(head, c);

    if (del == false)//c DNE in list
        return false;
    
    if (head == nullptr)//empty list
        return false;


    //non-empty list
    Course* course_ptr = head;
    Course* previous_ptr = nullptr;

    while ((course_ptr != nullptr) && (strcmp(course_ptr->code, c) != 0))
    {
        previous_ptr = course_ptr;
        course_ptr = course_ptr->next;
    }


    //check each course from head
        //check each prereq
        //check each exclus

    //segmentation fault

    for(Course* ptr = head; ptr != nullptr;)
    {
        if (ptr->prerequisites != nullptr)
        {   
            ll_delete_prerequisite(head, ptr->code, c);//seg fault
        }


        if (ptr->exclusions != nullptr)
        {
            ll_delete_exclusion(head, ptr->code, c);//seg fault
        }

        ptr = ptr->next;
    }


    if (course_ptr->prerequisites != nullptr)//delete prereq
    {
        CourseItem* temp_ptr2 = nullptr;

        for (CourseItem* prereq_ptr=course_ptr->prerequisites; prereq_ptr != nullptr;)
        {
            temp_ptr2 = prereq_ptr->next;
            delete prereq_ptr;
            prereq_ptr = temp_ptr2;

            //prereq_ptr = prereq_ptr->next;
        }        
    }


    if  (course_ptr->exclusions != nullptr)//delete exclu
    {
        CourseItem* temp_ptr3 = nullptr;

        for (CourseItem* exclu_ptr=course_ptr->exclusions; exclu_ptr != nullptr;)
        {
            temp_ptr3 = exclu_ptr->next;
            delete exclu_ptr;
            exclu_ptr = temp_ptr3;

            //exclu_ptr = exclu_ptr->next;
        }        
    }


    //option 4: double insertion of exclusion and prereq not handled



    if (course_ptr == head)//delete 1st node
    {
        head = course_ptr->next;
        delete course_ptr;
        return true;

    }
    else
    {//2nd,...,last node

        previous_ptr->next = course_ptr->next;
        delete course_ptr;
        return true;

    }

    
}


bool ll_modify_course_title(Course* head, const char c[MAX_CODE], const char t[MAX_TITLE]) {//ok
    
    // TODO: Implementation of modifying a course title
    //head = head of the linked list

    for (Course* course_ptr = head; course_ptr != nullptr;)
    {
        if (strcmp(c, course_ptr->code) == 0)
        {
            strcpy(course_ptr->title, t);       //address = address, doing actual pointing work, thus it is wrong
            return true;
        }

        course_ptr = course_ptr->next;
    }


    return false;
}


bool ll_modify_course_credit(Course* head, const char c[MAX_CODE], int cred) {//ok
    
    // TODO: Implementation of modifying a course credit

    for (Course* course_ptr = head; course_ptr != nullptr;)
    {
        if (strcmp(c, course_ptr->code) == 0)
        {
            course_ptr->credit = cred;
            return true;
        }        
    
        course_ptr = course_ptr->next;
    }

    return false;
}



void ll_cleanup_all(Course *&head) {//not sure, memory leak,etc.
    
    // TODO: Implementation of clean up all
    Course* temp_ptr = nullptr;
    for (Course* course_ptr=head; course_ptr != nullptr;)
    {
        if (course_ptr->prerequisites != nullptr)//clean up prerequisite for this course
        {
            CourseItem* temp_ptr2 = nullptr;

            for (CourseItem* prereq_ptr=course_ptr->prerequisites; prereq_ptr != nullptr;)
            {
                temp_ptr2 = prereq_ptr->next;
                delete prereq_ptr;
                prereq_ptr = temp_ptr2;

                //prereq_ptr = prereq_ptr->next;
            }

        }

        if (course_ptr->exclusions != nullptr)//clean up exclusion for this course
        {
            CourseItem* temp_ptr3 = nullptr;

            for (CourseItem* exclu_ptr=course_ptr->exclusions; exclu_ptr != nullptr;)
            {
                temp_ptr3 = exclu_ptr->next;
                delete exclu_ptr;
                exclu_ptr = temp_ptr3;

                //exclu_ptr = exclu_ptr->next;
            }

        }


        temp_ptr = course_ptr->next;
        delete course_ptr;
        course_ptr = temp_ptr;
    }

    head = nullptr;


    return;
}
