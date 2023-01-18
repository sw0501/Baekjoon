def solution(s):
    answer = ''
    
    M = 0
    m = 0
    
    tmp = 0
    
    if s[0] == '-':
        for i in s:
            if i == '-':
                continue
            elif i == ' ':
                M = tmp
                m = tmp
                break
            else:
                tmp*=10
                tmp+=int(i)
        M *= -1
        m *= -1
    else:
        for i in s:
            if i == ' ':
                M = tmp
                m = tmp
                break
            else:
                tmp*=10
                tmp+=int(i)
    
    tmp = 0
    flag = 0
    for i in s:
        if i == '-':
            flag = 1
        elif i == '+':
            flag = 0
        elif i == ' ':
            if flag==1:
                tmp*=-1
            if M < tmp:
                M = tmp
            if m > tmp:
                m = tmp
            tmp = 0
            flag = 0
        else:
            tmp *= 10
            tmp += int(i)
            
    if flag==1:
        tmp*=-1
    if M < tmp:
        M = tmp
    if m > tmp:
        m = tmp
    tmp = 0
    flag = 0
            
    answer = str(m) + " " + str(M)
    print(answer)
    return answer