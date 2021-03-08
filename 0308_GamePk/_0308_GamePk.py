import time
import random
player_victory = 0
enemy_victory = 0
while True:
    for i in range(1,4):
        time.sleep(1.5)
        print('  \n——————现在是第 {} 局——————'.format(i))
        player_life = random.randint(100,150)
        player_attack = random.randint(30,50)
        enemy_life = random.randint(100,150)
        enemy_attack = random.randint(30,50)
        print('【玩家】\n血量：{}\n攻击：{}'.format(player_life,player_attack))
        print('------------------------')
        time.sleep(1)
        print('【敌人】\n血量：{}\n攻击：{}'.format(enemy_life,enemy_attack))
        print('-----------------------')
        time.sleep(1)
        while player_life > 0 and enemy_life > 0:
            player_life = player_life - enemy_attack 
            enemy_life = enemy_life - player_attack
            print('敌人发起了攻击，【玩家】剩余血量{}'.format(player_life))
            print('你发起了攻击，【敌人】的血量剩余{}'.format(enemy_life))