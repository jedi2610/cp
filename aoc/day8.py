def main():
    file = open('input', 'r')
    oginput = file.readlines()
    # seen = set()
    for i in range(len(oginput)):
        input = list(oginput)
        if input[i].startswith('nop'):
            input[i] = 'jmp ' + input[i].split()[1]
        elif input[i].startswith('jmp'):
            input[i] = 'nop ' + input[i].split()[1]
        else:
            continue

        ip = acc = 0
        runs = 0
        while runs < 1000:

            # if ip in seen:
            #     print(acc)
            #     break

            if ip == len(input)-1:
                print(acc, "done")
                break
            # else:
                # seen.add(ip)
            runs += 1
            ins = input[ip].split()
            if input[ip].startswith('acc'):
                acc += int(ins[-1])
                ip += 1
            elif input[ip].startswith('nop'):
                ip += 1
            elif input[ip].startswith('jmp'):
                ip += int(ins[-1])

        if runs < 1000:
            print("more than 1000")
            break


if __name__ == "__main__":
    main()
