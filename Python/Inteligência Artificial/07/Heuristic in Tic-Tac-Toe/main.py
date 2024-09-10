import numpy as np


from timeit import default_timer as timer


# Melhorias
#   - Usar (-1, 0, 1) para (jogador 1, vazio, jogador 2)
#   - Fazer verificação de vitória pelo valor
#   - Fazer verificação de heurística (vitórias do 1 - vitórias do 2) através
#     da lógica (if all <= 0) para jogador 1 e (if all >= 0)
#   - Fazer classe com o formato do tabuleiro e função para varrer verticais,
#     horizontais e as duas diagonais (principal e secundária)
#   - 


# Generate random board in a matrix format
# 0 -> empty
# 1 -> player 1
# 1 -> player 2
# WARNING: It can generate some invalid states where both players wins ou that the game has already ended
def random_board():
    board = np.random.randint(3, size=(3, 3))
    
    while (np.sum(board == 1) - np.sum(board == 2)) > 1:
        board = np.random.randint(3, size=(3, 3))
    
    return board


# Count possible wins for a player in a board
def count_possible_wins(board, player):
    # Define opponent
    if player == 1:
        opponent = 2
    else:
        opponent = 1
    
    count = 0
    # Count verticals and horizontals
    for pos in range(3):
        # Horizontals
        if opponent not in board[pos, :]:
            count += 1
        
        # Verticals
        if opponent not in board[:, pos]:
            count += 1
    
    # Count main diagonal
    if opponent not in [board[0, 0], board[1, 1], board[2, 2]]:
        count += 1
    
    # Count secundary diagonal
    if opponent not in [board[0, 2], board[1,1], board[2, 0]]:
        count += 1
    
    return count


# Evaluation function for a board (state)
def evaluation_function(board):
    return count_possible_wins(board, 1) - count_possible_wins(board, 2)


# Calculation of how many random states are possible to be evaluated in the time passed 
def compute_eval_by_time(max_time):
    count = 0
    elapsed_time = 0
    start_time = timer()

    while elapsed_time < max_time:
        board = random_board()
        evaluation_function(board)
        count += 1
        elapsed_time = timer() - start_time

    return count


if __name__ == "__main__":
    board = random_board()

    print(f"Tabuleiro:\n{board}")
    print(f"Heurística avaliada no tabuleiro: {evaluation_function(board)}")

    time = 3
    result = compute_eval_by_time(time)
    print(f"Com {time}s foi possível computar a heurística para {int(result / time)} estados de tabuleiro")
