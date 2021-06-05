init = input()
end = input()
init = int(init)
end = int(end)
day = 0
while init > end:
    day += 12
    init = init//2
print(day)
