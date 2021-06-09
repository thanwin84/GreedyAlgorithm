def maxSum(s1, s2, s3):
    sum1 = 0
    sum2 = 0
    sum3 = 0
    for i in s1:
        sum1 += i
    for i in s2:
        sum2 += i
    for i in s3:
        sum3 += i
    n1 = len(s1)
    n2 = len(s2)
    n3 = len(s3)
    top1 = 0
    top2 = 0
    top3 = 0
    while True:
        if top1 == n1 or top2 == n2 or top3 == n3:
            return 0
        if sum1 == sum2 and sum2 == sum3:
            return sum1
        if sum1 >= sum2 and sum1 >= sum3:
            sum1 -= s1[top1]
            top1 += 1
        elif sum2 >= sum1 and sum2 >= sum3:
            sum2 -= s2[top2]
            top2 += 1
        elif sum3 >= sum1 and sum3 >= sum2:
            sum3 -= s3[top3]
            top3 += 1
stack1 = [ 3, 2, 1, 1, 1 ]
stack2 = [ 4, 3, 2 ]
stack3 = [ 1, 1, 4, 1 ]
print(maxSum(stack1, stack2, stack3))
