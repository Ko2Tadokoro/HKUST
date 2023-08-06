#include <iostream>
#include <ctime>
using namespace std;

/* -------------------------------------------------------------- */
/* This part serves as a pseudo random number generator for auto grade purpose only */
/* You are suggested not to refer to these codes in this assignment. */
/* You are not allowed to use global variables in this course. */
unsigned int next_num = 1; // Here we initiate an unsigned integer to be used in the following functions.

unsigned int pa1_rand() // This function is used to return a pseudo random number from 0 to 32767.
{
    next_num = next_num * 1103515245 + 2011;
    return static_cast<unsigned int>(next_num / 65536) % 32768;
}
void pa1_srand(unsigned int seed) // This function is used to set a seed of the pseudo random number generator.
{
    next_num = seed;
}
/* Everytime you call pa1_rand(), you will get a new pseudo random number. For the same seed, the sequence of pseudo 
   random number is fixed. For example, when seed = 3, the sequence of pseudo random number is fixed to be [17746, 
   30897, 9622, 18921, 4034, 17510, 24152, 14388, 23665, 31532, ...]. When seed = 5, the sequence of pseudo random 
   number is fixed to be [18655, 32247, 9873, 9718, 26373, 27678, 5314, 22512, 31845, 22885, ...] */
/* -------------------------------------------------------------- */



const int MAX_BOXES = 1000; // This constant stores the largest length of boxes[]. You can use it in your code.

// This function is used to fill the 1D array with a random sequence of unique numbers from 1 to the user input for the number of prisoners
void placeSlips(int boxes[], int num_prisoners)
{
    for (int i = 0; i < num_prisoners; i++)         //num_prisoners == 500
        boxes[i] = -1;                              //boxes[0,1,2,3,...,499] == -1
    int counter = 0;
    while (counter < num_prisoners)
    {
        int num = pa1_rand() % (num_prisoners);
        if (boxes[num] == -1)                       //boxes[0]
        {
            boxes[num] = counter;
            counter++;
        }
    }
}

// TASK 1: Simulate an actual riddle room
bool simulateRoom(const int boxes[], int num_prisoners, int num_trials)         //should be done 3 cases checked, have both failure and success
{
    
    /* Please replace this to your own code below */
    for (int i = 0; i < num_prisoners; i++)
    {           //prisoner with his number chooses his box          //there is 0 inside a box, which means it is counting from 0 to 99 for 100 boxes
        int c = 0;
        int temp = i;                                                  //100 prisoners, 100 trials, -> failure, bug
        while ( c < num_trials)
        {
                                                                   //int temp = i; initialize inside c loop, g
            if (i != boxes[temp])
            {
                temp =boxes[temp];
            }
            else if (i == boxes[temp])
            break;


        c++;
        }

        if (c == num_trials)
        return false;
    }


    return true;
}

// TASK 2: Display certain statistics for a given room
void statsRoom(const int boxes[], int num_prisoners, int num_trials)
{
    /* Here in this task, we provide some lines of code for your reference. Please write your code below and replace some of the given code */


                                    // total loops: C(num_)

int num_success_prisoners = 0;
int num_loops = 0;
int smallest_loop_length = 0;
int longest_loop_length = 0;

int* array1 = new int[num_prisoners]{1001};         //largest_loop
int array1_length = 0;

int* array2 = new int [num_prisoners]{1001};        //marker
int array2_length = 0;

int* array3 = new int [num_prisoners]{1001};        //total checked numbers
int array3_length = 0;

    int* loop_length_for_all_prisoners = new int[num_prisoners]{1001};


    int ll2 = 0;
    int iii = 0;
    int i_in_array3 = false;

    array1[0]=0;
    array3[0]=0;
    ll2++;

        int temp1 = 0;
        while (iii != boxes[temp1])          // array1 get
        {

           array1[ll2] = boxes[temp1];
           array3[ll2] = boxes[temp1];

            if (iii != boxes[temp1])           //keep circulating
            {
                temp1 = boxes[temp1];
            }
            else if (iii == boxes[temp1])      //stop circulating
            break;

        ll2++;
        }//array has elements now

        array1_length = ll2;
        array3_length = array1_length;
        num_loops++;

//       cout << num_loops << " num_loops " << array3_length << " array3_length " << array1_length << " array1_length " << endl;//1st





        for (int i = 0; i < num_prisoners; i++)     //number of boxes = num_prisoners
    {           //prisoner with his number chooses his box          //there is 0 inside a box, which means it is counting from 0 to 99 for 100 boxes
        int large_loop_length = 0;                  //for i =1
        int temp = i;                               //temp = 1;

        for (int count = 0; count < array3_length; count++)
        {
            if ( i == array3[count])
            {   
                i_in_array3 = true;
                break;
            }

        }

        /* cout << num_loops << " num_loops " << array3_length << " array3_length " << array1_length << " array1_length " << array2_length << " array2_length " << endl; *///2nd, 3rd

        if (i_in_array3)
        {
            i_in_array3 = false; 
            continue;
        }
    
        array2[large_loop_length] = i;                              //at this moment, large_loop_length = 0; i = 1;
        array3[array3_length] = array2[large_loop_length];        //array3[6+1]= 1, incorrect -> [6]
        array3_length++;

        /* cout << num_loops << " num_loops " << array3_length << " array3_length " << array1_length << " array1_length " << array2_length << " array2_length " << endl;//4rd

        cout << i << " i | loop length " << large_loop_length <<endl; */           //no display of i = 0; gd continue


        large_loop_length++;                                        //after this line, large_loop_length = 1;

        while ( i != boxes[temp] )           //c < num_trials -> //i != boxes[temp] , trials no longer matter
        {         
            array2[large_loop_length] = boxes[temp];
            array3[array3_length] = array2[large_loop_length];
            array3_length++;
                                                                /* cout << "array3 ";
                                                                 for (int count5 = 0; count5 < array3_length; count5++)//array3_length = 8 here
                                                                {
                                                                    cout << array3[count5] << '\t';
                                                                }

                                                                cout << endl;  */

            if (i != boxes[temp])           //keep circulating
            {
                temp = boxes[temp];
            }
            else if (i == boxes[temp])      //stop circulating
            break;

        large_loop_length++;
        }//array has elements now

        array2_length = large_loop_length;

        num_loops++;
                                                               /*  cout << "before amendment array1 ";
                                                                for (int count56 = 0; count56 < array1_length; count56++)//
                                                                {
                                                                    cout << array1[count56] << '\t';
                                                                }

                                                                cout << endl;

                                                                cout << "before amendment array2 ";
                                                                for (int count56 = 0; count56 < array2_length; count56++)//
                                                                {
                                                                    cout << array2[count56] << '\t';
                                                                }

                                                                cout << endl; */

         if (array2_length > array1_length)
        {
            for (int count3 = 0; count3 < array2_length; count3++)
            {
                /* cout << "changing " << array1[count3] << " to " << array2[count3] << '\t'; */
                array1[count3] = array2[count3];
            }

            array1_length = array2_length;

            /* cout << endl; */
        } 
                                                                         /* cout << "after amendment array1 ";
                                                                         for (int count56 = 0; count56 < array1_length; count56++)//
                                                                {
                                                                    cout << array1[count56] << '\t';
                                                                }

                                                                cout << endl;  */

/*         cout << large_loop_length << " large_loop_length" <<endl;
        loop_length_for_all_prisoners[i] = large_loop_length;  */            //all loop length acquired, however without now

    }






    //construct a new loop for statsRoom instead of calling simulate: num_success_prisoners
    //a new loop for: longest_loop_length

        for (int i = 0; i < num_prisoners; i++)     //number of boxes = num_prisoners
    {           //prisoner with his number chooses his box          //there is 0 inside a box, which means it is counting from 0 to 99 for 100 boxes
        int loop_length = 0;
        int temp = i;

//        cout << i << " i | loop length " << loop_length <<endl;
        loop_length++;

        while ( i != boxes[temp] )           //c < num_trials -> //i != boxes[temp] , trials no longer matter
        {         

            if (i != boxes[temp])           //keep circulating
            {
                temp = boxes[temp];
            }
            else if (i == boxes[temp])      //stop circulating
            break;

        loop_length++;
        }//array has elements now

        if (loop_length <= num_trials)
            num_success_prisoners++;

        if (loop_length > num_prisoners/2)
        {
            longest_loop_length = loop_length;
        }//cannot break here otherwise num_loop not counted


//         cout << loop_length << " loop_length" <<endl;
        loop_length_for_all_prisoners[i] = loop_length;              //all loop length acquired, however with overcounting

    }

/*     cout << "before bubble sort" << endl;
    for (int ii = 0; ii < num_prisoners; ii++)
    cout << loop_length_for_all_prisoners[ii] << '\t';

    cout <<endl; */


    //finding shortest_loop_length
    for (int a = 0; a < num_prisoners-1; a++)
    {
        for (int b = 0; b < num_prisoners-a-1; b++)
        {
            if (loop_length_for_all_prisoners[b] > loop_length_for_all_prisoners[b+1])
                swap(loop_length_for_all_prisoners[b],loop_length_for_all_prisoners[b+1]);
        }
    }

    smallest_loop_length = loop_length_for_all_prisoners[0];

/*     cout << "after bubble sort " << endl;
    for (int ii = 0; ii < num_prisoners; ii++)
    cout << loop_length_for_all_prisoners[ii] << '\t';

    cout <<endl; */


    cout << "The number of prisoners who find their slips: " << num_success_prisoners <<endl;       //ok
    cout << "Number of loops: " << num_loops <<endl;
    cout << "Smallest loop length: " << smallest_loop_length <<endl;        //ok
    cout << "Longest loop length: " << longest_loop_length <<endl;          //ok
    cout << "Largest loop: ";

    for (int count2 = 0; count2 < array1_length; count2++)
    {
        cout << array1[count2] << ' ';
    }

    //for num_loops, largest loop

    int pointer = 0;

    array1 = nullptr;
    delete[] array1;

    array2 = nullptr;
    delete[] array2;

    array3 = nullptr;
    delete[] array3;

    loop_length_for_all_prisoners = nullptr;
    delete[] loop_length_for_all_prisoners;

    /* Please replace this to your own code */

    cout << endl;
}

// TASK 3: Find the number of instances in 1000 rooms when the prisoners will all be able to escape
double successRooms(int boxes[], int num_prisoners, int num_trials) //  suceess rate of 1000 rooms basically repeating it a 1000 times
{
    /* Please replace this to your own code below */
    int num_success = 0;
    for (int i = 0; i < 1000; i++)
    {
        placeSlips(boxes, num_prisoners);
        if (simulateRoom(boxes, num_prisoners, num_trials))
            num_success++;
    }



    return num_success;
}

// TASK 4: Nice guard will help the prisoners to successfully leave the room by breaking any loop which is greater than the number of trials
//         Return true if the intervention was applied, else return false
bool niceGuard(int boxes[], int num_prisoners, int num_trials)
{
    /* Please replace this to your own code below */

    int loop_length = 0;
    /* int smallest_start_of_longest_loop = 0; */



    if (simulateRoom(boxes, num_prisoners, num_trials))         //escape success
        return false;
    else                                                        //escape fails, need nice guard
    {
        int* largest_loop = new int[num_prisoners];
        /* int* original_largest_loop_box_index = new int[num_prisoners]; */
        
    for (int i = 0; i < num_prisoners; i++)     //number of boxes = num_prisoners
    {           
        loop_length = 0;
        int temp = i;
        largest_loop[loop_length] = i;
//                                            cout << "prisoner no. " << i << endl; 
        loop_length++;

        while ( i != boxes[temp] )          //i = 1st element of the loop, boxes[temp = i] = 1st
        {
            largest_loop[loop_length] = boxes[temp];        // l_l = 0 = 1st element    // l_l = 1 = 2nd element
//             cout << largest_loop[loop_length] << "largest_loop" << endl; 

                                                                  
            if (i != boxes[temp])           //keep circulating
            {
                
                temp = boxes[temp];         //temp = boxes[temp], boxes[temp] = 2nd element
                
            }
            else if (i == boxes[temp])      //stop circulating
            break;


        loop_length++;                                                          //l_l = 1, loop_length = the number of elements in largest_loop
        }
                                                                                 //suppose i = the number held by prisoner, 
                                                                                //= box number of the smallest start of the longest loop
        if (loop_length > num_prisoners/2)
            break;

    }//THE LOOP TO COPY LONGEST LOOP

//     cout << loop_length << " loop_length" << endl;           //gd

     //ORIGINAL LARGEST LOOP
/*     copy(largest_loop, largest_loop+loop_length, original_largest_loop_box_index);      //loop_length = size of largest_loop

    for (int c = 0; c < loop_length; c++)
    {
        cout << largest_loop[c] << '\t';
        cout << original_largest_loop_box_index[c] << '\t';
    }
    cout << endl;   */  
    
     //THE SWAPPING                                                     l_l = [0,99] for 100 elemnts
    /* swap(largest_loop[0],largest_loop[loop_length/2]); */                  //swap(0,49) = swap 1st and 51st elements = 51 elements
    //1 5 7 0 3 8 6                                                     //swap(49,99) = swap 51st and 100th elements = 51 elements
    //largest_loop[0], largest_loop[3]
                                                                        //swap(0,98/2=49) = swap 1st and 50th elements = 50 elements
                                                                        //swap(49,98) = swap 50th and 99th elements = 50 elements
/*      cout << "largest_loop |" << endl;
    for (int c = 0; c < loop_length; c++)
    {
        cout << largest_loop[c] << '\t';
        //cout << original_largest_loop_box_index[c] << '\t';
    }
    cout << endl;   */   

    //ok


    //PUTTING MODIFIED ARRAY BACK TO BOXES

    swap(boxes[largest_loop[0]],boxes[largest_loop[loop_length/2]]);
    //
    //1 5 7 0 3 8 6 == swap(boxes[1], boxes[0])
    //0 5 7 1 3 8 6 == swap(boxes[0], boxes[1])
    //              == swap(boxes[0], boxes[7])
     
/*     for (int c = 0; c < num_prisoners; c++)
    {
        cout << boxes[c] << '\t';
    }
    cout << endl; */


        largest_loop = nullptr;
        delete[] largest_loop;
/*         original_largest_loop_box_index = nullptr;
        delete[] original_largest_loop_box_index; */

        return true;
    }                                          





    //return false; skeleton code
}

// DO NOT WRITE ANYTHING AFTER THIS LINE. ANYTHING AFTER THIS LINE WILL BE REPLACED.

int main()
{

    int num_prisoners, num_trials, seed;
    // set boxes, priosoners

    cout << "Enter the number of prisoners (from 1 to 1000) :" << endl;
    cin >> num_prisoners;
    cout << "Enter the number of boxes each prisoner can open (from 1 to 1000) :" << endl;
    cin >> num_trials;
    cout << "Enter the seed for randomization else enter 0 and the system will randomize for you :" << endl;
    cin >> seed;

    if (seed == 0)
    {
        pa1_srand(time(NULL));
    }
    else
    {
        pa1_srand(seed);
    }

    int boxes[MAX_BOXES]; // array for the boxes
    for (int i = 0; i < MAX_BOXES; i++)
        boxes[i] = 0;

    int choice;
    cout << "Please choose an option:" << endl;
    cout << "0.Print the boxes" << endl;
    cout << "1.Simulate a room" << endl;
    cout << "2.Compute statistics of a room:" << endl;
    cout << "3.Compute success rate over 1000 rooms" << endl;
    cout << "4.Apply nice guard intervention in a room" << endl;
    cin >> choice;

    switch (choice)
    {
    case 0:
        placeSlips(boxes, num_prisoners);
        for (int i = 0; i < num_prisoners; i++)
            cout << boxes[i] << " ";
        cout << endl;
        break;
    case 1:
        placeSlips(boxes, num_prisoners);
        if (simulateRoom(boxes, num_prisoners, num_trials) == true)
        {
            cout << "Success! All prisoners found their slip." << endl;
        }
        else
        {
            cout << "Failure! Not all prisoners were able to find their slip." << endl;
        }
        break;
    case 2:
        placeSlips(boxes, num_prisoners);
        statsRoom(boxes, num_prisoners, num_trials);
        break;
    case 3:
    {

        double prisoners_left = successRooms(boxes, num_prisoners, num_trials);
        cout << "All prisoners were able to leave " << prisoners_left << "/1000 of the rooms." << endl;
    }
    break;
    case 4:
    {
        placeSlips(boxes, num_prisoners);
        int copy_arr[MAX_BOXES];
        for (int i = 0; i < num_prisoners; i++)
        {
            copy_arr[i] = boxes[i]; // copying the array for checking if no more than 2 swaps are made
        }

        bool nice_guard_val = niceGuard(boxes, num_prisoners, num_trials);

        int swap_count = 0;
        for (int j = 0; j < num_prisoners; j++)
        {
            if (copy_arr[j] != boxes[j])
            {
                swap_count++;
            }
        }
        if (swap_count > 2)
        {
            cout << "Illegal intervention as you have more than 1 swap " << endl;
        }
        else
        {
            if (nice_guard_val == false)
                cout << "No intervention needed." << endl;
            else
            {
                cout << "Intervention applied." << endl;
                // validity function
                bool prisoners_left = simulateRoom(boxes, num_prisoners, num_trials);
                // should return true
                if (prisoners_left == true)
                    cout << "All the prisoners were able to escape" << endl;
                else
                {
                    cout << "All the prisoners were not able to escape" << endl;
                }
            }
        }
    }
    break;
    }

    return 0;
}