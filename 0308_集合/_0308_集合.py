
import random

# 输入过程
inputs = []
for i in [1, 2]:
    checked = False
    while not checked:
        text = input(f'输入第{i}个集合，格式如{set([random.randint(0, 9) for _ in range(3)])}: ')
        try:
            t = eval(text)
            if type(t) is not set:
                raise TypeError("数据类型错误！")
            t = set(t)
            for item in t:
                if type(item) is not int:
                    raise TypeError("存在元素类型错误，请输入int型元素！")
            if len(t) == 0:
                raise ValueError("输入长度不能为空！")
            inputs.append(t)
            checked = True
        except Exception as e:
            print(e)
            print("输入错误，请重新输入！")

print('inputs', inputs)
# 先计算并集和交集
result_and = inputs[0] & inputs[1]
result_or = inputs[0] | inputs[1]
print("result_and", result_and, "result_or", result_or)
length = max([max(inputs[0]), max(inputs[1])])
# 然后生成bit串
result_bits_and, result_bits_or = [0 for _ in range(length + 1)], [0 for _ in range(length + 1)]
for i in result_and:
    result_bits_and[i] = 1
for i in result_or:
    result_bits_or[i] = 1
print("result_bits_and", result_bits_and, "result_bits_or", result_bits_or)
print("result_str_and", ''.join(map(lambda x: str(x), result_bits_and)))
print("result_str_or", ''.join(map(lambda x: str(x), result_bits_or)))
