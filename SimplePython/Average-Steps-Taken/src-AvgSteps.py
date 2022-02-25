#Variables
Jan = 31
Feb = 28
March = 31
April = 30
May = 31
June = 30
July = 31
Aug = 31
Sept = 30
Oct = 31
Nov = 30
Dec = 31

#Define main
def main():
    try:
        #Check if leap year
        year = input('Enter current year to be checked: ')

        #If leap year, update Feb to 29 days
        if(year%4==0 and year%100!=0 or year%400==0):
            global Feb
            Feb = 29
            return Feb
        else:
            print('Not a leap year.')
    
        #Open file
        file = open('steps.txt', 'r')

        #Average steps each month
        average_steps(file, 'January', Jan)
        average_steps(file, 'February', Feb)
        average_steps(file, 'March', March)
        average_steps(file, 'April', April)
        average_steps(file, 'May', May)
        average_steps(file, 'June', June)
        average_steps(file, 'July', July)
        average_steps(file, 'August', Aug)
        average_steps(file, 'September', Sept)
        average_steps(file, 'October', Oct)
        average_steps(file, 'November', Nov)
        average_steps(file, 'December', Dec)

    #IOError
    except IOError as err:
        print('IOError:', err)

    #ValueError
    except ValueError as err:
        print('ValueError:', err)

    #FileNotFoundError
    except FileNotFoundError:
        print('File not found.')

    #Other Errors
    except Exception as err:
        print('Error occured:',err)

    else:
        #Close file
        file.close()
    
#Define average steps
def average_steps(file, month_name, days):
    sum = 0
    for count in range(days):
        sum += int(file.readline())
    average = sum / days
    print('The average steps taken in', month_name, 'was',
          format(average, ',.1f'))
    
#Call main function
main()
