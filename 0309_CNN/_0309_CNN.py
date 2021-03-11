# 此处是主程序模块，任务一的内容在此模块中编写
# 另外五个任务的内容，需要在这段主程序代码中调用不同的任务函数完成
# Python不会像C语言一样，标示出MAIN程序来代表主程序。
# 可以直接理解这段代码是我们分类项目的主程序
# classify_dog_project

from time import time, sleep
from os import listdir

# TODO: 1. 
   
#definition，主要是定义宠物图像文件夹，模型名称（后面要比较不同的模型,所以模型名称会被修改），小狗名称定义文件的名称
classify_dir='pet_images/'
arch='vgg'
dogfile='dognames.txt'

#Sets start time
start_time = time()
#Replace sleep(75) below with code you want to time
sleep(2)
#Sets end time
end_time = time()
#Computes overall runtime in seconds
tot_time = end_time - start_time
#Prints overall runtime in seconds
print("\nTotal Elapsed Runtime : ", tot_time,"in seconds.")

hours = int( (tot_time / 3600) )
minutes = int( ( (tot_time % 3600)/ 60 ) )
seconds = int ( ( (tot_time % 3600)% 60 ) )


print("\nTotal Elapsed Runtime:", str( int( (tot_time / 3600)) ) + ":"+
str( int( ( (tot_time % 3600)/ 60 ) ) ) +":"+
str( int(( (tot_time % 3600)% 60 ) ) ) )


# TODO: 2. 
answers_dic = get_pet_labels()

# TODO: 3. 
result_dic = classify_images()
    
# TODO: 4. 
adjust_results4_isadog()

# TODO: 5.
results_stats_dic = calculates_results_stats()

# TODO: 6. 
print_results()

# TODO: 1. 输出最终运行时长格式为 hh:mm:ss 


#Imports only listdir function from oS module
from os import listdir
# Retrieve the filenames from folder pet_images/
filename_list = listdir("pet_images/")
#Print 10 of the filenames from folder pet_images/
print(" \nPrints 10 filenames from folder pet_images/")
for idx in range(0,10,1):
    print("%2d file: %-25s" % (idx + 1, filename_list[idx]))



#Creates empty dictionary named pet_dic
pet_dic = dict()
# Determines number of items in dictionary
items_in_dic = len(pet_dic)
print("\nEmpty Dictionary pet_dic - n items=", items_in_dic)
# Adds new key-value pairs to dictionary ONLY when key doesn't already existkeys = ["beagle_0239.jpg"， "Boston_terrier_02259.jpg"]
values = ["beagle", "boston terrier"]
for idx in range(0, len(keys),1):
    if keys[idx] not in pet_dic:
        pet_dic[keys[idx]] = values[idx]
    else:
        print("** Warning: Key=", keys[idx],
    "already exists in pet_dic with value =", pet_dic[keys[idx]])
#Iterating through a dictionary printing all keys & their associated values
print("\nPrinting all key-value pairs in dictionary pet_dic:")
for key in pet_dic:
    print("Key=", key," Value=", pet_dic[key])


#Sets pet_image variable to a filename
pet_image = "Boston_terrier_02259.jpg"
#Sets string to lower case letters
low_pet_image = pet_image.lower()
#Splits lower case string by _ to break into words
word_list_pet_image = low_pet_image.split("_")
#Create pet_name starting as empty string
pet_name =""
#Loops to check if word in pet name is only
#alphabetic characters - if true append word
# to pet_name separated by trailing space
for word in word_list_pet_image:
    if word.isalpha() :
        pet_name += word + ""
# Strip off starting/trailing whitespace characters
pet_name = pet_name.strip(
#Prints resulting pet_name
print("\nFilename=", pet_image," Label=", pet_name)




