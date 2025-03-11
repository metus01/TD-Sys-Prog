#include <stdio.h>
#include <time.h>
typedef enum
{
  MON = 1,
  TUE = 2,
  WED = 3,
  THU = 4,
  FRI = 5,
  SAT = 6,
  SUN = 7
} dayname;

typedef enum
{
  JAN = 1,
  FEB = 2,
  MAR = 3,
  APR = 4,
  MAY = 5,
  JUN = 6,
  JUL = 7,
  AUG = 8,
  SEP = 9,
  OCT = 10,
  NOV = 11,
  DEC = 12
} monthname;

// bitfields
typedef struct
{
  dayname weekday : 3;
  unsigned int day : 5;
  monthname month : 4;
  int year : 20;
} date;

char *dayname_str(dayname day)
{
  switch (day)
  {
  case MON:
    return "Lundi";
  case TUE:
    return "Mardi";
  case WED:
    return "Mercredi";
  case THU:
    return "Jeudi";
  case FRI:
    return "Vendredi";
  case SAT:
    return "Samedi";
  case SUN:
    return "Dimanche";
  default:
    return "Jour inconnu";
  }
}

char *monthname_str(monthname month)
{
  switch (month)
  {
  case JAN:
    return "January";
  case FEB:
    return "February";
  case MAR:
    return "March";
  case APR:
    return "April";
  case MAY:
    return "May";
  case JUN:
    return "June";
  case JUL:
    return "July";
  case AUG:
    return "August";
  case SEP:
    return "September";
  case OCT:
    return "October";
  case NOV:
    return "November";
  case DEC:
    return "December";
  default:
    return "Invalid";
  }
}

dayname weekday(time_t when)
{
  struct tm *date_object = localtime(&when);
  int day_num = date_object->tm_wday + 1;
}

int leapyear(unsigned int year)
{
  if (((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

date from_time(time_t when)
{

  struct tm *date_object = localtime(&when);
  int date_year = date_object->tm_year + 1900;
  int date_month = date_object->tm_mon + 1;
  int date_week_day = date_object->tm_wday + 1;
  int date_month_day = date_object->tm_mday;
  dayname w_day = (dayname)date_week_day;
  unsigned int day = date_month_day;
  monthname month = (monthname)date_month;

  date returned_date = {w_day, day, month, date_year};

  return returned_date;
}

int main(void)
{
  time_t current_timestamp = time(NULL);
  date current_day = from_time(current_timestamp);
  printf("Le jour du mois : %d \n", current_day.day);
  printf("Le jour de la semaine : %d \n", current_day.weekday);
  printf("Le mois est : %d \n", current_day.month);
  printf("De l'an : %d \n", current_day.year);
}