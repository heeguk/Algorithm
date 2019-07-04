#!/usr/bin/env python
# coding: utf-8

# In[19]:


import re

dic = {
    '.-':'A','-...':'B','-.-.':'C','-..':'D','.':'E','..-.':'F',
    '--.':'G','....':'H','..':'I','.---':'J','-.-':'K','.-..':'L',
    '--':'M','-.':'N','---':'O','.--.':'P','--.-':'Q','.-.':'R',
    '...':'S','-':'T','..-':'U','...-':'V','.--':'W','-..-':'X',
    '-.--':'Y','--..':'Z'
}

def three_five_sum(num):
    result = 0
    for i in range(1, num):
        if i % 3 ==0 or i % 5 == 0:
            result += i
    return result
    

def digit(num):
    i = 1
    result = {}
    while num:
        digit = num % 10
        num = int(num / 10)
        result[str(i)] = digit
        i *= 10
    return result


def angle(num):
    hour = 0
    minute = 0
    angle = hour - minute
    result = []
    for i in range(0, 24):
        for j in range(0, 60):
            for k in range(0, 60):
                hour = 30 * i + 0.5 * j + 0.5 / 60 * k
                minute = 6 * j + 0.1 * k
                hour = hour % 360
                minute = minute % 360
                angle = abs(minute - hour)
                if angle > 180:
                    angle = 360 - angle
                if angle == num:
                    temp = ''
                    if i < 10:
                        temp += '0' + str(i)
                    else:
                        temp += str(i)   
                    temp += ':'
                    if j < 10:
                        temp += '0' + str(j)
                    else:
                        temp += str(j)   
                    temp += ':'
                    if k < 10:
                        temp += '0' + str(k)
                    else:
                        temp += str(k)   
                    result.append(temp)
    return result

def cover(sample):
    p = re.compile('(\w+)\s+(\d{6})[-](\d{7})\s+(\d{3})[-](\d{4})[-](\d{4})')
    m = p.sub('\g<1> \g<2>-******* \g<4>-\g<5>-****',sample)
    p2 = re.compile('(\w+)\s+(\d{6}[-][*]{7})\s+(\d{3}[-]\d{4}[-][*]{4})')
    m2 = p2.findall(m)
    return m2
    
    
def birth_year(sample):
    p = re.compile('\w+\s+(\d{2})\d{4}[-]\d{7}\s+\d{3}[-]\d{4}[-]\d{4}')
    m = p.sub('\g<1>', sample)
    m = list(map(int, m.split()))
    return sum(m)
    

def mos_abs(dic, sample):
    result = ''
    lines = sample.split('  ')
    for line in lines:
        alpha = line.split(' ')
        for i in alpha:
            result += dic[i]
        result += ' '
    result = result [:-1]
    return result
    

def abs_mos(dic, sample):
    result = ''
    sample = sample.upper()
    lines = sample.split(' ')
    for line in lines:
        for i in list(line):
            for key in dic.keys():
                if dic[key] == i:
                    result += key
                    break
            result += ' '
        result += ' '
    result = result[:-2]
    return result
    

def dashinsert(num):
    num = list(num)
    result = ''
    for i in range(0, len(num)):
        result += num[i]
        if i < len(num) - 1:
            if int(num[i]) % 2 + int(num[i+1]) % 2 == 2:
                result += '-'
            elif int(num[i]) % 2 + int(num[i+1]) % 2 == 0:
                result += '*'
    return result
    
def press(sample):
    repeat = 0
    result = ''
    for i in range(0, len(sample)):
        if i == 0:
            repeat = 1
        else:
            if sample[i-1] == sample[i]:
                repeat += 1
            else:
                result += sample[i-1] + str(repeat)
                repeat = 1
        if i == len(sample) - 1:
            result += sample[i] + str(repeat)
    return result


def judge(num):
    num = list(map(int, list(str(num))))
    dsc = False
    asc = False
    for i in range(1, len(num)):
        if num[i] > num[i-1]:
            asc = True
        if num[i] < num[i-1]:
            dsc = True
    if asc and dsc:
        return True
    else:
        return False
    
def not_orgr_count(num):
    result = num - 1
    for i in range(10, num):
        if judge(i):
            result -= 1
    return result
    
    
def even_fib_sum(num):
    fib = [1, 1]
    while True:
        if fib[-1] + fib[-2] > num:
            break
        fib.append(fib[-1] + fib[-2])
    result = []
    for i in fib:
        if i % 2 == 0:
            result.append(i)
    return sum(result)
        
class Calculator:
    def __init__(self):
        self.value = 0
    
    def add(self, num):
        self.value = self.value + num
        
    def mul(self, num):
        self.value = self.value * num
        
    def sub(self, num):
        self.value = self.value - num
    
    def div(self, num):
        if num == 0:
            return 0
        else:
            self.value = self.value / num
    def pow(self, num):
        self.value = pow(self.value, num)
        

def count_num(num):
    result = [0] * 10
    for i in range(1, num + 1):
        while i:
            result[i%10] += 1
            i = int(i / 10)
    return result

def prime(num):
    result = [False, False] + [True] * (num - 1)
    result_out = []
    for n in range(2, num + 1):
        ok = 1
        for i in range(2, n):
            if n % i == 0:
                ok = 0
                break
        if not ok:
            result[n] = False
    for i in range(0, len(result)):
        if result[i]:
            result_out.append(i)
    return result_out

def prime_sum(num):
    result = prime(num)
    return sum(result)


def Goldbach(num):
    prime_list = prime(num)
    result = []
    for n in prime_list:
        if num - n in prime_list:
            if not [min(n, num - n), max(n, num - n)] in result:
                result.append([min(n, num - n), max(n, num - n)])
    return result

print(angle(15))


