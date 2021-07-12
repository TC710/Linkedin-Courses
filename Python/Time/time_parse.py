#Unoptimized time parser for a string of "HH:MM:SS"
import datetime

class mytime:
    vectorTime = list()
    timeformat = "%H:%M:%S"

    def __init__(self, lis):
        self.vectorTime = lis

    def print_list(self):
        print(self.vectorTime)

    def add_time(self,str):
        try:
            validtime = datetime.datetime.strptime(str, self.timeformat)
            self.vectorTime.append(str)
        except ValueError:
            print("Not a valid format of time of HH:MM:SS")

    def add_lis_time(self,lis):
        for i in lis:
            try:
                validtime = datetime.datetime.strptime(i, self.timeformat)
                self.vectorTime.append(i)
            except ValueError:
                print(i +" Not a valid format of time of HH:MM:SS")
                continue

    def small_compare(self, dic, first, second):
        for i in range(3):
            if int(dic[first][i]) < int(dic[second][i]):
                return first
            elif int(dic[first][i]) == int(dic[second][i]):
                continue
            else:
                return second
        return first

    def smallest_time(self):
        temp = dict()
        if len(self.vectorTime) == 1:
            return self.vectorTime[0]
        for i in self.vectorTime:
            temp[i] = i.split(':')
        start = list(temp.keys())[0]
        for i in temp.keys():
            start = self.small_compare(temp, start, i)
        return start

    def largest_compare(self,dic,first, second):
        for i in range(3):
            if int(dic[first][i]) > int(dic[second][i]):
                return first
            elif int(dic[first][i]) == int(dic[second][i]):
                continue
            else:
                return second
        return first

    def largest_time(self):
        temp = dict()
        if len(self.vectorTime) == 1:
            return self.vectorTime[0]
        for i in self.vectorTime:
            temp[i] = i.split(':')
        start = list(temp.keys())[0]
        for i in temp.keys():
            start = self.largest_compare(temp, start, i)
        return start

test = mytime(["17:15:46","17:59:08","17:00:08","17:59:09"])
test.add_time("08:17:21")
test.print_list()
print(test.smallest_time())
test.add_lis_time(["10:15:46","03:59:08","04:00:08","03:59:09"])
test.print_list()
print(test.smallest_time())
print(test.largest_time())