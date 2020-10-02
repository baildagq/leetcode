def simplifyPath(path):
    paths = path.split('/')
    stack = []
    for p in paths:
        if p == '' or p == '.':
            continue
        elif p == '..':
            if len(stack) > 0:
                stack.pop()
        else:
            stack.append(p)
    return '/' + '/'.join(stack)

print(simplifyPath('/home/list/'))

