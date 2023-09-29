#!/usr/bin/python3
""" Log Parsing """


while(1):
    total_size = 0
    line_counter = 0
    check = 0
    try:
        while(line_counter < 9 and check == 0):
            current_line = input()
            line_as_list = current_line.split()
            if line_as_list[7] in codes_dict.keys():
                line_counter += 1
                codes_dict[line_as_list[7]] += 1
                total_size += int(line_as_list[8])
        print("File size: " + str(total_size))
        for code in codes_dict.keys():
            print(code + ": " + str(codes_dict[code]))
    except KeyboardInterrupt:
        check = 1
        print("File size: " + str(total_size))
        for code in codes_dict.keys():
            print(code + ": " + str(codes_dict[code]))

