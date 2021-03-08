movies = {
'妖猫传':['黄轩','染谷将太'],
'无问西东':['章子怡','王力宏','祖峰'],
'超时空同居':['雷佳音','佟丽娅'],
}
actor=input('请问你想查询哪位演员:>')
for movie in movies:# 用 for 遍历字典
    actors=movies[movie]# 用 for 遍历字典
    if actor in actors:
        print(actor + '出演了电影' + movie)