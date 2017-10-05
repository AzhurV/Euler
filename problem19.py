days_list = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

def is_leap(year):
    return year % 4 == 0 and year % 100 > 0\
        or year % 400 == 0

def num_days(year, month):
    if month == 1:
        if is_leap(year):
            return 29
        else:
            return 28
    else:
        return days_list[month]

def count_sundays(start, end):
    current_year = 1900
    current_day = 1
    weekday = 1
    current_month = 0
    sunday_count = 0
    while current_year < end:
        while current_month < 12:
            while current_day < num_days(current_year, current_month):
                if weekday == 0 and current_day == 0 and current_year >= start:
                    sunday_count += 1
                current_day += 1
                weekday += 1
                if weekday % 7 == 0:
                    weekday = 0
            current_day = 0
            current_month += 1
        current_month = 0
        current_year += 1
    return sunday_count

if __name__ == "__main__":
    n = count_sundays(1901,2000)
    print(n)
