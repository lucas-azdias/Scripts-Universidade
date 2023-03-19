#Média das notas de quatro alunos fornecidas pelo usuário

#Head
notas = list()
média = 0

#Body
for i in range(4):
    notas.append(float(input(f"Nota do Aluno {i + 1}: ")))
    média += notas[i]

média = média / 4

print(f"A média dos alunos foi: {média:.2f}")