// Create a class called "OpeningHours" with a "main" method.


import java.util.Scanner;
/*
 * Test your program after each step and not only when you have finished programming all tasks.
 * The aim of this task is to write a program that uses the opening hours of a shop to 
 * check whether the shop is open or closed at a specific time on a specific day. 
 * The class TimeTable , which saves the opening times for each day of the week (0 - Monday, 1 - Tuesday, ..., 6 - Sunday) 
 * is given. Shops only open and close on the hour and are open for no less than an hour or longer than 23 hours.
 */
/*
TimeTable
static int getOpeningHour(int day)
Returns the time at the given day when the shop opens.
static int getClosingHour(int day)
Returns the time at the given day when the shop closes.
static String getNameOfDay(int day)
Returns the name of the given day.
static void selectTimeTable(String[] args)
Changes the time table setting to the user's StudOn selection. Note: The required args argument should be the one that is passed to your main method.
static int getDayFromInput(String[] args)
Returns the day selected by the user in StudOn.
static int getHourFromInput(String[] args)
Returns the hour selected by the user in StudOn. 
*/

// 1) Create a public class OpeningHours with a main method.
// Close the main method and class at the end of this task. All of the following subtasks should be programmed within this main method.

public class OpeningHours {
    public static void main(String[] args) {

        // 2a) Use a loop and TimeTable to display the opening times for each day of the week. 
        // Follow the scheme below exactly :
        // Montag: 8:00 - 17:00 
        // Dienstag: 22:00 - 4:00 
        // Mittwoch: 20:00 - 2:00 
        // Donnerstag: 12:00 - 19:00 
        // Freitag: 18:00 - 2:00 
        // Samstag: 10:00 - 14:00 
        // Sonntag: 6:00 - 12:00

        //for (int i = 0; i < 7; i++) {
        //    System.out.println();
        // }

        // At the moment the same opening hours are always used in TimeTable . 
        // Expand your program so that the opening times selected in StudON are used. 
        // The selection is available within the main method in the args parameter and can 
        // be passed directly to the corresponding TimeTable method .

        TimeTable.selectTimeTable(args);

        // 3a) Now create two integer constants in which you can later store a day of the week (0 (=Monday) to 6 (=Sunday)) and a time (0 - 23).
        // 3b) So that the values ​​set by the user in StudON are used in your program, you must now initialize the two constants you just created with the corresponding methods from the TimeTable class.
        
        final int day = TimeTable.getDayFromInput(args);
        final int hour = TimeTable.getHourFromInput(args);

        // 4) Since the input comes from the user, it can contain errors. Check whether the values ​​for the day of the week and the time are in the valid range (see subtask 3a). If not, print an error message with System.err.println and end the main method (and thus your program) with the return statement ;
        
        if (day < 0 || day > 6 || hour < 0 || hour > 23) {
            System.err.println("Invalid input");
            return;
        }

        /*
        5) Use the  TimeTable class  and the point in time selected by the user in StudON from the previous subtaskautomatically  indicate whether the shop is currently open at the selected time. 
        Here are some possible outputs (use the same output scheme, but you want your program to output only for the user-selected time!):
        Montag, 8:00: Open 
        Montag, 16:00: Open 
        Montag, 17:00: Closed 
        Dienstag, 23:00: Open 
        Mittwoch, 3:00: Open 
        Mittwoch, 14:00: Closed 
        Mittwoch, 22:00: Open
On Wednesday morning at 3:00 the shop in Variant A is really open! The shop opens on Tuesday at 10:00 p.m. and closes again on Wednesday morning at 4:00 a.m. The shop only opens again on Wednesday evening at 8:00 p.m. until Thursday morning at 2:00 a.m.
         */

        final int openingHour = TimeTable.getOpeningHour(day);
        final int closingHour = TimeTable.getClosingHour(day);
        // Get name of day
        final String nameOfDay = TimeTable.getNameOfDay(day);
        final String textQuery = nameOfDay + ", " + hour + ":00: ";

        if (openingHour <= closingHour) {
            if (hour >= openingHour && hour < closingHour) {
                System.out.println(textQuery + "Offen");
            } else {
                System.out.println(textQuery + "Geschlossen");
            }
        } else {
            if (hour >= openingHour || hour < closingHour) {
                System.out.println(textQuery + "Offen");
            } else {
                System.out.println(textQuery + "Geschlossen");
            }
        }

        //6) Test your program with different days and hours and opening times. Above all, pay attention to borderline cases with opening hours that extend beyond the daily limit!
        //main-Methode und Klasse hier schließen

    }
}